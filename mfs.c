/*********************************************/
/* Mfs				             */
/* Don't expect this to work                 */
/* May not be sold without written permission*/
/* (c) 2011 Nathanael barry     	     */
/*********************************************/

#include <stdio.h>

int usage(int usage, char* argv[]);
int rot(int rotnum, int c);
//int getrotnum(char* argv[]);

int main(int argc, char *argv[]){

	int use; //1 = not enough params, 2 = incorrect params
	int i; //used in loops
	int done = 0;
	int cyphered;
	int c; //character storage
	FILE * inFile;
	FILE * outFile;
	int outstat;
	FILE * helpFile;
	int rotnum = 13; //rot num

	if ( argc < 2 ){
		use = 1;
		usage(use, argv);
	}else{
		if ( argv[1][0] == '-' ){  //need a hyphen for the first argument
			if ( argv[1][1] == 'h' || argv[1][1] == 'H' ){
				helpFile=fopen("HELP", "r");
				if ( helpFile == NULL ){
					perror ("Error opening file");
				}
				while(c != EOF){
					c = fgetc(helpFile);
					if (c != EOF) putchar(c);
				}
				return 0;
			}else{
				use = 2;
				usage(use, argv);
			}					
		}else if ( argv[1] != NULL ){
					if ( argv[2] == NULL ){
						use = 1;
						usage(use, argv);
					}else{
						rotnum = atoi(argv[2]);
					}
					if ( argv[3] == NULL ){
						outstat = 0;
					}else{
						outstat = 1;
					}						
					inFile=fopen (argv[1],"r");
					if (inFile==NULL){
						perror ("Error opening file");
					}
					if ( outstat == 0 ){
						while(c != EOF){
							c = fgetc(inFile);
							cyphered = rot(rotnum, c);
							putchar(cyphered);
						}
						printf("\n");
						fclose (inFile);
					}else{
						outFile=fopen (argv[3], "w");
						while(c != EOF){
							c = fgetc(inFile);	
							cyphered = rot(rotnum, c);
							fputc(c, outFile);	
						}
						fclose (inFile);
						fclose (outFile);								
					}
			}
	}	
	return 0;

}

int rot(int rotnum, int c){
	int offset;
	if (c >= 'a' && c <= 'z') {
					offset = 'a';
				} else if (c >= 'A' && c <= 'Z') {
					offset = 'A';
				}
				
				if (offset != 0) {
					if (c - offset < rotnum){
						c = c + rotnum;
					}else{
						c = c - rotnum;
					}
					
				}
	return c;
}
int usage(int usage, char* argv[]){
	switch(usage){
		case 1:
			printf("> Not enough parameters\n");
			printf("> Type %s -h for help\n", argv[0]);
			break;
		case 2:
			printf("> Incorrect parameters\n");
			printf("> Type %s -h for help\n", argv[0]);
			break;
		default:
			printf("> You broke me somehow\n");
			printf("> Try running %s -h\n", argv[0]);
			break;
	}
	exit(1);
}
