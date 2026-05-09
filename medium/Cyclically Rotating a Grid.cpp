class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        int m=a[0].size();

        for(int i=0;i<min(n,m)/2;i++)
        {
            int in=0;
            map<int,int>mp;
            for(int j=i;j<m-i;j++)mp[in++]=a[i][j];
            for(int r=i+1;r<n-i;r++)mp[in++]=a[r][m-i-1];
            for(int c=m-i-2;c>=i;c--)mp[in++]=a[n-i-1][c];
            for(int r=n-i-2;r>=i+1;r--)mp[in++]=a[r][i];
            
            int sz=in;
            in=0;
            for(int j=i;j<m-i;j++)
            {
                a[i][j]=mp[(in+k)%sz];
                in++;
            }
            for(int r=i+1;r<n-i;r++)
            {
                a[r][m-i-1]=mp[(in+k)%sz];
                in++;
            }
            for(int c=m-i-2;c>=i;c--)
            {
                a[n-i-1][c]=mp[(in+k)%sz];
                in++;
            }
            for(int r=n-i-2;r>=i+1;r--)
            {
                a[r][i]=mp[(in+k)%sz];
                in++;
            }
        }
        return a;
    }
};
