/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Dong Ngo
Student ID#: 129342233
Email      : dngo13@myseneca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "core.h"



//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// This function receive a cstring to check these requirements below and display it in phone format
//it is exactly 10 characters long
//only contains digits(0 - 9)
void displayFormattedPhone(const char* validPhoneCharacter)
{
    int i, count = 0;

    if (validPhoneCharacter != NULL)
    {

        for (i = 0; validPhoneCharacter[i] != '\0'; i++)
        {

            if (isdigit(validPhoneCharacter[i]))
            {
                count++;
            }

        }
        if (count != PHONE_LENGTH)
        {
            printf("(___)___-____");
        }
        else if (count == PHONE_LENGTH)
        {
            printf("(%.3s)%.3s-%.4s", &validPhoneCharacter[0],
                &validPhoneCharacter[3], &validPhoneCharacter[6]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
//Validate integer input
int inputInt(void) {
    int inputValue;
    char newLineChar = 'x';

    while (newLineChar != '\n')
    {
        scanf("%d%c", &inputValue, &newLineChar);
        if (newLineChar != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");

        }
    }
    return inputValue;

}

//perform the same operations as inputInt but validates the value entered is greater than 0.
// display an error message if the value is a zero or less(review the sample output for the appropriate error message).
int inputIntPositive(void)
{
    int inputPositiveValue, validNegative = 0;

    while (!validNegative)
    {
        inputPositiveValue = inputInt();

        if (inputPositiveValue <= 0)
        {
            printf("ERROR! Value must be > 0: ");

            validNegative = 0;
        }
        else if (inputPositiveValue > 0)
        {
            validNegative = 1;
        }
    }
    return inputPositiveValue;
}
//performs the same operations as inputInt but validates the value entered is between the two arguments received by the function(inclusive).
int inputIntRange(int lowerLimit, int upperLimit)
{
    int inputRangeValue = 0, validRange = 0;
    while (!validRange)
    {
        inputRangeValue = inputInt();
        if (inputRangeValue < lowerLimit || inputRangeValue > upperLimit)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerLimit, upperLimit);
            validRange = 0;
        }
        else if (inputRangeValue >= lowerLimit || inputRangeValue <= upperLimit)
        {
            validRange = 1;
        }
    }
    return inputRangeValue;
}
//get a single character value from the keyboard, validate the entered character matches any of the characters in the received C string argument.
char inputCharOption(const char validCharacter[])
{
    char inputValidCharacter, line = 'x';
    int validChar = 0;
    
    do
    {
        scanf("%c%c", &inputValidCharacter, &line);
       
        
        validChar = 1;
        if (strchr(validCharacter, inputValidCharacter) == NULL || line != '\n')
        {
            validChar = 0;
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", validCharacter);
        }
        
    } while (!validChar);
    
    return inputValidCharacter;
}
//this function must validate the entered number of characters is within the specified range. If not, display an error message(review the sample output for the appropriate error message).
void inputCString(char* validString, int minimumChar, int maxChar)
{
    char validStringFormat[FMT + 1] = { 0 };
    char inputValidString[STRING_LEN + 1] = { 0 };
    int count = 0, invalidString = 0;

    do 
    {
        //scanf 2000
        sprintf(validStringFormat, "%%%d[^\n]", STRING_LEN);
        scanf(validStringFormat, inputValidString);
        
        clearInputBuffer();

        count = strlen(inputValidString);


        if (count >= minimumChar && count <= maxChar)
        {
            invalidString = 1;
        }
        else
        {
            if (minimumChar == maxChar)
            {
                printf("ERROR: String length must be exactly %d chars: ", maxChar);
            }
            else
            {

                if (count > maxChar)

                {
                    printf("ERROR: String length must be no more than %d chars: ", maxChar);
                }

                else if (count < minimumChar)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", minimumChar, maxChar);
                }

            }
            count = 0;
        }

    } while (!invalidString);

    strcpy(validString, inputValidString);
}
// get user phone number input
void inputPhoneNumber(char* validPhoneNumber, int minimumChar, int maxChar)
{
    char validStringFormat[FMT + 1] = { 0 };
    char inputValidString[STRING_LEN + 1] = { 0 };
    int count = 0, invalidString = 1;

    do
    {
        if (!invalidString)
        {
            
            printf("Number: ");
        }
        else
        {
            printf("Number : ");
        }
        sprintf(validStringFormat, "%%%d[^\n]", STRING_LEN);
        scanf(validStringFormat, inputValidString);

        clearInputBuffer();

        count = strlen(inputValidString);


        if (count >= minimumChar && count <= maxChar)
        {
            invalidString = 1;
        }
        else
        {
            printf("Invalid 10-digit number! ");
            invalidString = 0;
            count = 0;
        }

    } while (!invalidString);

    strcpy(validPhoneNumber, inputValidString);
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

