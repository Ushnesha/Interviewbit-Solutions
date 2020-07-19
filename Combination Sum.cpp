//https://www.interviewbit.com/problems/combination-sum/


void fillComb(set<vector<int>>& ans, vector<int> vec, int target, vector<int> A, int ind){
    if(target==0){
        ans.insert(vec);
        return;
    }
    for(int i=ind;i<A.size() && target-A[i]>=0;i++){
        if(i && A[i]==A[i-1]) continue;
        vec.push_back(A[i]);
        fillComb(ans, vec, target-A[i], A, i);
        vec.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    set<vector<int>> res;
    fillComb(res, vector<int>(), B, A, 0);
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}
