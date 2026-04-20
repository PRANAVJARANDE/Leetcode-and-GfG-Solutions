class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n=colors.size();
        int ans=0;
        int c0=colors[0];
        int cn=colors[n-1];
        for(int i=0; i<n; i++)
        {
            int c=colors[i];
            if(c0!=c)ans=max(ans,i);
            if(cn!=c)ans=max(ans,n-1-i);
        }
        return ans;
    }
};
