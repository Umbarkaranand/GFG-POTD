class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int cnt=1;
        
        for(auto a:arr){
            if(a>=1 and cnt==a){
                cnt++;
            }
        }
        
        return cnt;
        
    }
};
