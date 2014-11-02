class Solution {
public:
    int jump(int A[], int n) {
        if(n == 1) return 0;
        int i = n-2, s = n-1, c = 0, k;
        while(1)
        {
            while(i>=0)
            {
                if(A[i]+i >= s)
                    k = i;
                i--;
            }
            if(s != k) c++;
            s = k;
            if(!s) return c;
            i = s-1;
        }
        return c;
    }
};