int Solution::longestSubsequenceLength(const vector<int> &A) {
    if (A.size() == 0)
    {
        return 0;
    }
    int max_el = A[0];
    int max_i = 0;
    vector<int> maxsub;
    vector<int> minsub;
    bool all_same = true;
    int same_el = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > max_el)
        {
            max_el = A[i];
            max_i = i;
        }
        maxsub.push_back(1);
        minsub.push_back(1);
        
        if (A[i] != same_el)
        {
            all_same = false;
        }
    }
    
    if (all_same)
    {
        return 1;
    }
    
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                maxsub[i] = max(maxsub[j] + 1, maxsub[i]);
            }
        }
    }
    
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[i])
            {
                minsub[i] = max(minsub[j] + 1, minsub[i]);
            }
        }
    }
    
    int max_num = 0, maxsub_el = 0, minsub_el = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (maxsub[i] > maxsub_el)
        {
            maxsub_el = maxsub[i];
        }
        if (minsub[i] > minsub_el)
        {
            minsub_el = minsub[i];
        }
        maxsub[i] = maxsub_el;
        minsub[i] = minsub_el;
        cout << "MAXSUB [" << i << "] is " << maxsub[i] << endl;
        cout << "MINSUB [" << i << "] is " << minsub[i] << endl;        
        if ((maxsub[i] + minsub[i] - 1) > max_num)
        {
            max_num = maxsub[i] + minsub[i] - 1;
        }
    }
    
    return max_num;
}
