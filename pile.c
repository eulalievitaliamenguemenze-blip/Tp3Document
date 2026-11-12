#include <stdlib.h>
#include "pile.h"
void pile_init(Pile *p){ p->sommet=NULL; p->taille=0; }
bool pile_vide(const Pile *p){ return p->sommet==NULL; }
void pile_push(Pile *p, double val){
    NoeudPile *n=malloc(sizeof(NoeudPile));
    n->valeur=val; n->suivant=p->sommet; p->sommet=n; p->taille++;
}
bool pile_pop(Pile *p, double *out){
    if(!p->sommet) return false;
    NoeudPile *t=p->sommet; if(out) *out=t->valeur;
    p->sommet=t->suivant; free(t); p->taille--; return true;
}
bool pile_peek(const Pile *p, double *out){
    if(!p->sommet) return false; if(out) *out=p->sommet->valeur; return true;
}
int pile_taille(const Pile *p){ return p->taille; }
void pile_detruire(Pile *p){ double d; while(pile_pop(p,&d)); }
