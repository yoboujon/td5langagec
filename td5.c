#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int getNbLines(FILE * readFile);
int EcritFichier(FILE * fich_lect, char * nom_fich_ecrit, int nb_lignes);

int main(void)
{
    FILE * f;
    char fileReadName[100],fileWriteName[100];
    
    printf("Entrez le nom du fichier à lire :\n");
    scanf("%s",fileReadName);
    printf("Entrez le nom du fichier à écrire :\n");
    scanf("%s",fileWriteName);
    f = fopen (fileReadName,"r");
    EcritFichier(f,fileWriteName,3);
    fclose(f);
    return 0;
}

int getNbLines(FILE * readFile)
{
    int c,count=0;
    do{
        c=getc(readFile);
        if(c == 0xa)
        {
            count++;
        }
    }while(c!=0xffffffff);
    return count+1;
}

int EcritFichier(FILE * fich_lect, char * nom_fich_ecrit, int nb_lignes)
{
    FILE * fich_ecrit;
    char str[MAX];

    fich_ecrit = fopen (nom_fich_ecrit,"w+");
    fseek(fich_lect,0,0);
    for(int i=0;i<nb_lignes;i++)
    {
        fgets(str,MAX,fich_lect);
        fputs(str,fich_ecrit);
    }
}