#include <stdio.h>
#include <locale.h>
#include <string.h>

#define NUMBER_OF_PEOPLE 23
#define NUMBER_OF_FEATURES 5
char list[NUMBER_OF_PEOPLE][NUMBER_OF_FEATURES][25];

/*function declarations*/

void
    menu(),
    sort_people_by_age(),
    sort_people_by_branch(),
    filter_people_by_branch(),
    filter_people_by_proffession(),
    print_list(int sorted_array[])
;

int main(){

    setlocale(LC_ALL,"tr_TR.UTF-8"); /*for turkish characters*/

    menu(); /*everything is done in menu() function*/

    return 0;
}

void print_list(int sorted_array[]){

    int i, j;

    printf("\n\n");
    printf("Name \t\t\t        Surname\t\t\t        Age\t\t\t        Branch 1\t       Branch 2\n");

    for(i=0; sorted_array[i]!=-1; i++){

        for(j=0; j<NUMBER_OF_FEATURES; j++){

            printf("%-20s\t\t", list[sorted_array[i]][j]); /*prints each person's features*/

        }
        printf("\n");
    }
    printf("\n\n");

}

void sort_people_by_branch(){

    int sorted_list_indexes[NUMBER_OF_PEOPLE+1]; /*we store the indexes of the list in a sorted way*/
    int i, j, temp;

    /*initializing the array*/

    for(i=0;i<NUMBER_OF_PEOPLE;i++){

        sorted_list_indexes[i]=i;

    }

    sorted_list_indexes[NUMBER_OF_PEOPLE]=-1;



    /*bubble sort*/

    for(i=0;i<NUMBER_OF_PEOPLE;i++){

        for(j=0;j< NUMBER_OF_PEOPLE-1-i;j++){

            /*compares branch 1's*/

            if(strcmp(list[sorted_list_indexes[j]][3], list[sorted_list_indexes[j+1]][3])>0){

                temp=sorted_list_indexes[j];

                sorted_list_indexes[j]=sorted_list_indexes[j+1];

                sorted_list_indexes[j+1]=temp;

            }

            /*if branch 1's are the same*/

            else if(strcmp(list[sorted_list_indexes[j]][3], list[sorted_list_indexes[j+1]][3])==0){

                /*if one doesn't have branch 2 it gets lower*/

                if(list[sorted_list_indexes[j]][4][0]=='\0'&& list[sorted_list_indexes[j+1]][4][0]!='\0'){

                    temp=sorted_list_indexes[j];

                    sorted_list_indexes[j]=sorted_list_indexes[j+1];

                    sorted_list_indexes[j+1]=temp;

                }

                /*compares branch 2's*/

                else if(strcmp(list[sorted_list_indexes[j]][4], list[sorted_list_indexes[j+1]][4])>0 ){

                    temp=sorted_list_indexes[j];

                    sorted_list_indexes[j]=sorted_list_indexes[j+1];

                    sorted_list_indexes[j+1]=temp;

                }

                /*if branch 2's are the same*/

                else if(strcmp(list[sorted_list_indexes[j]][4], list[sorted_list_indexes[j+1]][4])==0){

                    /*compares ages*/

                    if(strcmp(list[sorted_list_indexes[j]][2], list[sorted_list_indexes[j+1]][2])>0){

                        temp=sorted_list_indexes[j];

                        sorted_list_indexes[j]=sorted_list_indexes[j+1];

                        sorted_list_indexes[j+1]=temp;
                    }
                }
            }
        }
    }

    print_list(sorted_list_indexes);
}

void filter_people_by_proffession(){

    int i, k;

    int filtered_people_array[NUMBER_OF_PEOPLE]; /*stores the indexes of people needed*/

    k=0;

    /*stores the indexes of computer scientists who are not mathmaticians*/

    for(i=0;i<NUMBER_OF_PEOPLE;i++){ 

        if((strstr(list[i][3], "COMPUTER SCIENCE") != NULL || strstr(list[i][4], "COMPUTER SCIENCE") != NULL)

        && (strstr(list[i][3], "MATHEMATICS") == NULL && strstr(list[i][4], "MATHEMATICS") == NULL)){

            filtered_people_array[k]=i;

            k++;

        }

    }

    filtered_people_array[k]=-1; /*indicates the end of the array*/

    print_list(filtered_people_array);
}



