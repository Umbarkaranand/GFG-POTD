//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> dp;
    int solve(string &digits,int n,int index){
        //base case
        if(index==n)return 1;
        if(digits[index]=='0')return 0;
        //recursive case
        if(dp[index]!=-1)return dp[index];
        int one=solve(digits,n,index+1);
        int two=0;
        if(index + 1 < n &&  (digits[index]=='1' || (digits[index]=='2' && digits[index+1]<='6')))
        two=solve(digits,n,index+2);
        return dp[index]= one+two;
    }
    int countWays(string &digits) {
        // Code here
        dp=vector<int>(digits.size(),-1);
        return solve(digits,digits.size(),0);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
