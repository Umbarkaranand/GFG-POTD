class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 and st.top()<=arr[i]){
                st.pop();
            }
            
            if(st.size()==0){
                int j=0;
                while(j!=i){
                    if(arr[j]>arr[i])break;
                    j++;
                }
                if(i==j)ans[i]=-1;
                else
                ans[i]=arr[j];
            }
            else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        
        return ans;
    }
};
