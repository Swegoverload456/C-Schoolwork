/*
Student Name: Juan Velasquez
Date Written: 9/6/2021
Purpose of program: 
*/
#include <stdio.h>
//Function Declarations
int getLen(char str[]);
void forward(char str[]);
void backward(char str[], int len);
void vertical(char str[], int len); 
void triangle(char str[], int len);
void printLen(int len);
/*
    
*/
int getLen(char str[]){
    int out = 0;
    for(int i = 0; str[i]!='\0'; i++){
        out++;
    }
    return out;
}
/*
    
*/
void forward(char str[]){
    printf("\nForward: ");
    printf("\n%s", str);
}
/*
    
*/
void backward(char str[], int len){
    printf("\nBackward: ");
    printf("\n");
    for(int i = len; i >= 0; i--){
        printf("%c", str[i]);
    }
}
/*
    
*/
void vertical(char str[], int len){
    printf("\nVertical: ");
    for(int i = 0; i < len; i++){
        printf("\n%c", str[i]);
    }
}
/*

*/
void triangle(char str[], int len){
    printf("\nTriangle: ");
    int rows = 2;
    int total = 1;
    int prev = 2;
    while(1){
        total = total + prev;
        if(total + prev < len){
            rows++;
            prev++;
        }
        else{
            break;
        } 
    }
    int remainder = len - total;
    int cols[rows];
    for(int i = 0; i < rows; i++){
        cols[i] = i+1;
    }
    for(int i = 0; i < remainder; i++){
        cols[rows-i-1]++;
    }
    total = 0;
    for(int i = 0; i < rows; i++){
        printf("\n");
        for(int j = 0; j < cols[i]; j++){
            printf("%c", str[total]);
            total++;
        }
    }

}
/*

*/
void printLen(int len){
    printf("\nThe string is %d characters long.", len);
}
//The main function that the program runs.
int main(void){
    //Variable to store the user input.
    char input[100];
    int length = 0;
    //Print out asking what string the user wants.
    printf("\nPlease enter the string that you want to use (No longer than 100 letters): ");
    /*
    Scan the terminal for the next integer that the user inputs and set it equal to 
    the input variable.
    */
    char option = 'z';
    do{
        scanf("%s", input);
        length = getLen(input);
        forward(input);
        backward(input, length);
        vertical(input, length);
        triangle(input, length);
        printLen(length);
        printf("\nWould you like to enter another string?");
        printf("\nEnter Y/y if you do or enter Q/q if you want to quit.");
        scanf("%c", option);
    }
    while(option != 'q' || option != 'Q');
    //Exit program.
    return 0;
}