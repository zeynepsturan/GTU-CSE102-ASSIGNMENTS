  /*
    simple mancala game aganinst
    computer AI (without the even rule)
    written by: zeynepsturan
  */

#include <stdio.h>
/*function declarations*/
void initialize_game(int board[][7],int n),
     print_board(int board[][7]),
     game_play(int board[][7]),
     delay();

int player_move(int board[][7]),
    computer_move(int board[][7]),
    check_end(int board[][7]);

int main(){
    /*declaring the game board and number of stones(n) in the cups*/
    int gameboard[2][7];
    const int n=4;
    /*game*/
    initialize_game(gameboard,n);
    print_board(gameboard);
    game_play(gameboard);
    return 0;
}

void delay(){
    int i,j;
    for(i=0;i<20000;i++){
        for(j=0;j<20000;j++){
        }
    }
}

int check_end(int board[][7]){
    /*it returns 1 when the game has ended, if not it returns 0*/
    int check=0;
    /*if player's or computer's all cups are empty, game is over*/
    /*checks computer's cups*/
    if(board[0][0]==0 && board[0][1]==0 && board[0][2]==0 &&
       board[0][3]==0 && board[0][4]==0 && board[0][5]==0){
       check=1;
    }
    /*checks player's cups*/
    else if(board[1][0]==0 && board[1][1]==0 && board[1][2]==0 &&
        board[1][3]==0 && board[1][4]==0 && board[1][5]==0){
        check=1;       
    }
    
    return check;
}

int computer_move(int board[][7]){
    /*variable declarations*/
    int movecup=-1,move_number,i,j;
    /*if flag is 1, player will make another move*/
    int flag=0;
    int cupside,cupnum; /*holds the cup where the last stone placed*/

    /*computer AI*/
    for(i=0;i<6;i++){
        /*to not place stones to player's cups*/
        if(board[0][i]<=6-i+1 &&board[0][i]>0){
            movecup=i;
        }
        
    }

    for(i=0;i<6;i++){
        /*to prevent if there is a chance for player to end in their large cup and get 
        another turn*/
        if(board[1][i]==6-i+1){
            int j;
            for(j=0;j<6;j++){
                if(board[0][j]>(6-j+i+1)){
                    movecup=j;
                }
            }
            
        }
    }

    /*to prevent computer's last cups to fill*/
    for(i=4;i<6;i++){ 
        if(board[0][i]==1 && board[0][i]==2){
            movecup=i;
        }
    }

    for(i=0;i<6;i++){
        /*to prevent the cups from getting too many stones*/
        if(board[0][i]>=5){
            movecup=i;
        }
        
    }

    for(i=0;i<6;i++){
        int found=0;
        /*if there is a chance to end in computer's large cup and get another turn*/
        if(board[0][i]==6-i+1){
            movecup=i;
            found=1;
            break;
        }

        if(found){
            break;
        }
    }

    /*making the move*/
    /*self created delay function to make the game more realistic*/
    printf("Computer is making a move..\n");
    delay();
    if(board[0][movecup]==1){
        move_number=board[0][movecup];
    }

    else{
        move_number=board[0][movecup]-1;
    }
    i=1;
    j=0;

    while(move_number>0){
        /*when the computer is placing stones to its own cups*/
        if(movecup+i<7){
            board[0][movecup+i]++;
            board[0][movecup]--;
            cupside=0;
            cupnum=movecup+i;
            i++;
            move_number--;
            j=0;
        }
        /*when the computer is placing stones to the player's cups*/
        else{
            /*if computer placed stones to the player's cups and turns to its own cups*/
            if(j>5){
                i=0;
                if(i<6){
                    board[0][movecup+i]++;
                    board[0][movecup]--;
                    cupside=0;
                    cupnum=movecup+i;
                    i++;
                    move_number--;
                    j=0;
                }
            }
            /*placing to player's cups*/
            else{
                board[1][j]++;
                board[0][movecup]--;
                cupside=1;
                cupnum=j;
                j++;
                move_number--;
            }
        }
    }
    /*if the last stone ended in computer's large cup,it gets another turn*/
    if(cupside==0 && cupnum==6){
        flag=1;
    }
    return flag;
}

