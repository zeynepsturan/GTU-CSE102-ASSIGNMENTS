  /*
    program that asks user to number of hospitals 
    can be built and finds if all the cities get one
    written by: zeynepsturan
  */

#include <stdio.h>
#include <string.h>

typedef struct{
    char *name;
    char citiesServed[3]; /*Each hospital can serve to 3 cities at most*/
}Hospital;

/*finds all combinations in wihch all cities are covered(recursive)*/
void find_comb(Hospital *hospital, Hospital *comb, Hospital *hosp,int index, 
int start, int hospital_count, int total_count, char cities[])
;

/*checks if the combination found covers all cities*/
int check_comb(Hospital combination[],int hospital_count,char cities[]);

int main(){
    /*hospitals are stored in an array*/
    int i, hospital_count;
    Hospital hospital[]={ "hospital_1", "abc", "hospital_2", "acd", 
    "hospital_3", "bf", "hospital_4", "cef",
    };

    /*cities are stored in an array*/
    char cities[]={'a', 'b', 'c', 'd', 'e', 'f'};

    printf("Enter the maximum number of hospitals that can be constructed:");
    scanf(" %d",&hospital_count);

    /*Arrays for combination and the result*/
    Hospital comb[10];
    Hospital hosp[10];
    hosp->name=NULL; /*prevents from memory problems*/

    /*Finds all combinations then stores the first valid one in hosp*/
    find_comb(hospital, comb, hosp, 0, 0, hospital_count, 4, cities);

    if (hosp->name == NULL){
        printf("No, some cities are not covered.\n");
    }

    else{
        printf("Yes, can offer health care to all.\n\n");

        for (i=0; i<hospital_count; i++){
            printf("Hospitals - %d\n", i + 1);
            printf("Hospitals locations:%.3s\n", hosp[i].citiesServed);
        }
    }

    return 0;
}

void find_comb(Hospital *hospital, Hospital *comb, Hospital *hosp, int start,
               int index, int hospital_count, int total_count, char cities[]){
    int i=0;

    /*Base case: reached desired combination length*/
    if(index==hospital_count){
        /*if the combination covers all cities*/
        if(check_comb(comb, hospital_count, cities)){
            
            for (i=0; i<hospital_count; i++){
                hosp[i]=comb[i];
            }
        }

        return;
    }

    /*for hospitals remained*/
    for (i=start; i<=(total_count-hospital_count+index); i++){
        comb[index]=hospital[i];

        /*finding combinations with remaining hospitals (recursive)*/
        find_comb(hospital, comb, hosp, i + 1, index + 1, hospital_count, total_count, cities);
    }
}

int check_comb(Hospital combination[],int hospital_count,char cities[]){
    int i, j, k=0, cont=0;
    char hospitals_served[20]=""; /*stores all the cities served*/

    for (i=0; i<hospital_count; i++){

       for (j=0; j<hospital_count && combination[i].citiesServed[j]!='\0'; j++){
        hospitals_served[k]=combination[i].citiesServed[j];
        k++;
       }
    }

    i=0;

    /*each city in the original list*/
    while (cities[i]!='\0'){
        j=0;

        /*all served cities in combination*/
        while(hospitals_served[j]!='\0'){
            /*City found in served cities*/
            if (cities[i]==hospitals_served[j]){
                cont++;
                break;
            }
            j++;
        }
        i++;
    }

    /*return true if all cities are covered*/
    return cont==strlen(cities);
}
