typedef char* String;

#define STR_MAX_LEN 500
#define BD_SIZE 3922 // Quantidade Jogadores

char* readStr(FILE* stream, String input) {
	if (!stream) stream = stdin;

	fgets(input, STR_MAX_LEN, stream);
	input[(int)strcspn(input, "\r\n")] = '\0';
	return input;
}