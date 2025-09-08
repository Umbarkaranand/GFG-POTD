/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        vector<int> vp;
        Node* temp=head;
        while(temp!=NULL){
            vp.push_back(temp->data);
            temp=temp->next;
        }
        
        sort(vp.begin(),vp.end());
        temp=head;
        for(int i=0;i<vp.size();i++){
            temp->data=vp[i];
            temp=temp->next;
        }
        
        return head;
    }
};
