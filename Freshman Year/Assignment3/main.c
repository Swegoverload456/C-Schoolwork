#include<stdio.h>
#include<stdlib.h>
//Juan Velasquez 3/29/2021
main()
{
	/*Initialzation of variables.
	This is creating the array and giving the space to store
	50 integers.*/
	int data[50];
	/*This variable is going to be set to 1 when the user inputs
	-999 to leave the stage of the for loop where it asks for
	user inputs and just finished looping through without doing
	anything. Essentially just acting like a break for a for loop.*/
	int done = 0;
	/*This variable is going to be used for tracking how many 
	inputs the user has put into the array. It defaults to the 
	maximum 50 and will only be overwritten if the user inputs a 
	-999.*/
	int total = 50;
	/*This for loop is used for asking the user for inputs, 1 
	by 1, and then waiting until they either reach the maximum
	limit of 50 indicies or enter -999.*/
	for (int i = 0; i < 50; i++) {\
		/*This if statement is used to check if the user has 
		inputted -999 via the done variable.*/
		if (done != 1) {
			//This if statement only runs on the first loop.
			if (i == 0) {
				printf("\nPlease Enter the First Number: ");
				scanf_s("%i", &data[i]);
			}
			/*Slightly different than the if, runs every loop
			after the first.*/
			else {
				printf("\nPlease Enter the Next Number: ");
				scanf_s("%i", &data[i]);
			}
			/*Checks if the latest user input was equal to 
			-999 if so, set the done variable to 1 and 
			overwrite the total variable to equal i.*/
			if (data[i] == -999) {
				done = 1;
				total = i;
			}
		}
	}
	/*This for loop will print out the array according to how
	many indicies the user has populated by using the total 
	variable*/
	for (int i = 1; i < total+1; i++) {
		printf("\n%i. %i", i, data[i-1]);
	}
	//Quit the program
	return 0;
}
