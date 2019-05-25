#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	
	cin >> t;
	while (t--)
	{
	    int N, W;
	    cin >> N;
	    cin >> W;
	    int val[1000], wt[1000];
	    int knapsack[1001][1001];
	    
	    for (int i =0; i < N; i++)
	    {
	        cin >> val[i];
	    }
	    
	    for (int i =0; i < N; i++)
	    {
	        cin >> wt[i];
	    }
	    
	    for (int i = 0; i <= N; i++)
	    {
	        knapsack[i][0] = 0;
	    }
	    
	    for (int j = 0; j <= W; j++)
	    {
	        knapsack[0][j] = 0;
	    }
	    
	    for (int i = 1; i <= N; i++)
	    {
	        for (int j = 1; j <= W; j++)
	        {
	            if (wt[i-1] > j)
	            {
	                knapsack[i][j] = knapsack[i-1][j];
	            }
	            else
	            {
	                knapsack[i][j] = max(knapsack[i-1][j], val[i-1] + knapsack[i-1][j-wt[i-1]]);
	            }
	        }
	    }
	    
	    cout << knapsack[N][W] << endl;
	    
	}
	
	return 0;
}