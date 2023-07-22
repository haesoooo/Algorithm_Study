#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int N;
int ans;
int A[1001];
int dp[1001];
/*
10
1 2 0 1 3 2 1 5 4 2

dp[1]=0, dp[2]=1
dp[2]=1, dp[3]=2, dp[4]=2
dp[3]=2
dp[4]=2, dp[5]=3
dp[5]=3, dp[6]=4, dp[7]=4, dp[8]=4
dp[6]=4, dp[7]=4 vs 5, dp[8]=4 vs 5 (���� dp[i] vs dp[i]+1)
dp[7]=4

dp[i]=i��° ĭ���� �ּ� ���� Ƚ��
*/


void show(){
  for (int i = 1; i <= N; i++)
  {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++){
    cin >> A[i];
  }

  for (int i = 1; i <= N; i++){
    dp[i] = min(dp[i - 1] + 1, dp[i]); // �������� +1, ���� Ƚ���� ���ؼ� ���� ���� ����
    int jump = A[i];
    for (int j = i + 1; j <= i + jump; j++){
      // ������ �� �ִ� ��� �ε��� Ž��
      if(dp[j]==0){
        // ���� �ƹ� ���� �� ���� ���� ��Ȳ�̶��
        dp[j] = dp[i] + 1; // ���� Ƚ�� + 1
      }
      else{
        // �̹� ���� ���ִ� ��Ȳ�̸�
        dp[j] = min(dp[j], dp[i] + 1); 
      }
    }
  }

  bool err = false;
  for (int i = 2; i <= N; i++){
    if(dp[i]==0){ // dp �߰��� 0�� ������ ���� ���̹Ƿ� ������ ����
      cout << -1;
      err = true;
      break;
    }
  }
  if(!err)  cout << dp[N];

  return 0;
}