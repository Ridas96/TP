// Estructura básica para hacer animaciones interactivas
#include "Pantalla.h"
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include "Personaje.h" //apuntador a una estructura solo podremos usar las funciones que metamos en h
#include "Enemigo.h"
#include "Colision.h"
#include "Estrella.h"
#include "Estrellas.h"

int puntuacion;

int main(int argc, char **argv)
{
    // Creación y configuración de la pantalla
    Pantalla_Crea("fondo", 800,600);

    // Declaración de variables que mantengan el estado
    // de la animación
    Imagen inicio=Pantalla_ImagenLee("windows.bmp",0);

    PlaySound(TEXT("sonidowindows.wav"),NULL,SND_ASYNC); ///Sonido windows

    // Bucle principal de la animación
    int terminado = 0;
    while (Pantalla_Activa() && !terminado)
    {
        // Detección de los eventos producidos por el usuario
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) terminado=1;

        // Dibujo de los elementos de la simulación en el frame
        Pantalla_DibujaImagen(inicio,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_DibujaTexto("Hola Mundo" , 350 , 550);
        Pantalla_DibujaTexto("Pulsa return para continuar" ,50 ,50);

        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }

    srand(time(NULL));
    Imagen Imagenpersonaje=Pantalla_ImagenLee("Clipo.bmp",0);
    Personaje clipo= PersonajeCrea (Imagenpersonaje,70, 80,rand()%(Pantalla_Anchura()-70),rand()%(Pantalla_Altura()-80));

    Imagen Imagenenemigo=Pantalla_ImagenLee("apple.bmp",50);
    Enemigo apple= EnemigoCrea (Imagenenemigo,80,90,350,250,15,15);
    

    terminado = 0;

    ///tiempo inicial
    int t1= time(NULL);

    while (Pantalla_Activa() && !terminado)

    {
        //movimiento personaje
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) terminado=1;
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))PersonajeMueve(clipo,-20,0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))PersonajeMueve(clipo,20,0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))PersonajeMueve(clipo,0,20);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP))PersonajeMueve(clipo,0,-20);

        EnemigoMueve(apple);

        Pantalla_DibujaImagen(inicio,0,0,Pantalla_Anchura(),Pantalla_Altura());
        PersonajeDibuja(clipo);
        EnemigoDibuja(apple);
        Pantalla_DibujaTexto("Pulsa espacio para continuar" ,50 ,50);

        ///tiempo 2 y calcular tiempo
        int t2= time(NULL);
        int tiempo= t2-t1;
        char texto[100];
        if (Colision(PersonajeGetx(clipo),PersonajeGety(clipo),PersonajeGetw(clipo),PersonajeGeth(clipo),EnemigoGetx(apple),EnemigoGety(apple),EnemigoGetw(apple),EnemigoGeth(apple))){terminado=1;}
        sprintf(texto,"%d s.",tiempo); ///quitar el s. para que no aparezca en pantalla
        Pantalla_DibujaTexto(texto,350,550);
        puntuacion=tiempo;
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    char puntos[100];
    sprintf(puntos,"%d puntos",puntuacion); ///quitar puntos para que no aparezca en el txt

    ///guardar puntuacion en fichero(ELIMINADO)
    //FILE* fichero;
    //fichero=fopen("Puntuacion.txt","at");
    //fputs("Puntuacion= ",fichero);  /// quitar esta linea para que no apareca
    //fputs(puntos,fichero);
    //fputs("\n",fichero);
    //fclose(fichero);


    while (Pantalla_Activa())
    {
        Pantalla_DibujaImagen(inicio,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_DibujaTexto("Hasta pronto" , 350 , 550);
        Pantalla_DibujaTexto(puntos,350,500);
        Pantalla_DibujaTexto("Guarda tu puntuacion al acabar! ^^",435,500);
        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }
    // Liberar la pantalla
    PersonajeLibera(clipo);
    Pantalla_ImagenLibera(inicio);
    Pantalla_Libera();

///Guardar puntuacion en fichero con nombre
    FILE *f;

    char nombre;

    f = fopen ( "Puntuaciones.txt", "a+t" ); //parametro para escritura al final y para file tipo texto

    printf("Nombre del jugador: ");

    while((nombre = getchar()) != '\n')
    {
        printf("%c", fputc(nombre, f));

    }
    printf(", puntuacion guardada con exito");
    fputs("--Puntuacion= ",f);  /// quitar esta linea para que no apareca
    fputs(puntos,f);;
    fputs("\n",f);
    fclose ( f );

    return 1;
}
