  /*
    program that shuffles game cards 
    and prints the deck
    written by: zeynepsturan
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    const char *face; 
    const char *suit; 
}card;

void shuffle_deck(int order[]);
void print_deck(int order[], card deck[]);

int main(){

    srand(time(NULL));
    int i, j=0, k=0;
    int order[52]; /*the array where the shuffled order is kept*/

    char faces[13][6]={"Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    char suits[4][9]={"Hearts", "Diamonds", "Clubs", "Spades"};

    card deck[52];

    for(i=0;i<4;i++){ /*for every suit*/

        for(k=0;k<13;k++){ /*fills the next 13 card's suits same*/
            deck[j+k].suit=suits[i];
        }

        for(k=0;k<13;k++){ /*fills the next 13 card's faces*/
            deck[j+k].face=faces[k];
        }
        j+=13;
    }

    shuffle_deck(order);
    print_deck(order,deck);

    return 0;
}

void shuffle_deck(int order[]){

    int i,j, max, max_index;
    int random[52]; /*the array that is going to be assigned to random numbers*/

    for(i=0;i<52;i++){ /*assigning random numbers*/
        random[i]=rand()%1000;
        order[i]=-1;
    }

    for(i=0;i<52;i++){ /*selection sort*/

        max=0;
        for(j=0;j<52;j++){
            if(random[j]>max){
                max=random[j];
                max_index=j;
            }
        }
        order[i]=max_index;
        random[max_index]=-1;
    }

}

void print_deck(int order[], card deck[]){
    int i;

    for(i=0;i<52;i+=2){
        printf("%6s of %-6s\t",deck[(order[i])].face, deck[(order[i])].suit);
        printf("%6s of %-6s\n",deck[(order[i+1])].face, deck[(order[i+1])].suit);
    }
}
