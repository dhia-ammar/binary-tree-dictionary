#include "dico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dicoAfficher(TArbre a)
{
    char ancien[] = "";
    parcoursMots(ancien, a);
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