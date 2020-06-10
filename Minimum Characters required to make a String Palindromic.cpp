//reverse the given string
string rev(string se){
    for(int i=0, j=se.length()-1;i<j;i++,j--)
        swap(se[i],se[j]);
    return se;
}
//compute the Lps array of the concatenated pattern
vector<int> computeLpsArray(string s){
    vector<int> lps(s.length());
    int index=0;
    for(int i=1;i<s.length();){
        if(s[i]==s[index]){
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
int Solution::solve(string A) {
    //concat string by concatenating given string, a special character and reverse of given string
    string s=A+'$'+rev(A);
    //get lps array for this concatenated string
    vector<int> lps=computeLpsArray(s);
    //the last value of this lps array gives the largest suffix of the reversed string 
    //that matches the prefix of the original string i.e these many characters already 
    //satisfy the palindrome property
    //therefore A.length()-lps[lps.size()-1] gives the min chars that must be added to get the palindrome
    return A.length()-lps[lps.size()-1];
}
