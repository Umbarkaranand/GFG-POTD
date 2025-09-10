class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        char maxDigit = '0';
        int maxIndex=-1,l=-1,r=-1;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>maxDigit){
                maxDigit=s[i];
                maxIndex=i;
            }
            else if(s[i]<maxDigit){
                l=i;
                r=maxIndex;
            }
        }
        
        if(l==-1)return s;
            
            swap(s[l],s[r]);
            
            return s;
    }
};
