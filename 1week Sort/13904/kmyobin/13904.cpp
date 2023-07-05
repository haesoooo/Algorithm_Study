#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ; // �������� ����
vector<pair<int, int>> A;
int memo[1001];
// ������ ū ������ �������� ����
// 

void quicksort(int left, int right){
  if(left>=right)
    return;

  int p_right = right;
  int p_left = left;

  int pivot = A[(left + right) / 2].first;

  while(p_left<=p_right){
    while(A[p_left].first>pivot){
      p_left++;
    }
    while(pivot>A[p_right].first){
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
    int d, w;
    cin >> d >> w;
    A.push_back(make_pair(w, d)); // ����, ������ ��
  }

  quicksort(0, N - 1);
  
  int maximum = -1;
  for (int i = 0; i < N; i++)
  {
    for (int j = A[i].second; j >= 1; j--){
      // �ִ��� �ʰ� ����ֱ� ���� �ں��� ����
      if(memo[j]==0){
        memo[j] = A[i].first; // j������ A[i].first���� �´´�.
        maximum = (maximum > j) ? maximum : j;
        break;
      }
    }
  }

  int score = 0;
  for (int i = 1; i <= maximum; i++){
    score += memo[i];
  }

  cout << score;

  return 0;
}