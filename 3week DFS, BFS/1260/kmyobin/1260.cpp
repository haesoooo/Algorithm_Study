#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, V;
vector<int> A[1001];
bool visited_dfs[1001];
bool visited_bfs[1001];
int answer;


void dfs(int r){
  cout << r << " ";
  visited_dfs[r] = true; // r�� �湮 �Ϸ�
  for (int c = 0; c < A[r].size(); c++){
    int new_r = A[r][c];
    if(!visited_dfs[new_r]){
      // c���� �湮���� �ʰ� A[r][c]�� 1�̶��
      dfs(new_r);
    }
  }
}

void bfs(int s){
  queue<int> q;
  q.push(s);
  visited_bfs[s] = true;

  while(!q.empty()){
    // ť�� ���� ������ �湮�ؾ� �ϴ� ��尡 �ִٴ� ��
    int x = q.front();
    q.pop();
    cout << x << " ";

    for (int i = 0; i < A[x].size(); i++){
      int new_x = A[x][i];
      if(!visited_bfs[new_x]){
        // �湮���� �ʾҴٸ�
        q.push(new_x);
        visited_bfs[new_x] = true; // �湮 ó��
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> M;
  cin >> V;

  for (int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    A[x].push_back(y);
    A[y].push_back(x);
  }

  for (int i = 1; i <= N; i++){
    // �������� ���� (�湮 ������ ������ �������� ��� ��ȣ�� ���� ���� �����ؾ��ϹǷ�)
    sort(A[i].begin(), A[i].end());
  }

  dfs(V);
  cout << endl;
  bfs(V);

  return 0;
}