class Solution {
  public:
    
    int solve(vector<vector<int>>& mat,int m,int n,int row,int col,vector<vector<int>> &dp){
        if(row<0 || row>=m || col<0 || col>=n)return 0;
        
        if(dp[row][col]!=-1)return dp[row][col];
        
        int dir1=solve(mat,m,n,row-1,col+1,dp);
        int dir2=solve(mat,m,n,row,col+1,dp);
        int dir3=solve(mat,m,n,row+1,col+1,dp);
        return dp[row][col]=mat[row][col]+max({dir1,dir2,dir3});
        
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m=mat.size(),n=mat[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            ans=max(ans,solve(mat,m,n,i,0,dp));
        }
        return ans;
    }
};
