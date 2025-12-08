class Solution {
  public:
    int subsetXORSum(vector<int>& a) 
    {
        int n=a.size();
        int ans=0;
        
        for(int i=0;i<31;i++)
        {
            int oc=0,zc=0;
            for(int &x:a)
            {
                if(x%2)oc++;
                else zc++;
                x/=2;
            }
            if(oc==0)continue;
            int cnt=(1<<(oc-1))*(1<<zc);
            ans+=(cnt)*(1<<i);
        }
        return ans;
    }
};
