class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        
        int n = arr.size();
        map<int,int> mp;
        int maxLen  = 0;
        int start = 0;
        int begining=0;
        
        for(int end=0;end<n;end++){
            
            mp[arr[end]]++;
            auto minEle = mp.begin()->first;
            auto maxEle = mp.rbegin()->first;
            
           if(maxEle-minEle <= x){
                if(maxLen < end-start+1){
                maxLen=end-start+1;
                begining=start;
            }
           }
            else{
                while(start<end){
                    mp[arr[start]]--;
                    
                    if(mp[arr[start]]==0){
                        mp.erase(mp.find(arr[start]));
                    }
                    
                      start++;
                
                    auto minEle=mp.begin()->first;
                    auto maxEle=mp.rbegin()->first;
                    
                    if(maxEle-minEle <= x){
                        break;
                    }
                }
                
              
            }
            
        }
        
        vector<int> res;
        for(int i=begining;i<begining+maxLen;i++){
            res.push_back(arr[i]);
        }
        
        return res;
    }
};
