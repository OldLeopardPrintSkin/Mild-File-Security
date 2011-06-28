/*
 * Kruptos.c
 *
 *  Created on: Jun 21, 2011
 *      Author: woden
 */

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
	FILE * helpFile;
	int rotnum; //rot num

	if ( argc < 2 ){
		use = 1;
		usage(use, argv);
	}else{
		if ( argv[1][0] != '-' ){  //need a hyphen for the first argument
			use = 2;
			usage(use, argv);
		}
		switch ( argv[1][1] ){ 
			case 'h':  // Help
				helpFile=fopen("HELP", "r");
				if ( helpFile == NULL ){
					perror ("Error opening file");
				}
				while(c != EOF){
					c = fgetc(helpFile);
					if (c != EOF) putchar(c);
				}
				break;
			case 'r': // rotational cypher
				//rotnum = getrotnum(argv);
				if (argv[2][0] == '-'){ // if the second argument == -
					if (argv[2][1] == NULL){ // must specify filenames
						use = 1;
						usage(use, argv);//////////////////////////////////MAKE IT SO THAT CUSTOM FILENAMES
					}else{
					inFile=fopen ("myfile.txt","r");
					if (inFile==NULL){
						perror ("Error opening file");
					}
					while(c != EOF){
						c = fgetc(inFile);
						cyphered = rot(rotnum, c);
						putchar(cyphered);
					}
					fclose (inFile);
					}
				}else{
					use = 2;
					usage(use, argv);
				}
				printf("\n");
				break;
			default:
				use = 2;
				usage(use, argv);
				break;
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
	//putchar(c);
	return c;
}/*

int getrotnum(char* argv[]){
	int i;
	int(argv[1][2]);

	if ( argv[1][3] == NULL ){
		for(i = 0; i < 10; i++){
			if ( i == argv[1][1] ){
				return i;
			}
		}
	}else if ( argv[1][3] != NULL ){
		int(argv[1][3]);
		if 

}
*/
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
		case 3:
			printf("> -r only takes values below 26\n");
		default:
			printf("> You broke me somehow\n");
			printf("> Try running %s -h\n", argv[0]);
			break;
	}
	exit(1);
}
