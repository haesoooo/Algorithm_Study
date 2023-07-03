#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
  ��� �����ڿ� ������ ��, �����ɻ�, �������� ���� �� ��� �ϳ��� �ٸ� �����ں��� �������� �ʴ� �ڸ� ����
  ex) A ������ B �������� �� �� ������ Ż��
*/

vector<pair<int, int>> A;

void quicksort(int left, int right){
  if(left>=right)
    return;

  int p_right = right;
  int p_left = left;

  int pivot = A[(left + right) / 2].first;

  while(p_left<=p_right){
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

void show(int N){
  for (int i = 0; i < N; i++)
  {
    cout << A[i].first << ", " << A[i].second << endl;
  }
  
}

int compare_interview(int N){
  int cnt = N;
  int low_grade = A[0].second;
  int high_grade = A[0].second;
  for (int i = 1; i < N; i++)
  {
    if(A[i].second>low_grade){
      // ���� ���� �ֺ��� ���� �������
      cnt--;    
    }
    else{
      low_grade = A[i].second;
    }
  }

  return cnt;
}

int T, N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  
  for (int i = 0; i < T; i++)
  {
    cin >> N;
    A.clear();
    for (int j = 0; j < N; j++)
    {
      int a, b;
      cin >> a >> b;
      A.push_back(make_pair(a, b));      
    }

    quicksort(0, N - 1); // ����

    // ���� �������� �������� ���� �Ϸ�

    cout << compare_interview(N) << endl;
  }
  
  
}