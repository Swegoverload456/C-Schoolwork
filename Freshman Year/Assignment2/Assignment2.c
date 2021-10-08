#include<stdio.h>
#include<stdlib.h>
//Main function that is run by the compiler by default.
main()
{
	//Initlization of Variables
	//A variable counter that will be set to the input of the user to the with respect to each coin value.
	int pennies, nickels, dimes, quarters;
	//This variable is going to store the total monetary value of all the coins added together.
	double total = 0;
	//This line is going to print a question to the user asking how many pennies they have.
	printf("How many pennies do you have?\n");
	//This line is taking the next integer that the user inputs through the console and setting the value of pennies to it.
	scanf_s("%i", &pennies);
	//This line is going to print the integer that the user inputted for the amount of pennies.
	printf("\nYou entered %i", pennies);
	//This line is going to print a question to the user asking how many nickels they have.
	printf("\nHow many nickels do you have?");
	//This line is taking the next integer that the user inputs through the console and setting the value of nickels to it.
	scanf_s("%i", &nickels);
	//This line is going to print the integer that the user inputted for the amount of nickels.
	printf("\nYou entered %i", nickels);
	//This line is going to print a question to the user asking how many dimes they have.
	printf("\nHow many dimes do you have?");
	//This line is taking the next integer that the user inputs through the console and setting the value of dimes to it.
	scanf_s("%i", &dimes);
	//This line is going to print the integer that the user inputted for the amount of dimes.
	printf("\nYou entered %i", dimes);
	//This line is going to print a question to the user asking how many quarter they have.
	printf("\nHow many quarters do you have?");
	//This line is taking the next integer that the user inputs through the console and setting the value of quarters to it.
	scanf_s("%i", &quarters);
	//This line is going to print the integer that the user inputted for the amount of quarters.
	printf("\nYou entered %i", quarters);
	//This line is going to do the math for calculating the total amount of money all the coins the user inputted add up to.
	total = (pennies * 0.01) + (nickels * 0.05) + (dimes * 0.1) + (quarters * 0.25);
	//This line prints the value that was just calculated above for the variable total.
	printf("\nYou have $%.2lf", total);
	//This line prints thank you to the user before closing the program
	printf("\nThank you.");
	//This line breaks out of the main method, leading the closing of the program as there is no code left to run.
	return 0;
}