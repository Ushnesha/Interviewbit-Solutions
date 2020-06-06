int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l=0, h=A.size()-1;
    while(l<=h){
        int m=l+(h-l)/2;
        if(A[m]==B) return m;
        else if(A[m]<B) l=m+1;
        else h=m-1;
    }
    return h+1;
    
}