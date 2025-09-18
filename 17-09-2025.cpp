class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        stack<int> number;
        int num=0;
        
        for(auto c:s){
            
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c==']'){
                
                string temp="";
                while(!st.empty() and st.top()!='['){
                    temp+=st.top();
                    //cout<<st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                int topNumber=number.top();
              // cout<<topNumber<<temp<<endl;
                string temp2="";
                while( topNumber--){
                    temp2+=temp;
                   
                }
               // cout<<temp2<<endl;
                number.pop();
                for(auto ch:temp2){
                    st.push(ch);
                }
                
            }else{
                if(num){
                    number.push(num);
                    num=0;
                }
                st.push(c);
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
