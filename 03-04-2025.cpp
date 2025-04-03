//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        
        int m = mat.size();
        int n = mat[0].size();
        int res=0,fresh=0;
        queue<pair<int,int>> vp;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)fresh++;
                else if(mat[i][j]==2)vp.push({i,j});
            }
            
        
        while(fresh>0 and !vp.empty()){
            int size = vp.size();
            res++;
            for(int i=0;i<size;i++){
                int rw=vp.front().first;
                int cl=vp.front().second;
                vp.pop();
                
                for(int k=0;k<4;k++){
                    int fr=rw+row[k];
                    int fc=cl+col[k];
                    
                    if(fr>=0 && fr<m && fc>=0 && fc<n && mat[fr][fc]==1){
                        mat[fr][fc]=2;
                        vp.push({fr,fc});
                        fresh--;
                    }
                    
                }
            }
            
        }
        
        if(fresh==0)return res;
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
