# listPid = Enum.map(1..100, fn _ -> Playground.start end)
# listPid = Enum.map(listPid, fn x -> Playground.add(x, 1) end)

defmodule Playground do
  # Inicia um novo servidor e retorna seu PID
  def start do
    spawn(fn -> loop(0) end)
  end

  # Solicita ao servidor uma visualização do valor atual
  def view(server_pid) do
    send(server_pid, {:view, self()})
    receive do {:response, value} -> value end
  end

  # Envia uma mensagem para adicionar um valor ao servidor
  def add(server_pid, value), do: send(server_pid, {:add, value})

  # Envia uma mensagem para subtrair um valor do servidor
  def sub(server_pid, value), do: send(server_pid, {:sub, value})

  # Envia uma mensagem para multiplicar o valor do servidor por um valor
  def mult(server_pid, value), do: send(server_pid, {:mult, value})

  # Envia uma mensagem para dividir o valor do servidor por um valor
  def div(server_pid, value), do: send(server_pid, {:div, value})

  # Loop interno do servidor que processa as mensagens recebidas
  defp loop(current_value) do
    new_value =
      receive do
        {:view, caller_pid} ->
          send(caller_pid, {:response, current_value})
          current_value

        {:add, value} ->
          current_value + value

        {:sub, value} ->
          current_value - value

        {:mult, value} ->
          current_value * value

        {:div, 0} ->
          IO.puts("Erro: Divisão por zero")
          current_value

        {:div, value} ->
          current_value / value

        _ ->
          IO.puts("Mensagem inválida")
          current_value
      end
     Process.sleep(5000)  # Simula uma tarefa que leva algum tempo

    loop(new_value)
  end
end

# Inicia 100 servidores Playground em paralelo
servers = Enum.map(1..100, fn _ -> Playground.start() end)

# Define uma função para enviar uma operação aritmética a um servidor
send_operation = fn server_pid, operation, value ->
  case operation do
    :add -> Playground.add(server_pid, value)
    :sub -> Playground.sub(server_pid, value)
    :mult -> Playground.mult(server_pid, value)
    :div -> Playground.div(server_pid, value)
  end
end

# Envia uma operação aritmética para cada servidor
Enum.each(servers, fn server_pid ->
  send_operation.(server_pid, :add, 10)
end)

# Visualiza e imprime o valor atual de cada servidor
Enum.each(servers, fn server_pid ->
  value = Playground.view(server_pid)
  IO.puts("Valor atual do servidor #{inspect(server_pid)}: #{value}")
end)

# Inicia o contador com 0
total = 0

# Realiza 100 somas de forma síncrona
Enum.each(1..100, fn _ ->
    total = total + 10
    # Imprime o resultado final
    IO.puts("Total síncrono: #{total}")
    # Simula uma tarefa que leva algum tempo
    Process.sleep(5000)
  end
)
