class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        map<int,int>m;
        for(auto x:nums)m[x]++;

        if(m[1]%2==0 && m[1]!=0)m[1]--;
        int ans=m[1];

        map<int,int>vis;
        for(auto x:m)
        {
            if(x.first==1)continue;
            long long in=x.first;
            if(vis[in])continue;

            int cnt=0;
            while(m[in]>=2 && in<=1e9)
            {
                vis[in]=1;
                cnt+=2;
                in=in*in;
            }

            if(m[in]==1)
            {
                vis[in]=1;
                cnt++;
            }
            else cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
