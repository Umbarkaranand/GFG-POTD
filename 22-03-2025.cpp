//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dp;
    int solve(vector<int>& arr,int index,int n){
        //base case
        if(index>=n)return 0;
        
        //recursive case
        if(dp[index]!=-1)return dp[index];
        int pick=arr[index]+solve(arr,index+2,n);
        int noPick=solve(arr,index+1,n);
        return dp[index]=max(pick,noPick);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        dp=vector<int>(arr.size()+1,-1);
        int case1=solve(arr,0,arr.size()-1);
        dp=vector<int>(arr.size()+1,-1);
        int case2=solve(arr,1,arr.size());
        return max(case1,case2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
