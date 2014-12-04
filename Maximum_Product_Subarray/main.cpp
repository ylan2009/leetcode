class Solution {
public:
    int maxProduct(int A[], int n) {
        int b=1, f=1, res=INT_MIN;
        for(int i=0; i<n; i++){
            res=max(res, max(b*=A[i],f*=A[n-1-i]));
            if(b==0) b=1; if(f==0) f=1;
        }
        return res;
    }
};
