class Solution {
  public:
    void rearrangeQueue(queue<int> &q1) 
    {
        int n=q1.size();
        vector<int>v1;
        while(!q1.empty())
        {
            v1.push_back(q1.front());
            q1.pop();
        }
        int i=0;
        int j=n/2;
        while(j<n)
        {
            q1.push(v1[i++]);
            q1.push(v1[j++]);
        }
    }
};
