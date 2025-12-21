class Solution {
public:
    int minDeletionSize(vector<string>& s) 
    {
        int n=s.size();
        int m=s[0].size();
        int ans=0;
        vector<bool>res(n,0);
        for(int j=0;j<m;j++)
        {
            bool flag=0;
            for(int i=0;i<n-1;i++)
            {
                if(!res[i] && s[i][j]>s[i+1][j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                ans++;
                continue;
            }

            for(int i=0;i<n-1;i++)
            {
                if(!res[i] && s[i][j]<s[i+1][j])
                {
                    res[i]=1;
                }
            }
        }
        return ans;
    }
};
