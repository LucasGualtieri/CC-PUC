#include <stdio.h>
#include <string.h>

// clear && gcc stringFacilEmC.c && ./a.out

#define STR_MAX_LEN 80

typedef struct String {
	char s[STR_MAX_LEN];
	int length;
} String;

String newString(const char* const str) {
	String string = { "", strlen(str) };
	strcpy(string.s, str);
	return string;
}

String readString(String* s) {
	fgets(s->s, STR_MAX_LEN, stdin);
	s->s[(int)strcspn(s->s, "\n")] = '\0';
	s->length = strlen(s->s);
	return *s;
}

String getString() {
	String s;
	fgets(s.s, STR_MAX_LEN, stdin);
	s.s[(int)strcspn(s.s, "\n")] = '\0';
	s.length = strlen(s.s);
	return s;
}