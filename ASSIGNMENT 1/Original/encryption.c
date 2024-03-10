  /*
    the program that takes a valid C code
    from an input file, encrypts it using
    Caesar's method and prints to the output file
    written by zeynepsturan
  */
#include <stdio.h>

int main(){

	/* variable declarations*/
	char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
	'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '(', '<', '=', '+', ')', '[', '*', '/', ']',
	'{', '>', '!', '-', '}', '?', '\\', '&', '|', '%', '_', ';', '"',
	'#', '.', '\'', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	int key=8;
	int i;
	char c,after;

	/*encyrpting*/
	while(scanf("%c",&c)!=EOF){
	
		/*if there is a comment*/
		if(c=='/'){

			scanf("%c",&c);
			if(c=='*'){

				int count=0;
				printf("@ ");
				scanf("%c", &c);

				while(1){

        			scanf("%c", &after);
					if(c=='*' && after=='/'){
						scanf("%c",&c);
						break;
					}

					count++;
					c=after;
					
					if(c==' '){
						count--;
					}
				}
				/*encyrpting the count*/;

				int temp=count;
				int digit=0;
				int divisor=1;
				int number;

				/*getting the number of digits of count*/
				while(temp>0){

					temp/=10;
					digit++;

				}
				
				temp=count;
	
				/*getting the digits of the count from left to right*/
				for (i = digit; i > 0; i--) {
				    int tempdigit = i - 1;

				    int divisor = 1;
				    
				    while (tempdigit > 0) {
					divisor *= 10;
					tempdigit--;
				    }
				    
				    number=temp/divisor;
				    temp%=divisor;
				    
				    /*type casting the digits to char*/
				    char num=(char)number+48;
				    int j;
				    
				    /*encrypting*/
				    for(j=0;i<61;j++){

						if(num==alphabet[j]){

							if(j+key>=61){

						    	num=alphabet[j+key-61];
							}

							else{
							
								num=alphabet[j+key];
							}
						
							break;
		    			}
					}
        			printf("%c",num);
				}    
			}	

		}

			/*else*/
			for(i=0;i<61;i++){

				if(c==alphabet[i]){

					if(i+key>=61){

					    c=alphabet[i+key-61];
					}

					else{
					
					    c=alphabet[i+key];
					}
					break;
            			}
        		}

        		printf("%c",c);
		}

	return 0;
}
