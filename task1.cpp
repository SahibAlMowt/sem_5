#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long int A;
    long long int B;
    long long int C;
    long long int D;

    std::cin >> A >> B >> C >> D;

    std::vector<long long int> num;
    num = {A, B, C};

    std::sort(num.begin(), num.end());

    long long int first = num[0] + num[1];
    long long int second = num[2];

    long long int difference = first - second;

    if(std::abs(difference) <= D)
    {
        std::cout << "0\n";
    }
    else
    {
        std::cout << std::abs(difference) - D << "\n";
    }

    return 0;
}