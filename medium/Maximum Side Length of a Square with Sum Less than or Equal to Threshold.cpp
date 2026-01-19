class Solution {
public:

    int n,m;
    bool check(int k,vector<vector<int>>&a,int th)
    {
        for(int i=k-1;i<n;i++)
        {
            for(int j=k-1;j<m;j++)
            {
                int sum=a[i][j];
                if(i-k>=0)sum-=a[i-k][j];
                if(j-k>=0)sum-=a[i][j-k];
                if(i-k>=0 && j-k>=0)sum+=a[i-k][j-k];
                if(sum<=th)return 1;
            }
        }
        return 0;
    }




    int maxSideLength(vector<vector<int>>& a, int threshold) 
    {
        n=a.size();
        m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
            }
        }

        int l=1,r=min(n,m);
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a,threshold))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
