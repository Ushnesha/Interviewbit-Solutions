vector<int> computeLpsArray(string pat){
    vector<int> lps(pat.length());
    int index=0;
    for(int i=1;i<pat.length();){
        if(pat[index]==pat[i]){
            lps[i]=index+1;
            index++;
            i++;
        }else{
            if(index!=0) index=lps[index-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int Solution::strStr(const string A, const string B) {
    vector<int> lps=computeLpsArray(B);
    int i=0,j=0;
    while(i<A.length() && j<B.length()){
        if(A[i]==B[j]){
            i++;
            j++;
        }else{
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    if(j==B.length()) return i-j;
    else return -1;
}
