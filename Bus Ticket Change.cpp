class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        
        int five=0,ten=0,twenty=0;
        
        for(auto a: arr){
            if(a==5)five++;
            
            else if(a==10){
                if(five==0)return false;
                five--;
                ten++;
            }
            else{
                if((five<3 and ten==0) or five==0) return false;
                if(ten>=1 and five>=1){
                    ten--;
                    five--;
                }else if(ten==0 and five>=3){
                    five-=3;
                }
            }
        }
        
        return true;
        
    }
};
