#include <stdio.h>
/*function declarations*/
int find_size_of_array(int A[]);
float calculate_average(int A[],int a, int b), calculate_median(int A[],int a, int size);
void calculate_mode(int A[],int a, int size);
void draw_histogram(int occurrence_array[],int size),print_operations(int A[],int a,int size);

int main(){
    /*variable declarations*/
    int a,b,i,j,k,array_size,choice,newnum;
    int number_array[] = {
    73, 86, 72, 88, 65, 84, 76, 66, 77, 81, 81, 74, 71, 72, 63, 83, 76, 76, 83, 81,
    88, 85, 87, 72, 84, 87, 86, 68, 79, 66, 80, 72, 88, 78, 89, 74, 75, 83, 86, 76,
    80, 64, 87, 66, 73, 75, 71, 80, 69, -1};
    array_size=find_size_of_array(number_array);

    /*getting the boundaries*/
    printf("Enter A and B values: ");
    scanf("%d %d",&a,&b);

    while(a<50 || b>200 || b<a){
        if(a<50){
            printf("A must be at least 50\n");
            printf("Enter A value again: ");
            scanf("%d",&a);
        }

        if(b>200){
            printf("B must not exceed 200\n");
            printf("Enter B value again: ");
            scanf("%d",&b);
        }

        if(b<a){
            printf("B can't be less than A\n");
            printf("Enter A and B values: ");
            scanf("%d %d",&a,&b);
        }
    }

    /*creating an array for occurences and initializing it to 0*/
    int size=b-a+1;
    int occurrences[size];
    for(i=0;i<size;i++){
        occurrences[i]=0;
    }

    /*finding the occurences*/
    i=0;
    while(i<size){ /*this loop is to fill all the indexes of occurences*/
        for(j=a;j<=b;j++){ /*this is for boundaries*/
            for(k=0;k<array_size;k++){ /*this searches the whole number array*/
                if(number_array[k]==j){
                    occurrences[i]++;
                }
            }
            i++;
        }
    }

    /*printing the histogram*/
    draw_histogram(occurrences,size);

    /*a at 0, a+1 at 1*/
    printf("Would you like to add new numbers?(Enter 1 for yes, 0 for no): ");
    scanf("%d",&choice);

    if(choice==1){
    
        while(1){
            printf("Enter the number:");
            scanf("%d",&newnum);
            if(newnum>=a && newnum <= b){
                occurrences[newnum-a]++;
            }
            else if(newnum==-1){
                break;
            }
            else{
                printf("The number is not in the interval\n");
            }
        }
        /*printing the histogram*/
        draw_histogram(occurrences,size);
        print_operations(occurrences,a,size);
    }

    else if(choice==0){
        print_operations(occurrences,a,size);
    }

    return 0;
}

void draw_histogram(int occurrence_array[],int size){
    int i,j,occurrences_max=0;
    for(i=0;i<size;i++){
        if(occurrence_array[i]>occurrences_max){
            occurrences_max=occurrence_array[i];
        }
    }

    /*printing the histogram*/
    for(i=occurrences_max;i>0;i--){
        for(j=0;j<size;j++){
            if(occurrence_array[j]>=i){
                printf("*");
            }

            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int find_size_of_array(int A[]){
    int i,size=0;
    for(i=0;A[i]!=-1;i++){
        size++;
    }
    return size;
}

float calculate_average(int A[],int a, int size){
    int i;
    float sum=0,count=0,average;
    for(i=0;i<size;i++){
        sum+=A[i]*(a+i);
        count+=A[i];
    }
    average=sum/count;
    return average;
}

void calculate_mode(int A[],int a,int size){
    int i,most_occurrence=0,mode;
    for(i=0;i<size;i++){
        if(A[i]>most_occurrence){
            most_occurrence=A[i];
        }
    }
    printf("Mode: ");
    for(i=0;i<size;i++){
        if(A[i]==most_occurrence){
            mode=a+i;
            printf("%d ",mode);
        }
    }
    printf("\n");
}

float calculate_median(int A[],int a,int size){
    int i,j,count=0,numbercount=0;
    float median=0;

    /*finding out how many numbers there are*/
    for(i=0;i<size;i++){
        numbercount+=A[i];
    }

    if(size%2==1){
        for(i=0;i<size;i++){
            for(j=0;j<A[i];j++){
                count++;
                if(count==(numbercount/2)){
                    median=a+i;
                    break;
                }
            }
        }
    }

    else{
        for(i=0;i<size;i++){
            for(j=0;j<A[i];j++){
                count++;
                if(count==(numbercount/2)){
                    median+=a+i;
                }

                else if(count==((numbercount/2)+1)){
                    median+=a+i;
                    break;
                }
            }

            if(count>=numbercount/2+1){
                break;
            }
        }
    }
    median/=2;
    return median;
}

void print_operations(int A[],int a,int size){
    printf("Average: %.2f\n",calculate_average(A,a,size));
    printf("Median: %.2f\n",calculate_median(A,a,size));
    calculate_mode(A,a,size);
}
