#include "tutorial.h"

double sqrt(double inputValue)
{
    if (inputValue <= 0)
    {
        return 0;
    }
    double mid, pre;
    double low = 0, high = inputValue;
    mid = (low + high) / 2;
    do
    {
        if (mid * mid > inputValue)
        {
            high = mid;
        }
        else 
        {
            low = mid;
        }
        pre = mid;
        mid = (low + high) / 2;
    } while (abs(mid - pre) > 0.000001);
    return mid;
}

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    double result = sqrt(base);
    printf("the sqrt of %g is %g \n", base, result);
}