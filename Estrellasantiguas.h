#ifndef __Estrellas_H
#define __Estrellas_H
#include "Pantalla.h"
#include "Estrella.h"

typedef struct EstrellasRep *Estrellas;

Estrellas EstrellasCrea(int max);//creas el array
void EstrellasLibera(Estrellas p);
void EstrellasDibuja(Estrellas p);
int EstrellasColision(Estrellas p,int w,int h,int x,int y);
void EstrellasInserta(Estrellas p,Imagen i,int w,int h,int x,int y);
int EstrellasLleno(Estrellas p);
int EstrellasGetx(Estrellas p); //devuelve la x del personaje
int EstrellasGety(Estrellas p); //devuelve la y del personaje
int EstrellasGetw(Estrellas p);
int EstrellasGeth(Estrellas p);

#endif
