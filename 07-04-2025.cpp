//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void solve(vector<vector<char>>& grid,int i,int j,int m,int n){

        //recursive case
        
        grid[i][j]='W';
        if(i-1>=0 and grid[i-1][j]=='L')solve(grid,i-1,j,m,n);
       if(i-1>=0 and j-1>=0 and grid[i-1][j-1]=='L')solve(grid,i-1,j-1,m,n);
        if(j-1>=0 and grid[i][j-1]=='L')solve(grid,i,j-1,m,n);
        if(i+1<m and j-1>=0 and grid[i+1][j-1]=='L')solve(grid,i+1,j-1,m,n);
        if(i+1<m and grid[i+1][j]=='L')solve(grid,i+1,j,m,n);
        if(i+1<m and j+1<n and grid[i+1][j+1]=='L')solve(grid,i+1,j+1,m,n);
       if(j+1<n and grid[i][j+1]=='L')solve(grid,i,j+1,m,n);
        if(i-1>=0 and j+1<n and grid[i-1][j+1]=='L')solve(grid,i-1,j+1,m,n);
        
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='L'){
                    ans++;
                    solve(grid,i,j,m,n);
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
