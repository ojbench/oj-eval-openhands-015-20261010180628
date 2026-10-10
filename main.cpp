#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    const string data_file = "data.txt";
    // Ensure file exists
    {
        ofstream ofs(data_file, ios::app);
    }

    // Load existing data into memory
    unordered_map<string, set<int>> db;
    {
        ifstream ifs(data_file);
        string op, idx;
        int val;
        while(ifs >> op >> idx >> val) {
            if(op == "I") {
                db[idx].insert(val);
            } else if(op == "D") {
                auto it = db.find(idx);
                if(it != db.end()) {
                    it->second.erase(val);
                    if(it->second.empty()) db.erase(it);
                }
            }
        }
    }


    


    
    string cmd, idx;
    int val;
    for(int i=0;i<n;++i){
        cin>>cmd>>idx;
        if(cmd=="insert"){
            cin>>val;
            if(db[idx].find(val)==db[idx].end()){
                db[idx].insert(val);
                ofstream ofs(data_file, ios::app);
                ofs << "I " << idx << ' ' << val << '\n';
            }
        } else if(cmd=="delete"){
            cin>>val;
            auto it = db.find(idx);
            if(it!=db.end()){
                it->second.erase(val);
                if(it->second.empty()) db.erase(it);
            }
            ofstream ofs(data_file, ios::app);
            ofs << "D " << idx << ' ' << val << '\n';
        } else if(cmd=="find"){
            auto it = db.find(idx);
            if(it==db.end()||it->second.empty()){
                cout << "null\n";
            } else {
                bool first=true;
                for(int v: it->second){
                    if(!first) cout << ' ';
                    first=false;
                    cout << v;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
