/*******************************************************
 * Funncions sense probar                              *
 *******************************************************/

/* Inicialització del tauler de joc (a 0)*/
void inicialitzaTauler(){
    int i,j,cont=1;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            tauler[i][j]=0;
        }
    }
}

/* Presentació en pantalla del tauler de joc */
void mostraTauler(){
    system("cls");/* system("clear");//per a Linux */
    int i,j,cont=1;

    printf("\tTRES EN RATLLA\n");
    printf("\t--------------\n\n");
    printf("\t+-----+-----+-----+\n");
    for(i=0;i<3;i++){
        printf("\t|     |     |     |\n\t|");
        for(j=0;j<3;j++){
            if(tauler[i][j]==0){   /* si troba un '0'...    */
                printf("     |");  /* ... presenta un espai */
            }
            if(tauler[i][j]==1){   /* si troba un '1'...    */
                printf("  0  |");  /*   ... presenta un '0' */
            }
            if(tauler[i][j]==2){   /* si troba un '2'...    */
                printf("  X  |");  /*  ... presenta una 'X' */
            }
        }
        printf("\n\t|");
        for(j=0;j<3;j++){
                printf("    %d|", cont); /* indica el número de casella */
                cont++;
        }
        printf("\n\t+-----+-----+-----+\n\n");
    }
}
/* Comprova si algu ha ficat tres fitxes a la mateixa linia */
void comprovaGuanyador(){
/* bandes +---+---+---+ i +---+---+---+ per 'X' o '0'
          |   |   | X |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   |   | X |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   |   | X |   | X | X | X |
          +---+---+---+   +---+---+---+ */

    if(tauler[2][2]==88||tauler[2][2]==48){
        if((tauler[2][2]==tauler[1][2]&&tauler[2][2]==tauler[0][2])||(tauler[2][2]==tauler[2][1]&&tauler[2][2]==tauler[2][0])){
        guanyador=1;
        }
    }
/* bandes +---+---+---+ i +---+---+---+ per 'X' o '0'
          | X | X | X |   | X |   |   |
          +---+---+---+   +---+---+---+
          |   |   |   |   | X |   |   |
          +---+---+---+   +---+---+---+
          |   |   |   |   | X |   |   |
          +---+---+---+   +---+---+---+ */

    if(tauler[0][0]==88||tauler[0][0]==48){
        if((tauler[0][0]==tauler[0][1]&&tauler[0][0]==tauler[0][2])||(tauler[0][0]==tauler[1][0]&&tauler[0][0]==tauler[2][0])){
            guanyador=1;
        }
    }
/* bandes +---+---+---+ i +---+---+---+ sols per 'X'
          |   | X |   |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   | X |   |   | X | X | X |
          +---+---+---+   +---+---+---+
          |   | X |   |   |   |   |   |
          +---+---+---+   +---+---+---+ */

    if(tauler[1][1]==88){
        if((tauler[1][1]==tauler[0][1]&&tauler[1][1]==tauler[2][1])||(tauler[1][1]==tauler[1][0]&&tauler[1][1]==tauler[1][2])){
            guanyador=1;
        }
/* diagonals +---+---+---+ i +---+---+---+  sols per 'X'
             | X |   |   |   |   |   | X |
             +---+---+---+   +---+---+---+
             |   | X |   |   |   | X |   |
             +---+---+---+   +---+---+---+
             |   |   | X |   | X |   |   |
             +---+---+---+   +---+---+---+ */

        if((tauler[1][1]==tauler[0][0]&&tauler[1][1]==tauler[2][2])||(tauler[1][1]==tauler[2][0]&&tauler[1][1]==tauler[0][2])){
            guanyador=1;
        }
    }
}
/* Mou les fitxes per els 4 eixos OJO!!! faltan limits!!!! */
void moureFitxa(int jugador,int fitxa){
    if(tauler[x][y]==2&&jugador==1)&&(x!=1&&y!=1){
        if(tauler[x-1][y]==0){    /* moure fitxa abaix    */
            tauler[x-1][y]=fitxa;
            tauler[x][y]=0;
        }
        if(tauler[x+1][y]==0){    /* moure fitxa adalt    */
            tauler[x+1][y]=fitxa;
            tauler[x][y]=0;
        }
        if(tauler[x][y+1]==0){    /* moure fitxa dreta    */
            tauler[x][y+1]=fitxa;
            tauler[x][y]=0;
        }
        if(tauler[x][y-1]==0){    /* moure fitxa esquerra */
            tauler[x][y-1]=fitxa;
            tauler[x][y]=0;
        }
    }
    system("clear");

}
/* Posicio d'introducció de les fitxes */
void introPosicio1(){
    int casella;
    do{
        printf("\n\tJugador %d, introdueix un num. de casella:\n\t",jugador);
        scanf("%d",&casella);
    }
    while(casella<1&&casella>9);
    switch (casella){
    case 1: if (jugador==1){tauler[0][0]=2;}
            else{tauler[0][0]=1;} break;
    case 2: if (jugador==1){tauler[0][1]=2;}
            else{tauler[0][1]=1;} break;
    case 3: if (jugador==1){tauler[0][2]=2;}
            else{tauler[0][2]=1;} break;
    case 4: if (jugador==1){tauler[1][0]=2;}
            else{tauler[1][0]=1;} break;
    case 5: if (jugador==1){tauler[1][1]=2;}
            else{tauler[1][1]=1;} break;
    case 6: if (jugador==1){tauler[1][2]=2;}
            else{tauler[1][2]=1;} break;
    case 7: if (jugador==1){tauler[2][0]=2;}
            else{tauler[2][0]=1;} break;
    case 8: if (jugador==1){tauler[2][1]=2;}
            else{tauler[2][1]=1;} break;
    case 9: if (jugador==1){tauler[2][2]=2;}
            else{tauler[2][2]=1;} break;
        }
}

void introPosicio2){ /*UFFF.... s'ha d'arreglar.... hem de definir punt de sortida,
    desde la casella que correspongui (control errors) fins a la casella desti, per tant,
    NO CALDRE LA FUNCIO MOURE!!!!!*/
    int casellaPartida,casellaArribada;
    do{
        printf("\n\tJugador %d, introdueix un num. de casella de partida:\n\t",jugador);
        scanf("%d",&casellaPartida);
    }
    while(casellaPartida<1&&casellaPartida>9);
    printf("\n\tJugador %d, introdueix un num. de casella d'arribada:\n\t",jugador);
    scanf("%d",&casellaArribada);
    switch (casella){
    case 1: x=0;y=0; break;
    case 2: x=0;y=1; break;
    case 3: x=0;y=2; break;
    case 4: x=1;y=0; break;
    case 5: x=1;y=1; break;
    case 6: x=1;y=2; break;
    case 7: x=2;y=0; break;
    case 8: x=2;y=1; break;
    case 9: x=2;y=1; break;
    }
}
