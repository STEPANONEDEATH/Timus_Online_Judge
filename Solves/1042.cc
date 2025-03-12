// https://acm.timus.ru/problem.aspx?space=1&num=1042

#include <iostream>
#include <bitset>

int A[250][251];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        while(true)
        {
            std::cin >> x;
            if(x == -1)
                break;
            A[x-1][i] = A[x-1][n] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        int k = i;
        while(k < n && A[k][i] == 0) // Find the pivot row
            k++;
        if(k == n)
            continue; // No pivot found, skip
        for(int j = 0; j < n + 1; j++) // Bring it to the proper position
            std::swap(A[k][j], A[i][j]);
        for(k = 0; k < n; k++)
        {
            if(k != i && A[k][i]) // Clear out rows above and below the pivot row
            {
                for(int j = i; j < n + 1; j++)
                    A[k][j] ^= A[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(A[i][n])
            std::cout << (i + 1) << " ";
    }
}
