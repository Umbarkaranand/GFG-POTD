class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        map<char,int> mp;
        queue<char> q;
        string ans="";
       
        for(int i=0;i<s.size();i++){
            
            mp[s[i]]++;
            if(mp[s[i]]==1){
                q.push(s[i]);
            }
            
            while(!q.empty() and mp[q.front()]>1){
                q.pop();
            }
            
            if(q.empty()){
                ans+="#";
            }else{
                ans+=q.front();
            }
        }
        return ans;
    }
};
