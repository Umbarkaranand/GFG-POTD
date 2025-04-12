//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void solve(vector<vector<int>>& image, int sr, int sc, int newColor, int m, int n, int originalColor){
       //base case
       if(sr<0 || sr>=m || sc<0 || sc>=n)return;
       //recursive case
       if(image[sr][sc]==originalColor){
           image[sr][sc]=newColor;
           solve(image,sr,sc-1,newColor,m,n,originalColor);
           solve(image,sr-1,sc,newColor,m,n,originalColor);
           solve(image,sr,sc+1,newColor,m,n,originalColor);
           solve(image,sr+1,sc,newColor,m,n,originalColor);
       }
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        
        int m = image.size();
        int n = image[0].size();
        int originalColor=image[sr][sc];
        if(originalColor==newColor)return image;
        solve(image,sr,sc,newColor,m,n,originalColor);
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
