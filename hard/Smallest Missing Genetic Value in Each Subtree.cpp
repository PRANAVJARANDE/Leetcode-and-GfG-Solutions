class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parent, vector<int>& nums) 
    {   
        int n=nums.size();
        int in=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                in=i;
                break;
            }
        }
        vector<int>ans(n,1);
        if(in==-1)return ans;
        set<int>s1;
        for(int i=1;i<=1e5+2;i++)s1.insert(i);

        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++)adj[parent[i]].push_back(i);

        while(in!=-1)
        {
            queue<int>q1;
            q1.push(in);
            while(!q1.empty())
            {
                auto in=q1.front();
                q1.pop();
                s1.erase(nums[in]);
                for(auto x:adj[in])
                {
                    if(s1.count(nums[x]))q1.push(x);
                }
            }
            ans[in]=*s1.begin();
            in=parent[in];
        }
        return ans;
    }
};
