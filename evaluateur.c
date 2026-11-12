#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "evaluateur.h"
#include "pile.h"

bool evaluer_postfixe(const char *expr, double *resultat, char *err, int err_size){
    Pile p; pile_init(&p);
    char *copy=strdup(expr);
    char *tok=strtok(copy," \t\r\n");
    while(tok){
        char *end;
        double v=strtod(tok,&end);
        if(end!=tok && *end=='\0'){
            pile_push(&p,v);
        } else if(strlen(tok)==1 && strchr("+-*/%",tok[0])){
            double b,a;
            if(!pile_pop(&p,&b) || !pile_pop(&p,&a)){
                snprintf(err,err_size,"Expression invalide: pas assez d'operandes pour '%s'",tok);
                free(copy); pile_detruire(&p); return false;
            }
            double r=0;
            if(tok[0]=='+') r=a+b;
            else if(tok[0]=='-') r=a-b;
            else if(tok[0]=='*') r=a*b;
            else if(tok[0]=='/'){
                if(b==0){ snprintf(err,err_size,"Division par zero"); free(copy); pile_detruire(&p); return false; }
                r=a/b;
            } else if(tok[0]=='%'){
                if((int)b==0){ snprintf(err,err_size,"Modulo par zero"); free(copy); pile_detruire(&p); return false; }
                r=(int)a % (int)b;
            }
            pile_push(&p,r);
        } else {
            snprintf(err,err_size,"Token invalide: '%s'",tok);
            free(copy); pile_detruire(&p); return false;
        }
        tok=strtok(NULL," \t\r\n");
    }
    free(copy);
    double final_res;
    if(!pile_pop(&p,&final_res) || !pile_vide(&p)){
        snprintf(err,err_size,"Expression invalide: trop d'operandes");
        pile_detruire(&p); return false;
    }
    *resultat=final_res;
    return true;
}
