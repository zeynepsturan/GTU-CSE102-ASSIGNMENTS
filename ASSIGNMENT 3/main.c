#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char board[256];
int player=119;
int move=0,ects=0;
int object1_1, object1_2, object1_3, object1_4, object2_1, object2_2, object2_3;

void initialize_game(), print_board(), move_player(char direction); 
int place_object1(int x), place_object2(int x);
void inner_walls(char x), outer_walls(char x); /*these functions are to include or exclude the walls*/

int main(){
    initialize_game();
    print_board(); 
    printf("Total moves: %d\n",move);
    return 0;
}

void inner_walls(char x){
    int i,a=0;

    for(i=0;i<5;i++){
        board[85+i]=x;
    }

    for(i=0;i<3;i++){
        board[101+a]=x;
        board[101+a+4]=x;
        a+=16;
    }
    
    for(i=0;i<5;i++){
        board[149+i]=x;
    }
}

void outer_walls(char x){
    int i,a;
    for(i=0;i<9;i++){
        board[51+i]=x;
    }
    a=0;
    for(i=0;i<7;i++){
        board[67+a]=x;
        board[67+a+8]=x;
        a+=16;
    }
    for(i=0;i<9;i++){
        board[179+i]=x;
    }
}

void print_board(){
    int i;
    char direction;
    
    /*part 1*/
    while(ects<32){
        printf("Use W (Up), A (Left), S (Down), D (Right) to move\n");
        /*setting the board*/
        for(i=0;i<255;i++){
            board[i]='.';

            if((i==object1_1) || (i==object1_2) || (i==object1_3) || (i==object1_4)){
                board[i]='1';
            }

            else if((i==object2_1) || (i==object2_2) || (i==object2_3)){
                board[i]='2';
            }

            if(i==player){
                board[i]='P';
            }
        }

        board[255]='X';
        /*first walls*/
        inner_walls('#');

        /*second walls*/
        outer_walls('#');
        /*setting the board done*/

        /*printing the board*/
        for(i=0;i<256;i++){
            if(i==player){
                    
            }
            printf("%c ",board[i]);

                if(i%16==15){
                    printf("\n");
                }
        }
        /*printing the board done*/

        printf("Total ECTS: %d\n",ects);
        printf("Enter your move: ");
        scanf(" %c",&direction);
        printf("\n");
        move_player(direction);

        if(player==object1_1){
            ects+=8;
            object1_1=-1;
        }

        else if(player==object1_2){
            ects+=8;
            object1_2=-1;
        }

        else if(player==object1_3){
            ects+=8;
            object1_3=-1;
        }

        else if(player==object1_4){
            ects+=8;
            object1_4=-1;
        }
    }

    /*part 2*/
    while(ects<56){
        printf("Use W (Up), A (Left), S (Down), D (Right) to move\n");
        /*setting the board*/
        for(i=0;i<255;i++){
            board[i]='.';

            if((i==object2_1) || (i==object2_2) || (i==object2_3)){
                board[i]='2';
            }

            if(i==player){
                board[i]='P';
            }
        }

        /*first walls*/
        inner_walls('#');

        /*second walls*/
        outer_walls('#');
        board[player]='P';
        /*setting the board done*/

        /*printing the board*/
        for(i=0;i<256;i++){
            printf("%c ",board[i]);

                if(i%16==15){
                    printf("\n");
                }
        }
        /*printing the board done*/

        /*removing inner walls*/
        inner_walls('.');

        printf("Total ECTS: %d\n",ects);
        printf("Enter your move: ");
        scanf(" %c",&direction);
        printf("\n");
        move_player(direction);
        board[player]='P';

        if(player==object2_1){
            ects+=8;
            object2_1=-1;
        }

        else if(player==object2_2){
            ects+=8;
            object2_2=-1;
        }

        else if(player==object2_3){
            ects+=8;
            object2_3=-1;
        }
    }
    /*part 3*/
    while(player!=255){
        printf("Use W (Up), A (Left), S (Down), D (Right) to move\n");

        /*setting the board*/
        for(i=0;i<255;i++){
            board[i]='.';
            if(i==player){
                board[i]='P';
            }
        }

        /*first walls*/
        inner_walls('#');

        /*second walls*/
        outer_walls('#');
        board[player]='P';
        /*setting the board done*/

        /*printing the board*/
        for(i=0;i<256;i++){
            printf("%c ",board[i]);

                if(i%16==15){
                    printf("\n");
                }
        }
        /*printing the board done*/

        /*removing inner walls*/
        inner_walls('.');

        /*removing outer walls*/
        outer_walls('.');

        printf("Total ECTS: %d\n",ects);
        printf("Enter your move: ");
        scanf(" %c",&direction);
        printf("\n");
        board[player]='.';
        move_player(direction);
        board[player]='P';
    }
    /*end*/
    /*inner walls*/
    inner_walls('#');

    /*second walls*/
    outer_walls('#');

    for(i=0;i<256;i++){
    printf("%c ",board[i]);

        if(i%16==15){
            printf("\n");
        }
    }
    printf("CONGRATS, YOU WON!\n");
    printf("Total ECTS: %d\n",ects);
}


void move_player(char direction){
    switch(direction){
        case 'w':
        case 'W':
        if(player-16>=0){
            if(board[player-16]=='#'){
                printf("YOU CANNOT PASS THROUGH THE WALLS\n");
            }
            else{
                player-=16;
                move++;
            }
        }
        break;

        case 'a':
        case 'A':
        if((player)%16!=0){
            if(board[player-1]=='#'){
                printf("YOU CANNOT PASS THROUGH THE WALLS\n");
            }

            else{
                player-=1;
                move++;
            }
        }
        break;

        case 's':
        case 'S':
        if(player+16<=255){
            if(board[player+16]=='#'){
                printf("YOU CANNOT PASS THROUGH THE WALLS\n");
            }
            else{
                player+=16;
                move++;
            }
        }
        break;

        case 'd':
        case 'D':
        if((player)%16!=15){
            if(board[player+1]=='#'){
                printf("YOU CANNOT PASS THROUGH THE WALLS\n");
            }
            else{
                player+=1;
                move++;
            }
        }
        break;
    }
}

int place_object1(int x){
    int object1[8]={102,103,104,118,120,134,135,136};
    x=object1[x];
    return x;
}

int place_object2(int x){
    int object2[24]={68,69,70,71,72,73,74,84,100,116,132,148,164,90,106,122,138,154,165,166,167,168,169,170};
    x=object2[x];
    return x;
}

void initialize_game(){
    srand(time(NULL));
    /*first objects*/
    object1_1=rand()%8;
    do{
        object1_2=rand()%8;
    }while(object1_2==object1_1);

    do{
        object1_3=rand()%8;
    }while(object1_3==object1_1 || object1_3==object1_2);

    do{
        object1_4=rand()%8;
    }while(object1_4==object1_1 || object1_4==object1_2 || object1_4==object1_3);

    /*second objects*/
    object2_1=rand()%24;
    do{
        object2_2=rand()%24;
    }while(object2_2==object2_1);

    do{
        object2_3=rand()%24;
    }while(object2_3==object2_1 || object2_3==object2_2);

    object1_1=place_object1(object1_1);
    object1_2=place_object1(object1_2);
    object1_3=place_object1(object1_3);
    object1_4=place_object1(object1_4);

    object2_1=place_object2(object2_1);
    object2_2=place_object2(object2_2);
    object2_3=place_object2(object2_3);
}
