/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node *build(vector<int>& pre,vector<int>& post,int& preIndex,int l,int h,int size){
        //base case
        if(preIndex>=size|| l>h){
            return nullptr;
        }
        //recursive case
        Node* root = new Node(pre[preIndex]);
        preIndex++;
        
        if(l==h)return root;
        
        int i;
        for(i=l;i<=h;i++){
            if(pre[preIndex]==post[i])
                break;
        }
        
        if(i<=h){
            root->left = build(pre,post,preIndex,l,i,size);
            root->right = build(pre,post,preIndex,i+1,h-1,size);
        }
        
        return root;
        
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int size = pre.size();
        int preIndex=0;
        return build(pre,post,preIndex,0,size-1,size);
    }
};
