class Solution {
public:
    int minMovesToMakePalindrome(string s) 
    {
        int n=s.size();
        int l=0,r=n-1;
        int ct=-1;
        int ans=0;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                int pt=l+1;
                while(pt<r)
                {
                    if(s[r]==s[pt])break;
                    pt++;
                }    
                if(pt==r)
                {
                    ct=pt;
                    r--;
                }
                else
                {
                    int i=pt-1;
                    while(i>=l)
                    {
                        swap(s[i],s[i+1]);
                        ans++;
                        i--;
                    }
                    l++;
                    r--;
                }
                
            }
        }
        if(ct!=-1)ans+=(ct-(n/2));
        return ans;
    }
};
