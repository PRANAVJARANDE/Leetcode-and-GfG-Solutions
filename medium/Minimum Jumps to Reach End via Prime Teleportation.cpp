class Solution {
public:
    
    vector<int>spf;
    void sieve(int mx)
    {
        spf.resize(mx+1);
        for(int i=0;i<=mx;i++)spf[i]=i;
        for(int i=2;i*i<=mx;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<=mx;j+=i)
                {
                    if(spf[j]==j)spf[j]=i;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) 
    {
        int n=nums.size();
        int mx=*max_element(nums.begin(), nums.end());
        sieve(mx);

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            while(x>1)
            {
                int p=spf[x];
                mp[p].push_back(i);
                while(x%p==0)x/=p;
            }
        }

        vector<int>dist(n,-1);
        queue<int>q;
        q.push(0);
        dist[0]=0;

        vector<bool>vis(mx+1,0);

        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            int d=dist[i];
            if(i==n-1)return d;

            // left
            if(i-1>=0 && dist[i-1]==-1)
            {
                dist[i-1]=d+1;
                q.push(i-1);
            }

            // right
            if(i+1<n && dist[i+1]==-1)
            {
                dist[i+1]=d+1;
                q.push(i+1);
            }

            int val=nums[i];
            if(val>1 && spf[val]==val && !vis[val])
            {
                vis[val]=1;
                for(int idx:mp[val])
                {
                    if(dist[idx]==-1)
                    {
                        dist[idx]=d+1;
                        q.push(idx);
                    }
                }
                mp[val].clear();
            }
        }
        return dist[n-1];
    }
};
