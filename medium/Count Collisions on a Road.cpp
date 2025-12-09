class Solution {
public:
    int countCollisions(string s) 
    {
        int n=s.size();
        int ans=0;
        deque<char>temp1;
        for(int i=0;i<n;i++)
        {
            if(temp1.empty())temp1.push_back(s[i]);
            else
            {
                if(temp1.back()=='R' && s[i]=='L')
                {
                    ans+=2;
                    temp1.pop_back();
                    temp1.push_back('S');
                }
                else temp1.push_back(s[i]);
            }
        }

        // cout<<ans<<endl;
        // while(!temp1.empty())
        // {
        //     cout<<temp1.front()<<" ";
        //     temp1.pop_front();
        // }

        while(!temp1.empty() && temp1.front()=='L')temp1.pop_front();
        while(!temp1.empty() && temp1.back()=='R')temp1.pop_back();

        while(!temp1.empty())
        {
            if(temp1.back()!='S')ans++;
            temp1.pop_back();
        }
        return ans;
    }
};
