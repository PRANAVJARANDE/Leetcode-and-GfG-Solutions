#define ll long long
class Solution {
public:

    bool check(map<ll,ll>&m,vector<vector<int>>&a,int r1, int r2, int c1, int c2, long long diff) 
    {
        int rows=r2-r1+1;
        int cols=c2-c1+1;
        if(rows*cols==1)return 0;
        if(rows==1)return (a[r1][c1]==diff || a[r1][c2]==diff);
        if(cols==1)return (a[r1][c1]==diff || a[r2][c1]==diff);
        return m.count(diff) && m[diff]>0;
    }

    bool canPartitionGrid(vector<vector<int>>& a) 
    {
        int m=a.size();
        int n=a[0].size();
        ll tsum=0;
        map<ll,ll>m1,m2;

        for(auto row:a) 
        {
            for(auto x:row) 
            {
                tsum+=x;
                m1[x]++;
            }
        }

        ll sum=0;
        for(int i=0;i<m-1;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                sum+=a[i][j];
                m2[a[i][j]]++;
                m1[a[i][j]]--;
            }
            if(sum==tsum-sum)return 1;
            ll diff=abs(2*sum-tsum);
            if(sum>tsum-sum) 
            {
                if(check(m2,a,0,i,0,n-1,diff))return 1;
            } 
            else 
            {
                if(check(m1,a,i+1,m-1,0,n-1,diff))return 1;
            }
        }

        map<ll,ll>left,right;
        for(auto row:a) 
        {
            for(auto x:row) 
            {
                right[x]++;
            }
        }

        sum=0;
        for(int j=0;j<n-1;j++) 
        {
            for(int i=0;i<m;i++) 
            {
                sum+=a[i][j];
                left[a[i][j]]++;
                right[a[i][j]]--;
            }
            if(sum==tsum-sum)return 1;
            ll diff=abs(2*sum-tsum);
            if(2*sum>tsum) 
            {
                if(check(left,a,0,m-1,0,j,diff))return 1;
            } 
            else 
            {
                if(check(right,a,0,m-1,j+1,n-1,diff))return 1;
            }
        }
        return 0;
    }

    
};
