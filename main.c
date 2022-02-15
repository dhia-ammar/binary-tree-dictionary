#include <stdio.h>
#include <string.h>
#include "arbre.c"
#include "dico.c"
void main()
{
    TArbre arbre;
    arbre = arbreConsVide();
    dicoInsererMot("Arbre", &arbre);
    dicoInsererMot("Arbres", &arbre);
    dicoInsererMot("Armoire", &arbre);
    dicoInsererMot("Armoire", &arbre);
    dicoInsererMot("Dhia", &arbre);
    dicoInsererMot("Ammar", &arbre);
    dicoInsererMot("Ammare", &arbre);
    dicoInsererMot("Art", &arbre);
    dicoAfficher(arbre);
    printf("Mots differents :%i\n", dicoNbMotsDifferents(arbre));
    printf("Mots totals :%i\n", dicoNbMotsTotal(arbre));
    printf("NbOcc : %i\n", dicoNbOcc("Armoire", arbre));
    printf("NbOcc : %i\n", dicoNbOcc("Arbres", arbre));
    printf("NbOcc : %i\n", dicoNbOcc("Art", arbre));
}