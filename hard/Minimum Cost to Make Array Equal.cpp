#define ll long long
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        int n=nums.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=nums[i];
            v1[i][1]=cost[i];
        }
        sort(v1.begin(),v1.end());
        vector<ll>op1(n),psum(n,0);
        op1[0]=0;
        psum[0]=v1[0][1];
        ll sum=v1[0][1];
        for(int i=1;i<n;i++)
        {
            ll diff=v1[i][0]-v1[i-1][0];
            op1[i]=op1[i-1]+diff*sum;
            psum[i]=psum[i-1]+v1[i][1];
            sum+=v1[i][1];
        }

        vector<ll>op2(n),ssum(n);
        op2[n-1]=0;
        sum=v1[n-1][1];
        ssum[n-1]=v1[n-1][1];
        for(int i=n-2;i>=0;i--)
        {
            ll diff=v1[i+1][0]-v1[i][0];
            op2[i]=op2[i+1]+diff*sum;
            ssum[i]=ssum[i+1]+v1[i][1];
            sum+=v1[i][1];
        }

        ll in=v1[0][0];
        ll ans=min(op2[0],op1[n-1]);
        
        for(int i=1;i<n;i++)
        {
            while(in<=v1[i][0])
            {
                ll res=op2[i]+op1[i-1];
                res+=(v1[i][0]-in)*ssum[i];
                res+=(in-v1[i-1][0])*psum[i-1];
                ans=min(ans,res);
                in++;
            }
        }
        return ans;
    }
};
