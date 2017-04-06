#include <stdlib.h>
#include "Enemigos.h"
#include "Enemigo.h"

struct Nodo{
    Elemento Enemigo; ///el enemigo
    struct Nodo *sig;///el siguiente
};
typedef struct Nodo *NodoPtr; //auxiliar para manejarlo por dentro
struct EnemigosRep{
    NodoPtr cabecera;
    int n;
}
Enemigos EnemigosCrea(){
    Enemigos nuevo=malloc(sizeof(struct EnemigosRep));
    nuevo->cabecera=malloc(sizeof (struct Nodo);
    nuevo->sig=NULL;
    nuevo->n=0;
    return nuevo;
void EnemigosLibera(Enemigos e){
    while(e->cabecera){
        NodoPtr borrar=c->cabecera;
        e->cabecera=borrar->sig;
        free(borrar);
}
    free(e);
};
void EnemigosInserta(Estrellos e,Enemigo p){
    NodoPtr nuevo=malloc(sizeof(struct Nodo));
    nuevo->dato=e;
    nuevo->sig=aux->sig;
    aux->sig=nuevo;
    e->n++;
}
//void EnemigosMueve(Enemigos e){
    
   

};

void EnemigosInserta(Enemigos e,Enemigo p){
    NodoPtr nuevo=malloc(sizeof(struct Nodo));
    nuevo->dato=e;
    nuevo->sig=aux->sig;
    aux->sig=nuevo;
    e->n++;
};
void EnemigosDibuja(Enemigos e){
    while (e->cabecera){
            EnemigoDibuja(e->cabecera[n]);
    }
};

int EnemigosColision(Enemigos e,int x,int y, int w,int h){
    while (e->cabecera){
    if (Colision(EnemigoGetx(e->cabecera[n]),EnemigoGety(e->cabecera[n]),EnemigoGetw(e->cabecera[n]),EnemigoGeth(e->cabecera[n]),x,y,w,h)))
    {
        NodoPtr borrar=aux->sig;
        aux->sig=borrar->sig;
        free(borrar);
        c->n--;
    }
  }
};

