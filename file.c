#include <stdlib.h>
#include "file.h"
void file_init(File *f){ f->tete=NULL; f->queue=NULL; f->taille=0; }
bool file_vide(const File *f){ return f->tete==NULL; }
void file_enfiler(File *f, int val){
    NoeudFile *n=malloc(sizeof(NoeudFile));
    n->valeur=val; n->suivant=NULL;
    if(f->queue) f->queue->suivant=n; else f->tete=n;
    f->queue=n; f->taille++;
}
bool file_defiler(File *f, int *out){
    if(!f->tete) return false;
    NoeudFile *t=f->tete; if(out) *out=t->valeur;
    f->tete=t->suivant; if(!f->tete) f->queue=NULL;
    free(t); f->taille--; return true;
}
int file_taille(const File *f){ return f->taille; }
void file_detruire(File *f){ int v; while(file_defiler(f,&v)); }
