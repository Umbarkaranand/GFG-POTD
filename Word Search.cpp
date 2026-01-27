class Solution {
  public:
  
   bool solve(vector<vector<char>> &mat, string &word,int i,int j,int index,vector<vector<bool>> &vis){
       //base case
       if(index==word.size())return true;
       if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || word[index]!=mat[i][j] || vis[i][j]) return false;
       
       //recursive case
       vis[i][j]=true;
       if(solve(mat,word,i-1,j,index+1,vis) || solve(mat,word,i+1,j,index+1,vis) ||
          solve(mat,word,i,j-1,index+1,vis) || solve(mat,word,i,j+1,index+1,vis)){
              return true;
          }
       
       vis[i][j]=false;
       return false;
   }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==word[0]){
                    int index=0;
                    if(solve(mat,word,i,j,index,vis))return true;
                    
                }
            }
        }
        return false;
        
    }
};
