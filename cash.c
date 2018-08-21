#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cash;
    int i = 0;   // number of coins

    do
    {
        cash = get_float("Change in dollars: ");
    }
    while (cash < 0);

    // convert to integer
    int n = round(cash * 100);

    // 25 cent's coins
    while (n >= 25)
    {
        i++;
        n -= 25;
    }

    // 10 cent's coins
    while (n >= 10)
    {
        i++;
        n -= 10;
    }

    //5 cent's coins
    while (n >= 5)
    {
        i++;
        n -= 5;
    }

    // 1 cent's coins
    while (n >= 1)
    {
        i++;
        n -= 1;
    }

    printf("%i\n", i);
}