class Solution {
  public:
  
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int,int> mp;
        for(auto it:intervals){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int ans=-1;
        int count=0;
        for(auto a:mp){
            if(count>=k and count+a.second<k)
                ans=a.first-1;
            
            count+=a.second;
            if(count>=k)
                ans=a.first;
        }
        
        return ans;
    }
};
