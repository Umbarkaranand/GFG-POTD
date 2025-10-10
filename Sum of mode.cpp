class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> modes;
        int sum = 0;
        map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;

            if (i >= k - 1) {
                // Find mode in current window
                int maxFreq = -1, modeVal = INT_MAX;
                for (auto& p : freq) {
                    if (p.second > maxFreq || (p.second == maxFreq && p.first < modeVal)) {
                        maxFreq = p.second;
                        modeVal = p.first;
                    }
                }
                sum+=modeVal;

                // Remove the element going out of the window
                freq[arr[i - k + 1]]--;
                if (freq[arr[i - k + 1]] == 0) {
                    freq.erase(arr[i - k + 1]);
                }
            }
        }

        

        return sum;
    }
};
