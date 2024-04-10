# Definindo uma struct usando defstruct
defmodule Pessoa do
  defstruct nome: "vazio", idade: 0, cidade: "Desconhecida"
end

defmodule ApredendoStruct do
  def main do
    # Criando uma instância da struct Pessoa
    joao = %Pessoa{nome: "João", idade: 30, cidade: "São Paulo"}

    # Acessando os campos da struct
    IO.puts "Nome: #{joao.nome}"
    IO.puts "Idade: #{joao.idade}"
    IO.puts "Cidade: #{joao.cidade}"

    # Atualizando uma instância da struct usando o operador `|`
    maria = %{joao | nome: "Maria"}
    IO.puts "Nome atualizado: #{maria.nome}"

    # Verificando se um campo está presente em uma struct
    IO.puts "O campo :cidade está presente? #{Map.has_key?(maria, :cidade)}"

    # Convertendo uma struct para um mapa
    mapa_maria = Map.from_struct(maria)
    IO.inspect mapa_maria

    # Verificando se uma struct é igual a outra
    outra_maria = %Pessoa{nome: "Maria", idade: 30, cidade: "São Paulo"}
    IO.puts "As structs maria e outra_maria são iguais? #{maria == outra_maria}"
  end
end

ApredendoStruct.main()
