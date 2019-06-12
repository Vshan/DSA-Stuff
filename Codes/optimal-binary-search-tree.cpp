#include <bits/stdc++.h>
using namespace std;

class OptimalBST {
    public:
    int findOptimal(int keys[], int freq[])
    {
        int T[keys.length()][freq.length()];

        for (int i = 0; i < keys.length(); i++)
        {
            T[i][i] = freq[i];
        }

        for (int l = 2; l <= keys.length(); l++)
        {
            for (int i = 0; i < keys.length(); i++)
            {
                int j = i+l-1;
                T[i][j] = INT_MAX;

                int sum = getSum(freq, i, j);

                for (int k = i; k <= j; k++)
                {
                    int val = sum + (k-1 < i? 0: T[i][k-1]) + (k+1 > j? 0 : T[k+1][j]);
                    if (val < T[i][j])
                    {
                        T[i][j] = val;
                    }
                }
            }
        }

        return T[0][keys.length()-1]; 
    }
    private:
    int getSum(int freq[], int i, int j)
    {
        int sum = 0;
        for (int x = i; x <= j; x++)
        {
            sum += freq[x];
        }

        return sum;
    }

};

int main()
{
    OptimalBST bst;
    int keys[] = {1,2,3,4,5};
    int freq[] = {2,4,6,8,10};
    cout << "Optimal is " << bst.findOptimal(keys, freq);
    return 0;
}