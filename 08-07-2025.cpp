class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int> ans(n,0);
        ans[n-1]=-1;
        stack<int> st;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and mp[st.top()]<=mp[arr[i]]){
                st.pop();
            }
            
            if(st.size()==0){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
            
            st.push(arr[i]);
        }
        
        return ans;
        
    }
};
