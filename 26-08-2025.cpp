class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int index=0;
        for(int i=0;i<s2.size();i++){
            if(index==s1.size())return true;
            if(s1[index]==s2[i])index++;
            
        }
        if(index==s1.size())return true;
        return false;
    }
};
