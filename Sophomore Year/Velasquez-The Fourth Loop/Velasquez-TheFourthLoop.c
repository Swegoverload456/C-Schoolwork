/*
Student Name: Juan Velasquez
Date Written: 8/24/2021
Purpose of program: Take in a user inputted number and determine whether the number is a 
prime number without using while, do while, for or goto loops. My solution involves 
recursion that I personally came up with as a workaround for not being able to use loops, 
however, it is not optimized for computational efficiency.
*/
#include <stdio.h>
//Function Declarations
int iterate(int num, int validate, int iteration);
int isPrime(int num);
/*
    Iterate function will recursively loop through all possible numbers that the 
    input number could be divied by until it reaches itself. iteration.e if the user input 
    is 5, it will try to divide 5 by 2,3 and 4 and if none of those numbers cleanly 
    divide into 5 with a remainder of 0, then it is a prime. If it can be divided 
    by any of the numbers that come before it excluding 1, then it is not a prime 
    and the recursive loop will break.
*/
int iterate(int num, int validate, int iteration){
    /*
    This if statement checks if the iteration tracker has reached the input number-1, 
    if so, it will stop the recursion and return true(Is a prime).
    */
    if(iteration < num){
        /*
        This is setting the validation variable equal to the remainder of the input 
        number divided by the current iteration number.
        */
        validate = num % iteration;
        /*
        This if statement checks if the remainder of the input number divded by iteration 
        is equal to 0, if so, then we have confirmed that the input number is not a prime 
        and we can return false.
        */
        if(validate == 0){
            return 0;
        }
        /*
        If the remainder is not 0, then we are going to add 1 to iteration and recursively 
        run iterate() again with the new values for the validate and iteration variables.
        */
        else{
            iteration++;
            iterate(num, validate, iteration);
        }
    }
    /*
    If it reaches this point, then the input number is confirmed to be a prime number 
    and we can return true.
    */
    else{
        return 1;
    }  
}
/*
This is the primary function that is run to check if the number is a prime or not. 
It does basic things like filter out 2 and 3 immediately and runs an initial check 
on the input number to see if it is divisible by 2 or 3, which if it is, then it is not a 
prime and there is no need to go any further.
*/
int isPrime(int num){
    //Check if the input number is not equal to 2 or 3 before going any further.
    if(num != 2 && num != 3){
        //Check if the input number is divisible by 2 or 3, if so, return false.
        if(num % 2 == 0 || num % 3 == 0){
            return 0;
        }
        //If not, then return whatever the output of the iterate() function returns.
        else{
            return iterate(num, 1, 2);
        }
    }
    //Check if the number is less than 2, if so it is not a prime number.
    else if(num < 2){
        return 0;
    }
    //If the input number is equal to 2 or 3, then return true as those are prime numbers.
    else{
        return 1;
    }
}
//The main function that the program runs.
int main(void){
    //Variable to store the user input.
    int input;
    //Print out asking what number the user wants.
    printf_s("\nPlease enter a number between 2 and 2137383647: ");
    /*
    Scan the terminal for the next integer that the user inputs and set it equal to 
    the input variable.
    */
    scanf("%d", &input);
    /*
    Make a variable for the result of the calculation and set it equal to the output 
    of the isPrime() function when you input the user-inputted number.
    */
    int result = isPrime(input);
    //If result is equal to 0 or false, print the input number is not a prime.
    if(result == 0){
        printf_s("\nThe number %d is NOT a prime number.", input);
    }
    //If result is equal to 1, then print that the input number is a prime.
    else if (result == 1){
        printf_s("\nThe number %d is a prime number.", input);
    }
    //Exit program.
    return 0;
}
