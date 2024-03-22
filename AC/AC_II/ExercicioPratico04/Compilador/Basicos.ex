# Sure! Let's create a simple Elixir program.
# Elixir is a functional, concurrent, general-purpose
# programming language that runs on the Erlang virtual machine (BEAM).
# It's known for its scalability, fault tolerance, and functional
# programming features.

# Here's a simple program that calculates the factorial of a
# given number using recursion:

defmodule Factorial do
	def factorial(0), do: 1
	def factorial(n) when n > 0 do
		n * factorial(n - 1)
	end
end

IO.puts "Enter a number to calculate its factorial:"
number = IO.gets("") |> String.trim() |> String.to_integer()

factorial = Factorial.factorial(number)
IO.puts("Factorial of #{number} is #{factorial}")

# Functional Paradigm: Elixir is a functional programming language,
# which means functions are first-class citizens. In this program,
# we define a module Factorial and within it, define functions
# for calculating factorial using pattern matching and recursion.

# Pattern Matching: Elixir heavily uses pattern matching. In the
# factorial/1 function, we have two function clauses that match
# different cases: when the input is 0 and when it's greater than 0.

# Pipe Operator (|>): The pipe operator is used to chain function
# calls, passing the result of the expression on its left-hand side
# as the first argument to the function on its right-hand side.
# This allows for a more readable and sequential flow of data.
# We use it to process user input: IO.gets("") |> String.trim()|> String.to_integer().

# Module: Elixir code is organized into modules.
# In this program, we define a module named Factorial.

# Interactive Shell (IEx): Elixir comes with an interactive
# shell called IEx, which allows you to interactively
# experiment with the language. You can run this program
# in IEx and see the results interactively.

# To run the program, you can save it in a file with
# a .ex extension (e.g., factorial.ex), then compile
# it using elixirc factorial.ex and finally run it with
# elixir -r factorial.ex -e "Factorial.factorial(<number>)",
# replacing <number> with the desired integer input.
