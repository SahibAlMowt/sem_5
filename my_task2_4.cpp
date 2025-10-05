#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int n;
int k;

std::vector<int> values;

int char_to_int(char c)
{
    if(c >= '0' && c <= '9')
    {
        return c - '0';
    }

    return (10 + (c - 'A'));
}

char int_to_char(int num)
{
    if(num < 10)
    {
        return '0' + num;
    }

    return ('A' + (num - 10));
}

void generate_razb(int elem, std::vector<std::vector<std::vector<int>>> &razb, std::vector<std::vector<int>> &current)
{
    if(elem == k) 
    {
        razb.push_back(current);
        return;
    }
    
    for(size_t i = 0; i < current.size(); i++) 
    {
        current[i].push_back(elem);
        generate_razb(elem + 1, razb, current);
        current[i].pop_back();
    }
    
    current.push_back({elem});
    generate_razb(elem + 1, razb, current);
    current.pop_back(); 
}

bool check(const std::vector<std::vector<int>> &razb)
{
    std::vector<int> t_vec(k);
    for(size_t i = 0; i != razb.size(); i++) 
    {
        for(int elem: razb[i]) 
        {
            t_vec[elem] = i;
        }
    }
    
    std::map<std::vector<int>, int> check_map;
    int size = 1;

    for(int i = 0; i < n; i++)
    {
        size *= k;
    }
    
    for(int index = 0; index < size; index++) 
    {
        std::vector<int> x(n);

        int t = index;

        for(int i = n - 1; i >= 0; i--) 
        {
            x[i] = t % k;
            t /= k;
        }
        
        std::vector<int> pattern(n);
        for(int i = 0; i < n; i++) 
        {
            pattern[i] = t_vec[x[i]];
        }
        
        int val = values[index];
        int val_class = t_vec[val];
        

        if(check_map.find(pattern) == check_map.end()) 
        {
            check_map[pattern] = val_class;
        } 
        else 
        {
            if(check_map[pattern] != val_class) 
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    std::string values_str;

    fin >> k;
    fin >> n;

    fin >> values_str;

    std::vector<std::vector<std::vector<int>>> res;
    std::vector<std::vector<int>> current;

    for(char c: values_str)
    {
        values.push_back(char_to_int(c));
    }

    generate_razb(0, res, current);


    std::vector<std::string> result;
    
    for(auto &partition: res) 
    {

        for(auto &claas : partition) 
        {
            std::sort(claas.begin(), claas.end());
        }

        std::sort(partition.begin(), partition.end());
        
        if(check(partition)) 
        {
            std::string partition_str;
            for(auto &claas: partition) 
            {
                std::string claas_str;

                for(int elem: claas) 
                {
                    claas_str += int_to_char(elem);
                }

                if(!partition_str.empty()) 
                {
                    partition_str += " ";
                }
                partition_str += claas_str;
            }

            result.push_back(partition_str);
        }
    }
    
    std::sort(result.begin(), result.end());
    

    for(const auto &str: result) 
    {
        fout << str << "\n";
    }

    return 0;
}