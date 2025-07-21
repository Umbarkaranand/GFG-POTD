class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int zero=0;
        for(auto a:arr){
            if(a==0){
                zero=1;
                break;
            }
        }
        
        int totalPos = pow(10,n-1)*9;
        int m = 10-arr.size();
        int notPos = pow(m,n-1)*(zero?m:m-1);
        
        return totalPos-notPos;
        
    }
};
