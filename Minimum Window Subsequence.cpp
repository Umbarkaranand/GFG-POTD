class Solution {
  public:
  
    int getEnd(string s1,string s2,int i){
        int j=0;
        while(i<s1.size() and j<s2.size()){
            if(s1[i]==s2[j]){
                j++;
            }
            i++;
        }
        if(j<s2.size())return -1;
        return i;
    }
  
    string minWindow(string& s1, string& s2) {
        // Code here
        int m = s1.size();
        int n = s2.size();
        int end=-1,start=-1,minLen = INT_MAX;
        for(int i=0;i<m;i++){
            
            if(s1[i]==s2[0]){
                end=getEnd(s1,s2,i);
                if(end!=-1 and (end-i)<minLen){
                    start=i;
                    minLen=end-i;
                }
            }
        }
        
        if(start==-1)return "";
        return s1.substr(start,minLen);
    }
};
