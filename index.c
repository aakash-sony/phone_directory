#include <stdio.h>
#include <stdbool.h>
#include ".\headers\crud.h"

// Function declaration for the program.
void showMenu();
void choiceSelection();
void oneMoreChance();
void system();

void main()
{
    showMenu();
    choiceSelection();
}

// Function for showing main menu.
void showMenu()
{
    printf("**************Welcome to Telephone Directory**************\n\n");

    printf("1.  Add Contacts\n");
    printf("2.  Show Contacts\n");
    printf("3.  Update Contacts\n");
    printf("4.  Delete Contacts\n");
    printf("5.  Exit");
}

void choiceSelection()
{
    int ch;
again:
    printf("\nChoose any option:  ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
    {
        bool contactAdded = addContact();
        if (contactAdded)
        {
            oneMoreChance();
        }
        else{
            addContact();
        }
        break;
    }
    case 2:
        showContact();
        oneMoreChance();
        break;
    case 3:
        updateContact();
        oneMoreChance();
        break;
    case 4:
        deleteContact();
        oneMoreChance();
        break;
    case 5:
        printf("Thank you! good bye....");
        return;
    default:
        printf("\nInvalid option! Enter the correct option.\n\n");
        showMenu();
        goto again;
    }
}

// Function for giving another chance to user.
void oneMoreChance()
{
    char c;
    printf("\n\nDo you want to go to main menu(Press y/n)?:  ");
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y')
    {
        system("cls");
        showMenu();
        choiceSelection();
    }
    else
    {
        printf("Thank you....");
        return;
    }
}

// Add Validation on Name, Contact Number and Address
// When saving name, generate get current timestamp and save as unique contact id
//  Update or Delete contact by Contact Number
// Check if I am trying to add any contact with duplicate contact number, show messsage as already exist
//  Contact Number Validation: 10 Digit | All numbers only | Number could lie between 0-9
// Name Validation: 2-25 character(if going more than 25, show error message as only 25 character allowed, less than zero show error as invalid name)
// Address Validation: 5-35 character otherwise show error
