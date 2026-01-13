class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int n = arr.size();
        int ind=0;
        
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
            if(i-ind+1 ==k){
                while(pq.top().second < ind)pq.pop();
                ans.push_back({pq.top().first});
                ind++;
            }
        }
        
        return ans;
    }
};          
