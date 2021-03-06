/********************************
 *        TRES EN RATLLA        *
 *                              *
 *     (anem malament.....)     *
 ********************************/

#include <stdio.h>

void inicialitza();
void mostratabler();
void guanya();

char matriu[3][3];
int jugador=1,final=0;

int main(void){
    int casella;
    int opcio=0;

    inicialitza();
    mostratabler();
    printf("\n\tIntrodueix '5' per sortir '9' nper continuar\n\t");
    scanf("%d",&opcio);
    getchar();
    while(opcio!=5){
        do{
            printf("\n\tJugador %d, introdueix un num. de casella:\n\t",jugador);
            scanf("%d",&casella);
        }
        while(casella<1&&casella>9);
        switch (casella){
            case 1:
                if (jugador==1){
                    matriu[0][0]=88;
                }
                else{
                    matriu[0][0]=48;
                }
            break;
            case 2:
                if (jugador==1){
                    matriu[0][1]=88;
                }
                else{
                    matriu[0][1]=48;
                }
            break;
            case 3:
                if (jugador==1){
                    matriu[0][2]=88;
                }
                else{
                    matriu[0][2]=48;
                }
            break;
            case 4:
                if (jugador==1){
                    matriu[1][0]=88;
                }
                else{
                    matriu[1][0]=48;
                }
            break;
            case 5:
                if (jugador==1){
                    matriu[1][1]=88;
                }
                else{
                    matriu[1][1]=48;
                }
            break;
            case 6:
                if (jugador==1){
                    matriu[1][2]=88;
                }
                else{
                    matriu[1][2]=48;
                }
            break;
            case 7:
                if (jugador==1){
                    matriu[2][0]=88;
                }
                else{
                    matriu[2][0]=48;
                }
            break;
            case 8:
                if (jugador==1){
                    matriu[2][1]=88;
                }
                else{
                    matriu[2][1]=48;
                }
            break;
            case 9:
                if (jugador==1){
                    matriu[2][2]=88;
                }
                else{
                    matriu[2][2]=48;
                }
            break;
        }
        mostratabler();
        guanya();
        if (final!=0){
            return 0;
        }
    }
    return 0;
}
void inicialitza(){
    int i,j,cont=1;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matriu[i][j]=cont;
            cont++;
        }
    }
}
void mostratabler(){
    //system("clear");
    int i,j;
    printf("\tTRES EN RATLLA\n");
    printf("\t--------------\n\n");
    printf("\t+---+---+---+\n\t|");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if (matriu[i][j]>0&&matriu[i][j]<10){
                printf(" %d |", matriu[i][j]);
            }
            else{
                printf(" %c |", matriu[i][j]);
            }
        }
        if (i<2){
            printf("\n\t+---+---+---+\n\t|");
        }
        else{
            printf("\n\t+---+---+---+\n");
        }
    }
}

void guanya(){
/* bandes +---+---+---+ i +---+---+---+ per 'X' o '0'
          |   |   | X |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   |   | X |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   |   | X |   | X | X | X |
          +---+---+---+   +---+---+---+ */

    if(matriu[2][2]==88||matriu[2][2]==48){
        if((matriu[2][2]==matriu[1][2]&&matriu[2][2]==matriu[0][2])||(matriu[2][2]==matriu[2][1]&&matriu[2][2]==matriu[2][0])){
            if (jugador==1){
                printf("\tha guanyat el jugador 1\n");
                final=1;
            }
            else{
                printf("\tha guanyat el jugador 2\n");
                final=1;
            }
        }
    }
/* bandes +---+---+---+ i +---+---+---+ per 'X' o '0'
          | X | X | X |   | X |   |   |
          +---+---+---+   +---+---+---+
          |   |   |   |   | X |   |   |
          +---+---+---+   +---+---+---+
          |   |   |   |   | X |   |   |
          +---+---+---+   +---+---+---+ */

    if(matriu[0][0]==88||matriu[0][0]==48){
        if((matriu[0][0]==matriu[0][1]&&matriu[0][0]==matriu[0][2])||(matriu[0][0]==matriu[1][0]&&matriu[0][0]==matriu[2][0])){
            if (jugador==1){
                printf("\tha guanyat el jugador 1\n");
                final=1;
            }
            else{
                printf("\tha guanyat el jugador 2\n");
                final=1;
            }
        }
    }
/* bandes +---+---+---+ i +---+---+---+ sols per 'X'
          |   | X |   |   |   |   |   |
          +---+---+---+   +---+---+---+
          |   | X |   |   | X | X | X |
          +---+---+---+   +---+---+---+
          |   | X |   |   |   |   |   |
          +---+---+---+   +---+---+---+ */

    if(matriu[1][1]==88){
        if((matriu[1][1]==matriu[0][1]&&matriu[1][1]==matriu[2][1])||(matriu[1][1]==matriu[1][0]&&matriu[1][1]==matriu[1][2])){
            if (jugador==1){
                printf("\tha guanyat el jugador 1\n");
                final=1;
            }
            else{
                printf("\tha guanyat el jugador 2\n");
                final=1;
            }
        }
/* diagonals +---+---+---+ i +---+---+---+  sols per 'X'
             | X |   |   |   |   |   | X |
             +---+---+---+   +---+---+---+
             |   | X |   |   |   | X |   |
             +---+---+---+   +---+---+---+
             |   |   | X |   | X |   |   |
             +---+---+---+   +---+---+---+ */

        if((matriu[1][1]==matriu[0][0]&&matriu[1][1]==matriu[2][2])||(matriu[1][1]==matriu[2][0]&&matriu[1][1]==matriu[0][2])){
            if (jugador==1){
                printf("\tha guanyat el jugador 1\n");
                final=1;
            }
            else{
                printf("\tha guanyat el jugador 2\n");
                final=1;
            }
        }
    }
}

