vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> res;
    deque<int> Q(B);
    int i;
    for(i=0;i<B;i++){
        while(!Q.empty() && A[i]>=A[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    for(;i<A.size();i++){
        res.push_back(A[Q.front()]);
        while(!Q.empty() && Q.front() <= i-B) Q.pop_front();
        while(!Q.empty() && A[i]>=A[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    res.push_back(A[Q.front()]);
    return res;
}
