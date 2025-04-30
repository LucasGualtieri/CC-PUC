import os
import re
import matplotlib.pyplot as plt
import seaborn as sns
from collections import defaultdict

LOG_DIR = 'logs/'  # Diretório com os arquivos .log

sns.set_theme(style="whitegrid")

# Métricas e os blocos em que aparecem
metric_map = {
    'Main Memory Access': 'Main Memory',
    'Main Memory Time': 'Main Memory',
    'Page Table Access': 'Page Table',
    'TLB Access': 'TLB',
    'TLB Time': 'TLB',
    'TLB Hit Rate': 'TLB',
    'L1 Access': 'Unified Cache - Level 1',
    'L1 Hit Rate': 'Unified Cache - Level 1',
    'L2 Access': 'Unified Cache - Level 2',
    'L2 Hit Rate': 'Unified Cache - Level 2',
    'L3 Access': 'Unified Cache - Level 3',
    'L3 Hit Rate': 'Unified Cache - Level 3',
    'Total Time': 'ROOT',
}

def extract_block(content, header):
    # Captura o conteúdo de um bloco específico
    pattern = rf"{header}\n((?:.|\n)+?)(?:\n\S|\Z)"
    match = re.search(pattern, content)
    return match.group(1) if match else ""

def extract_value(text, label, is_float=False):
    # Captura valores numéricos a partir de um rótulo
    match = re.search(rf"{label}:\s+([0-9.]+)", text)
    if match:
        return float(match.group(1)) if is_float else int(float(match.group(1)))
    return None

def extract_total_time_global(content):
    # Captura o Total Time geral (fora dos blocos)
    matches = re.findall(r'(?m)^ Total Time: (\d+)', content)
    if matches:
        return int(matches[-1])
    return None

# Estrutura de dados: {Cenário: {Métrica: {Arquitetura: valor}}}
data = defaultdict(lambda: defaultdict(dict))

# Processamento dos arquivos
for filename in os.listdir(LOG_DIR):
    if filename.endswith('.log') and re.match(r'C\d+A\d+\.log', filename):
        with open(os.path.join(LOG_DIR, filename)) as f:
            content = f.read()

        match = re.match(r'(C\d+)(A\d+)\.log', filename)
        if not match:
            continue
        cenario, arquitetura = match.groups()

        for metric, section in metric_map.items():
            if metric == 'Total Time':
                val = extract_total_time_global(content)
            else:
                block = extract_block(content, section)
                if 'Access' in metric:
                    val = extract_value(block, 'Total Access')
                elif 'Time' in metric:
                    val = extract_value(block, 'Total Time')
                elif 'Hit Rate' in metric:
                    # TLB usa "Hit rate", caches usam "Hit/rate"
                    label = 'Hit rate' if section == 'TLB' else 'Hit/rate'
                    val = extract_value(block, label, is_float=True)
                else:
                    val = None
            if val is not None:
                data[cenario][metric][arquitetura] = val

# Geração de gráficos
for cenario, metricas in data.items():
    os.makedirs(cenario, exist_ok=True)
    for metrica, valores in metricas.items():
        plt.figure()
        arqs = sorted(valores)
        vls = [valores[a] for a in arqs]
        sns.lineplot(x=arqs, y=vls, marker='o')
        plt.title(f'{metrica} - {cenario}')
        plt.xlabel('Arquitetura')
        plt.ylabel(metrica)
        plt.tight_layout()
        plt.savefig(os.path.join(cenario, f'{metrica.replace(" ", "_").replace("/", "_")}.png'))
        plt.close()

