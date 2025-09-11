class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cur=0;
        int mx=INT_MIN;
        int jump=0;
        
        for(int i=0;i<n-1;i++){
            
           
            mx=max(mx,i+arr[i]);
            
            if(cur==i){
                cur=mx;
                jump++;
            }
            
            if(cur>=n-1){
                
                return jump;
            }
        }
        
      
        return -1;
    }
};
