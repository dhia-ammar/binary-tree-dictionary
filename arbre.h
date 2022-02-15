#pragma once
typedef struct arbre TArbre;
struct arbre
{
    TArbre *fg;
    TArbre *fd;
    char c;
    int val;
};

TArbre arbreConsVide();
int arbreEstVide(TArbre);
TArbre arbreCons(char, int, TArbre, TArbre);
char arbreRacineLettre(TArbre);
int arbreRacineNbOcc(TArbre);
TArbre arbreFilsGauche(TArbre);
TArbre arbreFilsDroit(TArbre);
void arbreSuppr(TArbre *);
void parcoursMots(char[], TArbre);