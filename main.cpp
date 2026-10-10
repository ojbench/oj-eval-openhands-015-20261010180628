#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    const string data_file = "data.txt";
    // Ensure data file exists
    {
        ofstream ofs(data_file, ios::app);
    }
    string cmd, idx;
    int val;
    for(int i=0;i<n;++i){
        cin>>cmd>>idx;
        if(cmd=="insert"){
            cin>>val;
            // Append insert operation to file
            ofstream ofs(data_file, ios::app);
            ofs << "I " << idx << ' ' << val << '\n';
        } else if(cmd=="delete"){
            cin>>val;
            // Append delete operation to file
            ofstream ofs(data_file, ios::app);
            ofs << "D " << idx << ' ' << val << '\n';
        } else if(cmd=="find"){
            // Compute current values for idx by scanning file
            ifstream ifs(data_file);
            set<int> values; // sorted unique values
            string op, cur_idx;
            int cur_val;
            while(ifs >> op >> cur_idx >> cur_val){
                if(cur_idx != idx) continue;
                if(op == "I") {
                    values.insert(cur_val);
                } else if(op == "D") {
                    values.erase(cur_val);
                }
            }
            if(values.empty()) {
                cout << "null\n";
            } else {
                bool first = true;
                for(int v : values){
                    if(!first) cout << ' ';
                    first = false;
                    cout << v;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
