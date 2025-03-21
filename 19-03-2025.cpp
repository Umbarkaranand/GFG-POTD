//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices,int k,int index,bool canBuy){
        //base case
        if(index>=prices.size() || k==0)return 0;
        
        //recursive case
        if(dp[index][k][canBuy]!=-1)return dp[index][k][canBuy];
        int involve=0,ignore=0;
        if(canBuy==true){
            involve=-prices[index]+solve(prices,k,index+1,false);
            ignore=solve(prices,k,index+1,true);
        }
        else{
            involve=prices[index]+solve(prices,k-1,index+1,true);
            ignore=solve(prices,k,index+1,false);
        }
        return dp[index][k][canBuy]=max(involve,ignore);
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
       dp=vector<vector<vector<int>>>(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        bool canBuy=true;
        return solve(prices,k,0,canBuy);
        
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
