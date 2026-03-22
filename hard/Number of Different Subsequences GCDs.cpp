class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) 
    {
        int mx=200003;
        vector<int>v1(mx,-1);

        for(auto x:nums)
        {
            for(int i=1;i<=sqrt(x);i++)
            {
                if(x%i==0)
                {
                    int d1=i;
                    int d2=x/i;
                    if(v1[d1]==-1)v1[d1]=x/d1;
                    else v1[d1]=__gcd(v1[d1],x/d1);
                    if(v1[d2]==-1)v1[d2]=x/d2;
                    else v1[d2]=__gcd(v1[d2],x/d2);
                }
            }
        }

        int ans=0;
        for(int i=0;i<mx;i++)
        {
            if(v1[i]==1)ans++;
        }
        return ans;   
    }
};
