#include <stdio.h>
#include <stdlib.h>

// The program works on the file contained 6 digits ( 3 pairs )

int main()
{

    	FILE *myFile;
    	myFile = fopen("somenumbers.txt", "r");

    	int i,j,a,b;
    	int num1,num2;
    	int sub;
    	int count=0;

    	if (myFile == NULL){

		fprintf(stderr,"Cannot open input file ");
    		return(-1);
    	}

	int check;
	fseek(myFile,0,SEEK_END);
	check = ftell(myFile);
	rewind(myFile);

	if(check == 0){
		return 0;	
	}

    	//Output the numbers to array and take 2 numbers separated by comma as a pair 
	while(fscanf(myFile,"%d,%d;",&num1,&num2)>0){
	
		count++;
	}
	
	count = count * 2;
	rewind(myFile);
	int numberArray[count];

	for (i = 0; i < count; i+=2)
    	{
        	fscanf(myFile, "%d,%d;", &numberArray[i],&numberArray[i+1] );
    
    	}
   
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

	if(sizeof(numberArray)/sizeof(int) <= 2){

		printf("0 \n");
	}

    	//Subtraction between odd number of each pair
    	for (i=0; i < (sizeof(numberArray)/sizeof(int) - 2 ); i+=2){
		sub = numberArray[i+3] - numberArray[i+1];

		printf("%d\n",sub);
   	 }
    fclose(myFile);

    return 0;
}
