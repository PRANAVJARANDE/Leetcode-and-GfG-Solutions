#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        ll tsum=0;
        for(auto x:grid)for(auto y:x)tsum+=y;

        ll sum=0;
        for(auto x:grid)
        {
            for(auto y:x)sum+=y;
            if(sum==tsum-sum)return 1;
        }

        sum=0;
        for(int j=0;j<grid[0].size();j++)
        {
            for(int i=0;i<grid.size();i++)
            {
                sum+=grid[i][j];
            }
            if(sum==tsum-sum)return 1;
        }
        return 0;
    }
};
