#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int N, M, V;
int A[1001][1001];
bool visited_bfs[1001][1001];
queue<pair<int,int>> T;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// ������, �Ʒ�, ����, ��
int answer = -1;



// �Ϸ簡 ������ ���� �͵� ������ ���� ���� �ʴ� �͵��� �ʹ´�
// ȥ�� ������ ���� ����
// ��� �������� ��ĥ�� ������ �� �ʹ���?
// 1 : ����, 0 : ������, -1 : ����

bool safe(int y, int x){
  return (0 <= x && x < M) && (0 <= y && y < N);
}

int check(){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if(A[i][j]==0)
        return -1; // ������ �丶�� �ִ� ���
    }
  }
  return 0; // ��� ���� �丶��
}

void show(){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void bfs(){
    while(!T.empty()){
      // ť�� ���� ������ �湮�ؾ� �ϴ� ��尡 �ִٴ� ��
      int rr = T.front().first;
      int cc = T.front().second;

      T.pop();
      //cout << "q.size() : " << q.size() << endl;

      for (int i = 0; i < 4; i++){
        //cout << rr + dy[i] << ", " << cc + dx[i] << endl;
        if(safe(rr+dy[i], cc+dx[i]) && A[rr+dy[i]][cc+dx[i]]==0){
          // ������ �Ѿ�� �ʰ�, �ش� ������ �� ���� �丶����
          
          //A[rr + dy[i]][cc + dx[i]] = 1;
          A[rr + dy[i]][cc + dx[i]] = A[rr][cc] + 1;
          answer = (answer > A[rr + dy[i]][cc + dx[i]]) ? answer : A[rr + dy[i]][cc + dx[i]];
          //visited_bfs[rr + dy[i]][cc + dx[i]] = true;
          T.push({rr + dy[i], cc + dx[i]});
        }
      }
      //show();
    }    



}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N; // ����, ����

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> A[i][j];
      if(A[i][j]==1)
        T.push({i, j});
    }
  }

  if(T.empty()){
    // �;��ִ� �丶�� ������ ���ɼ� ����
    cout << -1;
  } 
  else{
    if(check()==0){
      // �̹� ��� �;��ִٸ� (0�� ���ٸ�)
      cout << 0;
    }
    else{
      bfs();
      int ans = check();      
      if(ans==-1){
        cout << -1;
      }
      else{
        cout << answer - 1;
      }
    }

  }
  return 0;
}