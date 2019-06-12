class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int lps[s.length()+1][s.length()+1];
        
        for (int i = 0; i <= s.length(); i++)
        {
            lps[0][i] = 0;
            lps[i][0] = 0;
        }
        
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= s.length(); j++)
            {
                if (s[i-1] != s[s.length()-j])
                {
                    lps[i][j] = max(lps[i-1][j], lps[i][j-1]);
                }
                else
                {
                    lps[i][j] = lps[i-1][j-1] + 1;
                }
            }
        }
        
        return lps[s.length()][s.length()];
    }
};