class Solution {
public:

    int n;
    int helper(int in,int&k,vector<int>&v1,vector<int>&v2,vector<int>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];

        int op1=helper(in+1,k,v1,v2,dp);
        int op2=INT_MIN,op3=INT_MIN;
        
        if(v1[in])op2=1+helper(in+k,k,v1,v2,dp);
        if(v2[in])op3=1+helper(in+k+1,k,v1,v2,dp);
        return dp[in]=max(op1,max(op2,op3));
    }

    int maxPalindromes(string s, int k) 
    {
        n=s.size();
        vector<int>v1(n,0),v2(n,0);

        // k
        for(int i=0;i<n;i++)
        {
            int l,r,cnt;
            if(k%2)l=i-1,r=i+1,cnt=k-1;
            else l=i,r=i+1,cnt=k;
            while(l>=0 && r<n && cnt>0 && s[l]==s[r])
            {
                l--;
                r++;
                cnt-=2;
            }
            if(cnt==0)v1[l+1]=1;
        }

        //k+1
        for(int i=0;i<n;i++)
        {
            int l,r,cnt;
            if((k+1)%2)l=i-1,r=i+1,cnt=k;
            else l=i,r=i+1,cnt=k+1;
            while(l>=0 && r<n && cnt>0 && s[l]==s[r])
            {
                l--;
                r++;
                cnt-=2;
            }
            if(cnt==0)v2[l+1]=1;
        }

        vector<int>dp(n,-1);
        int ans=helper(0,k,v1,v2,dp);
        return ans;
    }
};
