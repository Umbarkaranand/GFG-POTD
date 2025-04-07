//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     bool solve(int V, int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &curVis) {
       vis[i] = 1;
       curVis[i] = 1;
       
       for (auto it : adj[i]) {
           if (vis[it] == 0) {
               if (solve(V, it, adj, vis, curVis)) return true;  // Return the result from the recursive call
           } else if (curVis[it] == 1) {
               return true;  // Cycle detected
           }
       }
       curVis[i] = 0;  // Backtrack
       return false;
   }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> vis(V, 0);  // visited nodes
        vector<vector<int>> adj(V);  // adjacency list
        
        // Build the adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        // Initialize the current visited array to handle recursion stack
        for (int i = 0; i < V; i++) {
            vector<int> curVis(V, 0);  // current visit tracking (DFS stack)
            if (!vis[i]) {
                if (solve(V, i, adj, vis, curVis)) return true;
            }
        }
        
        return false;  // No cycle found
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
