class Solution {
public:
    int minSwaps(vector<vector<int>>& a)
    {
        int n=a.size();
        vector<int>cnt(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]==1)break;
                else cnt[i]++;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int req=n-i-1;
            if(req<=cnt[i])continue;
            int pv=cnt[i];
            bool flag=0;
            for(int j=i+1;j<n;j++)
            {
                swap(cnt[j],pv);
                ans++;
                if(pv>=req)
                {
                    flag=1;
                    cnt[i]=pv;
                    break;
                }
            }
            if(flag==0)return -1;
        }
        return ans;
    }
};
