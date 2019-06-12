class Solution {
public:
    int minDistance(string word1, string word2) {
        int minArr[word1.length()+1][word2.length()+1];
        
        for (int i = 0; i <= word1.length(); i++)
        {
            minArr[i][0] = i;
        }
        
        for (int i = 0; i <= word2.length(); i++)
        {
            minArr[0][i] = i;
        }
        
        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            {
                if (word1[i-1] != word2[j-1])
                {
                    minArr[i][j] = 1 + min(minArr[i-1][j], min(minArr[i][j-1], minArr[i-1][j-1]));
                }
                else
                {
                    minArr[i][j] = minArr[i-1][j-1];
                }
            }
        }
        
        return minArr[word1.length()][word2.length()];
    }
};