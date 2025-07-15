class Solution {
  public:
    bool divby13(string &s) {
        // code here
        
        int remainder=0;
        for(int i=0;i<s.size();i++){
            int digit = s[i]-'0';
            remainder = (remainder*10+digit)%13;
        }
        if(remainder==0)return 1;
        return 0;
        
    }
};
