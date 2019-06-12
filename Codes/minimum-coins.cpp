#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while (t--)
	{
	    int V, N;
	    cin >> V;
	    cin >> N;
	    
	    int val[1000000];
	    
	    for (int i = 0; i < N; i++)
	    {
	        cin >> val[i];
	    }
	    
	    int minCoin[1000001][1000001];
	    
	    for (int i = 0; i <= N; i++)
	    {
	        minCoin[i][0] = 0;
	    }
	    
	    for (int j = 0; j <= V; j++)
	    {
	        minCoin[0][j] = 1000000;
	    }
	    
	    for (int i = 1; i <= N; i++)
	    {
	        for (int j = 1; j <= V; j++)
	        {
	            if (val[i-1] > j)
	            {
	                minCoin[i][j] = minCoin[i-1][j];
	            }
	            else
	            {
	                minCoin[i][j] = min(minCoin[i-1][j], 1 + minCoin[i][j-val[i-1]]);
	            }
	        }
	    }
	    
	    cout << minCoin[N][V] << endl;
	}
	
	
	return 0;
}