int Solution::atoi(const string A) {
    int i=0, sign=1;
    while(A[i]==' ') i++;
    if(A[i]=='+' || A[i]=='-'){
        if(A[i]=='-') sign=-1;
        i++;
    }
    if(A[i]<'0' && A[i]>'9') return 0;
    else{
        long ans=0;
        while(i<A.length() && A[i]>='0' && A[i]<='9'){
            ans=(ans*10) + (int)(A[i]-'0');
            if(sign==-1 && (ans*sign)<=INT_MIN) return INT_MIN;
            else if(ans>=INT_MAX) return INT_MAX;
            i++;
        }
         return ans*sign;
    }
   
}