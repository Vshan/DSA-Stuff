class Solution {
public:
    int cutrod(int len, vector<int>& rods, vector<int>& values) {
        int rodmat[rods.length()][values.length()+1];

        for (int i = 0; i < rods.length(); i++)
        {
            rodmat[i][0] = 0;
        }

        for (int i = 0; i < rods.length(); i++)
        {
            for (int j = 1; j <= values.length(); j++)
            {
                if (rods[i] > j)
                {
                    rodmat[i][j] = rodmat[i-1][j];
                }
                else
                {
                    rodmat[i][j] = max(rodmat[i-1][j], values[i] + rodmat[i][j-i]);
                }
            }
        }

        return rodmat[rods.length()-1][values.length()];
    }
};