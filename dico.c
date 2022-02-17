#include "dico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void dicoAfficher(TArbre a)
{
    parcoursMots("", a);
}
void parcoursMots(char ancien[], TArbre a)
{
    if (a.fg != NULL)
    {
        char s[50];
        strcpy(s, ancien);
        parcoursMots(strncat(s, &a.c, 1), *(a.fg));
    }
    if (a.fd != NULL)
    {
        parcoursMots(ancien, *(a.fd));
    }

    if (a.c == '\0')
    {
        printf("%s\n", ancien);
    }
}
void dicoInsererMot(char mot[], TArbre *pa)
{
    int l = strlen(mot);
    if (pa->c != mot[0] && pa->c != '\n')
    {
        if (pa->fd == NULL)
        {
            pa->fd = malloc(sizeof(TArbre));
            *(pa->fd) = arbreConsVide();
        }
        dicoInsererMot(mot, pa->fd);
    }
    else if (l > 0)
    {
        if (pa->c == '\n')
        {
            pa->c = mot[0];
            pa->fg = malloc(sizeof(TArbre));
            *(pa->fg) = arbreConsVide();
            dicoInsererMot(mot + 1, pa->fg);
        }

        else if (pa->c == mot[0])
        {
            if (pa->fg == NULL)
            {
                pa->fg = malloc(sizeof(TArbre));
                *(pa->fg) = arbreConsVide();
            }
            dicoInsererMot(mot + 1, pa->fg);
        }
    }
    else
    {
        if (pa->c == '\0')
        {
            pa->val += 1;
        }
        else if (pa->c == '\n')
        {
            pa->c = '\0';
            pa->val = 1;
        }
    }
}
int dicoNbOcc(char mot[], TArbre a)
{
    int l = strlen(mot);
    if (l > 0)
    {
        if (mot[0] == a.c)
        {
            if (a.fg != NULL)
            {
                return dicoNbOcc(mot + 1, *(a.fg));
            }
        }
        else if (a.fd != NULL)
        {
            return dicoNbOcc(mot, *(a.fd));
        }
    }
    else
    {
        if (a.c == '\0')
        {
            return a.val;
        }
        else if (a.fd != NULL)
        {
            return dicoNbOcc(mot, *(a.fd));
        }
    }
    return 0;
}
int dicoNbMotsDifferents(TArbre a)
{
    int n = 0;
    if (arbreRacineLettre(a) == '\0')
    {
        n = 1;
    }
    if (a.fd != NULL)
    {
        n += dicoNbMotsDifferents(arbreFilsDroit(a));
    }
    if (a.fg != NULL)
    {
        n += dicoNbMotsDifferents(arbreFilsGauche(a));
    }
    return n;
}
int dicoNbMotsTotal(TArbre a)
{
    int n = 0;
    if (arbreRacineLettre(a) == '\0')
    {
        n = arbreRacineNbOcc(a);
    }
    if (a.fd != NULL)
    {
        n += dicoNbMotsTotal(arbreFilsDroit(a));
    }
    if (a.fg != NULL)
    {
        n += dicoNbMotsTotal(arbreFilsGauche(a));
    }
    return n;
}

int piocherMot(char *motPioche)
{
    FILE *dico = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("./dico.txt", "r");
    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while (caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots);
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico);
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
    return 1;
}
int nombreAleatoire(int nombreMax)
{
    // le seed qui prend time donne le meme nombre plusieurs fois c'est pourquoi on ajoute un nombre aleatoir
    srand(time(NULL) + rand());
    return (rand() % nombreMax);
}