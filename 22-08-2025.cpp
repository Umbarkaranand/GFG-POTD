class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        
        int m = mat.size(),n=mat[0].size();
        int mid = (((m*n)/2));
        vector<int> v;
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                v.push_back(mat[i][j]);
            }
        }
        
        sort(v.begin(),v.end());
        
        return v[mid];
    }
};
