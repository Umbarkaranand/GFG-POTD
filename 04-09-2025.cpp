/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        vector<vector<int>> vectorPair;
        vector<int> vp;

        Node* temp = head;
        int cnt = 0;

        // Step 1: Collect values in chunks of k
        while (temp) {
            vp.push_back(temp->data);
            cnt++;
            if (cnt == k) {
                reverse(vp.begin(), vp.end()); // reverse only full groups
                vectorPair.push_back(vp);
                vp.clear();
                cnt = 0;
            }
            temp = temp->next;
        }

        // Step 2: Add remaining elements (less than k) without reversing
        if (!vp.empty()) {
            reverse(vp.begin(), vp.end());
            vectorPair.push_back(vp);
        }

        // Step 3: Write back values to the linked list
        temp = head;
        for (auto& group : vectorPair) {
            for (int val : group) {
                temp->data = val;
                temp = temp->next;
            }
        }

        return head;
    }
};
