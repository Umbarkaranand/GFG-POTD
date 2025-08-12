class Solution {
  public:
  
    int countPS(string &s) {
        // code here
        int n = s.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;
            while(left>=0 and right<n){
                if(s[left]==s[right]){
                    count++;
                }
                else 
                    break;
                
                left--;
                right++;
            }
        }
        
        for(int i=0;i<n;i++){
            int left=i;
            int right=i+1;
            while(left>=0 and right<n){
                if(s[left]==s[right]){
                    count++;
                }
                else
                    break;
                
                left--;
                right++;
            }
        }
        
        return count;
    }
};
