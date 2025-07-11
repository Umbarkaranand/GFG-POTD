class Solution {
  public:
    int countConsec(int n) {
        // code here
        
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        if(n<3)return dp[n];
        
        int a=0,b=1;
        for(int i=3;i<=n;i++){
            int c = a+b;
            dp[i]=dp[i-1]*2+c;
            a=b;
            b=c;
        }
        return dp[n];
    }
};
