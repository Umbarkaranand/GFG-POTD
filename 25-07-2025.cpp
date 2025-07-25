class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int curMax=0,maxSum=arr[0];
        int curMin=0,minSum=arr[0];
        int total=0;
        
        for(auto a:arr){
            curMax=max(curMax+a,a);
            maxSum=max(maxSum,curMax);
            
            curMin=min(curMin+a,a);
            minSum=min(curMin,minSum);
            
            total+=a;
        }
        
        if(minSum==total)return maxSum;
        
        return max(maxSum,total-minSum);
    }
};
