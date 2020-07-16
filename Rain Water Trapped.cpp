//take two arrays
//arr1 keeps values from l-r that are the differences between A[i] and the max element till now
//similarly, arr2 keeps values from r-l that are the diff b/w A[i] and max till now from r-l
//finally take the corresponding minimum values from both the arrays and print the sum
int Solution::trap(const vector<int> &A) {
    vector<int> arr1(A.size()), arr2(A.size());
    int maxE=INT_MIN, maxS=INT_MIN;
    for(int i=0;i<A.size();i++){
        maxS=max(maxS, A[i]);
        arr1[i]=maxS-A[i];
        maxE=max(maxE, A[A.size()-1-i]);
        arr2[A.size()-1-i]=maxE-A[A.size()-1-i];
    }
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=min(arr1[i], arr2[i]);
    }
    return sum;
}
