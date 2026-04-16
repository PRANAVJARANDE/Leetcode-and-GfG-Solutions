class Solution {
  public:
    int myAtoi(string &s) 
    {
        int n=s.size();
        int flag=1;
        long long ans=0;
        int i=0;
        while(i<n && s[i]==' ')i++;
        if(s[i]=='-')
        {
            flag=-1;
            i++;
        }
        if(s[i]=='+')i++;
        
        while(i<n && '0'<=s[i] && s[i]<='9')
        {
            ans*=10;
            ans+=s[i]-'0';
            if(flag==1 && ans>INT_MAX)
            {
                return INT_MAX;
            }
            if(flag==-1 && -ans<INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }
        ans*=flag;
        return ans;
    }
};
