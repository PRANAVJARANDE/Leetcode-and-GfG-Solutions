class Solution {
public:

    int minPartitions(string n) 
    {
        sort(n.begin(),n.end());
        int ans=n[0]-'0';
        for(int i=1;i<n.size();i++)ans+=abs(n[i]-n[i-1]);
        return ans;
    }
};
