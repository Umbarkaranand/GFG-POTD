class Solution {
  public:
  
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n,-1);
        vector<int> next(n,n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and arr[i]<arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                next[i]=st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                prev[i]=st.top();
            }
            st.push(i);
        }
        
        int ans =0;
        
        for(int i=0;i<n;i++){
            ans+= (i-prev[i])*(next[i]-i)*arr[i];
        }
        return ans;
    }
};
