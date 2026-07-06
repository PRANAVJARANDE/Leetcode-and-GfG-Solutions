class Solution {
public:

    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])return a[0]<b[0];
        else return a[1]>b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);

        int maxi=INT_MIN;
        int cnt=0;
        for(auto x:intervals)
        {
            int l=x[0],r=x[1]-1;
            if(r>maxi)cnt++;
            maxi=max(maxi,r);
        }
        return cnt;
    }
};
