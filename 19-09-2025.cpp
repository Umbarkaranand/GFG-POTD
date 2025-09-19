class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char> st1,st2;
        
        for(auto c:s){
            
            if(c==')' and !st1.empty() and st1.top()=='('){
                st1.pop();
            }else if(st1.empty() and c==')'){
                st2.push(c);
            }else{
                st1.push(c);
            }
        }
        
        return st1.size()+st2.size();
    }
};
