class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int m = pat.size(),n=tar.size();
        int i=m-1,j=n-1;
        
        while(i>=0 and j>=0){
            if(pat[i]==tar[j]){
                i--;
                j--;
             //  cout<<"j = "<<j<<endl;
            }
            else{
             //   cout<<"i = "<<i<<endl;
                i-=2;
            }
            
        }
        if(j==-1)return true;
        return false;
    }
};
