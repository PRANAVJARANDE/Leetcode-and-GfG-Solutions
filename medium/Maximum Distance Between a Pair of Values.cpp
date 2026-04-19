class Solution {
public:

/*
    Combine both the arrays
        - Keep track of Element belongs to which array
        - and its index

    Sort the arrays
    
    Iterate over array
    - Keep minimum i index and update mini_i on element of nums1 
    - keep dmax and keep maximum on nums[j] element 

    element- nums1 then mini_i=min(mini_i,index)
    element- nums2 then dmax=max(dmax,index-mini_i)

*/

    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>v1(n+m,vector<int>(3,0));

        for(int i=0;i<n;i++)
        {
            v1[i][0]=nums1[i];
            v1[i][1]=i;
            v1[i][2]=0;
        }

        for(int i=0;i<m;i++)
        {
            v1[n+i][0]=nums2[i];
            v1[n+i][1]=i;
            v1[n+i][2]=1;
        }

        sort(v1.begin(),v1.end());

        int dmax=0;
        int mini_i=INT_MAX;

        for(auto x:v1)
        {
            if(x[2]==0)
            {
                mini_i=min(mini_i,x[1]);
            }
            else
            {
                if(mini_i!=INT_MAX)dmax=max(dmax,x[1]-mini_i);
            }
        }
        return dmax;
    }
};
