// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> preSum(n),sufSum(n),res(n);
        
        preSum[0]=1;
        for(int i=1;i<n;i++){
            preSum[i]=arr[i-1]*preSum[i-1];
        }
        
        sufSum[n-1]=1;
        for(int i=n-2;i>=0;i--){
            sufSum[i]=arr[i+1]*sufSum[i+1];
        }
        
        for(int i=0;i<n;i++){
            res[i]=preSum[i]*sufSum[i];
        }
        
        return res;
    }
};
