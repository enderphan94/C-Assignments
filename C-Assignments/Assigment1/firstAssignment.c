#include <stdio.h>
#include <stdlib.h>

// The program works on the file contained 6 digits ( 3 pairs )

int main()
{

    FILE *myFile;
    myFile = fopen("somenumbers.txt", "r");

    int numberArray[6];
    int i;
    int j;
    int a;
    int b;
    int sub;

    if (myFile == NULL){

	fprintf(stderr,"Cannot open input file ");
    }

    //Output the numbers to array and take 2 numbers separated by comma as a pair 
    for (i = 0; i < 6; i+=2)
    {
        fscanf(myFile, "%d,%d;", &numberArray[i],&numberArray[i+1] );
    
    }
    //Sort Array ascending order
    for (i = 0; i < sizeof(numberArray)/sizeof(int); i+=2)
    {
	for(j=i+2;j<sizeof(numberArray)/sizeof(int);j+=2){
		if(numberArray[i] > numberArray[j]){
		a = numberArray[i];
		b = numberArray[i+1];
		numberArray[i] = numberArray[j];
		numberArray[i+1]= numberArray[j+1];
		numberArray[j+1]=b;
		numberArray[j] = a;
		}
	}
    }
    //Subtraction between odd number of each pair
    for (i=0; i < (sizeof(numberArray)/sizeof(int) - 2 ); i+=2){
	sub = numberArray[i+3] - numberArray[i+1];
	printf("%d\n",sub);
    }
    fclose(myFile);

    return 0;
}
