#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1]))
        printf("Archivo no encontrado\n");
        return 1;
    }
    int i =0; 
    int contadorletras =0;
    int contadorpalabras =0;
    int contadororaciones =0;
    while (text[i]>0) 
    {
        if (isalpha(text[i]))
        {
            contadorletras++;
        }
    
        if (text[i]==' ')
        {
            contadorpalabras++;    
        }
    
        if (text[i]=='?'||text[i]=='!'||text[i]=='.')
        {
            contadororaciones++;
        }

        i++;
    }
float index
    float l = 100 * contadorletras / contadorpalabras;
    float s = 100 * contadorpalabras / contadororaciones;
    index = 0.0588 * l - 0.296 * s - 15.8;
    round(index)
    if(index<1)
    {
        printf ("Before grade 1");
    }
    else if (index>16)
    {
        printf ("Grade 16+");
    }
    else
    {
        printf ("Grade %d\n", index);
    }
    printf ("cantidad de letras = %d\n", contadorletras);
    printf ("cantidad de palabras = %d\n", contadorpalabras);
    printf ("cantidad de oraciones = %d\n", contadororaciones);
    
    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
