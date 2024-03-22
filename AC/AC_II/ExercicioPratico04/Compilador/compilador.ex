defmodule FileProcessor do
	def process_file(input_file, output_file) do
		{:ok, input} = File.read(input_file)
		processed_data = process_data(input)
		write_output(processed_data, output_file)
	end

	defp process_data(data) do
		# Your processing logic here
		# For example, let's just capitalize the content
		String.upcase(data)
	end

	defp write_output(data, output_file) do
		File.write(output_file, data)
	end
end

# Example usage:
FileProcessor.process_file("input.txt", "output.txt")
