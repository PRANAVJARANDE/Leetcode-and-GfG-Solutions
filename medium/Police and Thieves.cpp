class Solution {
  public:
    int catchThieves(vector<char> &a, int k) 
    {
        int i=0,j=0;
        int n=a.size();
        int ans=0;
        while(i<n && j<n)
        {
            while(i<n && a[i]!='P')i++;
            while(j<n && a[j]!='T')j++;
            if(i<n && j<n && abs(i-j)<=k)
            {
                ans++;
                i++;
                j++;
            }
            else if(j<n && j<i)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
