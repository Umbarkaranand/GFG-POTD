class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto a:arr)
            mp[a]++;
        
        for(auto a:mp)
            if(a.second>(arr.size()/3))
                ans.push_back(a.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
