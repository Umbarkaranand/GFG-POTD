//Minimum Cost Path
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
      int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        dp[0][0]=grid[0][0];
        
        for(int i=1;i<m;i++)dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<n;i++)dp[i][0]=dp[i-1][0]+grid[i][0];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
