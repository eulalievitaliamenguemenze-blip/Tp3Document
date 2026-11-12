#ifndef EVAL_H
#define EVAL_H
#include <stdbool.h>
bool evaluer_postfixe(const char *expr, double *resultat, char *err, int err_size);
#endif
