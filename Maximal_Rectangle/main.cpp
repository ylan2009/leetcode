class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty() || !matrix.size() || !matrix[0].size()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int h[n+1];
        int maxArea = 0;
        for(int i = 0; i <= n; i++)
            h[i] = 0;
        for(int i = 0; i < m; i++)
        {
            stack<int> s;
            for(int j = 0; j <= n; j++)
            {
                if(j<n)
                {
                    if(matrix[i][j] == '1') h[j]++;
                    else h[j] = 0;
                }
                if(s.empty() || h[s.top()]<= h[j])
                    s.push(j);
                else
                {
                    while(!s.empty() && h[s.top()]>h[j])
                    {
                        int t = s.top();
                        s.pop();
                        int tmp = h[t] * (s.empty()?j:(j-1-s.top()));
                        maxArea = max(maxArea,tmp);
                    }
                    s.push(j);
                }
            }
        }
        return maxArea;
    }
};
