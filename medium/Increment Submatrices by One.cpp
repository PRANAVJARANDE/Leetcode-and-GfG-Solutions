class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(auto x:queries)
        {
            ans[x[0]][x[1]]++;
            if(x[2]+1<n)ans[x[2]+1][x[1]]--;
            if(x[3]+1<n)ans[x[0]][x[3]+1]--;
            if(x[2]+1<n && x[3]+1<n)ans[x[2]+1][x[3]+1]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-1>=0)ans[i][j]+=ans[i-1][j];
                if(j-1>=0)ans[i][j]+=ans[i][j-1];
                if(i-1>=0 && j-1>=0)ans[i][j]-=ans[i-1][j-1];
            }
        }
        return ans;
    }
};
