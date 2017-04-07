#include <stdlib.h>
#include "Estrellas.h"
#include "Estrella.h"
#include "Colision.h"
#include "Personaje.h"

struct EstrellasRep
{
    Estrella * estrella;
    int max, n;
};
Estrellas EstrellasCrea(int max)
{
    Estrellas p =malloc(sizeof(struct EstrellasRep));
    p->estrella=malloc(max*sizeof(Estrellas));
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
void EstrellasInserta(Estrellas p,Imagen i,int w,int h,int x,int y)
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
    }

};
int EstrellasColision(Estrellas p,int x, int y, int w, int h)//la coordenadas de la estrella(del personaje) desde el main la llamare como get x, get y, etc
{
    int i = 0;
    while (i < p->n)
    {
        if (Colision(EstrellaGetx(p->estrella[i]),EstrellaGety(p->estrella[i] ),EstrellaGetw(p->estrella[i]),EstrellaGeth(p->estrella[i]),x,y,w,h))//compruebo si colisionan con estrella iesima
        {
            p->estrella[i] = p->estrella[p->n-1];
            p->n--;
        }
        else i++;
    }
//bucle que recorra cada estrella para saber si hay colision
//bucle colision del estilo conjunto suprime maximo

}
