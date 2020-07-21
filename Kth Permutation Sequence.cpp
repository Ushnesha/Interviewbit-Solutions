https://www.interviewbit.com/problems/kth-permutation-sequence/

string Solution::getPermutation(int A, int B) {
    vector<int> ans;
    string s="";
    for(int i=1;i<=A;i++) ans.push_back(i);
    int i=1;
    do{
        if(i==B) break;
        i++;}while(next_permutation(ans.begin(), ans.end()));
    for(int s1 : ans) s+=to_string(s1);
    return s;
}
