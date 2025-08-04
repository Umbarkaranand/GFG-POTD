class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int m = opr.size();
        int row=mat.size(),col=mat[0].size();
        vector<vector<int>> diff(row+1,(vector<int>(col+1,0)));

        for (int i = 0; i < m; i++) {
            int val = opr[i][0];
            int r1=opr[i][1],c1=opr[i][2];
            int r2=opr[i][3],c2=opr[i][4];
            
            for(int k=r1;k<=r2;k++){
                diff[k][c1]+=val;
                diff[k][c2+1]-=val;
            }
            
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]+=diff[i][j];
            }
        }
        
        
        
        

        return mat;
    }
};
