import os
import glob
import re
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Configurações gerais
CACHE_CYCLE_TIME = 1
MEMORY_CYCLE_TIME = 10
DISK_CYCLE_TIME = 100

sns.set_theme(style="whitegrid")

def extrair_info(nome_arquivo):
    match = re.match(r'log(C\dA\d)(Temporal|Espacial|Aleatorio)\.log', nome_arquivo, re.IGNORECASE)
    if match:
        arq = match.group(1).upper()
        tipo = match.group(2).capitalize()
        return arq, tipo
    return nome_arquivo, 'Desconhecido'

def extrair_cenario(identificador):
    match = re.match(r'(C\d)', identificador)
    return match.group(1) if match else 'C?'

def ordena_identificadores(id_list, reverse=False):
    def sort_key(x):
        match = re.match(r'C(\d+)A(\d+)', x.upper())
        return (int(match.group(1)), int(match.group(2))) if match else (999, 999)
    return sorted(id_list, key=sort_key, reverse=reverse)

def process_log(file_path):
    hits = 0
    misses = 0
    memory_accesses = 0
    tlb_hits = 0
    tlb_misses = 0
    page_faults = 0
    disk_accesses = 0
    total_operations = 0

    with open(file_path, 'r') as file:
        content = file.read()

    # Cache hits/misses
    cache_actions = re.findall(r'Action = (load|store) operation  -  Access Type = (hit|miss)', content)
    for _, access_type in cache_actions:
        total_operations += 1
        if access_type == 'hit':
            hits += 1
        else:
            misses += 1
            memory_accesses += 1

    # TLB hits/misses
    tlb_actions = re.findall(r'Location: TLB\s+Action = .*? - Access Type = (hit|miss)', content)
    for access_type in tlb_actions:
        if access_type == 'hit':
            tlb_hits += 1
        else:
            tlb_misses += 1

    # Page Faults
    page_faults = len(re.findall(r'Page Fault', content, re.IGNORECASE))

    # Acessos ao disco
    disk_accesses = len(re.findall(r'Location: DISK\s+Action =', content))

    # Tempo estimado
    time = (hits * CACHE_CYCLE_TIME) + (misses * (MEMORY_CYCLE_TIME + CACHE_CYCLE_TIME)) + (disk_accesses * DISK_CYCLE_TIME)

    nome_arquivo = os.path.basename(file_path)
    identificador, tipo = extrair_info(nome_arquivo)
    cenario = extrair_cenario(identificador)

    return {
        'Arquivo': nome_arquivo,
        'Identificador': identificador,
        'Cenario': cenario,
        'Tipo': tipo,
        'Hits': hits,
        'Misses': misses,
        'Total Acessos': total_operations,
        'Taxa de Acerto (%)': (hits / total_operations) * 100 if total_operations else 0,
        'Tempo Total (unidades)': time,
        'Acessos Memoria Principal': memory_accesses,
        'TLB Hits': tlb_hits,
        'TLB Misses': tlb_misses,
        'Page Faults': page_faults,
        'Acessos ao Disco': disk_accesses,
    }

def gerar_graficos(pasta_logs, pasta_saida):
    log_files = glob.glob(os.path.join(pasta_logs, '*.log'))
    resultados = [process_log(f) for f in log_files]
    df = pd.DataFrame(resultados)

    for cenario, grupo_cenario in df.groupby('Cenario'):
        pasta_cenario = os.path.join(pasta_saida, cenario)
        os.makedirs(pasta_cenario, exist_ok=True)

        for metrica in ['Taxa de Acerto (%)', 'Tempo Total (unidades)', 'Acessos Memoria Principal',
                        'TLB Hits', 'TLB Misses', 'Page Faults', 'Acessos ao Disco']:
            pivot = grupo_cenario.pivot(index='Identificador', columns='Tipo', values=metrica)
            ordered_ids = ordena_identificadores(pivot.index.tolist(), reverse=False)
            pivot = pivot.reindex(ordered_ids)
            if all(col in pivot.columns for col in ['Temporal', 'Espacial', 'Aleatorio']):
                pivot = pivot[['Temporal', 'Espacial', 'Aleatorio']]
            pivot.plot(kind='line', marker='o')
            plt.title(f'{metrica} - {cenario}')
            plt.ylabel(metrica)
            plt.xlabel('Configuração')
            plt.grid(True)
            plt.tight_layout()
            filename = f'{metrica.lower().replace(" ", "_").replace("(", "").replace(")", "")}_{cenario}.png'
            plt.savefig(os.path.join(pasta_cenario, filename))
            plt.close()

    print(f'Gráficos gerados em: {pasta_saida}')

if __name__ == '__main__':
    pasta_logs = 'logs/'       # <-- Altere se necessário
    pasta_saida = 'graficos/'  # <-- Altere se necessário
    gerar_graficos(pasta_logs, pasta_saida)

