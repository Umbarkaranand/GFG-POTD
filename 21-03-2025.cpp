//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    vector<int>dp;
    int solve(vector<int>& arr,int index){
        //base case
        if(index>=arr.size())return 0;
        //recursive case
        if(dp[index]!=-1)return dp[index];
        int pick = arr[index]+solve(arr,index+2);
        int noPick = solve(arr,index+1);
        return dp[index]=max(pick,noPick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        dp=vector<int>(arr.size()+1,-1);
        return solve(arr,0);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
