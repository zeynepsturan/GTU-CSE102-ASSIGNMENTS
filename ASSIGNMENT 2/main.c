    /*
        a simple aritifcal intelligence
        to group the given data with
        least number of errors
        training and using it in the program
        and exploring some data
        written by: zeynepsturan
    */
#include <stdio.h>
int main(){
    FILE *ptr;
    int option;
    printf("Welcome to the Program. Please select from following:\n");

    while(1){
        /*menu*/
        printf("1:Explore Data\n");
        printf("2:Train Model\n");
        printf("3:Test Model\n");
        printf("4:Exit\n");
        printf("Your choice: ");
        scanf("%d",&option);
        printf("\n");

        switch(option){

            case 1: /*exploring data*/
            ptr=fopen("data.txt","r");
            if(ptr==NULL){
                printf("Error opening the file");
                fclose(ptr);
                return 0;
            }

            else{
                /*variable declarations*/
                int x,y,c;
                int xmax0,xmax1,xmin0,xmin1,ymax0,ymax1,ymin0,ymin1;
                /*these variables are to check if the variables in line4 are initialized*/
                int flag0=0,flag1=0;
                
                /*initializing the variables*/
                while(flag0==0 || flag1==0){
                    fscanf(ptr,"%d %d %d",&x,&y,&c);
                    if(c==0){
                        if(flag0==0){
                            xmax0=xmin0= x;
                            ymax0=ymin0= y;
                            flag0=1;
                        }
                    }

                    else if(c==1){
                        if(flag1==0){
                            xmax1=xmin1= x;
                            ymax1=ymin1= y;
                            flag1=1;
                        }
                    }
                }
                /*initializing done*/
                /*getting the max and min values*/
                fseek(ptr, 0, SEEK_SET);
                while((fgetc(ptr))!=EOF){

                    fscanf(ptr,"%d %d %d",&x,&y,&c);
                    if(c==0){
                        if(x>=xmax0){
                            xmax0=x;
                        }

                        if(x<=xmin0){
                            xmin0=x;
                        }

                        if(y>=ymax0){
                            ymax0=y;
                        }

                        if(y<=ymin0){
                            ymin0=y;
                        }
                    }

                    else if(c==1){

                        if(x>=xmax1){
                            xmax1=x;
                        }

                        if(x<=xmin1){
                            xmin1=x;
                        }

                        if(y>=ymax1){
                            ymax1=y;
                        }

                        if(y<=ymin1){
                            ymin1=y;
                        }
                    }
                }
                /*output*/
                printf("Minimum and Maximum X and Y values:\n");
                printf("Class 0: X in [%d %d], Y in [%d %d]\n",xmin0,xmax0,ymin0,ymax0);    
                printf("Class 1: X in [%d %d], Y in [%d %d]\n",xmin1,xmax1,ymin1,ymax1);
                fclose(ptr);
            }
            break;

            case 2: /*training model*/
            /*variable declarations*/
            int region,R1,R2,R3,R4;
            int save_x,save_y,save_R1,save_R2,save_R3,save_R4;
            int Dx,Dy,Dc;
            int xmax,xmin,ymax,ymin;
            int X,Y,i,j,k;
            int initializing=0;
            int flag=0;

            ptr=fopen("data.txt","r");
            /*if the file could not be opened*/
            if(ptr==NULL){
                printf("Error opening the file\n");
                return 0;
            }
            /*max min values*/
            
            /*initializing the variables*/
            while(fscanf(ptr,"%d %d %d",&Dx,&Dy,&Dc)!=EOF){
                if(initializing==0){

                    xmax=xmin= Dx;
                    ymax=ymin= Dy;
                    initializing=1;
                }
            }
            /*initializing done*/
            fclose(ptr);
            ptr=fopen("data.txt","r");
                
            /*getting the max and min values*/
            fseek(ptr, 0, SEEK_SET);
            while(fscanf(ptr,"%d %d %d",&Dx,&Dy,&Dc)!=EOF){

                if(Dx>=xmax){
                    xmax=Dx;
                }

                if(Dx<=xmin){
                    xmin=Dx;
                }

                if(Dy>=ymax){
                    ymax=Dy;
                }

                if(Dy<=ymin){
                    ymin=Dy;
                }
            }
            
            if((fclose(ptr))!=0){
                printf("Error closing the file\n");
            }

            /*part2*/
            ptr=fopen("data.txt","r");

            int errorCount=0;
            int minError;

            /*training*/
            for(i=0;i<16;i++){
                switch(i){
                    /*region labels*/
                    case 0:  R1=1; R2=1; R3=1; R4=1;  break;
                    case 1:  R1=1; R2=1; R3=1; R4=0;  break;
                    case 2:  R1=1; R2=1; R3=0; R4=1;  break;
                    case 3:  R1=1; R2=1; R3=0; R4=0;  break;
                    case 4:  R1=1; R2=0; R3=1; R4=1;  break;
                    case 5:  R1=1; R2=0; R3=1; R4=0;  break;
                    case 6:  R1=1; R2=0; R3=0; R4=1;  break;
                    case 7:  R1=1; R2=0; R3=0; R4=0;  break;
                    case 8:  R1=0; R2=1; R3=1; R4=1;  break;
                    case 9:  R1=0; R2=1; R3=1; R4=0;  break;
                    case 10: R1=0; R2=1; R3=0; R4=1;  break;
                    case 11: R1=0; R2=1; R3=0; R4=0;  break;
                    case 12: R1=0; R2=0; R3=1; R4=1;  break;
                    case 13: R1=0; R2=0; R3=1; R4=0;  break;
                    case 14: R1=0; R2=0; R3=0; R4=1;  break;
                    case 15: R1=0; R2=0; R3=0; R4=0;  break;
                }
                /*Testing all X,Y values*/
                for(j=xmin;j<=xmax;j++){
                    X=j;
                    for(k=ymin;k<=ymax;k++){
                        Y=k;
                        fseek(ptr, 0, SEEK_SET);
                        errorCount=0;
                        while(fscanf(ptr,"%d %d %d",&Dx,&Dy,&Dc)!=EOF){

                            if(Dx<=X && Dy>Y){
                                region=1;
                            }

                            else if(Dx>X && Dy>Y){
                                region=2;
                            }

                            else if(Dx<=X && Dy<=Y){
                                region=3;
                            }

                            else if(Dx>X && Dy<=Y){
                                region=4;
                            }

                            switch(region){
                                case 1:
                                if(R1!=Dc){
                                    errorCount++;
                                }
                                break;

                                case 2:
                                if(R2!=Dc){
                                    errorCount++;
                                }
                                break;

                                case 3:
                                if(R3!=Dc){
                                    errorCount++;
                                }
                                break;

                                case 4:
                                if(R4!=Dc){
                                    errorCount++;
                                }
                                break;
                            }
                        }

                        if(flag==0){
                           minError=errorCount;
                           flag=1; 
                        }
                        
                        if(errorCount<=minError){
                            minError=errorCount;
                            save_x=X;
                            save_y=Y;
                            save_R1=R1;
                            save_R2=R2;
                            save_R3=R3;
                            save_R4=R4;
                        }
                    }
                }
            }
            
            printf("Seperator coordinates: X = %d, Y = %d\n",save_x,save_y);
            printf("Training error of the model: %d\n",minError);
            printf("Labels of the regions R1 = %d, R2 = %d, R3 = %d, R4 = %d\n",save_R1,save_R2,save_R3,save_R4);
            break;

            case 3: /*testing model*/
            X=save_x;
            Y=save_y;
            R1=save_R1;
            R2=save_R2;
            R3=save_R3;
            R4=save_R4;
            errorCount=0;
            int count=0;

            ptr=fopen("test 1.txt","r");
            if(ptr==NULL){
                printf("Error opening the file");
                fclose(ptr);
                return 0;
            }

            while(fscanf(ptr,"%d %d %d",&Dx,&Dy,&Dc)!=EOF){
                count++;
                if(Dx<=X && Dy>Y){
                    region=1;
                }

                else if(Dx>X && Dy>Y){
                    region=2;
                }

                else if(Dx<=X && Dy<=Y){
                    region=3;
                }

                else if(Dx>X && Dy<=Y){
                    region=4;
                }

                switch(region){
                    case 1:
                    if(R1!=Dc){
                        errorCount++;
                    }
                    break;

                    case 2:
                    if(R2!=Dc){
                        errorCount++;
                    }
                    break;

                    case 3:
                    if(R3!=Dc){
                        errorCount++;
                    }
                    break;

                    case 4:
                    if(R4!=Dc){
                        errorCount++;
                    }
                    break;
                }
            }
            float success=(float)(count-errorCount)/(float)count*100;
            printf("Success rate : %.2f\n",success);
            printf("-------------------------------------\n");
            fclose(ptr);

            ptr=fopen("test-final.txt","r");
            if(ptr==NULL){
                printf("Error opening the file");
                fclose(ptr);
                return 0;
            }

            while(fscanf(ptr,"%d %d",&Dx,&Dy)!=EOF){
                printf("(%d,%d) ",Dx,Dy);
                if(Dx<=X && Dy>Y){
                    region=1;
                }

                else if(Dx>X && Dy>Y){
                    region=2;
                }

                else if(Dx<=X && Dy<=Y){
                    region=3;
                }

                else if(Dx>X && Dy<=Y){
                    region=4;
                }

                switch(region){
                    case 1:
                    printf("Label : %d\n",R1);
                    break;

                    case 2:
                    printf("Label : %d\n",R2);
                    break;

                    case 3:
                    printf("Label : %d\n",R3);
                    break;

                    case 4:
                    printf("Label : %d\n",R4);
                    break;
                }
            }
            fclose(ptr);
            break;

            case 4:
            printf("Exited from the program.\n");
            return 0;
            break;

            default:
            printf("There is no such option\n");
            break;
        }

        printf("\n\n");
    }

    
    return 0;
}
