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

    int light = 0;

    while(light < N && max_num > 0)
    {
        int pos;
        pos = light + max_r + 1;

        if(pos > N)
        {
            pos = N;
        }

        lamps.push_back({pos, max_r});

        light = pos + max_r;

        max_num--;

    }


    while(light < N && min_num > 0)
    {
        int pos;
        pos = light + min_r + 1;

        if(pos > N)
        {
            pos = N;
        }

        lamps.push_back({pos, min_r});

        light = pos + min_r;

        min_num--;
    }


    if(light < N)
    {
        std::cout << "-1\n";
        return 0;
    }

    for(size_t i = 0; i != lamps.size(); i++)
    {
        std::cout << lamps[i].position << " " << lamps[i].radius << "\n";
    }

    return 0;
}