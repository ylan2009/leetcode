class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0, s;
        if(n == 0) return false;
        while( i < n-1)
        {
            while(A[i] == 0)
            {
                s = i;
                do{i--;}while(i>=0 && A[i]+i<=s);
            }
            if(i<0) return false;
            i += A[i];
        }
        return true;
    }
};