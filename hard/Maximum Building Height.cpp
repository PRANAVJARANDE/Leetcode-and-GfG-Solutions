class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) 
    {
        rest.push_back({1,0});
        sort(rest.begin(),rest.end());

        int sz=rest.size();
        for(int i=1;i<sz;i++)
        {
            int dis=rest[i][0]-rest[i-1][0];
            rest[i][1]=min(rest[i][1],dis+rest[i-1][1]);
        }

        for(int i=sz-2;i>=0;i--)
        {
            int dis=rest[i+1][0]-rest[i][0];
            rest[i][1]=min(rest[i][1],dis+rest[i+1][1]);
        }


        // for(auto x:rest)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }

        int ans=n-rest.back()[0]+rest.back()[1];
        for(int i=1;i<sz;i++)
        {
            int diff=rest[i][0]-rest[i-1][0]-1;
            diff-=abs(rest[i][1]-rest[i-1][1]);
            int ta=(diff+1)/2;
            ta+=max(rest[i-1][1],rest[i][1]);  
            ans=max(ans,ta);
        }
        return ans;
    }
};
