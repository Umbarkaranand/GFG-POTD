class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q1,q2;
        int size = q.size();
        
        for(int i=0;i<(size/2);i++){
            q1.push(q.front());
            q.pop();
        }
        while(!q.empty()){
            q2.push(q.front());
            q.pop();
        }
        
        bool flag=true;
        while(!q1.empty() and !q2.empty()){
            if(flag){
                q.push(q1.front());
                q1.pop();
                
            }else{
                q.push(q2.front());
                q2.pop();
                
            }
            flag=!flag;
        }
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
    }
};
