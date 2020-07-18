//https://www.interviewbit.com/problems/combinations/

void combination(vector<vector<int>>& vec, int index, int A, int B, vector<int> v){
    if(v.size()==B){
        vec.push_back(v);
        return;
    }
    for(int i=index; i<=A; i++){
        v.push_back(i);
        combination(vec, i+1, A, B, v);
        v.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> res;
    combination(res, 1, A, B, vector<int>());
    return res;
}
