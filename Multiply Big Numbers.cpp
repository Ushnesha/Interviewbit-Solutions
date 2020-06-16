string add(string a, string b){
    
    int carry=0, i=a.length()-1, j=b.length()-1;
    if(i==-1) return b;
    if(j==-1) return a;
    string s="";
    while(i>=0 || j>=0 || carry){
        int sum=carry;
        if(i>=0) sum+=a[i]-'0';
        if(j>=0) sum+=b[j]-'0';
        s+=(sum%10)+'0';
        carry=sum/10;
        i--;
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

string Solution::multiply(string A, string B) {
    if(B=="0" || A=="0") return "0";
    int endi=0, endj=0;
    while(B[endi]=='0') endi++;
    while(A[endj]=='0') endj++;
    string mul="";
	for(int i=B.length()-1;i>=endi;i--){
	    string s3="";
	    int carry=0;
	    for(int j=A.length()-1;j>=endj;j--){
	        int prod=(B[i]-'0')*(A[j]-'0') + carry;
	        s3+=(prod%10)+'0';
	        carry=prod/10;
	    }
	    if(carry!=0) s3+=carry+'0';
	    reverse(s3.begin(), s3.end());
	    int z=B.length()-i-1;
	    while(z--){
	        s3+='0';
	    }
	    mul=add(mul,s3);
	}
	return mul;
}
