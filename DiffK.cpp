int Solution::diffPossible(vector<int> &A, int B) {
    int i=0, j=1;
    while(i<j && i<A.size() && j<A.size()){
        if(A[j]-A[i]==B) {
            return 1;
        }else if(A[j]-A[i] > B) {
            i++;
            if(i==j)
            j++;
        }
        else j++;
    }
    return 0;
}
