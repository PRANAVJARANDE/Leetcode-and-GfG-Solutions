class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& a) 
    {
        int ans=0;
        for(int i=1;i<a.size();i++)ans+=max(abs(a[i-1][0]-a[i][0]),abs(a[i-1][1]-a[i][1]));
        return ans;
    }
};
