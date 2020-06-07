string Solution::countAndSay(int A) {
    if(A==1) return "1";
    string s="";
    string s1=countAndSay(A-1);
    int i=0;
    while(i<s1.length()){
        int j=i;
        while(j<s1.length() && s1[i]==s1[j]) j++;
        s+=to_string(j-i);
        s+=s1[i];
        i=j;
    }
    return s;
}
