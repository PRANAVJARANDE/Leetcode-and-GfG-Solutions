#define ll long long
class Solution {
public:

    vector<int>dx{1,0};
    vector<int>dy{0,1};
    int minCost(vector<vector<int>>& a, int k) 
    {
        ll n=a.size();
        ll m=a[0].size();
        vector<vector<vector<ll>>>dis(n,vector<vector<ll>>(m,vector<ll>(k+1,INT_MAX)));
        dis[0][0][k]=0;

        vector< pair<ll,pair<ll,ll>> >v1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v1.push_back({a[i][j],{i,j}});
            }
        }
        sort(v1.begin(),v1.end());
        priority_queue<pair<pair<ll,ll>,pair<ll,ll>>,vector<pair<pair<ll,ll>,pair<ll,ll>>>,greater<pair<pair<ll,ll>,pair<ll,ll>>>>q1;
        q1.push({{0,k},{0,0}});

        vector<int>vis(k+1,0);
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            ll cst=pr.first.first;
            ll nk=pr.first.second;
            ll x=pr.second.first;
            ll y=pr.second.second;

            if(x==n-1 && y==m-1)return cst;

            if(cst>dis[x][y][nk])continue;

            for(int z=0;z<2;z++)
            {
                ll nx=x+dx[z],ny=y+dy[z];
                if(nx<n && ny<m && dis[nx][ny][nk]>cst+a[nx][ny])
                {
                    dis[nx][ny][nk]=cst+a[nx][ny];
                    q1.push({{dis[nx][ny][nk],nk},{nx,ny}});
                }
            }
            if(nk==0)continue;

            int in=vis[nk];
            for(;in<v1.size();in++)
            {
                auto pt=v1[in];
                if(pt.first>a[x][y])break;
                int i=pt.second.first;
                int j=pt.second.second;
                if(i==x && j==y)continue;
                if(dis[i][j][nk-1]>cst)
                {
                    dis[i][j][nk-1]=cst;
                    q1.push({{dis[i][j][nk-1],nk-1},{i,j}});
                }
            }
            vis[nk]=in;
        }
        return -1;
    }
};
