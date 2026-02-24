class Solution {
  public:
    
    int equalSumSpan(vector<int> &a1, vector<int> &a2) 
    {
        unordered_map<int,int>m;
        m[0]=-1;
        int n=a1.size();
        int ans=0;
        int s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            s1+=a1[i];
            s2+=a2[i];
            int diff=s1-s2;
            if(m.find(diff)!=m.end())ans=max(i-m[diff],ans);
            if(m.find(diff)==m.end())m[diff]=i;
        }
        return ans;
    }
};
