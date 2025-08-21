class Solution {
  public:
  
    bool possible(vector<int>& arr,int k,int mid){
        int count=1;
        int last=arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=mid){
                count++;
                last=arr[i];
            }
            
            if(count==k)return true;
        }
        return false;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        int low=0;
        int high = arr.back()-arr.front();
        int ans=0;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(possible(arr,k,mid)){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};
