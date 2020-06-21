//question is basically about count every possible combination of 0s and 1s in
//every possible bit position
#define mod 1000000007
int Solution::cntBits(vector<int> &A) {
    long long n=A.size();
    long long count=0;
    for(int i=0; i<32; i++){
        int c=0;
        for(int j=0;j<A.size();j++){
            c+=((A[j]&(1<<i)) != 0 ? 1 : 0);
        }
        //here c*(n-c) will give all combinations of complimentary bit pairs
        //since we are taking each pair twice here to multiply it by 2 as well
        count=(count+(c*(n-c)*2)%mod)%mod;
    }
    return count%mod;
}
