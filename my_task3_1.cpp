#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

std::string preobr(int state, int n) 
{
    std::string result = "";
    for(int i = n - 1; i >= 0; i--) 
    {
        result += ((state >> i) & 1) ? '1' : '0';
    }

    return result;
}

int main() 
{
    std::ifstream fin("input.txt");

    int n;
    std::string start;
    fin >> n >> start;

    std::vector<std::string> q_t(n);

    for(int i = 0; i < n; i++) 
    {
        int l, values;
        fin >> l >> values;
        fin >> q_t[i];
    }

    std::string y_t;
    int two, vars;
    fin >> two >> vars;
    fin >> y_t;

    fin.close();

    const int size = 1 << n;
    
    std::vector<std::vector<int>> next_state(size, std::vector<int>(2));
    std::vector<std::vector<bool>> output_value(size, std::vector<bool>(2));

    for(int state = 0; state < size; state++) 
    {
        for(int input = 0; input < 2; input++) 
        {
            int index = (state << 1) | input;
            
            int new_state = 0;

            for(int j = 0; j < n; j++) 
            {
                if(q_t[j][index] == '1') 
                {
                    new_state |= (1 << (n - 1 - j));
                }
            }

            next_state[state][input] = new_state;
            output_value[state][input] = (y_t[index] == '1');
        }
    }

    std::vector<std::vector<bool>> non_equiv(size, std::vector<bool>(size, false));
    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < size; i++) 
    {
        for(int j = i + 1; j < size; j++) 
        {
            if(output_value[i][0] != output_value[j][0] || output_value[i][1] != output_value[j][1]) 
            {
                non_equiv[i][j] = true;
                q.push({i, j});
            }
        }
    }

    std::vector<std::vector<std::vector<int>>> prev(size, std::vector<std::vector<int>>(2));

    for(int input = 0; input < 2; input++) 
    {
        for(int state = 0; state < size; state++) 
        {
            int next = next_state[state][input];
            prev[next][input].push_back(state);
        }
    }


    while(!q.empty()) 
    {
        auto [a, b] = q.front();
        q.pop();
        
        if(a > b)
        {
            std::swap(a, b);
        } 
        
        for(int input = 0; input < 2; input++) 
        {

            for(int i : prev[a][input]) 
            {
                for(int j : prev[b][input]) 
                {
                    int u = std::min(i, j);
                    int v = std::max(i, j);

                    if(u != v && !non_equiv[u][v]) 
                    {
                        non_equiv[u][v] = true;
                        q.push({u, v});
                    }
                }
            }
        }
    }

    std::vector<std::pair<int, int>> result;

    for(int i = 0; i < size; i++) 
    {
        for(int j = i + 1; j < size; j++) 
        {
            if(!non_equiv[i][j]) 
            {
                result.push_back({i, j});
            }
        }
    }

    std::ofstream fout("output.txt");

    if(result.empty()) 
    {
        fout << -1;
    } 
    else 
    {
        for(size_t i = 0; i < result.size(); i++) 
        {
            fout << preobr(result[i].first, n) << " " << preobr(result[i].second, n);
            if(i != result.size() - 1)
            {
                fout << " ";
            } 
        }
    }

    fout.close();

    return 0;
}