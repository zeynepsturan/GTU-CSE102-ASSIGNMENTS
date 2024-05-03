#include<stdio.h>
#include<string.h>
#define MAX_COLUMN 100
#define MAX_ROW 100

/*function declarations*/
void 
    search_p1(char strs[][MAX_COLUMN],int rows,int matches[][2],int *num_matches),
    search_p2(char strs[][MAX_COLUMN],int rows,int matches[][2],int *num_matches),
    search_p3(char strs[][MAX_COLUMN],int rows,int matches[][2],int *num_matches)
;

int main() {
    /*variable declarations*/
    char strs[MAX_ROW][MAX_COLUMN];
    int num_rows=0;
    int matches[MAX_ROW*MAX_COLUMN][2];
    int match_count=0;
    int i;

    FILE *ptr=fopen("input2.txt","r");
    /*Storing the text in the array*/
    while (fscanf(ptr,"%s",strs[num_rows])==1){
        num_rows++;
    }
    fclose(ptr);

    /*searching patterns and printing results*/
    /*pattern 1*/
    search_p1(strs,num_rows,matches,&match_count);
    for(i=0;i<match_count;i++){
        printf("P1 @ (%d,%d)\n",matches[i][0],matches[i][1]);
    }
    match_count=0;

    /*pattern 2*/
    search_p2(strs,num_rows,matches,&match_count);
    for(i=0;i<match_count; i++){
        printf("P2 @ (%d,%d)\n",matches[i][0],matches[i][1]);
    }
    match_count=0;

    /*pattern 3*/
    search_p3(strs,num_rows,matches,&match_count);
    for(i=0;i<match_count;i++){
        printf("P3 @ (%d,%d)\n",matches[i][0],matches[i][1]);
    }
    return 0;
}

/*pattern 1 function (horizontal search)*/
void search_p1(char strs[][MAX_COLUMN],int rows,int matches[][2],int *num_matches){
  
    /*variable declarations*/
    char pattern[]="***++++***++++***"; /*pattern being looked for*/
    int flag,i,j,k;
    int pattern_length=strlen(pattern); /*length of the pattern*/
    int strs_lenght=strlen(strs[0]); /*length of the array searched in*/

    for(i=0;i<rows;i++){
        for(j=0;j<=strs_lenght-pattern_length;j++){
            flag=1; /*flag default value*/
            for(k=0;k<pattern_length;k++){
                if(strs[i][j+k]!=pattern[k]){
                    flag=0;
                    break;
                }
            }

            if(flag){ /*if there is a match*/
                /*storing coordinates*/
                matches[*num_matches][0]=i+1;
                matches[*num_matches][1]=j+1;
                (*num_matches)++;
            }
        }
    }
}

/*pattern 2 function (vertical search)*/
void search_p2(char strs[][MAX_COLUMN],int rows,int matches[][2],int *num_matches){
  
    /*variable declarations*/
    char pattern[]="+*+*+"; /*pattern being looked for*/
    int flag,i,j,k;
    int pattern_length=strlen(pattern); /*length of the pattern*/
    int strs_length=strlen(strs[0]); /*length of the array searched in*/

    for(j=0;j<strs_length;j++){
        for(i=0;i<=rows-pattern_length;i++){
            char col_pattern[MAX_ROW] = ""; /*array initialized*/

            /*storing the column patterns of array to compare*/
            for(k=0;k<pattern_length;k++){
                col_pattern[k]=strs[i+k][j];
            }
            flag=1; /*flag default value*/
            for(k=0;k<pattern_length;k++){
                if(col_pattern[k]!=pattern[k]){
                    flag=0;
                    break;
                }
            }

            if(flag){ /*if there is a match*/
                /*storing coordinates*/
                matches[*num_matches][0] =i+1;
                matches[*num_matches][1] =j+1;
                (*num_matches)++;
            }
        }
    }
}

/*pattern 3 function (diagonal search)*/
void search_p3(char strs[][MAX_COLUMN],int rows,int matches[][2],int *num_matches){
  
    /*variable declarations*/
    char pattern[]="+**+++****+++**+"; /*pattern being looked for*/
    int flag,i,j,k;
    int pattern_length=strlen(pattern); /*length of the pattern*/
    int strs_length=strlen(strs[0]); /*length of the array searched in*/

    for(i=0; i<=rows-pattern_length;i++){
        for(j=0;j<=strs_length-pattern_length;j++){
            flag=1; /*flag default value*/
            for(k=0;k<pattern_length;k++){
                if(strs[i+k][j+k]!=pattern[k]){ /*if there is an unmatched character*/
                    flag=0; /*flag is set to 0*/
                    break;
                }
            }

            if(flag){ /*if there is a match*/
                /*storing coordinates*/
                matches[*num_matches][0]=i+1;
                matches[*num_matches][1]=j+1;
                (*num_matches)++;
            }
        }
    }
}
