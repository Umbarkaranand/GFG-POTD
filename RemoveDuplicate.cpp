#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> count(n, 0); // Array to store count of elements
        
        for(int i = 0; i < n; i++) {
            count[arr[i]]++; // Increment count for each element
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(count[i] > 1) {
                result.push_back(i); // Add element to result if count > 1
            }
        }
        
        if(result.empty()) {
            result.push_back(-1); // No duplicates found
        }
        
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
