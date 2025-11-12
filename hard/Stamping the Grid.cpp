// https://leetcode.com/problems/stamping-the-grid/solutions/7344103/prefix-sum-in-matrix-by-pranavjarande-h9pk

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& a, int h, int w) 
    {
        vector<vector<int>>org=a;
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
            }
        }

        vector<vector<int>>cnt(n,vector<int>(m,0));
        for(int i=h-1;i<n;i++)
        {
            for(int j=w-1;j<m;j++)
            {
                int cs=a[i][j];
                if(i-h>=0)cs-=a[i-h][j];
                if(j-w>=0)cs-=a[i][j-w];
                if(i-h>=0 && j-w>=0)cs+=a[i-h][j-w];
                if(cs==0)
                {
                    cnt[i-h+1][j-w+1]++;
                    if(i+1<n)cnt[i+1][j-w+1]--;
                    if(j+1<m)cnt[i-h+1][j+1]--;
                    if(i+1<n && j+1<m)cnt[i+1][j+1]++;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)cnt[i][j]+=cnt[i-1][j];
                if(j-1>=0)cnt[i][j]+=cnt[i][j-1];
                if(i-1>=0 && j-1>=0)cnt[i][j]-=cnt[i-1][j-1];
                if(cnt[i][j]==0 && org[i][j]==0)return 0;
            }
        }
        return 1; 
    }
};
