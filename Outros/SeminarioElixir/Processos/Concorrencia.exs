# Define uma função que imprime uma mensagem após um atraso
defmodule Processos do
  def imprimir_mensagem(mensagem, atraso) do
    IO.puts("#{mensagem} iniciou!")
    Process.sleep(atraso) # Simula uma tarefa que leva algum tempo
    IO.puts("#{mensagem} terminou!")
  end
end

# Inicia dois processos concorrentes para imprimir mensagens
spawn(fn -> Processos.imprimir_mensagem("Processo 1", 1000) end)
spawn(fn -> Processos.imprimir_mensagem("Processo 2", 500) end)

Process.sleep(1500)  # Simula uma tarefa que leva algum tempo

IO.puts("Todos os processos concluíram.")
