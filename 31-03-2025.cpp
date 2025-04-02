//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
         stack<char> st;

        for (auto c : s) {
            if (c != ']') {
                st.push(c);
            } else {
                // Step 1: Pop until '[' to get the encoded string
                string temp = "";
                while (!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); // Remove the '['

                // Step 2: Extract the number (could be multi-digit)
                string number = "";
                while (!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }

                int num = stoi(number);
                reverse(temp.begin(), temp.end());

                // Step 3: Repeat the decoded string
                string repeated = "";
                for (int i = 0; i < num; i++) {
                    repeated += temp;
                }

                // Step 4: Push the result back to the stack
                for (auto ch : repeated) {
                    st.push(ch);
                }
            }
        }

        // Step 5: Construct the final result
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
