defmodule Operacoes do
  def quadrado(x) do
    IO.puts("x = #{x * x}")
    x * x
  end

  def dobro(x) do
    IO.puts("x = #{x * 2}")
    x * 2
  end
end

imprimir = fn x -> IO.puts("O resultado é: #{x}") end

5 |> Operacoes.quadrado |> Operacoes.dobro |> imprimir.()
