#include <cs50.h>
#include <stdio.h>
#include <math.h>



int addTensAndUnits(int num)
{
    int tens = 0;
    int units = 0;

    tens = num / 10;
    units = num % 10;

    return tens + units;
}

int checkAmericanExpress(long num)
{

    // American Express uses 15-digit numbers
    // All American Express numbers start with 34 or 37;

    int startNum = 0;
    startNum = num / pow(10, 13);

    if (startNum == 34 || startNum == 37)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int checkMasterCard(long num)
{

    // MasterCard uses 16-digit numbers
    // most MasterCard numbers start with 51, 52, 53, 54, or 55
    // (they also have some other potential starting numbers
    // which we won’t concern ourselves with for this problem);

    int startNum = 0;
    startNum = num / pow(10, 14);

    if (startNum == 51 || startNum == 52 || startNum == 53 || startNum == 54 || startNum == 55)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int checkVisa(long num)
{

    // Visa uses 13- and 16-digit numbers
    // Visa numbers start with 4

    int startNum1 = 0;
    int startNum2 = 0;
    startNum1 = num / pow(10, 12);
    startNum2 = num / pow(10, 15);

    if (startNum1 == 4 || startNum2 == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int LuhnAlgorithm(long num)
{

    int oddOrEvenDigit = 1;
    int currentNum = 0;
    int total = 0;

    while (num > 0)
    {
        // get current unit
        currentNum = num % 10;

        if (oddOrEvenDigit == 1)
        {

            total += currentNum;
            oddOrEvenDigit = 2;

        }
        else
        {

            total += addTensAndUnits(currentNum * 2);
            oddOrEvenDigit = 1;
        }
        num = num / 10;
    };


    // check modulo 10
    if (total % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(void)
{
    long num = get_long("Credti Card Number: \n");

    // first with algorithm
    if (LuhnAlgorithm(num))
    {

        // then by each company
        if (checkAmericanExpress(num))
        {
            printf("AMEX\n");

        }
        else if (checkMasterCard(num))
        {
            printf("MASTERCARD\n");

        }
        else if (checkVisa(num))
        {
            printf("VISA\n");

        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}