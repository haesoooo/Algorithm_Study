#include <iostream>
#include <queue>
using namespace std;


// �켱���� ť : �켱������ ���� �����Ͱ� ���� ������ ������ �ڷᱸ��
priority_queue<int, vector<int>, greater<int>> pq; // ��������
int N;
int A[100001];
int score;
int k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    pq.push(input); // �������� ����
  }

  if(pq.size()==1){
    cout << 0;
  }
  else{
    while(!pq.empty()){
      int answer = pq.top();
      pq.pop();
      answer += pq.top();
      pq.pop();

      A[k] = answer;
      if(pq.empty()){
        k++;
        break;
      }
      pq.push(answer);
      k++;
    }
    for (int j = 0; j < k; j++){
      score += A[j];
    }
    cout << score;
  }

  return 0;
}