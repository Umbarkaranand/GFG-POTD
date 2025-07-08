class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int ans=0, left=0, right=0;
        unordered_map<int,int> mp;
        int n = arr.size();
        
        while(right<n){
            mp[arr[right]]++;
            
            while(mp.size()>2){
                mp[arr[left]]--;
                if(mp[arr[left]]==0){
                    mp.erase(arr[left]);
                }
                left++;
            }
            
            
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
};
