#include<stdio.h>
void coordenades();
void inicialitzaTauler();
void mostraTauler();
void introduirPosicio();
void colocarFitxes();
void comprovarGuanyador();
void canviJugador();
void moureFitxes();

int tauler[3][3],casella,x,y,jugador=2,guanyador=0,tirades=1;

int main (void){

    inicialitzaTauler();
    tauler[1][1]=1;
    mostraTauler();

    printf("\tComenca el jugador 1 a la casella central\n\n");
    do{
        introduirPosicio();
        colocarFitxes();
        mostraTauler();
        comprovarGuanyador();
        canviJugador();
    }while(tirades<6&&guanyador==0);

    while(guanyador==0){
        moureFitxes();
        colocarFitxes();
        comprovarGuanyador();
        canviJugador();
    }
    if(jugador==1){
        printf("\tJugador 1, HAS GUANYAT!!!\n\n");
    }
    else{
        printf("\tJugador 2, HAS GUANYAT!!!\n\n");
    }
    return 0;
}

