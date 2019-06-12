class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ccmat[coins.size()+1][amount+1];
        
        for (int i = 0; i <= coins.size(); i++)
        {
            ccmat[i][0] = 1;
        }
        
        for (int j = 0; j <= amount; j++)
        {
            ccmat[0][j] = 0;
        }
        
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i-1] > j)
                {
                    ccmat[i][j] = ccmat[i-1][j];
                }
                else
                {
                    ccmat[i][j] = ccmat[i-1][j] + ccmat[i][j-coins[i-1]];
                }
            }
        }
        
        return ccmat[coins.size()][amount];
    }
};