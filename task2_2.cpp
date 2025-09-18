#include <iostream>

int main()
{
    long long int n;
    long long int m;

    std::cin >> n >> m;

    long long int res = 0;

    res += 16 * n * m;

    res -= 6 * m;
    
    res -= 6 * n;

    res += 4;

    std::cout << res << " === res\n";

    return 0;
}