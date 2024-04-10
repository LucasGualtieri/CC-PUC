# Define uma função que imprime uma mensagem após um atraso
defmodule Processos do
  def imprimir_mensagem(mensagem, atraso) do
    IO.puts("#{mensagem} iniciou!")
    Process.sleep(atraso) # Simula uma tarefa que leva algum tempo
    IO.puts("#{mensagem} terminou!")
  end
end

pid = spawn (fn ->
  receive do
    {:msg, mensagem} -> IO.puts(mensagem)
  end
  Processos.imprimir_mensagem("Processo 1", 1000)
end)

IO.puts "Incio do programa"
Process.sleep(1500)
send(pid, {:msg, "Uma mensagem qualquer."})
Process.sleep(1500)
