#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MIN_NAME_LENGTH 2

#define CONTACT_NUMBER_LENGTH 10

#define MAX_ADDRESS_LENGTH 35
#define MIN_ADDRESS_LENGTH 5

bool isValidName(char name[])
{
    if (strlen(name) < MAX_NAME_LENGTH && strlen(name) > MIN_NAME_LENGTH)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidContactNumber(char contactNumber[])
{
    if (strlen(contactNumber) == CONTACT_NUMBER_LENGTH)
    {
        if (contactNumber[0] == '6' || contactNumber[0] == '7' || contactNumber[0] == '8' || contactNumber[0] == '9')
        {
            for (int i = 1; i < strlen(contactNumber); i++)
            {
                if (contactNumber[i] == '0' || contactNumber[i] == '1' || contactNumber[i] == '2' || contactNumber[i] == '3' || contactNumber[i] == '4' || contactNumber[i] == '5' || contactNumber[i] == '6' || contactNumber[i] == '7' || contactNumber[i] == '8' || contactNumber[i] == '9')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isValidAddress(char address[])
{
    if (strlen(address) >= MIN_ADDRESS_LENGTH && strlen(address) <= MAX_ADDRESS_LENGTH)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long getTimestamp()
{
    time_t millis;
    millis = time(NULL);
    return millis;
}