
/*
  simple program to calculate the number of
  permutations for the shortest path recursively
  written by: zeynepsturan
*/

#include <stdio.h>
#define NUM_OF_STREETS 5
#define NUM_OF_AVENUES 5

int numPathsHome(int street, int avenue);

int main(){
    int street, avenue,total_paths;

    printf("Enter the street number: ");
    scanf("%d",&street);

    while(street<1 || street>NUM_OF_STREETS){ /*check for invalid input*/
        printf("The street number is unvalid. It should be between 1-%d.\n",NUM_OF_STREETS);
        scanf("%d",&street);
    }

    printf("Enter the avenue number: ");
    scanf("%d",&avenue);
    
    while(avenue<1 || avenue>NUM_OF_AVENUES){ /*check for invalid input*/
        printf("The avenue number is unvalid. It should be between 1-%d.\n",NUM_OF_AVENUES);
        scanf("%d",&avenue);
    }

    if(street==1 && avenue==1){
        printf("Scout is already at home.\n");
    }

    else{

        total_paths=numPathsHome(street-1,avenue)+numPathsHome(street,avenue-1);

        printf("Number of optimal paths to take back home: %d",total_paths);
    }
    
    return 0;
}

int numPathsHome(int street, int avenue){

    if(street==1 & avenue==1){ /*if (1,1) is reached*/
        return 1;
    }

    else if(street<1 || avenue<1){ /*in case of going out of the map*/
        return 0;
    }

    else{
        return numPathsHome(street-1, avenue) + numPathsHome(street, avenue-1);
    }
}
