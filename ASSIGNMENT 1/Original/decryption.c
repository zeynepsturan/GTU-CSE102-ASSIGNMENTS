  /*
    the program that decrypts the
    input file encrypted using Caesar's
    method and prints to the output file
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
	char c;

	/*decyrpting*/
	while(scanf("%c",&c)!=EOF){
	
		/*if there is a comment*/
		if(c=='@'){
			
			scanf("%c",&c);
			printf("/*There are ");

			/* read characters until space, newline, or tab */
            while (scanf("%c", &c)!=EOF) {
            	if(c== ' ' || c == '\n' || c == '\t'){
            		break;
            	}
            	
            	else{
            		for (i = 0; i < 61; i++) {
		                if (c == alphabet[i]) {
		                    if (i - key < 0) {
		                        c = alphabet[i - key + 61];
		                    } else {
		                        c = alphabet[i - key];
		                    }
		                    break;
		                }
		            }
		            printf("%c", c);
            	}
                
            }

            printf(" characters as comment*/");
            printf("%c", c);
        } 
        /* not a comment */
        else {
            for (i = 0; i < 61; i++) {
                if (c == alphabet[i]) {
                    if (i - key < 0) {
                        c = alphabet[i - key + 61];
                    } else {
                        c = alphabet[i - key];
                    }
                    break;
                }
            }
            printf("%c", c);
        }
    }
	return 0;
}
