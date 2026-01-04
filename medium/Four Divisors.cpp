class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        long long mx=1e5+2;
        static vector<int>res;
        static bool done = 0;

        if(!done)
        {
            done=1;
            res=vector<int>(mx,0);
            vector<long long>primes;
            vector<bool>isprime(mx,1);
            isprime[0]=0;
            isprime[1]=0;
            for(long long i=2;i<mx;i++)
            {
                if(isprime[i]==1)
                {
                    primes.push_back(i);
                    for(long long j=i+i;j<mx;j+=i)isprime[j]=0;
                }
            }

            for(int i=0;i<primes.size();i++)
            {
                if(primes[i]*primes[i]<mx)
                {
                    long long cb=primes[i]*primes[i]*primes[i];
                    if(cb<mx)res[cb]=primes[i]+(primes[i]*primes[i]);
                }
                for(int j=i+1;j<primes.size();j++)
                {
                    long long tp=primes[i]*primes[j];
                    if(tp<mx)res[tp]=primes[i]+primes[j];
                }
            }
        }

        int ans=0;
        for(auto x:nums)if(res[x]!=0)ans+=res[x]+1+x;
        return ans;
    }
};
