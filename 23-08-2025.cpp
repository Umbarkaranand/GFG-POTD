class Solution {
  public:
  
    bool isPossible(vector<int> &arr,int mid,int k){
        int student=1,sum=0;
        for(auto a:arr){
            sum+=a;
            if(sum>mid){
                student++;
                sum=a;
            }
        }
        
        return student<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n)return -1;
        int low=INT_MIN,high=0,ans=INT_MAX;
        
        for(auto a:arr){
            high+=a;
            low=max(low,a);
        }
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(isPossible(arr,mid,k)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
       
        return ans;
        
    }
};
