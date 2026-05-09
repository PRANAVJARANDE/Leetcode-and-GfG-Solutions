class Solution {
  public:
    
    long long calc(vector<vector<double>>& a)
    {
        int n = a.size();
        double det = 1;

        for(int i = 0; i < n; i++)
        {
            int pivot = i;

            for(int j = i; j < n; j++)
            {
                if(abs(a[j][i]) > abs(a[pivot][i]))
                {
                    pivot = j;
                }
            }

            if(abs(a[pivot][i]) < 1e-9)
            {
                return 0;
            }

            if(i != pivot)
            {
                swap(a[i], a[pivot]);
                det *= -1;
            }

            det *= a[i][i];

            for(int j = i + 1; j < n; j++)
            {
                double factor = a[j][i] / a[i][i];

                for(int k = i; k < n; k++)
                {
                    a[j][k] -= factor * a[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<double>> a(n, vector<double>(n, 0));

        for(auto x : edges)
        {
            int u = x[0];
            int v = x[1];

            a[u][v] = -1;
            a[v][u] = -1;

            a[u][u]++;
            a[v][v]++;
        }

        a.pop_back();

        for(int i = 0; i < n - 1; i++)
        {
            a[i].pop_back();
        }

        return calc(a);
    }
};
