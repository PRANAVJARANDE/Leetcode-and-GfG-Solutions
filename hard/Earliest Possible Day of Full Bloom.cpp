class Solution {
public:

    int earliestFullBloom(vector<int>& p, vector<int>& g) 
    {
        int n=p.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=g[i];
            v1[i][1]=p[i];
        }
        sort(v1.begin(),v1.end(),greater<vector<int>>());
        int ans=v1[0][0]+v1[0][1];
        for(int i=1;i<n;i++)
        {
            v1[i][1]+=v1[i-1][1];
            ans=max(ans,v1[i][0]+v1[i][1]);
        }
        return ans;
    }
};
