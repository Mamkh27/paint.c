#include <stdio.h>
#include <stdlib.h>


char** makeCanvas (int numRows, int numCols);
void printCanvas(int numRows, int numCols, char** canvas);
bool checkInt(char string[]);


void setUp (char*** canvas, int numRows, int numCols){
	*canvas = makeCanvas(numRows, numCols);
	return; 
}

void printCanvas(int numRows, int numCols, char** canvas){
int i;
int j;
for (i = 0 ; i < numRows; ++i){
	printf("%d", numRows - i -1);
	for(j = 0; j < numCols; ++j){
		printf(" %c", canvas[i][j]);
		       }
	printf("\n");
}
printf(" "); 	 
for (j = 0 ; j < numCols; ++j){
	printf(" %d", j);
}
return; 
}
		
		
char** makeCanvas (int numRows, int numCols){	
char** canvas = (char**) malloc(numRows * sizeof(char*)); 
		 
int i;
int j; 
		 	 
for (i = 0; i < numRows; ++i){
	(canvas)[i] = (char*) malloc(numCols *sizeof(char));
	for (j = 0; j < numCols; ++j){
	(canvas)[i][j] = '*'; 
	}
}		 		 
return canvas; 
}

		 
		 


int main(int argc, char* argv[]){
	int numRows = 0;
	int numCols = 0;
	
if (argc < 2){
		numRows = 10; 
		numCols = 10; 
	} else {
		numRows = atoi(argv[1]);
		numCols = atoi(argv[2]);
		
		 if (checkInt(argv[1]) == false){
			 printf("The number of rows is not an integer.\n");
			 numRows = 10; 
			numCols = 10;
			printf("Making default board of 10 X 10.\n");
		 }
		 
		 if (checkInt(argv[2]) == false){
			 printf("The number of columns is not an integer.\n");
			 numRows = 10; 
			numCols = 10;
			printf("Making default board of 10 X 10.\n");
		 }
		
		if (numRows < 1){
			printf("The number of rows is less than 1.\n");
			numRows = 10; 
			numCols = 10;		
			printf("Making default board of 10 X 10.\n");
		}
		
		if (numCols < 1){
			printf("The number of columns is less than 1.\n");
			numRows = 10; 
			numCols = 10;	
			printf("Making default board of 10 X 10.\n");
		}
	}
	
	printf(" The board is %d X %d\n", numRows, numCols);
	return 0;
}

	bool checkInt(char string[]){
		int i; 
	
		for(i = 0; i < strlen(string); i++){
			if (!(isdigit(string[i]))){
		return false; 
			}	
		}
		return true; 
	}
	
	setUp(&canvas, numRows, numCols);
	printCanvas(numRows, numCols, canvas);
	
	//input(); 
	//cleanup(); 
	
	return 0;
}
