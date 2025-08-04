class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        int maxSum=INT_MIN;
        
        for(int top=0;top<m;top++){
            vector<int> temp(n,0);
            for(int bottom=top;bottom<m;bottom++){
                for(int col=0;col<n;col++)
                    temp[col]+=mat[bottom][col];
            
               
            int curSum=temp[0],best=temp[0];
            for(int i=1;i<n;i++){
                curSum=max(curSum+temp[i],temp[i]);
                best=max(best,curSum);
            }
            maxSum=max(maxSum,best);
            }
            
        }
        
        return maxSum;
    }
};
