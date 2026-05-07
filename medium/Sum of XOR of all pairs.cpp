class Solution {
  public:
    long long sumXOR(vector<int> &a) 
    {
        // 2^k = 10^5
        // k = log2(10^5)
        
        // 18 bits to represent 10^5
        
        
        long long ans=0;
        for(long long b=0;b<18;b++)
        {
            long long zc=0,oc=0;
            
            for(auto x:a)
            {
                bool val=(x & (1ll<<b));
                
                long long cnt;
                if(val)cnt=zc;
                else cnt=oc;
                ans+=(1ll<<b)*cnt;
                if(val)oc++;
                else zc++;
            }
        }
        return ans;
    }
};
