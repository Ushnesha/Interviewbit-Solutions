string Solution::addBinary(string A, string B) {
    int i=A.length()-1, j=B.length()-1, carry=0;
    string s="";
    while(i>=0 || j>=0 || carry){
        int sum=carry;
        if(i>=0) sum+=A[i]-'0';
        if(j>=0) sum+=B[j]-'0';
        s+='0' + sum%2;
        carry=sum/2;
        i--;
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}
