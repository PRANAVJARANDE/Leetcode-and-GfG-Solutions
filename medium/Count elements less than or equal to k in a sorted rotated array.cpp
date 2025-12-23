class Solution {
public:
    int countLessEqual(vector<int>& a, int x) 
    {
        int n=a.size();
        int l=0,r=n-1;
        while(l<r) 
        {
            int mid=l+(r-l)/2;
            if(a[mid]>a[r])l=mid+1;
            else r=mid;
        }
        int p=l;
        
        // p -minimum in rotated sorted array
        //cout<<p<<endl;
        if(p==0)
        {
            int in=upper_bound(a.begin(),a.end(),x)-a.begin();
            return in;
        }
        else
        {
            int i1=upper_bound(a.begin(),a.begin()+p,x)-a.begin();
            //cout<<i1<<endl;
            int i2=upper_bound(a.begin()+p,a.end(),x)-(a.begin()+p);
            //cout<<i2<<endl;
            return i1+i2;
        }
        return 0;
        
    }
};
