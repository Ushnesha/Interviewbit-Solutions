int Solution::singleNumber(const vector<int> &A) {
    int aux[32]={0};
    int res=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<A.size();j++){
           count+=((A[j]&(1<<i)) != 0 ? 1 : 0);
        }
        aux[31-i]=count%3;
    }
    for(int i=0;i<32;i++){
        res=res*2+aux[i];
    }
    return res;
}
