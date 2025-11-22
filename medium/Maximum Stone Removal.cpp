class Solution {
  public:
    int maxRemove(vector<vector<int>>& a) 
    {
        int n=a.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int cnt=1;
                queue<int>q1;
                q1.push(i);
                vis[i]=1;
                while(!q1.empty())
                {
                    auto in=q1.front();
                    q1.pop();
                    
                    for(int j=0;j<n;j++)
                    {
                        if(vis[j]==0 && (a[in][0]==a[j][0] || a[in][1]==a[j][1]))
                        {
                            vis[j]=1;
                            cnt++;
                            q1.push(j);
                        }
                    }
                }
                ans+=cnt-1;
            }
        }
        return ans;
    }
};
