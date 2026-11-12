#ifndef PILE_H
#define PILE_H
#include <stdbool.h>
typedef struct NoeudPile {
    double valeur;
    struct NoeudPile *suivant;
} NoeudPile;
typedef struct {
    NoeudPile *sommet;
    int taille;
} Pile;
void pile_init(Pile *p);
bool pile_vide(const Pile *p);
void pile_push(Pile *p, double val);
bool pile_pop(Pile *p, double *out);
bool pile_peek(const Pile *p, double *out);
int pile_taille(const Pile *p);
void pile_detruire(Pile *p);
#endif
