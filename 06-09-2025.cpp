/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map<Node*,int> mp;
        int ans=0;
        
        while(head){
            mp[head]++;
            if(mp[head]==2)ans++;
            
            if(mp[head]==3)break;
            head=head->next;
        }
        
        
        return ans;
    }
};
