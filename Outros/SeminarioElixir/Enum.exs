# Criando uma lista de números
numeros = [1, 2, 3, 4, 5]

# Mostrando a lista original
IO.puts "Lista original: #{inspect(numeros)}"

# Usando o método Enum.map para transformar os elementos da lista
dobro = Enum.map(numeros, fn x -> x * 2 end)
IO.puts "Dobro de cada elemento: #{inspect(dobro)}"

# Usando o método Enum.filter para filtrar os elementos da lista
pares = Enum.filter(numeros, fn x -> rem(x, 2) == 0 end)
IO.puts "Números pares: #{inspect(pares)}"

# Usando o método Enum.reduce para reduzir a lista a um único valor
soma = Enum.reduce(numeros, 0, &(&1 + &2))
IO.puts "Soma dos números: #{soma}"

# Usando o método Enum.sort para ordenar a lista
ordenados = Enum.sort([42, 7, 18, 35, 27], :desc)
IO.puts "Lista ordenada: #{inspect(ordenados)}"

# Usando o método Enum.all? para verificar se todos os
# elementos da lista satisfazem uma condição
todos_positivos = Enum.all?(numeros, fn x -> x > 0 end)
IO.puts "Todos os números são positivos? #{todos_positivos}"
