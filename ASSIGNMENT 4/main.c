    /*
    a data base program for students and instructors
    it's a bad written assignment so i don't recommend
    it as a good example, just analizing it would be better.
    written by: zeynepsturan
    */
#include <stdio.h>
/*function declarations*/
char first_initial (FILE *id_fp, int id), last_initial(FILE *id_fp, int id);
int get_id_fi(FILE *id_fp, char first_initial), get_id_li(FILE *id_fp, char first_initial);
int average_grade(FILE *info_fp, int id), course_id(FILE *info_fp, int id);
void course_averages(FILE *info_fp), role_and_department(FILE *info_fp,char role);
void number_of_classes(FILE *info_fp,int id);
int main(){
    FILE *ptr, *ptr2;
    char choice, role, get_initial, lettergrade, c;
    int get_id, class, pass_status, id, course_code,flag;

    ptr=fopen("first 1.txt","r");
    course_averages(ptr);
    fseek(ptr, 0, SEEK_SET);
    average_grade(ptr,0);
    fclose(ptr);
    
    while(1){
        printf("Please select from the following\n");
        printf("Enter p to print all the users pass or fail\n");
        printf("Enter n to print only the user with a specific first initial\n");
        printf("Enter g to Calculate the GPA of a given student\n");
        printf("Enter c to print whether each user passed or failed the same class. \n");
        printf("Enter t to print the number of classes for the instructor.\n");
        printf("Enter d to print the department of all persons according to the role\n");
        printf("Enter l to print the course_id of a given student\n");
        printf("Enter e to quit program\n");
        printf("Your choice: ");
        scanf(" %c",&choice);
        switch(choice){

            case 'p':
            ptr2=fopen("grades.txt","r");
            while(fscanf(ptr2,"%d %c %d %d", &get_id,&lettergrade, &class,&pass_status)!=EOF){
                printf("%d ",get_id);
                if(pass_status==1){
                    printf("PASSED\n");
                }

                else{
                    printf("FAILED");
                }
            }
            fclose(ptr2);
            break;

            case 'n':
            printf("Enter the first name initial of the student: ");
            scanf(" %c",&get_initial);

            ptr=fopen("second 1.txt","r");
            get_id_fi(ptr, get_initial);
            fclose(ptr);

            ptr=fopen("first_initials.txt","r");
            while(fscanf(ptr,"%c",&c)!=EOF){
                printf("%c",c);
            }
            fclose(ptr);
            break;

            case 'g':
            flag=1;
            printf("Enter the id of the student:");
            scanf("%d",&get_id);

            ptr2=fopen("grades.txt","r");
            while(fscanf(ptr2,"%d %c %d %d", &id,&lettergrade, &class,&pass_status)!=EOF){
                if(id==get_id){
                    printf("%d - Letter Grade: %c ",id,lettergrade);
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("The ID you entered does not belong to a student");
            }
            fclose(ptr2);
            break;

            case 'c':
            printf("Please enter the course code:");
            scanf("%d",&course_code);
            if(course_code==102 || course_code==108){
                ptr2=fopen("grades.txt","r");
                while(fscanf(ptr2,"%d %c %d %d", &get_id,&lettergrade, &class,&pass_status)!=EOF){
                    if(class==course_code){
                        printf("%d ",get_id);
                        if(pass_status==1){
                            printf("PASSED\n");
                        }

                        else{
                            printf("FAILED\n");
                        }
                    }
                }
                fclose(ptr2);
            }

            else{
                printf("There is no such a course code");
            }
            break;

            case 't':
            printf("Enter the ID of the instructor: ");
            scanf("%d",&get_id);
            ptr=fopen("first 1.txt","r");
            number_of_classes(ptr,get_id);
            fclose(ptr);
            break;

            case 'd':
            printf("Please enter the role (s for student/i for instructor): ");
            scanf(" %c",&role);
            ptr=fopen("second 1.txt","r");
            role_and_department(ptr,role);
            fclose(ptr);
            break;

            case 'l':
            ptr=fopen("first 1.txt","r");
            printf("Enter the ID of the student: ");
            scanf("%d",&get_id);
            int course=course_id(ptr,get_id);

            if(course==-1){
                printf("The ID you entered belongs to a instructor");
            }

            else if(course==-2){
                printf("The ID you entered could not be found");
            }

            else{
                printf("Course ID of the student is %d",course);
            }
            fclose(ptr);
            break;

            case 'e':
            printf("Exited from the program\n");
            return 0;
            break;

            default:
            printf("There is no such an option");
            break;

        }
        printf("\n\n");
    }
    return 0;
}

void role_and_department(FILE *info_fp,char role){
    int id,i;
    int department;
    char c,keep_role;

    while(fscanf(info_fp,"%d",&id)!=EOF){
        fscanf(info_fp,"%c",&c); /*getting the semi colon*/

        /*getting the  first and last name*/
        for(i=0;i<2;i++){
            do{
                fscanf(info_fp,"%c",&c);
            }while(c!=';');
        }
        /*getting the first initial of the role*/
            fscanf(info_fp,"%c",&keep_role);
        /*getting the remaining of the role*/
            do{
                fscanf(info_fp,"%c",&c);
            }while(c!=';');

        /*getting the department*/
        fscanf(info_fp,"%d",&department);

        if(keep_role==role){
            printf("No: %d Department: %d\n",id,department);
        }
    }
}

void number_of_classes(FILE *info_fp,int id){
    char c;
    int get_id,a1,a2,a3,a4,number_classes,flag;
    flag=1;
    while(fscanf(info_fp,"%d",&get_id)!=EOF){
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%d",&a1);
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%d",&a2);
        if(a2==500){
            /*instructor*/
            /*number of classes is a1*/
            /*department is a2*/
            number_classes=a1;
            if(id==get_id){
                printf("Number of classes of the instructor is %d\n",number_classes);
                flag=0;
                break;
            }
        }

        else{
            fscanf(info_fp,"%c",&c);
            fscanf(info_fp,"%d",&a3);
            if(a3==108){
            /*class 108*/
            }

            else{
                fscanf(info_fp,"%c",&c);
                fscanf(info_fp,"%d",&a4);
                /*class 102*/   
            }
        }
    }
    if(flag==1){
        printf("The ID you entered does not belong to an instructor\n");
    }
}

int course_id(FILE *info_fp, int id){
    char c;
    int get_id,a1,a2,a3,a4,course_id;
    while(fscanf(info_fp,"%d",&get_id)!=EOF){
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%d",&a1);
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%d",&a2);
        if(a2==500){
            /*instructor*/
            /*number of classes is a1*/
            /*department is a2*/
            course_id=-1;
        }

        else{
            fscanf(info_fp,"%c",&c);
            fscanf(info_fp,"%d",&a3);
            if(a3==108){
            /*class 108*/
            /*midterm=a1, final=a2, course id=a3*/
            course_id=a3;
            }

            else{
                fscanf(info_fp,"%c",&c);
                fscanf(info_fp,"%d",&a4);
                /*class 102*/
                /*midterm 1=a1, midterm 2=a2*/
                /*final=a3,course id=a4*/
                course_id=a4;   
            }
        }

        if(id==get_id){
            return course_id;
        }
    }

    return -2;
}

void course_averages(FILE *info_fp){
    FILE *avg_fp;
    avg_fp=fopen("averages.txt","w");
    int get_id;
    float a1,a2,a3,a4;
    float midterm102,midterm108,final102,final108;
    int count102,count108;
    midterm102=midterm108=final102=final108=0;
    count102=count108=0;
    char c;
    while(fscanf(info_fp,"%d",&get_id)!=EOF){
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%f",&a1);
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%f",&a2);
        if(a2==500){
            /*instructor*/
            /*number of classes=a1, department=a2*/
        }

        else{
            fscanf(info_fp,"%c",&c);
            fscanf(info_fp,"%f",&a3);
            if(a3==108){
                /*class 108*/
                /*midterm=a1, final=a2, course id=a3*/
                midterm108+=a1;
                final108+=a2;
                count108++;
            }

            else{
                fscanf(info_fp,"%c",&c);
                fscanf(info_fp,"%f",&a4);
                /*class 102*/
                /*midterm 1=a1, midterm 2=a2*/
                /*final=a3,course id=a4*/
                midterm102+=((a1+a2)/2);
                final102+=a3;
                count102++;
            }
        }
    }
    midterm102/=count102;
    final102/=count102;
    midterm108/=count108;
    final108/=count108;
    fprintf(avg_fp,"%.2f %.2f %.2f %.2f",midterm102,final102,midterm108,final108);
    fclose(avg_fp);
}

int average_grade(FILE *info_fp, int id){
    FILE *avg_fp, *grade_fp;
    float midterm102,midterm108,final102,final108,midterm,final;
    int class;
    avg_fp=fopen("averages.txt","r");
    grade_fp=fopen("grades.txt","w");
    fscanf(avg_fp,"%f %f %f %f",&midterm102,&final102,&midterm108,&final108);
    int get_id,a1,a2,a3,a4,midterm_average,final_average,pas_status;
    float gpa=0.0;
    char c,lettergrade;
    while(fscanf(info_fp,"%d",&get_id)!=EOF){
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%d",&a1);
        fscanf(info_fp,"%c",&c);
        fscanf(info_fp,"%d",&a2);
        if(a2==500){
            /*instructor*/
            /*number of classes is a1*/
            /*department is a2*/
            continue;
        }

        else{
            fscanf(info_fp,"%c",&c);
            fscanf(info_fp,"%d",&a3);
            if(a3==108){
            /*class 108*/
            /*midterm=a1, final=a2, course id=a3*/
            midterm=a1;
            final=a2;
            midterm_average=midterm108;
            final_average=final108;
            class=108;
            }

            else{
                fscanf(info_fp,"%c",&c);
                fscanf(info_fp,"%d",&a4);
                /*class 102*/
                /*midterm 1=a1, midterm 2=a2*/
                /*final=a3,course id=a4*/
                midterm=(a1+a2)/2;
                final=a3;
                midterm_average=midterm102;
                final_average=final102;
                class=102;
            }
        }

        /*calculating the midterm grade*/
        if(midterm<40 && midterm<midterm_average){
            gpa+=1;
            
        }

        else if(midterm>=40 && midterm<midterm_average){
            gpa+=2.5;
            
        }

        else if(midterm>=40 && midterm>=midterm_average){
            gpa+=3;
            
        }

        else if(midterm<90 && midterm>=midterm_average){
            gpa+=3.5;
            printf("A\n");
        }

        else if(midterm>=90){
            gpa+=4;
        }

        if(final<40 && final<final_average){
            gpa+=1;
        }

        else if(final>=40 && final<final_average){
            gpa+=2.5;
        }

        else if(final>=40 && final>=final_average){
            gpa+=3;
        }

        else if(final<90 && final>=final_average){
            gpa+=3.5;
        }

        else if(final>=90){
            gpa+=4;
        }
        gpa=gpa/2.0;

        if(gpa<1){
            lettergrade='F';
            pas_status=0;
        }

        else if(gpa<2.5){
            lettergrade='D';
            pas_status=1;
        }

        else if(gpa<3){
            lettergrade='C';
            pas_status=1;
        }

        else if(gpa<3.5){
            lettergrade='B';
            pas_status=1;
        }

        else if(gpa<=4){
            lettergrade='A';
            pas_status=1;
        }

        fprintf(grade_fp,"%d %c %d %d\n",get_id,lettergrade,class,pas_status);
        gpa=0;
    }
    fclose(grade_fp);
    fclose(avg_fp);
    return id;
    
}

char first_initial(FILE *id_fp, int id){
    id_fp=fopen("second 1.txt", "r");
    int temp_id,i;
    int grade;
    char initial_letter='0'; /*if the given id could not be found in the file it will return the character 0*/
    char c;

    while(fscanf(id_fp,"%d",&temp_id)!=EOF){
        
        if(temp_id==id){
            fscanf(id_fp,"%c",&c); /*gets the semi colon*/
            fscanf(id_fp,"%c",&initial_letter);
            break;
        }

        else{
            /*getting the first name,last name and role*/
            for(i=0;i<4;i++){
                do{
                    fscanf(id_fp,"%c",&c);
                }while(c!=';');
            }

            /*getting the grade*/
            fscanf(id_fp,"%d",&grade);
        }

    }
    fclose(id_fp);
    return initial_letter;
}

char last_initial(FILE *id_fp, int id){
    id_fp=fopen("second 1.txt", "r");
    int temp_id,i;
    int grade;
    char initial_letter='0'; /*if the given id could not be found in the file it will return the character 0*/
    char c;

    while(fscanf(id_fp,"%d",&temp_id)!=EOF){
        fscanf(id_fp,"%c",&c); /*gets the semi colon*/
        /*getting the first name*/
        do{
            fscanf(id_fp,"%c",&c);
        }while(c!=';'); /*gets the name and the semi colon and stops*/
    
        if(temp_id==id){
            fscanf(id_fp,"%c",&initial_letter);
            break;
        }

        else{
            /*getting the last name and role*/
            for(i=0;i<2;i++){
                do{
                    fscanf(id_fp,"%c",&c);
                }while(c!=';');
            }

            /*getting the grade*/
            fscanf(id_fp,"%d",&grade);
        }
    }
    fclose(id_fp);
    return initial_letter;
}

int get_id_fi(FILE *id_fp, char first_initial){
    FILE *fi_ptr;
    fi_ptr=fopen("first_initials.txt", "w");
    int temp_id,i;
    int grade;
    char c;

    while(fscanf(id_fp,"%d",&temp_id)!=EOF){
        fscanf(id_fp,"%c",&c); /*getting the semi colon*/
        fscanf(id_fp,"%c",&c); /*getting the first inital of the name*/
        
        if(c==first_initial){
            if(temp_id>=200000000){
                fprintf(fi_ptr,"%c",first_initial);
            }

            /*getting the remaining of first name and the last name*/
            for(i=0;i<2;i++){
                do{
                    fscanf(id_fp,"%c",&c);
                    if(temp_id>=200000000){
                        if(c==';'){
                            fprintf(fi_ptr," ");
                        }

                        else{
                            fprintf(fi_ptr,"%c",c);
                        }
                    }
                }while(c!=';');
            }
            if(temp_id>=200000000){
                fprintf(fi_ptr,"\n");
            }

            /*getting the role*/
            for(i=0;i<1;i++){
                do{
                fscanf(id_fp,"%c",&c);
                }while(c!=';');
            }

            /*getting the grade*/
            fscanf(id_fp,"%d",&grade);
        }

        else{
            /*getting the remaining of first name,the last name and the role*/
            for(i=0;i<3;i++){
                do{
                    fscanf(id_fp,"%c",&c);
                }while(c!=';');
            }

            /*getting the grade*/
            fscanf(id_fp,"%d",&grade);
        }
    }
    fclose(fi_ptr);
    return 0;
}

int get_id_li(FILE *id_fp, char first_initial){
    id_fp=fopen("second 1.txt", "r");
    int temp_id,i;
    int department;
    char c;
    int id=0; /*if the given id could not be found in the file it will return 0*/

    while(fscanf(id_fp,"%d",&temp_id)!=EOF){
        fscanf(id_fp,"%c",&c); /*getting the semi colon*/

        /*getting the  first name*/
        do{
            fscanf(id_fp,"%c",&c);
        }while(c!=';');

        fscanf(id_fp,"%c",&c); /*getting the first inital of the last name*/
        
        if(c==first_initial){
            id=temp_id;
            break;
        }
        
        else{
            /*getting the remaining of the last name,role*/
            for(i=0;i<2;i++){
                do{
                 fscanf(id_fp,"%c",&c);
                }while(c!=';');
            }

            /*getting the department*/
            fscanf(id_fp,"%d",&department);
        }
    }
    return id;
}
