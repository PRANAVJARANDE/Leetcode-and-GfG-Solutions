class Solution {
public:
    int maximumGood(vector<vector<int>>& a) 
    {
        int ans=0;
        int n=a.size();
        for(int i=1;i<(1<<n);i++)
        {
            int cnt=0;
            bool flag=1;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    cnt++;
                    for(int z=0;z<n;z++)
                    {
                        if(a[j][z]==1)
                        {
                            if(!(i & (1<<z)))
                            {
                                flag=0;
                                break;
                            }
                        }
                        else if(a[j][z]==0)
                        {
                            if(i & (1<<z))
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    if(flag==0)break;
                }
            }
            if(flag)ans=max(ans,cnt);
        }
        return ans;
    }
};
