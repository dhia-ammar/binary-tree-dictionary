#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

TArbre arbreConsVide()
{
    TArbre abr;
    abr.c = '\n';
    abr.val = 0;
    abr.fd = NULL;
    abr.fg = NULL;
    return abr;
}
int arbreEstVide(TArbre a)
{
    if (a.c == '\0')
    {
        return 1;
    }
    return 0;
}
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd)
{
    TArbre abr;
    abr.c = c;
    abr.val = n;
    *(abr.fg) = fg;
    *(abr.fd) = fd;
    return abr;
}
char arbreRacineLettre(TArbre a)
{
    return a.c;
}
int arbreRacineNbOcc(TArbre a)
{
    return a.val;
}
TArbre arbreFilsGauche(TArbre a)
{
    return *(a.fg);
}
TArbre arbreFilsDroit(TArbre a)
{
    return *(a.fd);
}
void arbreSuppr(TArbre *a)
{
    *a = arbreConsVide();
}