bool isAllPrefixSame(vector<string> &A, string st, int s, int e){
    // string st=A[0];
    for(int i=0;i<A.size();i++){
        for(int j=s;j<=e;j++){
            if(A[i][j]!=st[j]) return false;
        }
    }
    return true;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    int minLen=INT_MAX;
    for(int i=0;i<A.size();i++){
        if(minLen>A[i].length())
        minLen=A[i].length();
    }
    int l=0, h=minLen;
    string prefix="";
    while(l<=h){
        int m=l+(h-l)/2;
        if(isAllPrefixSame(A,A[0],l,m)){
            prefix=prefix+A[0].substr(l,m-l+1);
            l=m+1;
        }else h=m-1;
    }
    return prefix;
}
