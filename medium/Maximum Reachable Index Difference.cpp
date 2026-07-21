class Solution {
  public:
    int maxIndexDifference(string &s) 
    {
        int n=s.size();
        int in=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                in=i;
                break;
            }
        }
        if(in==-1)return -1;
        
        vector<vector<int>>v1(26);
        for(int i=0;i<n;i++)v1[s[i]-'a'].push_back(i);
        
        int ans=0;
        int st=in;
        char c=1;
        
        while(c<26)
        {
            auto nxin=lower_bound(v1[c].begin(),v1[c].end(),in)-v1[c].begin();
            if(nxin==v1[c].size())break;
            ans=max(ans,v1[c].back()-st);
            in=v1[c][nxin];
            c++;
        }
        return ans;

    }
};
