/*
Student Name: Juan Velasquez
Date Written: 9/1/2021
Purpose of program: Take in a user inputted character to run a menu-based
program that keeps track of scores for the user's and opponent's team and
manipulates them using a 2D array a way of storing the user inputted
scores.
*/
#include <stdio.h>
#include <stdlib.h>
//Function Prototypes
char getUserChoice();
void displayMenu();
int menuA(int size, int s[][2]);
int getWins(int size, int s[][2]);
int getLosses(int size, int s[][2]);
int getTies(int size, int s[][2]);
void menuB(int size, int s[][2]);
void menuC(int size, int s[][2]);
void menuD(int size, int s[][2]);
void menuE();
/*
    This function prints out what the menu options are.
*/
void displayMenu(){
    printf("\n***********************************************");
    printf("\n**          Game score tracker menu          **");
    printf("\n***********************************************");
    printf("\nA) Enter game results");
    printf("\nB) Display Current Record");
    printf("\nC) Display results from games won");
    printf("\nD) Display all results");
    printf("\nE) Quit");
    printf("\n\nEnter choice: ");
}
/*
    This function runs displayMenu() and then scans for the next user-inputted
    character and returns it.
*/
char getUserChoice(){
    displayMenu();
    char temp;
    scanf("%c", &temp);
    return temp;
}
/*
    This function is for the menu option A. It takes in a parameter for the
    number of rows in the 2D array and then takes in the 2D array with 2 columns.
    It asks the user for their team's score and sets it equal to first column in
    in the row 'size' (a number) and then asks for the opponent's score and sets
    it to the second column. It then increments size by 1 and returns size to it
    can be saved to keep track of how many rows are in the 2D array.
*/
int menuA(int size, int s[][2]){
    printf("\nEnter your team's score....: ");
    scanf("%d", &s[size][0]);
    printf("\nEnter your opponent's score: ");
    scanf("%d", &s[size][1]);
    size+=1;
    return size;
}
/*
    This function calculates how many wins the user has. It takes in size and the
    2D array and output an int for number of wins. It loops through the rows and
    adds one to the win counter if the user score is bigger than the oppponent's
    score in that specific row. Then it returns the win counter.
*/
int getWins(int size, int s[][2]){
    int out = 0;
    for(int i = 0; i < size; i++){
        if(s[i][0] > s[i][1]){
            out++;
        }
    }
    return out;
}
/*
    This function calculates how many losses the user has. It takes in size and the
    2D array and output an int for number of losses. It loops through the rows and
    adds one to the loss counter if the user score is less than the oppponent's
    score in that specific row. Then it returns the loss counter.
*/
int getLosses(int size, int s[][2]){
    int out = 0;
    for(int i = 0; i < size; i++){
        if(s[i][0] < s[i][1]){
            out++;
        }
    }
    return out;
}
/*
    This function calculates how many ties the user has. It takes in size and the
    2D array and output an int for number of ties. It loops through the rows and
    adds one to the tie counter if the user score is equal to the oppponent's
    score in that specific row. Then it returns the tie counter.
*/
int getTies(int size, int s[][2]){
    int out = 0;
    for(int i = 0; i < size; i++){
        if(s[i][0] == s[i][1]){
            out++;
        }
    }
    return out;
}
/*
    This function is for the menu option B. It takes in a parameter for the
    number of rows in the 2D array and then takes in the 2D array with 2 columns.
    It prints out how many wins, losses and ties the user has at the time by
    calling the getWins(), getLosses(), and getTies functions respectively and
    printing their outputs. It the calculates the user and opponent's total points
    by looping through the rows of the 2D array and adding the current user score
    the user total and the current opponent score to the counter. It then prints 
    the totals.
*/
void menuB(int size, int s[][2]){
    printf("\n=========================================");
    printf("\n==           Current Record            ==");
    printf("\n=========================================");
    printf("\n      WINS..: %d", getWins(size, s));
    printf("\n      LOSSES: %d", getLosses(size, s));
    printf("\n      TIES..: %d", getTies(size, s));
    int userT = 0;
    int oppT = 0;
    for(int i = 0; i < size; i++){
        userT += s[i][0];
        oppT += s[i][1];
    }
    printf("\n      (Points for....: %d)", userT);
    printf("\n      (Points against: %d)", oppT);
    printf("\n=========================================");
}
/*
    This function is for the menu option C. It takes in a parameter for the
    number of rows in the 2D array and then takes in the 2D array with 2 columns.
    It prints the exact scores of the user's winning games. To do this, it loops
    through the 2D array and checking if the user's score from that row is bigger
    than the opponent's score from that row, if so, then you print the scores.
*/
void menuC(int size, int s[][2]){
    printf("\n=========================================");
    printf("\n==         Score from Games Won        ==");
    printf("\n=========================================");
    printf("\n      My Score          Their Score      ");
    printf("\n      --------          -----------      ");
    for(int i = 0; i < size; i++){
        if(s[i][0] > s[i][1]){
            printf("\n      %d\t\t%d", s[i][0], s[i][1]);
        }
    }
    
}
/*
    This function is for the menu option D. It takes in a parameter for the
    number of rows in the 2D array and then takes in the 2D array with 2 columns.
    It prints the exact scores of all of the games. It does this by looping
    through the 2D array and printing the user values and opponent values in each
    row.
*/
void menuD(int size, int s[][2]){
    printf("\n=========================================");
    printf("\n==    Results from all games played    ==");
    printf("\n=========================================");
    printf("\n      My Score          Their Score      ");
    printf("\n      --------          -----------      ");
    for(int i = 0; i < size; i++){
        printf("\n      %d\t\t%d", s[i][0], s[i][1]);
    }
}
/*
    This function is for the menu option E. It prints goodbye for the user.
*/
void menuE(){
    printf("\nGood Bye!");
}
int main(void){
    //This tracks the size of how many rows there are in the 2D array.
    int size = 0;
    //This 2D array has 2 columns and is used to store the scores of the matches.
    int scores[][2] = {0};
    //This is used to track the user input through the menu.
    char selection;
    /*
        This do while is used for the menu system and will run in the do{} until
        the user inputs 'E' to quit out of the program.
    */
    do{
        //We set the selection variable to the output of getUserChoice.
        selection = getUserChoice();
        /*
            This swich case statement is used to run the menu option chosen by 
            the user.
        */
        switch(selection){
            //Choice A
            case 'A':
                /*
                    Set size equal the output of menuA so we can keep track 
                    of how many rows are in the 2D array.
                */
                size = menuA(size,scores);
                break;
            //Choice B
            case 'B':
                //Run the menuB() function.
                menuB(size, scores);
                break;
            //Choice C
            case 'C':
                //Run the menuC() function.
                menuC(size, scores);
                break;
            //Choice D
            case 'D':
                //Run the menuD() function.
                menuD(size, scores);
                break;
            //Default incase the user inputs something that isn't an option.
            default:
                system("pause");
                break;

        }
    }
    //The condition making sure that the program loops until the user inputs 'E'.
    while(selection != 'E');
    //Run the menuE() function.
    menuE();
    //Quit the program.
    return 0;
}