# Definindo uma função anônima (lambda) simples
dobro = fn x -> x * 2 end

# Usando a função anônima para dobrar um número
IO.puts "Dobro de 5: #{dobro.(5)}"

# Definindo e usando uma função anônima diretamente
IO.puts "Dobro de 5: #{(fn x -> x * 2 end).(5)}"

# Função anônima reduzida usando a sintaxe "&(&1 + 10)"
dobroReduzido = &(&1 * 2)

# Usando a função anônima reduzida para adicionar 10 a um número
IO.puts "Dobro de 5: #{dobroReduzido.(5)}"
