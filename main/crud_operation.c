#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "..\headers\utility.h"

#define Max_Contacts 100 // Maximum contacts in the directory.

struct contact
{
    long contactId;
    char name[30];
    char contactNumber[30];
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
    name:
        fflush(stdin);
        printf("Enter the name: ");
        gets(newContact.name);

        if (!isValidName(newContact.name))
        {
            printf("Please enter valid name. Name must be between (2-25 )character.\n");
            goto name;
        }
    contact:
        printf("Enter contact number: ");
        gets(newContact.contactNumber);
        if (!isValidContactNumber(newContact.contactNumber))
        {
            printf("Please enter valid contact number. Contact number must be (10 digits only) and start from(6-9).\n");
            goto contact;
        }

    address:
        printf("Enter the address: ");
        gets(newContact.address);
        if (!isValidAddress(newContact.address))
        {
            printf("\nPlease enter a valid address.\n");
            goto address;
        }

        newContact.contactId = getTimestamp();

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
            printf("\nContact Id: %ld", directory[i].contactId);
            printf("\nName: %s", directory[i].name);
            printf("\nContact No: %s", directory[i].contactNumber);
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
        printf("\nNo contacts in the directory to update.\n");
    }
    else
    {
        char contactNum[20];
        fflush(stdin);
        printf("Enter the contact number to update the existing contact: ");
        gets(contactNum);
        int found = 0;
        for (int i = 0; i < countContact; i++)
        {
            if (strcmp(directory[i].contactNumber, contactNum) == 0)
            {
            againA:
                fflush(stdin);
                printf("Enter new name: ");
                gets(directory[i].name);
                if (!isValidName(directory[i].name))
                {
                    printf("Please enter valid name. Name must be between (2-25 )character.\n");
                    goto againA;
                }
            contactA:
                fflush(stdin);
                printf("Enter new contact number: ");
                gets(directory[i].contactNumber);
                if (!isValidContactNumber(directory[i].contactNumber))
                {
                    printf("Please enter valid contact number. Contact number must be (10 digits only) and start from(6-9).\n");
                    goto contactA;
                }
            addressA:
                fflush(stdin);
                printf("Enter new address: ");
                gets(directory[i].address);
                if (!isValidAddress(directory[i].address))
                {
                    printf("\nPlease enter a valid address.\n");
                    goto addressA;
                }
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
        char contactNum[10], i, j;
        fflush(stdin);
        printf("Enter the contact number which you want to delete :");
        gets(contactNum);
        for (i = 0; i < countContact; i++)
        {
            if (strcmp(directory[i].contactNumber, contactNum) == 0)
            {
                for (j = i; j < countContact - 1; j++)
                {
                    directory[i] = directory[j + 1];
                }
                countContact--;
                printf("\nContact deleted successfully.\n");
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
