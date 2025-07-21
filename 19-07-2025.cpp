class Solution {
  public:
  
    int factorial(int n){
         int sum =1;
        for(int i=1;i<=n;i++){
            sum*=i;
        }
        return sum;
    }
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int> mp;
        int lenSize = s.size();
        
        for(auto a:s){
            if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
                mp[a]++;
        }
        
        if(mp.size()==0)return 0;
        int total = factorial(mp.size());
        
        for(auto a:mp){
            total*=a.second;
        }
        return total;
    }
};
