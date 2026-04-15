class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) 
    {
        int n=words.size();
        int ans1=0,cnt=n,in=st;
        while(cnt--)
        {
            if(words[in]==target)break;
            ans1++;
            in=(in+1)%n;
        }
        
        int ans2=0;
        cnt=n,in=st;
        while(cnt--)
        {
            if(words[in]==target)break;
            ans2++;
            in=(in-1+n)%n;
        }
        int res=min(ans1,ans2);
        if(res==n)return -1;
        return res;
    }
};
