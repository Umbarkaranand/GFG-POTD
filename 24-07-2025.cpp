class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        
        int maxi=0;
        for(auto a:left){
           maxi=max(a,maxi);
        }
        
        for(auto a:right){
            maxi=max(maxi,n-a);
        }
        
        return maxi;
        
        
    }
};
