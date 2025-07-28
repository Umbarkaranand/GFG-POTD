class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<int> row,col;
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(find(row.begin(),row.end(),i)!=row.end() or find(col.begin(),col.end(),j)!=col.end()){
                    mat[i][j]=0;
                }
            }
        }
    }
};
