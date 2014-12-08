class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int g[n];

        for(int i = 0; i < m; i++)
            for(int j = i; j >= 0; j--)
            {
                if(!i && !j) g[j] = triangle[i][j];
                else if(i==j) g[j] = g[j-1] + triangle[i][j];
                else if(i && !j) g[j] = g[j] + triangle[i][j];
                else g[j] = min(g[j],g[j-1]) + triangle[i][j];
            }
        int minValue = g[0];
        for(int i = 0; i < n; i++)
            minValue = min(minValue,g[i]);
            
        return minValue;
    }
};
