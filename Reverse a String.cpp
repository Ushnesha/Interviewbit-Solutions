string Solution::solve(string A) {
    //put all words in a vectors
//     vector<string> words;
//     string s="";
//     for(int i=0;i<A.length();i++){
//         if(A[i]==' ') continue;
//         s+=A[i];
//         if((i==A.length()-1) || (A[i+1]==' ')) {
//             words.push_back(s);
//             s="";
//         }
//     }
//     s="";
//     //from the vector iterate reversely and add it to string along with a space
//     for(int i=words.size()-1; i>=0;i--){
//         s+=words[i];
//         if(i!=0) s+=' ';
//     }
//     return s;
    
    //short and better approach
    stringstream ss(A);
    string word, res;
    while(ss >> word){
        if(res.empty()) res=word;
        else res= word+' '+res;
    }
    return res;
}
