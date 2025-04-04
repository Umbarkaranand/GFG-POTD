//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
   bool solve(int V, vector<vector<int>>& adj, vector<int>& vis, int src) {
        // Initialize the BFS queue with the source node and its parent (-1 for root)
        queue<pair<int, int>> q; 
        q.push({src, -1});
        vis[src] = 1;  // Mark the source as visited
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;  // The parent of this node
            q.pop();
            
            // Iterate through all adjacent nodes
            for (int adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    // If the adjacent node is not visited, mark it and enqueue it
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (adjacentNode != parent) {
                    // If the adjacent node is visited and is not the parent, there's a cycle
                    return true;
                }
            }
        }
        return false;  // No cycle found
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Create adjacency list for the graph
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Since it's an undirected graph
        }

        vector<int> vis(V, 0);  // Vector to keep track of visited nodes
        
        // Run BFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (solve(V, adj, vis, i)) {
                    return true;  // Cycle detected
                }
            }
        }

        return false;  // No cycle detected in the graph
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
