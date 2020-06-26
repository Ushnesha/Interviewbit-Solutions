int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<3) return 0;
    sort(A.begin(), A.end());
    int l,r, minSum=INT_MAX, sum=0;
    for(int i=0;i<A.size()-2;i++){
        l=i+1;
        r=A.size()-1;
        while(l<r){
            int tmp=A[i]+A[l]+A[r];
            int diff=abs(B-tmp);
            if(diff==0) return B;
            if(minSum > diff){
                minSum=diff;
                sum=tmp;
            }
            if(tmp<B) l++;
            else r--;
        }
    }
    return sum;
}
