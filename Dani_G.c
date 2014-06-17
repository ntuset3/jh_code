#include<stdio.h>

void inicialitzaTauler();
void mostrar();
void introPosicio();
void comprovaGuanyador();
void moureFitxa();

int main(void){
    inicialitzaTauler();
    mostrar();
    tabler[1][1]=2;
    do{
        introPosicio();
        if(jugador==1){
            matriu[posx][posy]=2;
        }
        else{
            matriu[posx][posy]=1;
        }
        mostrar();
        comprovaGuanyador();
    }
    while(tirades<6||guanyador==0);
    while(guanyador==0){
        introPosicio();
        moureFitxa();
        comprovaGuanyador();
    }
    if(jugador==1){
        printf("Ha guanyat el Jugador 1");
    }
    else{
        printf("Ha guanyat el Jugador 2");
    }
    return 0;
}
