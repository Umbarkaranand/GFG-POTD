class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int preHour = stoi(arr[0].substr(0,2));
        int preMinu = stoi(arr[0].substr(3,2));
        int preSec = stoi(arr[0].substr(6,2));
        
        int minDiff = INT_MAX;
        
        for(int i=1;i<n;i++){
            
            int curHour = stoi(arr[i].substr(0,2));
            int curMinu = stoi(arr[i].substr(3,2));
            int curSec = stoi(arr[i].substr(6,2));
            
            int diff = (((curHour-preHour)*60*60)+((curMinu-preMinu)*60)+(curSec-preSec));
            minDiff = min(minDiff,diff);
            
            preHour = curHour;
            preMinu = curMinu;
            preSec = curSec;
        }
        
        int curHour = stoi(arr[0].substr(0,2));
        int curMinu = stoi(arr[0].substr(3,2));
        int curSec = stoi(arr[0].substr(6,2));
        
        int firstTime = ((curHour*60*60)+(curMinu*60)+(curSec));
        int lastTime = ((preHour*60*60)+(preMinu*60)+(preSec));
        
        minDiff = min(minDiff,86400-lastTime+firstTime);
        return minDiff;
    }
};
