class Solution {
public:
    int countTriples(int n) 
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int lhs=(i*i)+(j*j);
                int sq=sqrt(lhs);
                if(sq*sq==lhs)
                {
                    if(sq<=n)ans++;
                }
            }
        }
        return ans;
    }
};
