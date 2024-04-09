#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "..\headers\utility.h"

#define Max_Contacts 100 // Maximum contacts in the directory.

struct contact
{
    char name[30];
    char telephone[30];
    char address[70];
};

struct contact directory[Max_Contacts];
int countContact = 0;

// Function for adding contacts in the directory.
bool addContact()
{
    if (countContact < Max_Contacts)
    {
        struct contact newContact;

        printf("Enter the name: ");
        scanf("%s", newContact.name);
        if (!isValidName(newContact.name))
        {
            printf("Please enter valid name.");
            return false;
        }

        printf("Enter telephone number: ");
        scanf(" %s", newContact.telephone);
        if (!isValidContactNumber(newContact.telephone))
        {
            printf("Please enter valid telephonr number.");
            return false;
        }

        printf("Enter the address: ");
        scanf("%s", newContact.address);

        directory[countContact] = newContact;
        countContact++;

        printf("\nContact added successfully.");
        return true;
    }
    else
    {
        printf("Directory is already full, contact can't be add.");
        return false;
    }
}

// Function for showing existing contacts of the directory.
void showContact()
{
    int i;
    if (countContact == 0)
        printf("\nNo contacts in the dierctory.");
    else
    {
        printf("Contacts in the directory: \n");
        for (i = 0; i < countContact; i++)
        {
            printf("\nContact %d", i + 1);
            printf("\nName: %s", directory[i].name);
            printf("\nTelephone No: %s", directory[i].telephone);
            printf("\nAddress: %s", directory[i].address);
            printf("\n");
        }
    }
}

// function for updating the existing contacts of the directory.
void updateContact()
{
    if (countContact == 0)
    {
        printf("\nNo contacts in the directory to update.");
    }
    else
    {
        char name[30];
        printf("Enter the name to update the existing contact: ");
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < countContact; i++)
        {
            if (strcmp(directory[i].name, name) == 0)
            {
                printf("Enter new name: ");
                scanf("%s", directory[i].name);
                printf("\nEnter new telephone number: ");
                scanf("%s", directory[i].telephone);
                printf("Enter new address: ");
                scanf("%s", directory[i].address);
                printf("\nContact updated successfully.");
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            puts("\nContact not found.");
        }
    }
}

// Function for deleting  the existing contact.
void deleteContact()
{
    int found = 0;
    if (countContact == 0)
    {
        printf("\nNo contacts in the dierctory.");
    }
    else
    {
        char name[30], i, j;
        printf("Enter the name to delete the existing contact: ");
        scanf("%s", name);
        for (i = 0; i < countContact; i++)
        {
            if (strcmp(directory[i].name, name) == 0)
            {
                for (j = i; j < countContact - 1; j++)
                {
                    directory[i] = directory[j + 1];
                }
                countContact--;
                printf("\nContact deleted successfully.");
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("\nContact not found.");
        }
    }
}

// S.O.L.I.D
// S -> Single Resposibility -> Every method should posses only single resposibility