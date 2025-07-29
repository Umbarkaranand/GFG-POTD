class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        unordered_map<char,int> mp;
        
        for(auto a:s){
            mp[a]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>1){
                int j=i+1,sum=0;
                while(mp[s[i]]>1){
                    if(s[j]==s[i]){
                        mp[s[i]]--;
                    }
                    sum+=s[j];
                    j++;
                }
                
                if(sum-s[i]>0)ans.push_back(sum-s[i]);
            }
        }
        return ans;
    }
};
