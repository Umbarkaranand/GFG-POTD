class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        
        int n = prices.size();
        int minCost=0,maxCost=0;
        sort(prices.begin(),prices.end());
        
        int index=0,cnt=0;
        while(cnt<n){
            cnt+=k;
            cnt++;
            minCost+=prices[index++];
        }
        
        index=n-1,cnt=0;
        while(cnt<n){
            cnt+=k;
            cnt++;
            maxCost+=prices[index--];
        }
        
        return {minCost,maxCost};
    }
};
