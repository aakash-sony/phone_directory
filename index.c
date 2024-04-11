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
        if (contactAdded == false)
        {
            addContact();
        }
        else
        {
            oneMoreChance();
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