void filter_people_by_branch(){

    int i, k;

    int filtered_people_array[NUMBER_OF_PEOPLE]; /*stores the indexes of people needed*/

    k=0;

    /*stores the indexes of people whose branches contains science*/

    for(i=0;i<NUMBER_OF_PEOPLE;i++){

        if(strstr(list[i][3], "SCIENCE") != NULL || strstr(list[i][4], "SCIENCE") != NULL){

            filtered_people_array[k]=i;

            k++;

        }

    }

    filtered_people_array[k]=-1; /*indicates the end of the array*/

    print_list(filtered_people_array);

}



void sort_people_by_age(){

    int sorted_list_indexes[NUMBER_OF_PEOPLE+1];

    int i, j, temp;

    /*initializing the array*/

    for(i=0;i<NUMBER_OF_PEOPLE;i++){

        sorted_list_indexes[i]=i;

    }

    sorted_list_indexes[NUMBER_OF_PEOPLE]=-1;

    /*bubble sort*/

    for(i=0;i<NUMBER_OF_PEOPLE-1;i++){

        for(j=0;j< NUMBER_OF_PEOPLE-1-i;j++){

            /*compares ages*/

            if(strcmp(list[sorted_list_indexes[j]][2], list[sorted_list_indexes[j+1]][2])>0){

                temp=sorted_list_indexes[j];

                sorted_list_indexes[j]=sorted_list_indexes[j+1];

                sorted_list_indexes[j+1]=temp;
            }
        }
    }

    print_list(sorted_list_indexes);
}

void menu(){

    /*variable declarations*/
    char option, c;
    int i, j, k, flag=0;
    FILE *ptr;

    /*storing data in the array*/
    ptr=fopen("input1.txt","r");

    for(i=0; i<NUMBER_OF_PEOPLE; i++){ /*i works for every individual*/

        for(j=0; j<NUMBER_OF_FEATURES-1; j++){ /*j works for their features*/

            for(k=0; fscanf(ptr,"%c",&c)==1 && c!=',' && c!='\n' && c!=EOF;){ /*k works for indexes*/

                if(c==' '){

                    if(j==3 || j==4){

                        if(flag==0){

                            flag=1;

                        }

                        else if(flag==1){

                            list[i][j][k]=c;

                            k++;
                        }
                    }
                }

                else{

                    list[i][j][k]=c;

                    k++;

                }

            }

            flag=0;

            list[i][j][k]='\0';

        }

        if(c=='\n' || c==EOF){

            list[i][NUMBER_OF_FEATURES-1][0]=' ';

            list[i][NUMBER_OF_FEATURES-1][1]='\0';

        }

        /*if they have branch 2*/

        else{

            for(k=0; fscanf(ptr,"%c",&c)==1 && c!=',' && c!='\n' && c!=EOF;){ /*k works for indexes*/

                if(c==' '){

                    if(j==3 || j==4){

                        if(flag==0){

                            flag=1;

                        }

                        else if(flag==1){

                            list[i][j][k]=c;

                            k++;

                        }

                    }

                }

                else{

                    list[i][NUMBER_OF_FEATURES-1][k]=c;

                    k++;

                }

            }

            list[i][j][k]='\0';

            flag=0;

        }

    }

    fclose(ptr);

    do{

        printf("********Menu********\n");

        printf("1. Sort and display all individuals by age\n");

        printf("2. Sort and display individuals in the branch by age\n");

        printf("3 Show individuals with the branch 'SCIENCE'\n");

        printf("4. Show computer scientists who are not mathmaticians\n");

        printf("5. Exit\n");

        printf("Your choice: ");

        scanf("%c",&option);

        while((c=getchar())!='\n'){}

        switch(option){

            case '1':
            sort_people_by_age();
            break;

            case '2':
            sort_people_by_branch();
            break;

            case '3':
            filter_people_by_branch();
            break;

            case '4':
            filter_people_by_proffession();
            break;

            case '5':
            break;

            default:
            printf("There is no such an option\n");
            break;
        }

    }while(option!='5');
}
