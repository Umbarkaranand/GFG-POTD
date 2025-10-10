/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        bool flip=false;
        vector<int> ans;
        
        q.push(root);
        
        while(!q.empty()){
            
            int size=q.size();
            vector<int> temp;
             
            while(size){
                
                Node* node = q.front();
                q.pop();
                
                if(flip)temp.push_back(node->data);
                else ans.push_back(node->data);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                size--;
            }
            
            for(int i=temp.size()-1;i>=0;i--)
                ans.push_back(temp[i]);
        
            flip=!flip;
        }
        
        
        return ans;
    }
};
