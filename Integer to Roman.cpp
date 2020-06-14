string Solution::intToRoman(int A) {
    int number[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string s[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string st="";
    int i=12;
    while(A>0){
        int d=A/number[i];
        A%=number[i];
        while(d--) st+=s[i];
        i--;
    }
    return st;
}
