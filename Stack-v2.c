// Denis STEFANOIU
// Varianta 2

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
//#include "stiva.h"
#define LMAX 80// lungime maxima sir


// defineste structura nodurilor listei simplu inlantuite
struct node {
    void* data;
    struct node* next;
};

// se defineste tipul de date struct numit stack (structura stivei)
// structura contine doua componente:
// 1. pointer catre varful stivei
// 2. lungimea stivei (inaltimea stivei - nr. de valori puse in stiva)

struct stack{
    struct node* v;
    int length;
};

typedef struct stack* Stack;  // se defineste tipul de date Stack (pentru stiva)



//
// PROTOTIPUL FUNCTIILOR
//

// functia new creeaza o stiva noua in memorie
Stack new();

// functia isEmpty intoarce 1 daca stiva este vida, 0 daca stiva contine date
int isEmpty(Stack S);

// functia size intoarce lungimea stivei (inaltimea stivei)
int size(Stack S);

// functia intoarce adresa zonei de memorie unde este stocata valoarea din varful stivei
void* peek(Stack S);

//functia push pune valoarea in stiva
void push(Stack S, void* x);

// functia pop extrage valoarea din varful stivei
void* pop(Stack S);





//functia main
int main() {
    //citesc sirul de la tastaura
     char sir[LMAX+1];
     printf("Introduceti sirul [maxim %d caractere]: ",LMAX);
     gets(sir);
     //scanf("%[^\n]",sir);

     int lSir=strlen(sir); // lungimea sirului citit de la tastatura

     if (lSir==0) exit(1); // terminare daca nu introduci nimic

     // terminare daca introduci mai multe caractere decat LMAX

     if (lSir>LMAX){
         printf("\nAti depasit nr maxim de %d caractere permise!\n",LMAX);
         exit(1);
     }

     //creez stiva
     Stack s=new();

     // parcurg sirul si pun caracterele din sir in stiva
     for (char* c=sir;*c!='\0';c++){
            push(s,c);
     }

     printf("\nSirul inversat: ");

     // golesc stiva
     for (int lstack=size(s);lstack>0;lstack--){
        printf("%c",*(char*)pop(s)); //extrag caracterele din stiva si le afisez
      }
     printf("\n");
     free(s); // eliberez memoria alocata pentru stiva (head of stack)

     return EXIT_SUCCESS;
    }


    //
    // IMPLEMTAREA FUNCTIILOR
    //



// functia new creeaza o stiva noua in memorie
Stack new(){
    Stack S=(Stack) malloc(sizeof(struct stack));
    if (S==NULL) {
        printf("Insuficienta memorie: Nu se poate initializa stiva!!!");
        exit(1); // terminare program
    }
    S->v=0;
    S->length=0;
    return S;
}

// functia isEmpty intoarce 1 daca stiva este vida, 0 daca stiva contine date
int isEmpty(Stack S){
    return S->length==0;
}

// functia size intoarce lungimea stivei (inaltimea stivei)
int size(Stack S){
    return S->length;
}

// functia intoarce adresa zonei de memorie unde este stocata valoarea din varful stivei
void* peek(Stack S){
    assert(!isEmpty(S));
    return ((struct node*)(S->v))->data;
}

//functia push pune valoarea in stiva
void push(Stack S, void* x){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("Insuficienta memorie: Nu se poate adauga in stiva!!!\n");
        exit(1); // terminare program
    }
    n->data=x;
    n->next=S->v;
    S->v=n;
    S->length++;
} // valoarea de pus in stiva este transmisa prin adresa zonei de memorie in care este stocata

// functia pop extrage valoarea din varful stivei
void* pop(Stack S){
    assert(!isEmpty(S));
    struct node* s=S->v;
    void* x=s->data;
    S->v=s->next;
    free(s);
    S->length--;
    return x; //returneaza adresa zonei de memorie unde este stocata valoarea extrasa din varfu stivei
}


