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
void mostraTauler(){
    #if WIN32
        system("cls");   /* per a Windows */
    #elif LINUX
        system("clear"); /* per a Linux */
    #endif
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
                printf("  X  |");  /*   ... presenta una 'X' */
            }
            if(tauler[i][j]==2){   /* si troba un '2'...    */
                printf("  0  |");  /*  ... presenta un '0' */
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
void introduirPosicio(){
    do{
        printf("\tJugador %d, introdueix la posicio (1-9)\n\t",jugador);
        scanf("%d",&casella);
        coordenades();
    }while((casella<1&&casella>9)||(tauler[x][y]!=0));
    tirades++;
}
///////////////////////////////////////ATENCIOOOOOOO///////////////////////////////////////////////////////////
void moureFitxes(){ //s'han de corretgir els && i || dels while. Jo no crec que tingui temps de fer res mes....
    do{ 
        printf("\tJugador %d, introdueix la casella a moure:\n\t",jugador);
        scanf("%d",&casella);
        coordenades();
    }while((tauler[x][y]==1&&jugador==1)&&(tauler[x][y]==2&&jugador==2)&&(tauler[x][y]==0)&&(casella<10&&casella>0&&casella!=5));
    tauler[x][y]=0;
    do{
        printf("\tIntrodueix la casella de desti:\n\t");
        scanf("%d",&casella);
        coordenades();
    }while(tauler[x][y]!=0);
    if(jugador==1){
        tauler[x][y]=1;
    }
    else{
        tauler[x][y]=2;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

/* Comprova si algu ha ficat tres fitxes a la mateixa linia */
void comprovarGuanyador(){
/* bandes +---+---+---+ i +---+---+---+ per 'X' o '0'
          |   |   | X |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   |   | X |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   |   | X |   | X | X | X |
          +---+---+---+   +---+---+---+ */

    if(tauler[2][2]==1||tauler[2][2]==2){
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

    if(tauler[0][0]==1||tauler[0][0]==2){
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

    if(tauler[1][1]==1){
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
