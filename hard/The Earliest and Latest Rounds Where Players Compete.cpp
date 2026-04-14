class Solution {
public:

    //mini maxi
    pair<int,int> helper(int p1,int p2,int n)
    {
        if(p1>p2)swap(p1,p2);
        if(p1+p2==n+1)return {1,1};
        if(n<=4)return {2,2};

        if(p1>n-p2+1)
        {
            int temp=n-p1+1;
            p1=n+1-p2;
            p2=temp;
        }

        int mid=(n+1)/2;    
        int mini=n,maxi=1;
        if(2*p2<=n+1)
        {
            for(int i=0;i<=p1-1;i++)
            {
                for(int j=0;j<=p2-p1-1;j++)
                {
                    auto pr=helper(i+1,i+j+2,mid);
                    mini=min(mini,pr.first+1);
                    maxi=max(maxi,pr.second+1);
                }
            }
        }
        else
        {   
            int tp=n+1-p2;
            int gp=p2-tp-1;
            for(int i=0;i<=p1-1;i++)
            {
                for(int j=0;j<=tp-p1-1;j++)
                {
                    int ex=(p1+p2-n-1)/2;
                    auto pr=helper(i+1,i+j+1+(gp+1)/2 + 1,mid);
                    mini=min(mini,pr.first+1);
                    maxi=max(maxi,pr.second+1);
                }
            }
        }
        return {mini,maxi};
    }

    vector<int> earliestAndLatest(int n, int p1, int p2) 
    {
        auto pr=helper(p1,p2,n);
        return {pr.first,pr.second};
    }
};