int player_move(int board[][7]){
    /*variable declarations*/
    int movecup,move_number,i,j;
    /*if flag is 1, player will make another move*/
    int flag=0;
    int cupside,cupnum; /*holds the cup where the last stone placed*/
    /*getting the number of the cup wanted to be played*/
    printf("Enter your move(cups(1-6) are ordered left to right): ");
    scanf("%d",&movecup);
    movecup--;

    /*checks for if the cup exist and it is not empty*/
    while(movecup>5 || movecup<0 || board[1][movecup]==0){
        if(movecup>5 || movecup<0){
            printf("The cup numbers are 1-6. Make a valid move\n");
            printf("Your move: ");
            scanf("%d",&movecup);
        }

        else if(board[1][movecup]==0){
            printf("The cup is empty. Make a valid move\n");
            printf("Your move: ");
            scanf("%d",&movecup);
            movecup--;
        }
    }

    /*making the move*/
    if(board[1][movecup]==1){
        move_number=board[1][movecup];
    }

    else{
        move_number=board[1][movecup]-1;
    }
    i=1;
    j=0;

    while(move_number>0){
        /*when the player is placing stones to their own cups*/
        if(movecup+i<7){
            board[1][movecup+i]++;
            board[1][movecup]--;
            cupside=1;
            cupnum=movecup+i;
            i++;
            move_number--;
            j=0;
        }
        /*when the player is placing stones to the computer's cups*/
        else{
            /*if player placed stones to the computer's cups and turns to their own cups*/
            if(j>5){
                i=0;
                if(movecup+i<7){
                    board[1][movecup+i]++;
                    board[1][movecup]--;
                    cupside=1;
                    cupnum=movecup+i;
                    i++;
                    move_number--;
                    j=0;
                }
            }
            /*placing to computer's cups*/
            else{
                board[0][j]++;
                board[1][movecup]--;
                cupside=0;
                cupnum=j;
                j++;
                move_number--;
            }
            
        }   
    }
    /*if the last stone ended in player's large cup,they get another turn*/
    if(cupside==1 && cupnum==6){
        flag=1;
    }
    return flag;
}

void initialize_game(int board[][7],int n){
    int i,j;
    /*initializing small cups to n*/
    for(i=0;i<2;i++){
        for(j=0;j<6;j++){
            board[i][j]=n;
        }
    }
    /*initializing large cups to 0*/
    board[0][6]=board[1][6]=0;
}

void print_board(int board[][7]){
    int i;
    int k=5;
    printf("\n\t    Computer\n");
    /*first row*/
    printf("+----");
    for(i=0;i<6;i++){
        printf("+---");
    }
    printf("+----+\n");
    /*second row*/
    printf("|");
    for(i=0;i<4;i++){
        printf(" ");
    }

    for(i=0;i<25;i++){
        if(i%4==0){
            printf("|");
        }

        else if(i%4==2){
            printf("%2d",board[0][k]);
            k--;
        }

        else if(i%4!=1){
            printf(" ");
        }
    }

    for(i=0;i<4;i++){
        printf(" ");
    }
    printf("|\n");
    /*third row*/

    printf("|");
    for(i=0;i<4;i++){
        if(i!=0){
            if(i==1){
                printf("%2d",board[0][6]);
            }

            else{
                printf(" ");
            }
        }
    }
    printf("|");
    for(i=1;i<6;i++){
        printf("---+");
    }
    printf("---|");

    for(i=0;i<4;i++){

        if(i!=0){
            if(i==1){
                printf("%2d",board[1][6]);
            }

            else{
                printf(" ");
            }
        }
    }
    printf("|\n");

    /*forth row*/
    k=0;
    printf("|");
    for(i=0;i<4;i++){
        printf(" ");
    }

    for(i=0;i<25;i++){
        if(i%4==0){
            printf("|");
        }

        else if(i%4==2){
            printf("%2d",board[1][k]);
            k++;
        }

        else if(i%4!=1){
            printf(" ");
        }
    }

    for(i=0;i<4;i++){
        printf(" ");
    }
    printf("|\n");

    /*fifth row*/
    printf("+----");
    for(i=0;i<6;i++){
        printf("+---");
    }
    printf("+----+\n");
    printf("\t    Player\n\n");

}

void game_play(int board[][7]){
    int player_flag,computer_flag,check;
    while(1){
        do{
            player_flag=player_move(board);
            print_board(board);
            check=check_end(board);
        }while(player_flag==1 && check==0);

        if(check==1){
            break;
        }

        do{
            computer_flag=computer_move(board);
            print_board(board);
            check=check_end(board);
        }while(computer_flag==1 && check==0);

        if(check==1){
            break;
        }
    }

    if(board[0][6]>board[1][6]){
        printf("YOU LOST TO THE COMPUTER. MAYBE NEXT TIME\n");
    }

    else if(board[0][6]<board[1][6]){
        printf("CONGRATS!!YOU WON!\n");
    }

    else{
        printf("IT'S A DRAW. WHAT A CHANCE!\n");
    }
}
