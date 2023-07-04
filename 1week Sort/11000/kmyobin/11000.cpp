#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ; // �������� ����
vector<pair<int, int>> A;

void quicksort(int left, int right){
  if(left>=right)
    return;

  int p_right = right;
  int p_left = left;

  int pivot = A[(left + right) / 2].first;

  while(p_left<=p_right){
    // ���� �ð�(s) �������� �������� ����
    while(A[p_left].first<pivot){
      p_left++;
    }
    while(pivot<A[p_right].first){
      p_right--;
    }
    if(p_left<=p_right){
      swap(A[p_left], A[p_right]);
      p_left++;
      p_right--;
    }
  }

  quicksort(left, p_right);
  quicksort(p_left, right);
}


int N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N;i++){
    int s, t;
    cin >> s >> t;
    A.push_back(make_pair(s, t));
  }

  // ���� �������� �������� ���� (s)
  quicksort(0, N - 1);

  // �켱���� ť�� ������ �ð�(t) push
  PQ.push(A[0].second); // ��������
  
  // ù��° �ε������� ����
  for (int i = 1; i < N; i++){
    if(A[i].first<PQ.top()){
      // �ȳ������� ���ǽ� �߰� == i��° �ε����� ������ �ð� �߰�
      PQ.push(A[i].second);
    }
    else{
      // �������� ���ǽ� �̾ �� �� ���� == PQ pop, i��° �ε����� ������ �ð� �߰�(���ο� ������ �������Ƿ�)
      PQ.pop();
      PQ.push(A[i].second);
    }
  }

  cout << PQ.size();

  return 0;
}