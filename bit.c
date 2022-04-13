#include <stdio.h>
#include <math.h>

int dec_bin(int nbr)
{
    int binary = 0;
    int mod, temp = 1;

    while (nbr != 0)
    {
        mod = nbr % 2;
        nbr = nbr / 2;
        binary = binary + mod * (temp);
        temp *= 10;
    }
    return binary;
}

int main()
{
    printf("%d", dec_bin(10));
}