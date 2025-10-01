class Solution {
  public:
    
    void solve(vector<string>& ans,int n,string temp){
        //base case
        if(temp.size()>n)return;
        
        //recursive case
         if(temp.size()==n)ans.push_back(temp);
        solve(ans,n,temp+"0");
       // ans.push_back(temp);
        solve(ans,n,temp+"1");
       
        
    }
    vector<string> binstr(int n) {
        // code here
        
        vector<string> ans;
        solve(ans,n,"");
        return ans;
    }
};
