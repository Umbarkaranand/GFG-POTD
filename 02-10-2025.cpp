class Solution {
  public:
    
    void solve(int n,int k,vector<vector<int>>& ans,int cur,vector<int>& temp,int sum){
    
        //base case
        if(sum==n && temp.size()==k){
            ans.push_back(temp);
            return;
        }else if(temp.size()>k || cur>9){
            return;
        }
       
        
        //recursive case
        
        for(int i=cur;i<=9;i++){
            temp.push_back(i);
            sum+=i;
            solve(n,k,ans,i+1,temp,sum);
            sum-=i;
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(n,k,ans,1,temp,0);
        return ans;
    }
};
