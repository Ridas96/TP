#include <stdlib.h>
#include "Estrellas.h"
#include "Estrella.h"
#include "Colision.h"
#include "Personaje.h"

struct EstrellasRep
{
    Elemento * estrella;
    int max, n;
};
Estrellas EstrellasCrea(int max)
{
    Estrellas p =malloc(sizeof(struct EstrellasRep));
    p->estrella=malloc(max*sizeof(Elemento));
    p->n=0;
    return p;
};
void EstrellasLibera(Estrellas p)
{
    free(p->estrella);
    free(p);
};
int EstrellasLleno(Estrellas p)
{
    return (p->n==p->max);

};
void EstrellasInserta(Estrellas p,Elemento estrella)
{
    p->estrella[p->n]=EstrellaCrea(i,w,h,x,y);
    p->n++;
};
void EstrellasDibuja(Estrellas p)
{
     int i=0;
        while (i<p->n){
         EstrellaDibuja(p->estrella[i]);
         i++;
};
int EstrellasColision(Estrellas p,int x, int y, int w, int h)//la coordenadas de la estrella(del personaje) desde el main la llamare como get x, get y, etc
{
    int i = 0;
    while (i < p->n)
    {
        if (Colision(x,y,w,h,EstrellaGetx(p->estrella[i]),EstrellaGety(p->estrella[i] ),EstrellaGetw(p->estrella[i]),EstrellaGeth(p->estrella[i])))//compruebo si colisionan con estrella iesima
        {
            p->estrella[i] = p->n[p->n-1];
            p->n--;
        }
        else i++;
    }

//bucle colision del estilo conjunto suprime maximo

}
