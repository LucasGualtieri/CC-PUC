#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define sTAM 200
#define aNTAM 300

bool toBool(char *input);

struct Character
{
    char id[sTAM];
    char name[sTAM];
    char alternativeNames[aNTAM];
    char house[sTAM];
    char ancestry[sTAM];
    char species[sTAM];
    char patronus[sTAM];
    bool hogwartsStaff;
    bool hogwartsStudent;
    char actorName[sTAM];
    bool alive;
    char dateOfBirth[sTAM];
    int yearOfBirth;
    char eyeColour[sTAM];
    char gender[sTAM];
    char hairColour[sTAM];
    bool wizard;
};
typedef struct Character Character;

void setId(char id[], Character *x)
{
    strcpy(x->id, id);
}

void setName(char name[], Character *x)
{
    strcpy(x->name, name);
}

void setAlternativeNames(char alternativeNames[], Character *x)
{
    int tam = strlen(alternativeNames);

    alternativeNames[0] = '{';
    alternativeNames[tam - 1] = '}';

    strcpy(x->alternativeNames, alternativeNames);
}

void setHouse(char house[], Character *x)
{
    strcpy(x->house, house);
}

void setAncestry(char ancestry[], Character *x)
{
    strcpy(x->ancestry, ancestry);
}
void setSpecies(char species[], Character *x)
{
    strcpy(x->species, species);
}
void setPatronus(char patronus[], Character *x)
{
    strcpy(x->patronus, patronus);
}
void setHogwartsStaff(char staff[], Character *x)
{
    // x -> hogwartsStaff = isBool(staff);
    x->hogwartsStaff = false;
}
void setHogwartsStudent(char student[], Character *x)
{
    // x -> hogwartsStudent = isBool(student);
    x->hogwartsStudent = false;
}
void setActorName(char actorName[], Character *x)
{
    strcpy(x->actorName, actorName);
}
void setAlive(char alive[], Character *x)
{
    // x -> alive = isBool(alive);
    x->alive = false;
}
void setDateOfBirth(char dateOfBirth[], Character *x)
{
    strcpy(x->dateOfBirth, dateOfBirth);
}
void setYearOfBirth(char yearOfBirth[], Character *x)
{
    x->yearOfBirth = atoi(yearOfBirth);
}
void setEyeColour(char eyeColour[], Character *x)
{
    strcpy(x->eyeColour, eyeColour);
}
void setGender(char gender[], Character *x)
{
    strcpy(x->gender, gender);
}
void setHairColour(char hairColour[], Character *x)
{
    strcpy(x->hairColour, hairColour);
}
void setWizard(char wizard[], Character *x)
{
    x->wizard = toBool(wizard);
}

char **split(char *string)
{

    int len = strlen(string);
    int n = 1;

    for (int i = 0; i < len; i++)
    {
        if (string[i] == ';')
            n++;
    }

    char **array = (char **)malloc((n + 1) * sizeof(char *));

    for (int i = 0; i < n + 1; i++)
    {
        array[i] = calloc(sTAM, sizeof(char *));
    }

    strcpy(array[n], "cFIM");

    strcpy(array[0], strtok(string, ";"));

    for (int i = 1; i < n; i++)
    {
        char* temp = strtok(NULL, ";");
        // strcpy(array[i], temp == NULL ? "vazio" : temp);
        if (temp == NULL) {
            strcpy(array[i], "vazio");
            strtok(NULL, ";");
        }

        else {
            strcpy(array[i], temp);

        }
    }   

    return array;
}

Character ler(char *string)
{

    // char aux[2000];
    // strcpy(aux, string);
    char **array = split(string);

    int pos = 0;
    Character x;

    setId(array[pos++], &x);

    setName(array[pos++], &x);

    setAlternativeNames(array[pos++], &x);

    setHouse(array[pos++], &x);

    setAncestry(array[pos++], &x);

    setSpecies(array[pos++], &x);

    setPatronus(array[pos++], &x);

    setHogwartsStaff(array[pos++], &x);

    setHogwartsStudent(array[pos++], &x);

    setActorName(array[pos++], &x);

    setAlive(array[pos++], &x);

    setDateOfBirth(array[pos++], &x);

    setYearOfBirth(array[pos++], &x);

    setEyeColour(array[pos++], &x);

    setGender(array[pos++], &x);

    setHairColour(array[pos++], &x);

    setWizard(array[pos++], &x);

    int i;
    for (i = 0; strcmp(array[i], "cFIM"); i++)
    {
        free(array[i]);
    }

    free(array[i]);

    free(array);

    return x;
}

bool toBool(char *input)
{
    return strcmp(input, "VERDADEIRO") == 0;
}

void status(Character x)
{
    printf("[%s ## ", x.id);
    printf("%s ## ", x.name);
    printf("%s ## ", x.alternativeNames);
    printf("%s ## ", x.house);
    printf("%s ## ", x.ancestry);
    printf("%s ## ", x.species);
    printf("%s ## ", x.patronus);
    printf("%s ## ", x.hogwartsStaff ? "true" : "false");
    printf("%s ## ", x.hogwartsStudent ? "true" : "false");
    printf("%s ## ", x.actorName);
    printf("%s ## ", x.alive ? "true" : "false");
    printf("%s ## ", x.dateOfBirth);
    printf("%d ## ", x.yearOfBirth);
    printf("%s ## ", x.eyeColour);
    printf("%s ## ", x.gender);
    printf("%s ## ", x.hairColour);
    printf("%s]", x.wizard ? "true" : "false");
    printf("\n");
}

bool stop(char *id)
{
    bool stop = false;

    if (strcmp(id, "FIM"))
    {
        stop = true;
    }

    return stop;
}

void importDB(Character lista[], char *fileName)
{
    FILE *arq = fopen(fileName, "r");

    char line[2000];

    fgets(line, 2000, arq);

    for (int i = 0; fgets(line, 2000, arq); i++)
    {
        // line[strspn("\n\r", line)] = '\0';
        lista[i] = ler(line);
        // status(lista[i]);
        // printf("Linha: %s\n", line);

    }

    fclose(arq);
}

char* readString(char* string) {
    scanf("%s", string);
    return string;
}

Character pesquisaSequencial(char* id, Character* array) {
    for (int i = 0; i < 404; i++) {
        if (strcmp(array[i].id, id) == 0) return array[i];
    }
}

int main()
{

    Character listaCSV[404];

    importDB(listaCSV, "characters.csv");
    char id[100];


    Character subConjunto[404];

    int n;
    for (int n = 0; strcmp(readString(id), "FIM") != 0; n++)
    {
        subConjunto[n] = pesquisaSequencial(id, listaCSV);
        status(subConjunto[n]);
    }
}