class Solution {
  public:
    int maxCharGap(string &s) {
        vector<int>fo(26,-1);
        int ans=-1;
        for(int i=0;i<s.size();i++)
        {
            if(fo[s[i]-'a']==-1)fo[s[i]-'a']=i;
            ans=max(ans,i-fo[s[i]-'a']-1);
        }
        return ans;
    }
};
