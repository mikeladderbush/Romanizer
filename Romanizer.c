#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *romanize(int number)
{
    char *romanNumber = (char *)malloc(15 * sizeof(char));
    romanNumber[0] = "\0";
    char *thousandStr = "";
    char *hundredStr = "";
    char *tenStr = "";
    char *oneStr = "";

    int thousands = 0;
    int hundreds = 0;
    int tens = 0;
    int ones = 0;

    while (number >= 1000)
    {
        number -= 1000;
        thousands += 1;
    }
    while (number >= 100)
    {
        number -= 100;
        hundreds += 1;
    }
    while (number >= 10)
    {
        number -= 10;
        tens += 1;
    }
    while (number >= 1)
    {
        number -= 1;
        ones += 1;
    }

    switch (thousands)
    {
    case 0:
        break;
    case 1:
        thousandStr = "M\0";
        break;
    case 2:
        thousandStr = "MM\0";
        break;
    case 3:
        thousandStr = "MMM\0";
        break;
    }

    switch (hundreds)
    {
    case 0:
        break;
    case 1:
        hundredStr = "C\0";
        break;
    case 2:
        hundredStr = "CC\0";
        break;
    case 3:
        hundredStr = "CCC\0";
        break;
    case 4:
        hundredStr = "CD\0";
        break;
    case 5:
        hundredStr = "D\0";
        break;
    case 6:
        hundredStr = "DC\0";
        break;
    case 7:
        hundredStr = "DCC\0";
        break;
    case 8:
        hundredStr = "DCCC\0";
        break;
    case 9:
        hundredStr = "CM\0";
        break;
    }

    switch (tens)
    {
    case 0:
        break;
    case 1:
        tenStr = "X\0";
        break;
    case 2:
        tenStr = "XX\0";
        break;
    case 3:
        tenStr = "XXX\0";
        break;
    case 4:
        tenStr = "XL\0";
        break;
    case 5:
        tenStr = "L\0";
        break;
    case 6:
        tenStr = "LX\0";
        break;
    case 7:
        tenStr = "LXX\0";
        break;
    case 8:
        tenStr = "LXXX\0";
        break;
    case 9:
        tenStr = "XC\0";
        break;
    }

    switch (ones)
    {
    case 0:
        break;
    case 1:
        oneStr = "I\0";
        break;
    case 2:
        oneStr = "II\0";
        break;
    case 3:
        oneStr = "III\0";
        break;
    case 4:
        oneStr = "IV\0";
        break;
    case 5:
        oneStr = "V\0";
        break;
    case 6:
        oneStr = "VI\0";
        break;
    case 7:
        oneStr = "VII\0";
        break;
    case 8:
        oneStr = "VIII\0";
        break;
    case 9:
        oneStr = "IX\0";
        break;
    }

    strcat(romanNumber, thousandStr);
    strcat(romanNumber, hundredStr);
    strcat(romanNumber, tenStr);
    strcat(romanNumber, oneStr);

    return romanNumber;
}

int main()
{
    for (int i = 0; i < 4000; i++)
    {
        char *romanString = romanize(i);
        printf("%s\n", romanString);
        free(romanString);
    }
    return 0;
}
