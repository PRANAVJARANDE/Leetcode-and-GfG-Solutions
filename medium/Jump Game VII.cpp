class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n=s.size();
        if(s[n-1]!='0')return 0;
        set<int>v1;
        for(int i=1;i<n;i++)if(s[i]=='0')v1.insert(i);
        queue<int>q1;
        q1.push(0);

        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();

            auto itr=v1.lower_bound(in+minJump);
            while(itr!=v1.end() && (*itr)<=in+maxJump)
            {
                q1.push(*itr);
                itr++;
            }
            itr=v1.lower_bound(in+minJump);
            while(itr!=v1.end() && (*itr)<=in+maxJump)
            {
                v1.erase(itr);
                itr++;
            }
        }
        return !v1.count(n-1);
    }
};
