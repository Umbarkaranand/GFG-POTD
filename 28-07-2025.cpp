class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        
        int m = mat.size(),n=mat[0].size();
        int rowMax=0,colMax=0,sum=0;
        
        for(int i=0;i<m;i++){
            int rowSum=0,colSum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
                rowSum+=mat[i][j];
                colSum+=mat[j][i];
            }
            rowMax=max(rowMax,rowSum);
            colMax=max(colMax,colSum);
        }
        
        return rowMax>=colMax? ((m*rowMax)-sum) : ((m*colMax)-sum);
    }
};
