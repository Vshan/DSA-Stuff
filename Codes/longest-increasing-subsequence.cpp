class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> mins;
        for (int i = 0; i < nums.size(); i++)
        {
            mins.push_back(1);
        }
        
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                     if (mins[j] + 1 > mins[i])
                     {
                         mins[i] = mins[j] + 1;
                     }
                }
            }
        }
        
        int maxlen = 0;
        for (int i = 0; i < mins.size(); i++)
        {
            if (mins[i] > maxlen)
            {
                maxlen = mins[i];
            }
        }
        
        return maxlen;
    }
};