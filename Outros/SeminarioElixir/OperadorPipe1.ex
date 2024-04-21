defmodule MyModule do
	def sum(arg1, arg2) do
    IO.puts(arg1)
    IO.puts(arg2)
		arg1 + arg2
	end
	def sub(arg1, arg2) do
    IO.puts(arg1)
    IO.puts(arg2)
		arg1 - arg2
	end
	def mult(arg1, arg2) do
    IO.puts(arg1)
    IO.puts(arg2)
		arg1 * arg2
	end
	def print(arg) do
		IO.puts arg
	end
end

1
|> MyModule.sum(2)
|> MyModule.sub(3)
|> MyModule.mult(4)
|> MyModule.print
