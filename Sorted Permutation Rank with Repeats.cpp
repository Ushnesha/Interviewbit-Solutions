#define mod 1000003

long long binary_exp(int m, int n){
    if(n==0) return 1;
    else if(n==1) return m%mod;
    long long res = binary_exp(m, n/2);
    long long temp = (res*res)%mod;
    if(n%2==0) return temp;
    else return ((m%mod)*temp)%mod;
}

long long fact(int n){
    int mul=1;
    for(int i=1;i<=n;i++)
        mul=(mul*i)%mod;
    return mul%mod;
}

int Solution::findRank(string A) {
    int n=A.length();
    long long t_count=1;
    for(int i=0;i<n;i++){
        int less_count=0;
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]) less_count++;
        }
        int d_count[52]={0};
        for(int j=i;j<n;j++){
            if((int)A[j]>='A'&&(int)A[j]<='Z') d_count[A[j]-'A']++;
            else d_count[A[j]-'a'+26]++;
        }
        
        long long denom=1;
        for(int ele : d_count){
            denom=(denom*fact(ele))%mod;
        }
        // Permutation(abaa) = 4!/3! 
        //(m!/n!) where m=number of letters, n=number of repeated letters
        //here used the fact that (a/b)%mod = ((a%mod)*((b^mod-2)%mod))%mod
        long long numer=(less_count*fact(n-i-1))%mod;
        t_count=(t_count+(numer*(binary_exp(denom,mod-2)%mod))%mod)%mod;
    }
    return t_count%mod;
}
