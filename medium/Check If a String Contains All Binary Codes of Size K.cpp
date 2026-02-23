class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int n=s.size();
        if(k>n)return 0;
        vector<int>vis(1<<k,0);
        int num=0;
        for(int i=0;i<k;i++)
        {
            num*=2;
            if(s[i]=='1')num++;
        }
        vis[num]=1;
        for(int i=k;i<n;i++)
        {
            if(s[i-k]=='1')num-=(1<<(k-1));
            num*=2;
            if(s[i]=='1')num++;
            vis[num]=1;
        }
        for(auto x:vis)if(x==0)return 0;
        return 1;
    }
};
