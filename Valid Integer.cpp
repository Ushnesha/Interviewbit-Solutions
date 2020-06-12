int Solution::isNumber(const string A) {
    int i=0, j=A.length()-1;
    while(A[i]==' ' && i<A.length()) i++;
    while(A[j]==' ' && j>=0) j--;
    if(i>j) return 0;
    if(i==j && (A[i]<'0' || A[i]>'9')) return 0;
    if(A[i]!='+' && A[i]!='-' && A[i]!='.' && (A[i]<'0' || A[i]>'9')) return 0;
    bool flagDotOrE = false;
    for(;i<=j;i++){
        
        if(A[i]!='+' && A[i]!='-' && A[i]!='e' && A[i]!='.' && (A[i]<'0' || A[i]>'9')) return 0;
        if(A[i]=='.'){
            if(flagDotOrE) return 0;
            if(i+1==A.length())  return 0;
            if(A[i+1]<'0' || A[i+1]>'9') return 0;
            flagDotOrE = true;
        }
        if(A[i]=='e'){
            flagDotOrE=true;
            if(i+1==A.length()) return 0;
            if(A[i-1]<'0'||A[i-1]>'9') return 0;
            if((A[i+1]<'0' || A[i+1]>'9') && A[i-1]!='+' && A[i+1]!='-') return 0;
        }
    }
    return 1;

}
