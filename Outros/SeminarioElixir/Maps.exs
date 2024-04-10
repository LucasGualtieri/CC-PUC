# Criando um mapa
mapa = %{
  4 => "Arthur",
  2 => "Gabriel",
  1 => "Lucas",
  3 => "Pedro"
}

# Acessando valores do mapa
IO.puts "Nome de chave 1: #{mapa[1]}"
IO.puts "Nome de chave 2: #{mapa[2]}"
IO.puts "Nome de chave 3: #{mapa[3]}"
IO.puts "Nome de chave 4: #{mapa[4]}"

# Atualizando valores do mapa
mapa = Map.put(mapa, 3, "Pedro Alves")
IO.puts "Nome de chave 3: #{mapa[3]}"

# Adicionando novos pares chave-valor ao mapa
mapa = Map.put_new(mapa, 0, "Marco Rodrigo Costa")
IO.puts "Nome de chave 0: #{mapa[0]}"

# Verificando a existência de uma chave no mapa
IO.puts "A chave 0 existe no mapa? #{Map.has_key?(mapa, 0)}"

# Removendo um par chave-valor do mapa
mapa = Map.delete(mapa, 0)
IO.puts "A chave 0 existe no mapa? #{Map.has_key?(mapa, 0)}"

# Iterando sobre os pares chave-valor do mapa
Enum.each mapa, fn {chave, valor} ->
  IO.puts "#{chave}: #{valor}"
end
