class Solution {
public:

    int countPrimeSetBits(int left, int right) 
    {
        vector<int>isprime(30,1);
        isprime[0]=0;
        isprime[1]=0;
        for(int i=2;i<30;i++)
        {
            if(isprime[i])
            {
                for(int j=i+i;j<30;j+=i)
                {
                    isprime[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int cnt=0;
            int num=i;
            while(num)
            {
                cnt+=num%2;
                num/=2;
            }
            if(isprime[cnt])ans++;
        }
        return ans;
    }
};
