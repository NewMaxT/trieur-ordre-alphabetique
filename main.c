#include <stdio.h>
#include <string.h>

#define MAX_LIGNE (1500)
#define MAX_COL (1500)

char CHEMIN_FICHIER_LECTURE[50];
char CHEMIN_FICHIER_ECRITURE[50];

static char mots[MAX_LIGNE][MAX_COL] = {{'\0','\0'}};
FILE *fichier = NULL;

int main(void)
{
    do {
        printf("Indiquez le chemin du fichier a trier :\n");
        scanf("%s", CHEMIN_FICHIER_LECTURE);

        fichier = fopen(CHEMIN_FICHIER_LECTURE, "r");

        if(NULL == fichier)  {
            printf("Erreur: Fichier introuvable\nVeuillez recommencer.\n");
        }
    } while (NULL == fichier);




    int nbMots = 0;

    while( fgets(mots[nbMots], MAX_COL, fichier ) ) {
        mots[nbMots][strlen(mots[nbMots]) - 1] = '\0';
        nbMots++;
    }

    int c;
    int d;

    char arrayNulle[MAX_COL] = {'\0'};

    for (c = 0 ; c < (nbMots - 1); c++) {
        for (d = 0 ; d <  (nbMots - c - 1); d++)  {
            if(  0 < strcmp( mots[d], mots[d+1] ) )   {
                strcpy( arrayNulle, mots[d]  );
                strcpy( mots[d], mots[d+1]);
                strcpy( mots[d+1], arrayNulle );
            }
        }
    }

    int i;

    char userInput[1];

    printf("Voulez-vous ecraser le fichier ? (O/N)\n");
    scanf("%s", userInput);

    do {
        if (strcmp(userInput, "N") == 0) {
            printf("Indiquez le chemin du fichier en sortie :\n");
            scanf("%s", CHEMIN_FICHIER_ECRITURE);
            fichier = fopen(CHEMIN_FICHIER_ECRITURE, "w+");
        } else {
            fichier = fopen(CHEMIN_FICHIER_LECTURE, "w+");
        }

        if(NULL == fichier)  {
            printf("Erreur: Fichier introuvable\nVeuillez recommencer.\n");
        }
    } while (NULL == fichier);


    for( i=0; i < nbMots; i++ ) {
        fprintf(fichier, "%s\n", mots[i]);
    }


    printf("Trie effectue et place dans : ");
    printf("%s\n", CHEMIN_FICHIER_ECRITURE);

    fclose(fichier);
    return(0);
}
