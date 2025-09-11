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
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        vector<int> vp;
        
        for(auto temp:arr){
            while(temp){
                vp.push_back(temp->data);
                temp=temp->next;
            }
        }
        
        sort(vp.begin(),vp.end());
        
        Node *head=new Node(vp[0]);
        Node *temp=head;
        
        for(int i=1;i<vp.size();i++){
            Node *newNode = new Node(vp[i]);
            temp->next=newNode;
            temp=newNode;
        }
        
        return head;
    }
};
