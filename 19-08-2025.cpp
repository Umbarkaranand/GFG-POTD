class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> vp;
        
        for(int i=0;i<n;i++){
            vp.push_back({abs(arr[i]-x),i});
        }
        
        sort(vp.begin(),vp.end());
        vector<int> temp=arr;
        for(int i=0;i<n;i++){
            arr[i]=temp[vp[i].second];
        }
        
    
    }
};
