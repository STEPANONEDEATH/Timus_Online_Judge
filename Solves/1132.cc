// https://acm.timus.ru/problem.aspx?space=1&num=1132

#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 32767;

std::vector<std::pair<int, int>> k[maxn+1]; // Maps each prime to the input positions querying it

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K, a, n;
    std::cin >> K;
    for(int i = 0; i < K; i++)
    {
        std::cin >> a >> n;
        k[n].push_back({i, a % n});
    }

    std::vector<std::pair<int, int>> output(K);
    for(int n = 0; n <= maxn; n++)
    {
        if(!k[n].empty())
        {
            std::vector<int> r(n, -1); // The map that we fill in iteratively
            for(int x = 0; x < n; x++)
                r[(x*x)%n] = x;

            for(auto& p : k[n])
            {
                int a_mod_n = p.second;
                if(r[a_mod_n] != -1)
                {
                    int root1 = r[a_mod_n];
                    int root2 = (n - root1) % n;
                    output[p.first] = std::make_pair(std::min(root1, root2), std::max(root1, root2));
                }
                else
                {
                    output[p.first] = std::make_pair(-1, -1);
                }
            }
        }
    }

    for(int i = 0; i < K; i++)
    {
        if(output[i].first == -1)
            std::cout << "No root\n";
        else if(output[i].first == output[i].second)
            std::cout << output[i].first << "\n";
        else
            std::cout << output[i].first << " " << output[i].second << "\n";
    }
}
