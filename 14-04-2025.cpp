//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<bool> present(26,false);
        vector<int> inOrder(26,0);
        
        for(auto word:words){
            for(auto a:word){
                present[a-'a']=true;
            }
        }
        
        for(int i=0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            bool check = false;
            
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    check=true;
                    inOrder[s2[ptr]-'a']++;
                    break;
                }
            }
            
             if (!check && s1.length() > s2.length()) {
                return "";
            }
            
        }
        
        queue<int> q;
        for(int i=0;i<26;i++){
            if(present[i] && inOrder[i]==0) 
                q.push(i);
        }
        
        string ans="";
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans+=node+'a';
            
            for(auto it:adj[node]){
                inOrder[it]--;
                if(inOrder[it]==0){
                    q.push(it);
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (present[i] && inOrder[i] > 0) {
                return "";  // Cycle detected
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
