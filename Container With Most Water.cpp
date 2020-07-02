int Solution::maxArea(vector<int> &A) {
    int i = 0;
    int j = A.size()-1;
    int ans = 0;
    
    while(i < A.size()){
        int curr = 0;
        if(A[i] <= A[j]){
            curr = (j-i)*A[i];
            i++;
        }
        else{
            curr = (j-i)*A[j];
            j--;
        }
        ans=max(ans,curr);
        if(i == j){
            break;
        }
    }
    
    return ans;
    

}
