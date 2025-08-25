class Solution {
  public:
  
    bool isPossible(vector<int> &arr,int k,int m,int mid){
        int cnt=0;
        int bouquets=0;
        
        for(auto a:arr){
            if(a<=mid){
                cnt++;
            }else{
                bouquets+=cnt/k;
                cnt=0;
            }
        }
        
        bouquets+=cnt/k;
        return bouquets>=m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        if(k*m > n)return -1;
        
        int high = *max_element(arr.begin(),arr.end());
        int low=0;
        int ans=INT_MAX;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(isPossible(arr,k,m,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};
