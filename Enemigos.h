typedef struct EnemigosRep *Enemigos;
typedef int Elemento;

Enemigos EnemigosCrea();
void EnemigosLibera(Enemigos e);
void EnemigosInserta(Enemigos e, Imagen i,int x,int y, int w,int h, int vx,int vy);
void EnemigosDibuja(Enemigos e);
void EnemigosMueve(Enemigos e);
int EnemigosColision(Enemigos e,int x,int y,int w,int h);

#endif
