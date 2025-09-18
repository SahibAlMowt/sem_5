#include <iostream>

int main() 
{
    long long int m;
    long long int n;
    long long int k;

    std::cin >> m >> n >> k;

    long long int yurec = 0;

    for (long long int h = 1; h <= m; h++) 
    {
        long long int t = (m * n - k + 1) / h;

        if(t > n)
        {
            t = n; 
        } 

        long long int piece = t * h;

        if (piece > yurec)
        {
            yurec = piece;
        } 
    }

    std::cout << yurec << "\n";
    
    return 0;
}
