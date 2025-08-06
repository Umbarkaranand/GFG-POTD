class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int n = s.size();
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int number = 0;
        
        for(int i=n-1;i>=0;i--){
            if(i+1 < n and mp[s[i]]<mp[s[i+1]]){
                number -= mp[s[i]];
            }else{
                number+=mp[s[i]];
            }
        }
        
        return number;
    }
};
