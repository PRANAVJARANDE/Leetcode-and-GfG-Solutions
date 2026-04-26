class Solution {
  public:
    int smallestSubstring(string s) 
    {
        int n=s.size();
        
        int ans=INT_MAX;
        int p0=-1,p1=-1,p2=-1;
        for(int i=0;i<n;i++)
        {
           if(s[i]=='0')
           {
                p0=i;
           }
           else if(s[i]=='1')
           {
                p1=i;
           }
           else 
           {
                p2=i;
           }
           
           if(p1!=-1 && p2!=-1 && p0!=-1)
           {
               ans=min(ans,i-min(p1,min(p2,p0))+1);
           }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
        
        
    }
};
