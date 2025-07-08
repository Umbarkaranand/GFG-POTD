class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int left=0,right=0,ans=0;
        unordered_map<char,int> mp;
        string temp="";
        int dist=0;
        
        while(right<n){
            temp+=s[right];
            mp[s[right]]++;
            
            if(mp.size()==k)
                ans=max(ans,(int)temp.length());
            
            else if(mp.size()>k){
                mp[temp[0]]--;
                if(mp[temp[0]]==0){
                    mp.erase(temp[0]);
                }
                temp.erase(0,1);
            }
            
            
            right++;
            
        }
        
        return ans==0? -1:ans;
    }
};
