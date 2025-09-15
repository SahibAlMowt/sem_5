#include <iostream> 
#include <vector>

struct flashlight
{
    int position;
    int radius;
};

int main()
{
    int N;

    int A;
    int X;

    int B;
    int Y;

    int max_num;
    int max_r;

    int min_num;
    int min_r;

    std::cin >> N >> A >> X >> B >> Y;

    std::vector<flashlight> lamps;

    if(X >= Y)
    {
        max_num = A;
        max_r = X;

        min_num = B;
        min_r = Y;
    }
    else
    {
        max_num = B;
        max_r = Y;

        min_num = A;
        min_r = X;
    }

    return 0;
}