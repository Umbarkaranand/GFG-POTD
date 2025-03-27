//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> dp;
    bool solve(string &s,set<string> &st,int index){
        //base case
        if(index==s.size())return 1;
        //recursive case
        if(dp[index]!=-1)return dp[index];
        string temp="";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(solve(s,st,i+1))return dp[index]=1;
            }
        }
        return dp[index]=0;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        set<string> st;
        dp=vector<int>(s.size()+1,-1);
        for(auto it:dictionary)st.insert(it);
        return solve(s,st,0);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
