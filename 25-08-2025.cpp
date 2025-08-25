class Solution {
  public:
  
    bool isPossible(vector<int>& arr,int mid,int k){
        
        int n = arr.size();
        if(n%2==1){
            for(int i=n/2;i<n;i++){
                if(arr[i]<mid){
                    k-=(mid-arr[i]);
                }
                
                if(k<0)break;
            }
        }else{
            if(arr[n/2]<=mid){
                k-=(mid-arr[n/2]);
                k-=(mid-arr[(n/2)-1]);
            }
            // else {
            // k -= (2 * mid - 
            //         (arr[n / 2] + arr[n / 2 - 1]));
            //     }
            for(int i=n/2+1;i<n;i++){
                if(arr[i]<mid){
                    k-=(mid-arr[i]);
                }
                
                if(k<0)break;
            }
        }
        
        return k>=0;
    }
  
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int median=arr[n/2];
        if(n%2==0){
            median+=arr[(n/2)-1];
            median/=2;
        }
        
        int low=median,high=median+k;
        int bestMedian=median;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(isPossible(arr,mid,k)){
                bestMedian=mid;
                low=mid+1;
                
            }
            else{
                high=mid-1;
            }
        }
        
        return bestMedian;
    }
};
