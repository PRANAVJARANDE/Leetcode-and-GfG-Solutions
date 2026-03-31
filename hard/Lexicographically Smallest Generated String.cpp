class Solution {
public:
    string generateString(string s1, string s2) 
    {
        int n=s1.size(); 
        int m=s2.size();

        string ans(n+m-1,'a');
        vector<bool>vis(n+m-1,0);

        for(int i=0;i<n;i++) 
        {
            if(s1[i]=='T')
            {
                for(int j=i;j<i+m;j++) 
                {
                    if(vis[j] && ans[j]!=s2[j-i])return "";
                    else 
                    {
                        ans[j]=s2[j-i];
                        vis[j]=1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++) 
        {
            if(s1[i]=='F') 
            {
                bool flag=1;
                int in=-1;
                for(int j=i+m-1;j>=i;j--) 
                {
                    if(s2[j-i]!=ans[j]) 
                    {
                        flag=0;
                        break;
                    }
                    if(in==-1 && !vis[j])in=j;
                }
                if(!flag)continue;
                else if (in!=-1)ans[in]='b';
                else return "";
            }
        }
        return ans;
    }
};
