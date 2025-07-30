class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int presum=0;
        int ans=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            presum+=arr[i];
            if(presum==k)ans++;
            
            if(mp.find(presum-k)!=mp.end())
                ans+=mp[presum-k];
            
            mp[presum]++;
        }
        return ans;
    }
};
