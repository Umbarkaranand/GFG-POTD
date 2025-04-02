//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void dfsSolve(int start,vector<vector<int>>& adj,vector<int>& res,vector<int>& v){
        if(v[start]==1)return;
        
        v[start]=1;
        res.push_back(start);
        
        for(auto it:adj[start]){
            if(v[it]==0)dfsSolve(it,adj,res,v);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        int n = adj.size();
        vector<int> res;
        vector<int> v(n+1,0);
        
        for(int i=0;i<n;i++){
            if(v[i]==0)dfsSolve(i,adj,res,v);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
