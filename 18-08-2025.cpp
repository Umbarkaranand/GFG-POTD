class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)temp.push_back({arr[i],i});
        sort(temp.begin(),temp.end());
        
        vector<int> ans(n,-1);
        int m=-1;
        for(int i=0;i<n;i++){
            if(m>temp[i].second)ans[temp[i].second]=m;
            m=max(m,temp[i].second);
        }
        
        return ans;
    }
};
