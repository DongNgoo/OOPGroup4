/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Dong Ngo
Student ID#: 129342233
Email      : dngo13@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H
#define FMT 20
#define PHONE_LENGTH 10

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

#define STRING_LEN 2000
// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//should not assume a valid C string array, and therefore, should carefully validate the
//argument char array to determine :
//it is exactly 10 characters long
//only contains digits(0 - 9)
void displayFormattedPhone(const char* validPhoneCharacter);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//Validate integer input
int inputInt(void);

//perform the same operations as inputInt but validates the value entered is greater than 0.
// display an error message if the value is a zero or less(review the sample output for 
// the appropriate error message).
int inputIntPositive(void);

//performs the same operations as inputInt but validates the value entered is between the 
// two arguments received by the function(inclusive).
int inputIntRange(int lowerLimit, int upperLimit);

//get a single character value from the keyboard, validate the entered character matches
//  any of the characters in the received C string argument.
char inputCharOption(const char validCharacter[]);

//must validate the entered number of characters is within the specified range. If not,
//  display an error message(review the sample output for the appropriate error message).
void inputCString(char* validString, int minimumChar, int maxChar);

//this function use to get the phone input from the patient
void inputPhoneNumber(char* validPhoneNumber, int minimumChar, int maxChar);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
