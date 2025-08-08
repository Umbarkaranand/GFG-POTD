class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
       int n = s.size();
       vector<int> lp(n,0);
       int i=0,j=1;
       
       while(j<n){
           if(s[i]==s[j]){
               lp[j]=i+1;
               i++;
               j++;
           }else if(i!=0){
               i=lp[i-1];
           }else{
               lp[j]=0;
               j++;
           }
       }
       
       return lp[n-1];
    }
};
