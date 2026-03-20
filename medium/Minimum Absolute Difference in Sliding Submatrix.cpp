class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<=n-k;i++)
        {
            vector<int>res;
            for(int j=0;j<=m-k;j++)
            {
                vector<int>v1;
                for(int r=0;r<k;r++)
                {
                    for(int c=0;c<k;c++)
                    {
                        v1.push_back(a[i+r][j+c]);
                    }
                }
                sort(v1.begin(),v1.end());
                int ans=INT_MAX;
                for(int i=1;i<v1.size();i++)
                {
                    if(v1[i]==v1[i-1])continue;
                    ans=min(ans,v1[i]-v1[i-1]);
                }
                if(v1.size()==1)ans=0;
                if(ans==INT_MAX)ans=0;
                res.push_back(ans);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
