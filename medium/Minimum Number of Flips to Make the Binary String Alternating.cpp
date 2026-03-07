class Solution {
public:
    int minFlips(string s) 
    {
        int n=s.size();
        s=s+s;

        int ans=n;

        // 101010101
        int sum=0;
        for(int i=0;i<n;i++)if((s[i]-'0')==i%2)sum++;
        ans=min(ans,sum);
        for(int i=n;i<2*n;i++)
        {
            if((s[i]-'0')==i%2)sum++;
            if((s[i-n]-'0')==(i-n)%2)sum--;
            ans=min(ans,sum);
        }

        // 0101010101
        sum=0;
        for(int i=0;i<n;i++)if((s[i]-'0')!=i%2)sum++;
        ans=min(ans,sum);
        for(int i=n;i<2*n;i++)
        {
            if((s[i]-'0')!=i%2)sum++;
            if((s[i-n]-'0')!=(i-n)%2)sum--;
            ans=min(ans,sum);
        }
        return ans;
    }
};
