class Solution {
public:
    int mindrop(int eggdrop[][10001], int i, int j) {
        int min_drop = INT_MAX;
        int curr_drop;
        for (int k = 0; k <= j; k++)
        {
            curr_drop = max(eggdrop[i-1][k-1], eggdrop[i][j-k]);
            if (curr_drop < min_drop)
            {
                min_drop = curr_drop;
            }
        }
        return 1 + min_drop;
    }

    int superEggDrop(int K, int N) {
        int eggdrop[K][N];
        
        for (int j = 0; j < N; j++)
        {
            eggdrop[0][j] = j+1;
        }
        
        for (int i = 1; i < K; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i > j)
                {
                    eggdrop[i][j] = eggdrop[i-1][j];
                }
                else
                {
                    eggdrop[i][j] = mindrop(eggdrop, i, j);
                }
            }
        }
        
        return eggdrop[K-1][N-1];
    }
};