class Solution {
  public:
    
    void solve(vector<int>& arr,int n,int index,set<vector<int>>& st){
        //base case
        if(index>=n){
            st.insert(arr);
            return;
        }
        
        //recursive case
        for(int i=index;i<n;i++){
            swap(arr[index],arr[i]);
            solve(arr,n,index+1,st);
            swap(arr[i],arr[index]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n = arr.size();
        set<vector<int>> st;
        solve(arr,n,0,st);
        
        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        
        return ans;
    }
};
