class Solution {
public:
    vector<string> svec;
    map<string, multiset<string>> mp;
    void dfs(string start){
        while(mp[start].size()){
            string next=*mp[start].begin();
            mp[start].erase(mp[start].begin());
            dfs(next);
        }
        svec.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets)
            mp[ticket[0]].insert(ticket[1]);
        dfs("JFK");
        reverse(svec.begin(), svec.end());
        return svec;
    }
};