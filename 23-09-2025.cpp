class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
       
if (q.empty()) return; // Optional: handle empty queue

        stack<int> s;
        // Move all elements from queue to stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        // Move all elements back to queue (reversed)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    
    }
};
