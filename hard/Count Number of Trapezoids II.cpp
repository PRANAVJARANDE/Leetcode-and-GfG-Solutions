#define ll long long
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& a) 
    {
        // { slope , {intercept,count}}
        map<double,map<double,int>>m;
        map<pair<int,int>,map<double,int>>temp;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double dx=a[i][0]-a[j][0];
                double dy=a[i][1]-a[j][1];
                double s,c;
                if(dx==0)
                {
                    s=1e9+7;
                    c=a[i][0];
                }
                else
                {
                    s=dy/dx;
                    c=(((double)a[i][1]*dx)-( (double)a[i][0]*dy) )/dx;
                }
                int xmid=a[i][0]+a[j][0];
                int ymid=a[i][1]+a[j][1];
                temp[{xmid,ymid}][s]++;
                m[s][c]++;
            }
        }
        ll ans=0;
        for(auto x:m)
        {
            ll ps=0;
            for(auto z:x.second)
            {
                ans+=(z.second*ps);
                ps+=z.second;
            }
        }

        for(auto x:temp)
        {
            ll ps=0;
            for(auto z:x.second)
            {
                ans-=(z.second*ps);
                ps+=z.second;
            }
        }
   
        return ans;
    }
};
