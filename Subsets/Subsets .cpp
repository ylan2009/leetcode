//λ��������1����S��λ��n���õ�2^n����������n��Ԫ�ص��������
//�Դ���ÿ����ϵ���������ÿһλ�Ƿ�Ϊ1�������Ƿ�������Ӽ���
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

//��DFS�������ݹ鹹��һ������ÿ��Ԫ����Ϊ�ڽڵ㣬�������������������Ԫ�ص��Ӽ�������������������Ԫ�ص��Ӽ���
//�е����ƾ��������ݹ�����������ֱ�����ʵ��սڵ㣬���ء�
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