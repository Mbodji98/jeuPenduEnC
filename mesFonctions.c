#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dico.h"
#include "mesFonctions.h"


char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caract�re
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�

    // On lit les autres caract�res m�moris�s un � un jusqu'au \n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caract�re qu'on a lu
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

    // On parcourt motSecret pour v�rifier si la lettre propos�e y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On m�morise que c'�tait une bonne lettre
            lettreTrouvee[i] = 1; // On met � 1 la case du tableau de bool�ens correspondant � la lettre actuelle
        }
    }

    return bonneLettre;
}
