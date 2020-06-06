int numberOfPages(vector<int> &A, long long maxPages){
    long long total=0;
    int requiredPages=1;
    for(int i=0;i<A.size();i++){
        total+=A[i];
        if(total>maxPages){
            total=A[i];
            requiredPages++;
        }
    }
    return requiredPages;
}

int Solution::books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    long long l=*max_element(A.begin(), A.end());
    long long h=0;
    for(int i=0;i<A.size();i++){
        h+=A[i];
    }
    while(l<h){
        long long m=l+(h-l)/2;
        int rP=numberOfPages(A, m);
        if(rP<=B) h=m;
        else l=m+1;
    }
    return l;
}