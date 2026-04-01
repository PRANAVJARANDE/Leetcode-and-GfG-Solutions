class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) 
    {
        int n=pos.size();
        vector<vector<int>>v1(n,vector<int>(4,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=pos[i];
            v1[i][1]=h[i];
            if(dir[i]=='R')v1[i][2]=0;
            else v1[i][2]=1;
            v1[i][3]=i;
        }
        sort(v1.begin(),v1.end());
        
        vector<int>ans(n,-1);
        stack<pair<int,int>>s1;

        int in=0;
        for(auto x:v1)
        {
            int h=x[1];
            int d=x[2];
            int in=x[3];

            if(d==1)
            {
                while(!s1.empty() && s1.top().first<h && h>0)
                {
                    h--;
                    s1.pop();
                }
                if(!s1.empty() && s1.top().first==h)
                {
                    s1.pop();
                    continue;
                }
                if(h==0)continue;
                if(s1.empty())ans[in]=h;
                else
                {
                    auto pr=s1.top();
                    s1.pop();
                    s1.push({pr.first-1,pr.second});
                }
            }
            else
            {
                s1.push({h,in});
            }
        }

        while(!s1.empty())
        {
            ans[s1.top().second]=s1.top().first;
            s1.pop();
        }

        vector<int>res;
        for(auto x:ans)
        {
            if(x!=-1)res.push_back(x);
        }
        return res;
    }
};
