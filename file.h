#ifndef FILE_H
#define FILE_H
#include <stdbool.h>
typedef struct NoeudFile {
    int valeur;
    struct NoeudFile *suivant;
} NoeudFile;
typedef struct {
    NoeudFile *tete;
    NoeudFile *queue;
    int taille;
} File;
void file_init(File *f);
bool file_vide(const File *f);
void file_enfiler(File *f, int val);
bool file_defiler(File *f, int *out);
int file_taille(const File *f);
void file_detruire(File *f);
#endif
