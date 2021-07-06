# Interviewbit-Solutions
--- 
### Three Sum
###### Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false.

| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Two Pointers | CPP | O(nLogn) | O(1) |

```cpp
int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<3) return 0;
    sort(A.begin(), A.end());
    int l,r, minSum=INT_MAX, sum=0;
    for(int i=0;i<A.size()-2;i++){
        l=i+1;
        r=A.size()-1;
        while(l<r){
            int tmp=A[i]+A[l]+A[r];
            int diff=abs(B-tmp);
            if(diff==0) return B;
            if(minSum > diff){
                minSum=diff;
                sum=tmp;
            }
            if(tmp<B) l++;
            else r--;
        }
    }
    return sum;
}
```
---
### Add Binary Strings
##### Given two binary strings, return their sum (also a binary string).

| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Strings | CPP | O(n) | O(1) |

```cpp
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
```
---
### Allocate Books
##### Given an array of integers A of size N and an integer B. College library has N books,the ith book has A[i] number of pages. You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2. Calculate and return that minimum possible number.
##### NOTE: Return -1 if a valid assignment is not possible.

| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| inary Search | CPP | O(nLogn) | O(1) |

```cpp
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
```
---
