int Solution::romanToInt(string A) {
    int res=0, i=0;
    map<char, int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    while(i<A.length()){
        if(i==A.length()-1) res+=mp[A[i]];
        else if(mp[A[i+1]]>mp[A[i]]){
            res+=mp[A[i+1]]-mp[A[i]];
            i++;
        }
        else res+=mp[A[i]];
        i++;
    }
    return res;
}
