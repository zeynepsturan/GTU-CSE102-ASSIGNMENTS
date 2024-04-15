    /*
        the program that prints the daily news
        about astronaut Alper Gezeravcı, marks
        them as read and decrypts the secret key
        written by: zeynepsturan
    */
#include <stdio.h>
#include <locale.h>
/*function declarations*/
void menu();
char read_news(),list_readed_news(), get_decrypted();
float f(int x),g(int x);
/*variable declarations*/
char filename[12]="news\\x.txt"; /*this is competible for windows. in ubuntu, file path is shown by a /. so change it to "news/x.txt" */
FILE *ptr,*ptr2;

int main(){
    /*to be able to read turkish characters(in every platform)*/
    setlocale(LC_ALL,"tr_TR.UTF-8");
    menu();
    return 0;
}

char read_news(){
    /*variable declarations*/
    char newschoice,c,repeatchoice,choice;
    int newsnum,num,flag=0,flag2=0,i;

    /*choosing the news*/
    printf("Which news do you want to read?\n");
    printf("Your choice: ");
    scanf(" %c",&newschoice);
    newsnum=newschoice-'0';

    /*to find out the name index of the news for the chosen news number*/
    ptr2=fopen("all_news_id.txt","r");
    for(i=0;i<newsnum;i++){
        fscanf(ptr2,"%c\n",&newschoice);
    }
    fclose(ptr2);
    filename[5]=newschoice;
    

    /*checking if the new has been read before*/
    ptr=fopen("read_news_id.txt","r");
    while(fscanf(ptr,"%d",&num)!=EOF){

        /*if it's been read before*/
        if(num==newsnum){
            printf("This news is read. Do you want to read it again? Yes(y)/No(n)");
            scanf(" %c",&repeatchoice);
            if(repeatchoice=='y'){
                /*printing the news*/
                printf("\n");
                ptr=fopen(filename,"r");
                while((fscanf(ptr,"%c",&c))!=EOF){
                    printf("%c",c);
                }
                fclose(ptr);
            }

            else{
                printf("Exited from the program\n");
                
            }
            flag=1;
        }
    }

    /*if it hasn't been read before*/
    if(flag!=1){
        ptr=fopen(filename,"r");
        while((fscanf(ptr,"%c",&c))!=EOF){
            printf("%c",c);
        }
        fclose(ptr);
        ptr=fopen("read_news_id.txt","a");
        while(fscanf(ptr,"%d",&num)!=EOF){
            if(num==newsnum){
                flag2=1;
            }
        }
        if(flag2!=1){
            fprintf(ptr,"%d ",newsnum);
        }
        fclose(ptr);
    }
    printf("\nDo you want to continue?Yes(y)/No(n): ");
    scanf(" %c",&choice);
    return choice;
}

char list_readed_news(){
    /*variable declarations*/
    char choice;
    int num;

    /*printing the reads has been read*/
    ptr=fopen("read_news_id.txt","r");
    while(fscanf(ptr,"%d",&num)!=EOF){
        printf("%d. news is read\n",num);
    }
    fclose(ptr);

    printf("Do you want to continue? Yes(y)/No(n): ");
    scanf(" %c",&choice);
    return choice;
}

/*f and g are functions to calculate experiment key*/
float f(int x){
    return (x*x*x)-(x*x)+2;
}

float g(int x){
    return (x*x);
}

char get_decrypted(){
    /*variable declarations*/
    char newschoice,c,choice;
    int num;
    float secret_number;

    /*choosing the news*/
    printf("Which news would you like to decrypt?\n");
    printf("Your choice: ");
    scanf(" %c",&newschoice);
    printf("\n");
    filename[5]=newschoice;

    /*decrypting*/
    ptr=fopen(filename,"r");
    while((fscanf(ptr,"%c",&c))!=EOF){
        printf("%c",c);
        if(c=='#'){
            printf("%c",c);
            fscanf(ptr,"%d",&num);
            printf("%d",num);
            secret_number+=g(f(num));
        }
    }

    /*printing the key*/
    printf("%c. experiment key is %.2f\n",newschoice,secret_number);
    fclose(ptr);
    printf("Do you want to continue? Yes(y)/No(n): ");
    scanf(" %c",&choice);
    return choice;
}

void menu(){
    /*variable declarations*/
    int i;
    char c,option,return_value,num;

    /*checking if the read_news file exist*/
    ptr=fopen("read_news_id.txt","r");
    if(ptr==NULL){
        /*creating it if it doesn't exist*/
        ptr=fopen("read_news_id.txt","w");
        fclose(ptr);
    }

    else{
        fclose(ptr);
    }

    /*menu*/
    printf("******* Daily Press *******");
    printf("\nToday's news are listed for you:");

    /*printing the headers of the news*/
    ptr2=fopen("all_news_id.txt","r");
    for(i=1;i<=4;i++){
        fscanf(ptr2,"%c\n",&num);
        filename[5]=(char)num;
        printf("\nTitle of %d. news:",i);
        ptr=fopen(filename,"r");
        while((fscanf(ptr,"%c",&c))!=EOF){
            if(c=='\n'){
                break;
            }
            printf("%c",c);
        }
        fclose(ptr); 
    }
    fclose(ptr2);

    /*options*/
    printf("\nWhat do you want to do?\n");
    printf("a. Read a news\n");
    printf("b. List the readed news\n");
    printf("c. Get decrypted information from the news\n");

    /*choosing one*/
    printf("Your choice: ");
    scanf(" %c",&option);
    switch(option){
        case 'a':
        return_value=read_news();
        if(return_value=='y'){
            printf("\n\n");
            menu();
        }

        else if(return_value=='n'){
            printf("Exited from the program\n");
        }

        else{
            printf("Invalid option.\n\n");
            menu();
        }
        break;

        case 'b':
        return_value=list_readed_news();
        if(return_value!='n'){
            printf("\n");
            menu();
        }
        break;

        case 'c':
        return_value=get_decrypted();
        if(return_value=='y'){
            printf("\n\n");
            menu();
        }

        else if(return_value=='n'){
            printf("Exited from the program\n");
        }

        else{
            printf("Invalid option.\n\n");
            menu();
        }
        break;

        default:
        printf("Your choice is invalid\n");
        break;
    }
}
