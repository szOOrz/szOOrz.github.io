#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

bool valid[10000 + 100];
set<string>ans;
int main()
{
    string s;
    cin >> s;
    valid[s.length()] = 1;
    for (int i = s.length() - 1; i>4; --i){
        if (valid[i + 2]){
            string t = s.substr(i, 2);
            if (s.find(t, i + 2) != i + 2 || valid[i + 5]){
                valid[i] = 1;
                ans.insert(t);
            }
        }
        if (valid[i + 3]){
            string t = s.substr(i, 3);
            if (s.find(t, i + 3) != i + 3 || valid[i + 5]){
                valid[i] = 1;
                ans.insert(t);
            }
        }
    }
    cout << ans.size() << "\n";
    for (set<string>::iterator i=ans.begin();i!=ans.end();i++){
    	cout << *i << endl;
    }
    return 0;
}
