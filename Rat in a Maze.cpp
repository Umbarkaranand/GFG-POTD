// User function template for C++

class Solution {
  public:
    
    set<string> ans;
    void help(vector<vector<int>> &mat,int n,int i,int j,set<string> &ans,string temp)
    {
        if(i<0 or j<0 or i==n or j==n or mat[i][j]==0)return;
        if(i==n-1 and j==n-1){
            ans.insert(temp);
            return;
        }
        mat[i][j]=0;
        help(mat,n,i+1,j,ans,temp+"D");
        help(mat,n,i-1,j,ans,temp+"U");
        help(mat,n,i,j+1,ans,temp+"R");
        help(mat,n,i,j-1,ans,temp+"L");
        mat[i][j]=1;
    }
    
    vector<string> ratInMaze(vector<vector<int>> &mat) {
        // Your code goes here
        help(mat,mat.size(),0,0,ans,"");
        vector<string> returnAns(ans.begin(),ans.end());
        return returnAns;
    }
};

