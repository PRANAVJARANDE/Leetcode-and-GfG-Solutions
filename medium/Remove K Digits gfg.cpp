class Solution {
  public:
    string removeKdig(string &s, int k) 
    {
        int n=s.size();
        if(n<=k)return "0";
        
        vector<vector<int>>nx(n+1,vector<int>(10,n));
        for(int i=n-1;i>=0;i--)
        {
            nx[i]=nx[i+1];
            nx[i][s[i]-'0']=i;
        }
        
        string ans;
        
        for(int i=0;i<n;)
        {
            bool flag=0;
            for(int d=0;d<10;d++)
            {
                int pos=nx[i][d];
                if(pos==n)continue;
                int to_del=pos-i;
                if(to_del<=k)
                {
                    if(!(ans.empty() && d==0))ans.push_back(d+'0');
                    k-=to_del;
                    i=pos+1;
                    flag=1;
                    break;
                }
            }
            if(!flag)break;
        }
        while(k>0 && !ans.empty()) 
        {
            ans.pop_back();
            k--;
        }
        return ans.empty() ? "0" : ans;;
    }
};
