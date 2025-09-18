#include <iostream>
#include <vector>
#include <string>



bool compare(const std::string &a, const std::string &b) 
{
    if(a.size() != b.size()) 
    {
        return a.size() < b.size();
    }

    return a < b; 
}

std::string function(const std::string &current, const std::string &previous) 
{
    if(current.size() > previous.size())
    {
        return current;
    } 
    if (current.size() == previous.size()) 
    {
        if (current >= previous)
        {
            return current;
        }

        return current + "0";
    }

    std::string prefix = previous.substr(0, current.size());
    if(prefix > current) 
    {
        return current + std::string(previous.size() - current.size() + 1, '0');
    }
    else if(prefix < current) 
    {
 //       std::cout << current << " === current\n";
        return current + std::string(previous.size() - current.size(), '0');
    } 
    else 
    {
        std::string suffix = previous.substr(current.size());
  //      std::cout << current << " === current\n";
        return current + suffix;
    }
}

int main() 
{
    int n;
    std::cin >> n;
    std::vector<std::string> vec(n);

    for (size_t i = 0; i != n; i++)
    {
        std::cin >> vec[i];
    } 

    for (size_t i = 1; i < n; i++) 
    {
        if (compare(vec[i], vec[i - 1])) 
        {
        //    std::cout << "vec[" << i << "] === " << vec[i] << "\n";
            vec[i] = function(vec[i], vec[i - 1]);
     //       std::cout << "vec[" << i << "] === " << vec[i] << "\n";
        }
    }

    std::cout << vec.back() << " === res\n";

    return 0;
}
