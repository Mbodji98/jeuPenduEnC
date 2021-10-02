#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dico.h"
#include "mesFonctions.h"


char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    long i = 0;
    int bonneLettre = 0;

    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouvee[i] = 1; // On met à 1 la case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}
