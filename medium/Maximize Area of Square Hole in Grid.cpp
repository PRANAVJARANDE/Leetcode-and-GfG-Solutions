class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hb, vector<int>& vb) 
    {
        sort(hb.begin(),hb.end());
        sort(vb.begin(),vb.end());

        int ans1=1;
        int c1=1;
        for(int i=1;i<hb.size();i++)
        {
            if(hb[i]==hb[i-1]+1)c1++;
            else c1=1;
            ans1=max(ans1,c1);
        }

        int ans2=1;
        int c2=1;
        for(int i=1;i<vb.size();i++)
        {
            if(vb[i]==vb[i-1]+1)c2++;
            else c2=1;
            ans2=max(ans2,c2);
        }
        int s=1+min(ans1,ans2);
        return s*s;
    }
};
