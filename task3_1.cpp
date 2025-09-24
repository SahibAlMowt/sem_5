#include <iostream>

int main() 
{
    long long int n, m, k;

    std::cin >> n >> m >> k;

    long long int x = m - 1;
    long long int y = n - 1;
    long long int moves = 0;

    long long int d_steps = std::min(x, y) / k;
    moves += d_steps;
    x -= d_steps * k;
    y -= d_steps * k;

    if(x > 0 && y > 0) 
    {
        long long int t = std::min(x, y);
        moves += 1;
        x -= t;
        y -= t;
    }

    if(x > 0)
    {
        moves += (x + k - 1) / k;
    } 
    
    if(y > 0)
    {
        moves += (y + k - 1) / k;
    } 

    std::cout << moves << "\n";

    return 0;
}
