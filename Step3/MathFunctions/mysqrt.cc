#include "MathFunctions.h"

double mysqrt(double inputValue)
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