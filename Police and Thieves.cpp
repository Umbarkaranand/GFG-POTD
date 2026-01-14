class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        
        queue<int> p,t;
        int n = arr.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]=='P')p.push(i);
            else t.push(i);
            
            while(!p.empty() and !t.empty()){
                if(abs(p.front()-t.front())<=k){
                    ans++;
                    p.pop();
                    t.pop();
                }
                else{
                    if(p.front()<t.front()){
                        p.pop();
                    }else{
                        t.pop();
                    }
                }
            }
            
        }
        return ans;
    }
};
