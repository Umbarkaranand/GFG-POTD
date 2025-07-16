class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        int limit = sqrt(n)+1;
        vector<bool> isPrime(limit,true);
        isPrime[0]=isPrime[1]=false;
        
        for(int i=2;i*i<limit;i++){
            if(isPrime[i]){
                for(int j=i*i;j<limit;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        
        vector<int> primes;
        for(int i=2;i<limit;i++)
        {
            if(isPrime[i]){
                primes.push_back(i);
               
            }
        }
        
        int cnt=0;
        for(auto p: primes){
            long long p8 = 1;
            for(int i=0;i<8;i++){
                p8*=p;
                if(p8>n)break;
            }
            if(p8<=n)cnt++;
        }
        
        for(int i=0;i<primes.size();i++){
            long long p2 = (long long)primes[i]*primes[i];
            if(p2>n)break;
            
            for(int j=i+1;j<primes.size();j++){
                long long q2 = (long long)primes[j]*primes[j];
                
                if(p2*q2<=n)cnt++;
            }
        }
        
        return cnt;
    }
};
