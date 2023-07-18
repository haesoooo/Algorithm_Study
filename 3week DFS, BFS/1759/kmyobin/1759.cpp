#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int L, C;
vector<string> A;
vector<string> ans;
bool visited[16];

// �ּ� �� ���� ����(a,e,i,o,u)�� �ּ� �� ���� ����
// ���ĺ� �����ؾ� ��
// a c i s t w
// ���������Ƿ� ����


void print(){
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i];
  }
  cout << endl;
}
void backtracking(int cnt, int index, int mo, int ja){
  if(cnt==L){
    // �� ������
    if(mo>=1 && ja>=2)  {
      print();
    }
    return;
  }

  for (int i = index; i < C; i++){
    if(visited[i]) // �湮�ߴٸ� pass
      continue;
    visited[i] = true;
    ans.push_back(A[i]);
    
    // �ݺ��� ���� ������ mo += ~ �̷��� �ȵ�
    int new_mo = mo + (A[i] == "a" || A[i] == "e" || A[i] == "i" || A[i] == "o" || A[i] == "u"); // ����
    int new_ja = ja + (A[i] != "a" && A[i] != "e" && A[i] != "i" && A[i] != "o" && A[i] != "u"); // ����
    backtracking(cnt+1, i + 1, new_mo, new_ja);
    ans.pop_back();
    visited[i] = false;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> L >> C;
  for (int i = 0; i < C; i++){
    string input;
    cin >> input;
    A.push_back(input);
  }

  sort(A.begin(), A.end());

  backtracking(0, 0, 0, 0);

  return 0;
}