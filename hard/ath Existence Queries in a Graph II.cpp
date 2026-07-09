class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<int> pos(n);
        for(int i=0;i<n;i++)
        {
            nums[i]=v[i].first;
            pos[v[i].second]=i;
        }

        vector<int>comp(n);
        comp[0]=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i - 1]<=maxDiff)comp[i]=comp[i-1];
            else comp[i]=comp[i-1]+1;
        }

        vector<int>nxt(n);
        int r=0;
        for(int l=0;l<n;l++)
        {
            while(r+1<n && nums[r + 1]-nums[l]<=maxDiff)r++;
            nxt[l]=r;
        }

        int LOG=1;
        while((1LL<<LOG)<=n)LOG++;

        vector<vector<int>>up(LOG,vector<int>(n));

        for(int i=0;i<n;i++)up[0][i]=nxt[i];
        for(int j=1;j<LOG;j++)
        {
            for(int i=0;i<n;i++)
            {
                up[j][i]=up[j-1][up[j-1][i]];
            }
        }

        vector<int>ans;
        for(auto q:queries)
        {
            int u=pos[q[0]];
            int v=pos[q[1]];
            if(u==v)
            {
                ans.push_back(0);
                continue;
            }
            int l=min(u,v);
            int target=max(u,v);
            if(comp[l]!=comp[target])
            {
                ans.push_back(-1);
                continue;
            }

            int steps=0;
            int cur=l;
            for(int j=LOG-1;j>=0;j--)
            {
                if(up[j][cur]<target)
                {
                    cur=up[j][cur];
                    steps+=(1<<j);
                }
            }
            ans.push_back(steps+1);
        }
        return ans;
    }
};
