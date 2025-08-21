class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        // for(auto a:intervals){
        //     cout<<a[0]<<" "<<a[1]<<endl;
        // }
        int index=0;
        vector<vector<int>> ans;
        while(index<intervals.size()){
           if(index+1<intervals.size() and intervals[index][1]>=intervals[index+1][0]){
               int subIndex=index;
               int EndTime=intervals[index][1];
               while(subIndex+1<intervals.size() and EndTime>=intervals[subIndex+1][0]){
                   subIndex++;
                   EndTime = max(EndTime,intervals[subIndex][1]);
               }
            //  cout<<intervals[subIndex][0]<<endl<<intervals[subIndex][1];
               ans.push_back({min(intervals[index][0],intervals[subIndex][0]),EndTime});
               index=subIndex;
           }else
                ans.push_back({intervals[index][0],intervals[index][1]});
            
            index++;
        }
        
        return ans;
    }
};
