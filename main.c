#include<stdio.h>

void inicialitzaTauler();
void mostraTauler();
void introPosicio();
void comprovaGuanyador();
void moureFitxa();

int tauler[3][3],tirades=1,guanyador=0;

int main(void){
    int jugador=2
    inicialitzaTauler();
    mostraTauler();
    tabler[1][1]=2;
    do{
        introPosicio1();
        if(jugador==1){
            matriu[posx][posy]=2;
        }
        else{
            matriu[posx][posy]=1;
        }
        tirades++;
        mostraTauler();
        comprovaGuanyador();
    }
    while(tirades<6||guanyador==0);
    while(guanyador==0){
        introPosicio2();
        moureFitxa();
        mostraTauler();
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
