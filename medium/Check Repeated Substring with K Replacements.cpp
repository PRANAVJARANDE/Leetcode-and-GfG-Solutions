class Solution {
  public:
    
    bool kSubstr(string &s, int k) 
    {
        int n=s.size();
        int in=-1;
        for(int i=0;i<k;i++)
        {
            for(int j=i;j<n;j+=k)
            {
                if(s[i]!=s[j])
                {
                    in=(j/k)*k;
                    break;
                }
            }
            if(in!=-1)break;
        }
        if(in==-1)return 1;
        
        bool flag1=1,flag2=1;
        for(int i=0;i<k;i++)
        {
            set<int>s1;
            for(int j=i;j<n;j+=k)
            {
                if(j>=in && j<in+k)continue;
                s1.insert(s[j]-'a');
            }
            if(s1.size()>1)
            {
                flag1=0;
                break;
            }
        }
        
        for(int i=0;i<k;i++)
        {
            set<int>s1;
            for(int j=i;j<n;j+=k)
            {
                if(j<k)continue;
                s1.insert(s[j]-'a');
            }
            if(s1.size()>1)
            {
                flag2=0;
                break;
            }
        }
        return flag1 || flag2;
    }
};
