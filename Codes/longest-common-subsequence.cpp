#include <iostream>
using namespace std;

int main() {
    int t;
	cin >> t;
	
	while (t--)
	{
	    int A,B;
	    cin >> A;
	    cin >> B;
	    
	    char strA[300];
	    char strB[300];
	    
	    cin >> strA;
	    cin >> strB;
	    
	    int lcs[101][101];
	    
	    for (int i = 0; i <= A; i++)
	    {
	        lcs[i][0] = 0;
	    }
	    
	    for (int j = 0; j <= B; j++)
	    {
	        lcs[0][j] = 0;
	    }
	    
	    for (int i = 1; i <= A; i++)
	    {
	        for (int j = 1; j <= B; j++)
	        {
	            if (strA[i-1] != strB[j-1])
	            {
	                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	            }
	            else
	            {
	                lcs[i][j] = lcs[i-1][j-1] + 1;
	            }
	        }
	    }
	    
	    cout << lcs[A][B] << endl;
	}
	
	return 0;
}