class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(),citations.end(),greater<int>());
        int n = citations.size(),index=0;
        
        
        while(index<n and citations[index]>index)
            index++;
        
        return index;
    }
};
