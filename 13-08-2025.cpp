class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        int cnt=0,requiredSoldier=0;
        for(auto a:arr){
            if((a%k)!=0){
                pq.push(k-(a-(a/k)*k));
            }else{
                cnt++;
            }
        }
        
       
        // bool isEven=true;
        // if((arr.size()%2)!=0) isEven=false;
        
        // if(isEven){
        //     if(cnt>=(arr.size()/2))
        //         return requiredSoldier;
        // }else{
        //     if(cnt>(arr.size()/2))
        //         return requiredSoldier;
        // }
        
        int x = ceil(arr.size()/2.0);
        if(cnt>=x) return requiredSoldier;
       
       
        while(!pq.empty()){
            requiredSoldier+=pq.top();
            cnt++;
            pq.pop();
            //   if(isEven){
            //     if(cnt>=(arr.size()/2))
            //         return requiredSoldier;
            //     }else{
            //         if(cnt>(arr.size()/2))
            //             return requiredSoldier;
            //     }
        
             if(cnt>=x) return requiredSoldier;
        }
        
        return requiredSoldier;
    }
};
