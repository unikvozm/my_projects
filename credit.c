#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long cc_number, x;

    //asking for a credit card number
    do
    {
        cc_number = get_long_long("Credit card number: ");
    }
    while (cc_number < 0);

    if (cc_number < 4000000000000 || (cc_number >= 50000000000000 && cc_number < 340000000000000) || (cc_number >= 350000000000000 && cc_number < 370000000000000) || (cc_number >= 380000000000000 && cc_number < 4000000000000000) || (cc_number >= 5000000000000000 && cc_number < 5100000000000000) || cc_number >= 5600000000000000)
    {
        printf("INVALID\n");
    }
    else
    {
        //checking validity - counting sums
        int sum1 = 0;
        int sum2 = 0;
        x = cc_number;
        int y1, y2;

        while (x > 0)
        {
            y1 = x % 10;
            sum1 += y1;
            x = (x - y1) / 10;

            y2 = x % 10;
            if (y2 * 2 < 10)
            {
                sum2 += y2 * 2;
            }
            else
            {
                sum2 += (((y2 * 2) % 10) + ((y2 * 2 - ((y2 * 2) % 10)) / 10));
            }
            x = (x - y2) / 10;
        }
        //checking sums
        if ((sum1 + sum2) % 10 == 0)
        {
            //checking company
            if ((cc_number >= 340000000000000 && cc_number < 350000000000000) || (cc_number >= 370000000000000 && cc_number < 380000000000000))
            {
                printf("AMEX\n");
            }
            if (cc_number >= 5100000000000000 && cc_number < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }
            if ((cc_number >= 4000000000000 && cc_number < 5000000000000) || (cc_number >= 4000000000000000 && cc_number < 5000000000000000))
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}