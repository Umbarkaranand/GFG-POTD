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
    Node* swapKth(Node* head, int k) {
        // code here
        
        Node* temp=head;
        int kCnt=0;
        while(temp){
            temp=temp->next;
            kCnt++;
        }
        
        int count=1,l=kCnt-k+1;
        int valueFirst=-1,valueSecond=-1;
        
        temp=head; 
        while(temp){
            if(count==k){
                valueFirst=temp->data;
            }
            if(count==l){
                valueSecond=temp->data;
            }
            count++;
            temp=temp->next;
        }
        
        temp=head;
        count=1;
        
        while(temp){
             if(count==k){
               temp->data= valueSecond;
            }
            if(count==l){
                temp->data=valueFirst;
            }
            count++;
            temp=temp->next;
        }
        
        return head;
    }
};
