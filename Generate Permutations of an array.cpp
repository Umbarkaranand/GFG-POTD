class Solution {
  public:
    void solve(vector<int>& arr, vector<vector<int>> &ans,map<vector<int>,int> &mp,int index,int n){
        //base case
        if(index==n){
            if(!mp[arr]){
                ans.push_back(arr);
                mp[arr]=1;
            }
        }
        
        //recursive case
        for(int i=index;i<n;i++){
            swap(arr[i],arr[index]);
            solve(arr,ans,mp,index+1,n);
            swap(arr[i],arr[index]);
        }
        
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        map<vector<int>,int> mp;
        int n = arr.size();
        
        solve(arr,ans,mp,0,n);
        return ans;
    }
};
