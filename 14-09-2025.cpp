class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int totalGas=0,totalCost=0;
        
        for(int i=0;i<n;i++){
             totalGas+=gas[i];
             totalCost+=cost[i];
        }
        
        if(totalGas<totalCost)return -1;
        
        int ans=0,currentGas=0;
        for(int i=0;i<n;i++){
            currentGas+=(gas[i]-cost[i]);
            if(currentGas<0){
                ans=i+1;
                currentGas=0;
            }
        }
        
        return ans;
        
    }
};
