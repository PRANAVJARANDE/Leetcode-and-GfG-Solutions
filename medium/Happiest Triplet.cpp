class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i=0,j=0,k=0;
        int ans=INT_MAX;
        vector<int>res(3);

        while(i<a.size() && j<b.size() && k<c.size())
        {
            int x=a[i],y=b[j],z=c[k];

            int mx = max({x, y, z});
            int mn = min({x, y, z});
            int diff = mx - mn;

            if (diff < ans || (diff == ans && x + y + z < res[0] + res[1] + res[2]))
            {
                ans = diff;
                res = {x, y, z};
            }

            // Move pointer having minimum value
            if (mn == x) i++;
            else if (mn == y) j++;
            else k++;
        }

        sort(res.begin(), res.end(), greater<int>());
        return res;
    }
};
