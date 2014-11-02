//位操作，将1左移S的位数n，得到2^n个数，代表n个元素的所有组合
//对代表每种组合的数，根据每一位是否为1来代表是否出现在子集中
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > v;
        vector<int> sub;
        int n = S.size();
        int max = 1<<n;
        int j,idx;
        for(int i = 0; i < max; i++)
        {
            sub.clear();
            idx = 0;
            j = i;
            while(j>0)
            {
                if(j&1) sub.push_back(S[idx]);
                idx++;
                j = j>>1;
            }
            v.push_back(sub);
        }
        return v;
    }
};

//树DFS方法，递归构造一颗数，每个元素作为内节点，其左子树代表不包含这个元素的子集，右子树代表包含这个元素的子集，
//有点类似决策树。递归遍历这棵树，直到访问到空节点，返回。
class Solution {
public:
    void generate(vector<int> res,int i, vector<int> &S, vector<vector<int> > &result)
    {
        if(i == S.size())
        {
            result.push_back(res);
            return;
        }
        generate(res,i+1,S,result);
        res.push_back(S[i]);
        generate(res,i+1,S,result);
    }
    vector<vector<int> > subsets(vector<int> &S) {
       vector<vector<int> > result;
       vector<int> res;
       sort(S.begin(),S.end());
       generate(res,0,S,result);
       return result;
    }
};