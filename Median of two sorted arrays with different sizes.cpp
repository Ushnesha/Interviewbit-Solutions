double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int x = A.size(), y = B.size();
    
    if(x > y) return findMedianSortedArrays(B, A);
    
    int l = 0, h = x;
    while(l<=h){
        int partitionX=l+(h-l)/2;
        int partitionY=(x+y+1)/2 - partitionX; //partitionX+partionY should be equal to (x+y+1)/2
        int maxLeftX= partitionX==0 ? INT_MIN : A[partitionX-1];
        int minRightX = partitionX==x ? INT_MAX : A[partitionX];
        int maxLeftY= partitionY==0 ? INT_MIN : B[partitionY-1];
        int minRightY = partitionY==y ? INT_MAX : B[partitionY];
        if(maxLeftX <= minRightY && maxLeftY <= minRightX){
            if((x+y) % 2 == 0)
                return (double)(max(maxLeftX, maxLeftY)+min(minRightX, minRightY))/(double)2;
            else return max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY) h = partitionX-1;
        else l=partitionX+1;
    }
}