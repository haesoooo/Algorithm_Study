
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional>
// using namespace std;
// /*
// int sol (vector <int> t){
//     sort(t.begin(), t.end(), greater<int>());
//     for (int i = 0; i < t.size() - 2; i++) {
//         if (t[i] < t[i + 1] + t[i + 2]) return t[i] + t[i + 1] + t[i + 2];
//     }
//     return -1;
// }*/
// int main(){
//     int N, s;
//     vector <int> t;
//     cin >> N;
//     for (int i = 0; i < N; i++) {
//         cin >> s;
//         t.push_back(s);
//     }
//     int ans = -1;
//     //sol(t);
//     sort(t.begin(), t.end(), greater<int>());   
//     for (int i = 0; i < t.size() - 2; i++) {
//         if (t[i] < t[i + 1] + t[i + 2]) ans = t[i] + t[i + 1] + t[i + 2];
//     }
//     cout << ans;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int sol (vector <int> t){
    sort(t.begin(), t.end(), greater<int>());
    for (int i = 0; i < t.size() - 2; i++) {
        if (t[i] < t[i + 1] + t[i + 2]) return t[i] + t[i + 1] + t[i + 2];
    }
    return -1;
}

int main(){
    int N, s;
    vector <int> t;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        t.push_back(s);
    }
    cout << sol(t);

    
}