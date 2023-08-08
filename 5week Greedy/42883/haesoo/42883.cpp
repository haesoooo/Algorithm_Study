#include <string>
#include <vector>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";

    int n = number.length() - k;
    int idx = -1;
 
    for(int i = n; i > 0; i--) {
        int max = -1;
        for(int j = idx + 1; j <= number.length() - i; j++) {
            if((number[j] - '0') > max) {
                max = number[j] - '0';
                idx = j;
            }
        }
        answer += number[idx];
    }
 
    return answer;
}