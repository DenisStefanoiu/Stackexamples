// Denis STEFANOIU
// Varianta 1


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define LMAX 80 // lungime maxima sir

// Program inversare sir citit de la tastatura
// Inversarea se face prin punerea caracterelor sirului in stiva (caracter cu caracter
// incepand cu primul caracter al sirului
// si apoi  afisarea in ordine inversa prin extragerea caracterelor din stiva

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
// PROTOTIPUL FUNCTIILOR UTILIZATE
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
     char sir[LMAX];
     printf("Introduceti sirul: ");
     gets(sir);

     //creez stiva
     Stack s=new();


     int len=strlen(sir); // determin lungimea sirului
     char* p; // pointer care indica inceputul sirului
     p=sir; // initializez p cu inceput de sir

     for (int i=0;i<len;i++){
        push(s,p+i); // parcurg sirul si pun caracterele din sir in stiva
     }

     printf("\nSirul inversat: ");

     len=s->length; // lungimea stivei . Nu era nevoie pt ca am determinat anterior lungimea sirului
            //pus in stiva caracter cu caracter; Lungimea stivei este egala cu lungimea sirului.

     for (int i=1;i<=len;i++){
        printf("%c",*(char*)pop(s)); //extrag caracterele din stiva si le afisez
      }

     printf("\n\n");
     if (s->length==0) printf("Gata! Am golit Stiva!!!\n");
     free(s);
     return 0;
    }


    //
    //
    // IMPLEMENTAREA FUNCTIILOR
    //
// functia new creeaza o stiva noua in memorie
Stack new(){
    Stack S=(Stack) malloc(sizeof(struct stack));
    S->v=NULL;
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
