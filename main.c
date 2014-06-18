#include<stdio.h>
void coordenades();
void inicialitzaTauler();
void mostraTauler();
void introduirPosicio();
void colocarFitxes();
void comprovarGuanyador();
void canviJugador();
void moureFitxes();

int tauler[3][3],casella,x,y,jugador;

int main (void){
    int tirades=1,guanyador=0;

    jugador=2;

    inicialitzaTauler();
    mostraTauler();
    tauler[1][1]=1;
    printf("\tComença el jugador 1 a la casella central\n");
    do{
        introduirPosicio();
        colocarFitxes();
        mostraTauler();
        //comprovarGuanyador();
        canviJugador();
        tirades++;
    }while(tirades<9||guanyador==0);

    while(guanyador==0){
        moureFitxes();
        colocarFitxes();
        //comprovarGuanyador();
        canviJugador();
    }
    if(jugador==1){
        printf("Jugador 1, HAS GUANYAT!!!");
    }
    else{
        printf("Jugador 2, HAS GUANYAT!!!");
    }
    return 0;
}
void coordenades(){
    switch(casella){
        case 1:x=0;y=0;break;
        case 2:x=0;y=1;break;
        case 3:x=0;y=2;break;
        case 4:x=1;y=0;break;
        case 5:x=1;y=1;break;
        case 6:x=1;y=2;break;
        case 7:x=2;y=0;break;
        case 8:x=2;y=1;break;
        case 9:x=2;y=2;break;
    }
}
void inicialitzaTauler(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            tauler[i][j]=0;
        }
    }
}
void introduirPosicio(){
    do{
        printf("\tJugador %d, introdueix la posició (1-9)\n");
        scanf("%d",&casella);
        coordenades();
    }while((casella<1||casella>9)||(tauler[x][y]!=0));
}

void moureFitxes(){
    do{
        printf("\tJugador %d, introdueix la casella a moure:\n",jugador);
        scanf("%d",&casella);
        coordenades();
    }while((tauler[x][y]==1&&jugador==1)||(tauler[x][y]==2&&jugador==2)||(tauler[x][y]==0));

}
void canviJugador(){
    if(jugador==1){
        jugador=2;
    }
    else{
        jugador=1;
    }
}

void colocarFitxes(){
    if(jugador==1){
        tauler[x][y]=1;
    }
    else{
        tauler[x][y]=2;
    }
}
