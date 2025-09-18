#include <iostream>

long long int n; 
long long int a;
long long int b;

long long int function(long long int x_1) 
{
 //   long long int t_left = (x_1 - 1) * a;
 //   long long int t_right = (n - x_1) * b;

    long long int t_diff = (x_1 - 1) * a - (n - x_1) * b;

    if(t_diff >= 0)
    {
        return t_diff;
    }
    else
    {
        return -t_diff;
    }
}


int main() 
{
    std::cin >> n >> a >> b;

    long long int left = 2;
    long long int right = n - 1;

    while (right - left > 3) 
    {  
        long long int mid = (left + right) / 2;

        if (function(mid) <= function(mid + 1))
        {
            right = mid;
        }
        else
        {
            left = mid + 1; 
        }       
    }

  
    long long int x_1 = left;
    long long int best_value = function(left);

    for (long long int x = left + 1; x != right; x++) 
    {
        long long int value = function(x);

        if (value < best_value) 
        {
            best_value = value;
            x_1 = x;
        }
    }

    std::cout << x_1 << "\n";

    return 0;
}
