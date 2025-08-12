class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        
        int n = s.size();
        for(int i=n;i>=1;i--){
            if(s[0]!=s[i])continue;
            
            int len=i;
            int s1=0,s2=i;
            while(s2<n and s[s1]==s[s2]){
                s1=(s1+1)%len;
                s2++;
            }
            
            if(s2==n)return len;
        }
        
        return -1;
    }
};
