class Solution {
public:

    int intersectionSizeTwo(vector<vector<int>>& temp) 
    {
        int n=temp.size();
        sort(temp.begin(),temp.end());
        vector<vector<int>>a;
        a.push_back(temp[0]);
        for(int i=1;i<n;i++)if(temp[i]!=temp[i-1])a.push_back(temp[i]);

        n=a.size();
        vector<vector<int>>v1;
        for(int i=0;i<n;i++)
        {
            bool flag=1;
            int l=a[i][0];
            int r=a[i][1];
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(l<=a[j][0] && a[j][1]<=r)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)v1.push_back(a[i]);
        }

        // v1 has all non-dominated pairs
        sort(v1.begin(),v1.end());
        priority_queue<int,vector<int>,greater<int>>q1;
        int ans=0;
        for(auto x:v1)
        {
            while(!q1.empty() && q1.top()<x[0])q1.pop();
            if(q1.size()<2)
            {
                ans++;
                q1.push(x[1]);
            }
            if(q1.size()<2)
            {
                ans++;
                q1.push(x[1]-1);
            }
        }
        return ans;
    }
};
