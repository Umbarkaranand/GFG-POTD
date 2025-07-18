class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if(n<3)return n;
        
        if(n%2!=0) return n*(n-1)*(n-2);
        else if(n%3!=0)return n*(n-1)*(n-3);
        
        return (n-3)*(n-1)*(n-2);
    }
};
