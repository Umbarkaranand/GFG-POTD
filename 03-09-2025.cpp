/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* cur=head;
        Node* temp=NULL;
        
       while(cur){
           temp=cur->prev;
           cur->prev=cur->next;
           cur->next=temp;
           cur=cur->prev;
       }
       
       if(temp) return temp->prev;
       return head;
    }
};
