#include <stdio.h>
#include <string.h>
#include "pile.h"
#include "file.h"
#include "evaluateur.h"
#include "parenthese.h"

void test_pile_file(){
    printf("=== Test Pile / File ===\n");
    Pile p; pile_init(&p);
    pile_push(&p,10); pile_push(&p,20);
    double v; pile_pop(&p,&v); printf("Pile pop: %.0f (attendu 20)\n",v);
    pile_detruire(&p);
    File f; file_init(&f);
    file_enfiler(&f,1); file_enfiler(&f,2); file_enfiler(&f,3);
    int iv; file_defiler(&f,&iv); printf("File defile: %d (attendu 1)\n",iv);
    file_detruire(&f);
}

void test_postfixe(){
    printf("\n=== Test Evaluateur Postfixe ===\n");
    struct { const char *expr; double attendu; bool doit_reussir; } tests[]={
        {"3 4 +",7,true},
        {"5 1 2 + 4 * + 3 -",14,true},
        {"3 4 + 2 *",14,true},
        {"10 2 /",5,true},
        {"10 0 /",0,false},
        {"3 +",0,false},
        {"3 4 5 +",0,false},
        {"2 3 %",2,true},
        {"",0,false}
    };
    char err[128]; double res;
    for(int i=0;i<9;i++){
        bool ok=evaluer_postfixe(tests[i].expr,&res,err,128);
        if(ok==tests[i].doit_reussir){
            if(ok) printf("[OK] '%s' = %.2f\n",tests[i].expr,res);
            else printf("[OK] '%s' echoue comme prevu: %s\n",tests[i].expr,err);
        } else {
            printf("[FAIL] '%s'\n",tests[i].expr);
        }
    }
}

void test_parentheses(){
    printf("\n=== Test Parenthesage ===\n");
    struct { const char *expr; bool valide; } tests[]={
        {"(a+b)",true},
        {"{[()]}",true},
        {"((()))",true},
        {"(a+b]",false},
        {"([)]",false},
        {"(((",false},
        {")))",false},
        {"",true},
        {"{[(a+b)*c]}",true}
    };
    char err[128];
    for(int i=0;i<9;i++){
        bool ok=verif_parenthesage(tests[i].expr,err,128);
        printf("[%s] '%s' %s\n", ok==tests[i].valide?"OK":"FAIL", tests[i].expr, ok?"valide":"invalide");
        if(!ok) printf("      -> %s\n",err);
    }
}

int main(){
    test_pile_file();
    test_postfixe();
    test_parentheses();
    printf("\nTous les tests termines - valgrind doit afficher 0 fuite\n");
    return 0;
}
