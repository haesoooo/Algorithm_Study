#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int alphabet[26] = {0, };
vector <string> word;

int main() {
    cin >> N;
    string a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        word.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        string b = word[i];
        int p = 1;
        for (int j = b.length() - 1; j >= 0; j--) {
            int t = b[j] - 'A';
            alphabet[t] = alphabet[t] + p;
            p *= 10;
        }    
    }
    sort(alphabet, alphabet + 26, greater<>());
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += alphabet[i] * (9 - i);
    }

    cout << answer;
}

