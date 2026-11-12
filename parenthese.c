#include <string.h>
#include <stdio.h>
#include "parenthese.h"
#include "pile.h"

bool verif_parenthesage(const char *s, char *err, int err_size){
    Pile p; pile_init(&p);
    for(int i=0;s[i];i++){
        char c=s[i];
        if(c=='('||c=='['||c=='{') pile_push(&p,(double)c);
        else if(c==')'||c==']'||c=='}'){
            double top;
            if(!pile_pop(&p,&top)){
                snprintf(err,err_size,"Fermante '%c' sans ouvrante en pos %d",c,i);
                pile_detruire(&p); return false;
            }
            char o=(char)top;
            if((c==')'&&o!='(')||(c==']'&&o!='[')||(c=='}'&&o!='{')){
                snprintf(err,err_size,"Mal imbrique: '%c' ferme '%c' en pos %d",c,o,i);
                pile_detruire(&p); return false;
            }
        }
    }
    if(!pile_vide(&p)){
        snprintf(err,err_size,"Parenthese ouvrante non fermee");
        pile_detruire(&p); return false;
    }
    return true;
}
