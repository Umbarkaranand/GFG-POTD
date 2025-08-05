class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        stack<char> st;
        string str1="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                s[i]=tolower(s[i]);
                st.push(s[i]);
                str1+=s[i];
            }
        }
        
        string str2="";
        while(!st.empty()){
            str2+=st.top();
            st.pop();
        }
        
        
        return str1==str2? 1:0;
            
        
    }
};
