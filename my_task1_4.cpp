#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>

using farray = std::vector<uint64_t>; 

inline bool get_bit(const farray &arr, int i) 
{
    return (arr[i >> 6] >> (i & 63)) & 1ULL;
}

inline void set_bit(farray &arr, int i, bool val) 
{
    if(val)
    {
        arr[i >> 6] |= (1ULL << (i & 63));
    } 
    else
    {
        arr[i >> 6] &= ~(1ULL << (i & 63));
    }
        
}

bool self_dual_function(const farray &array, int size) 
{
    for(int i = 0; i <= (size - 1) / 2; i++) 
    {
        if(get_bit(array, i) == get_bit(array, size - i - 1))
        {
            return false;
        }          
    }

    return true;
}

bool monotonic_function(const farray &array, int n, int size) 
{
    for(int i = 0; i < size; i++) 
    {
        for(int bit_pos = 0; bit_pos < n; bit_pos++) 
        {
            int j = i | (1 << bit_pos);

            if(i != j && !get_bit(array, i) && get_bit(array, j))
            {
                continue;
            }
                
            if(i != j && get_bit(array, i) && !get_bit(array, j))
            {
                 return false;
            }             
        }
    }
    return true;
}

bool linear_function(farray &array, int n, int size) 
{
    for(int i = 0; i < n; i++) 
    {
        int step = 1 << i;

        for(int mask = 0; mask < size; mask++) 
        {
            if(mask & step) 
            {
                bool val = get_bit(array, mask) ^ get_bit(array, mask ^ step);
                set_bit(array, mask, val);
            }
        }
    }

    for(int mask = 0; mask < size; mask++) 
    {
        int cnt = __builtin_popcount(mask);

        if(cnt > 1 && get_bit(array, mask))
        {
            return false;
        }
            
    }

    return true;
}

int main() 
{
    std::fstream fin("input.txt", std::ios::in);

    int n;

    fin >> n;

    int size = 1 << n;

    int blocks = (size + 63) / 64;

    farray array(blocks, 0);

    char c;

    for(int i = 0; i < size; i++) 
    {
        fin >> c;
        set_bit(array, i, c == '1');
    }

    fin.close();

    std::fstream fout("output.txt", std::ios::out);

    if(!get_bit(array, 0))
    { 
     //   std::cout << "~T0"; 
        fout << 0;
        return 0; 
    }

    if(get_bit(array, size - 1)) 
    { 
    //    std::cout << "~T1";
        fout << 0;
        return 0; 
    }

    if(self_dual_function(array, size)) 
    { 
     //   std::cout << "~S"; 
        fout << 0;
        return 0; 
    }

    if(monotonic_function(array, n, size)) 
    { 
     //   std::cout << "~M"; 
        fout << 0;
        return 0; 
    }

    if(linear_function(array, n, size)) 
    { 
     //   std::cout << "~L"; 
        fout << 0;
        return 0; 
    }

    fout << 1;

    fout.close();

    return 0;
}
