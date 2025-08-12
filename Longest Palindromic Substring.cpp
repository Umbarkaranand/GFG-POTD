class Solution {
  public:
  
    string getLongestPal(string &s) {
        // code here
        
        int n = s.size();
        string ans="";
        ans+=s[0];
        int maxCount=0,startIndex,endIndex;
        
        for(int i=0;i<n;i++){
            
            int count=0;
            int left=i-1;
            int right=i+1;
            
            while(left>=0 and right<n){
                if(s[left]==s[right]){
                    count++;
                }else
                    break;
                
                if(count>maxCount){
                    maxCount=count;
                    startIndex=left;
                    endIndex=right;
                    
                }
                
                left--;
                right++;
            }
        }
        
        if(maxCount!=0)
        ans = s.substr(startIndex,(maxCount*2+1));
        
        int evenMaxCount=0;
        
        for(int i=0;i<n;i++){
            
            int left=i;
            int right=i+1;
            int count=0;
            while(left>=0 and right<n){
                if(s[left]==s[right]){
                    count++;
                }else
                    break;
                
                if(count>evenMaxCount){
                    evenMaxCount=count;
                    startIndex=left;
                    endIndex=right;
                }
                
                left--;
                right++;
            }
        }

        if(evenMaxCount>maxCount){
            ans=s.substr(startIndex,(evenMaxCount*2));
        }
        
        return ans;
    }
}; 
