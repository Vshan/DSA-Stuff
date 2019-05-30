#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
	    
	    int N, arr[1002];
	    cin >> N;
	    int sum = 0;
	    
	    for (int i = 0; i < N; i++)
	    {
	        cin >> arr[i];
	        sum += arr[i];
	    }
	    
	    if (sum % 2 != 0)
	    {
	        cout << "NO";
	        continue;
	    }
	    
	    sum = sum/2;
	    
	    bool subsetsum[1002][1000000];
	    
	    for (int i = 0; i <= N; i++)
	    {
	        subsetsum[i][0] = true;
	    }
	    
	    for (int j = 0; j <= sum; j++)
	    {
	        subsetsum[0][j] = false;
	    }
	    
	    for (int i = 1; i <= N; i++)
	    {
	        for (int j = 1; j <= sum; j++)
	        {
	            if (arr[i] < j)
	            {
	                subsetsum[i][j] = subsetsum[i-1][j];
	            }
	            else
	            {
	                subsetsum[i][j] = subsetsum[i-1][j] || subsetsum[i-1][j-arr[i]];
	            }
	            
	        }
	    }
	    
	    if (subsetsum[N][sum])
	    {
	        cout << "YES";
	    }
	    else
	    {
	        cout << "NO";
	    }
	    
	    
	}
	
	return 0;
}