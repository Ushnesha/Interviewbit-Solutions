#define mod 1000003
#define MAX 256
int fact(int n){
    int mul=1;
    for(int i=1;i<=n;i++)
        mul=(mul*i)%mod;
    return mul;
}

int Solution::findRank(string A) {
    int len=A.length(), ans=1;
    for(int i=0;i<len;i++){
        int c=0;
        for(int j=i+1;j<len;j++)
            if(A[j]<A[i]) c++;
        ans+=(c*fact(len-i-1))%mod;
    }
    return ans%mod;
}
