#define inf 1000000007
int findrot(string &s){
    string r = s;
    while(r.length()%2==0){
        string t = r.substr(0, r.length()/2), t1 = r.substr(r.length()/2, r.length()/2);
        if(t==t1)
            r = t;
        else
            break;
    }
    int len = r.length();
    for(int i=1; i<2*len; i++){
        long long val = i;
        if(((val*(val+1))/2)%r.length()==0)
            return i;
    }
    return 2*len-1;
}
vector<int> primes;
void fun(){
    vector<bool> bt(450, true);
    bt[0] = bt[1] = false;
    for(int i=2; i<450; i++){
        if(bt[i]){
            for(int j=i*i; j<450; j+=i){
                if(bt[j])
                    bt[j] = false;
            }
        }
    }
    for(int i=0; i<450; i++){
        if(bt[i])
            primes.push_back(i);
    }
}
void fill(int n, map<int, int> &maxpower){
    for(int i=0; i<primes.size(); i++){
        int prime = primes[i];
        int ex = 0;
        while(n%prime==0){
            n /= prime;
            ex++;
        }
        if(ex>0){
            auto it = maxpower.find(prime);
            if(it==maxpower.end())
                maxpower[prime] = ex;
            else
                it->second = max(it->second, ex);
        }
    }
    if(n>1){
        auto it = maxpower.find(n);
        if(it==maxpower.end())
            maxpower[n] = 1;
    }
    return;
}
int Solution::solve(vector<string> &A) {
    primes.clear();
    fun();
    vector<int> v;
    for(int i=0; i<A.size(); i++){
        if(!A[i].length())
            continue;
        v.push_back(findrot(A[i]));
    }
    map<int, int> maxpower;
    for(int i=0; i<v.size(); i++)
        fill(v[i], maxpower);
    long long res = 1;
    for(auto it=maxpower.begin(); it!=maxpower.end(); it++){
        int base = it->first, ex = it->second;
        long long ans = 1;
        while(ex){
            ans = (ans*base)%inf;
            ex--;
        }
        res = (res*ans)%inf;
    }
    return (int)res;
}