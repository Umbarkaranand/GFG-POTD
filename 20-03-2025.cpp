//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>&prices,int k,int index,bool canBuy){
        //base case
        if(index>=prices.size()||k==0)return 0;
        
        //recursive case
        if(dp[index][k][canBuy]!=-1)return dp[index][k][canBuy];
        int involve=0,ignore=0;
        if(canBuy){
            involve=-prices[index]+solve(prices,k,index+1,false);
            ignore=solve(prices,k,index+1,true);
        }
        else{
            involve=+prices[index]+solve(prices,k-1,index+1,true);
            ignore=solve(prices,k,index+1,false);
        }
        return dp[index][k][canBuy]=max(involve,ignore);
    }
    
    int maxProfit(vector<int> &prices) {
        // code here
        bool canBuy=true;
        dp=vector<vector<vector<int>>>(prices.size()+1,vector<vector<int>>(2+1,vector<int>(2,-1)));
        return solve(prices,2,0,canBuy);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
