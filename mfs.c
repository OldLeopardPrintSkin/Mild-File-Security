/*********************************************/
/* Mfs				             */
/* Don't expect this to work                 */
/* May not be sold without written permission*/
/* (c) 2011 Nathanael barry     	     */
/*********************************************/

#include <stdio.h>

int usage(int usage, char* argv[]);
int rot(int rotnum, int c);
int dorot(char* argv[]);
int multchar(char* argv[]);

int main(int argc, char *argv[]){

	int use = 0; //1 = not enough params, 2 = incorrect params
	int c; //character storage
	FILE * inFile;
	FILE * outFile;
	int outstat;
	FILE * helpFile;
	int rotnum; //rot num

	if ( argc < 2 ){
		use = 1;
		usage(use, argv);
	}else{
		if ( argv[1][0] == '-' ){ 
			switch ( argv[1][1] ){
				case 'h':
				case 'H':
					helpFile=fopen("HELP", "r");
					if ( helpFile == NULL ){
						perror ("Error opening file");
					}
					while(c != EOF){
						c = fgetc(helpFile);
						if (c != EOF) putchar(c);
					}
					break;
				case 'm':
				case 'M':
					multchar(argv);
				case 'r':
				case 'R':
					dorot(argv);
					break;		
				default:
					use = 2;
					usage(use, argv);
					break;
			}					
		}else{
			usage(use, argv);
			}
	}	
	return 0;

}
int dorot(char* argv[]){
	FILE * inFile;
	FILE * outFile;
	int c, outstat, rotnum, use;
	if ( argv[3] == NULL ){
		use = 1;
		usage(use, argv);
	}else{
		rotnum = atoi(argv[2]);
	}
	if ( argv[4] == NULL ){
		outstat = 0;
	}else{
		outstat = 1;
	}	
	inFile=fopen (argv[3],"r");
	if (inFile==NULL){
		perror ("Error opening file");
	}
	if ( outstat == 0 ){
		while(c != EOF){
			c = fgetc(inFile);
			c = rot(rotnum, c);
			putchar(c);
		}
		printf("\n");
		fclose (inFile);
	}else{
		outFile=fopen (argv[4], "w");
		while(c != EOF){
			c = fgetc(inFile);	
			c = rot(rotnum, c);
			fputc(c, outFile);	
		}
		fclose (inFile);
		fclose (outFile);
	}	
		
		return 0;							
}
	
int multchar(char* argv[]){
	FILE * inFile;
	FILE * outFile;
	int c, outstat, use;
	if ( argv[2] == NULL ){
		use = 1;
		usage(use, argv);
	}
	if ( argv[3] == NULL ){
		outstat = 0;
	}else{
		outstat = 1;
	}	
	inFile=fopen (argv[2],"r");
	printf("%s", argv[2]);
	if (inFile==NULL){
		perror ("Error opening file");
	}
	if ( outstat == 0 ){
		while( c != EOF ){
			c = fgetc(inFile);
			c *= 1.1;
			putchar(c);
		}
		
	}else{
		outFile=fopen (argv[3], "w");
		while( c != EOF ){
			c = fgetc(inFile);
			c *= 1.1;
			fputc (c, outFile);
		}
			fclose (outFile);
	}
	fclose (inFile);
	
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
	return 1;
}
