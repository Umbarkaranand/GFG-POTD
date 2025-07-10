class Solution {
  public:
  
    static bool cmp(string a,string b){
        if(a.size()!=b.size()){
            return a.size()<b.size();
        }
        return a>b;
    }
    string longestString(vector<string> &words) {
        // code here
        
        unordered_map<string,int> mp;
        for(auto a:words)
            mp[a]++;
        
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        
        
        for(int i=n-1;i>=0;i--){
            int l = words[i].size();
            string t="";
            bool ye = true;
            
            for(int k=0;k<l;k++){
                t+=words[i][k];
                if(mp[t]==0){
                    ye=false;
                    break;
                }
                
            }
            if(ye)return words[i];
        }
        
        return "";
    }
};
