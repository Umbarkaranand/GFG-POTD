class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.size();
        int ans=0;
        string str="";
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++){
            str+=s[i];
            mp[s[i]]++;
            
            if(str.length()==k){
                if(mp.size()==k-1){
                    ans++;
                }
                mp[str[0]]--;
                if(mp[str[0]]==0){
                    mp.erase(str[0]);
                }
                
                str.erase(0,1);
            }
        }
        
        return ans;
    }
};
