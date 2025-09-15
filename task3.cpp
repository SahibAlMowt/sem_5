#include <iostream>
#include <vector>

int main()
{
    long long int stamina; // a.k.a E
    int N;

    std::cin >> stamina >> N;

    std::vector<long long int> a(N+2);

    for(size_t i = 1; i != N + 1; i++)
    {
        std::cin >> a[i];
    }

    long long int position = 0;

    for(size_t i = 1; i != N + 2; i++)
    {
        if(a[i] >= 0)
        {
            long long difference = i - position;

            if(stamina < difference)
            {
                std::cout << "-1\n";
                return 0;
            }

            stamina -= difference;
            stamina += a[i];

 //           position = i - 1;

            position = i;
        }

    }


    std::cout << stamina << " === stamina \n";

    return 0;

}