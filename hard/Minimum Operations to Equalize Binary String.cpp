class Solution {
public:
    int minOperations(string s, int k) 
    {
        int n=s.size();
        int m=0;
        vector<int>dis(n+1,INT_MAX);
        vector<set<int>>s1(2);
        for(auto x:s)if(x=='0')m++;
        for(int i=0;i<=n;i++)s1[i%2].insert(i);
        queue<int>q1;
        q1.push(m);
        dis[m]=0;
        s1[m%2].erase(m);   
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();
            int c1=max(0,k-n+in);
            int c2=min(k,in);
            int maxi=in+k-2*c1;
            int mini=in+k-2*c2;
            int flag=(in+k)%2;
            auto itr=s1[flag].lower_bound(mini);
            while(itr!=s1[flag].end() && *itr<=maxi)
            {
                int nxt=*itr;
                itr=s1[flag].erase(itr);
                dis[nxt]=dis[in]+1;
                if(nxt==0) return dis[nxt];  
                q1.push(nxt);
            }
        }
        if(dis[0]==INT_MAX)dis[0]=-1;
        return dis[0];
    }
};
