#include <iostream>
#include <string>
using namespace std;

int N;
string A[51];

/*
1. ���� ��
2. ���� ���� == ���� ��� �ڸ��� �� ����
3. ������ ��(�ƽ�Ű �ڵ�)
*/

void show(){
  for (int i = 0; i < N; i++){
    cout << A[i] << "  ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  // bubble sort
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1 - i; j++)
    {
      if(A[j].length() > A[j+1].length()){
        // ���̰� ��� �� ���̶��
        swap(A[j], A[j+1]);
      }
      else if(A[j].length() == A[j+1].length()){
        // ���̰� �����ϴٸ�
        int score_j = 0;
        int score_next_j = 0;
        for (int k = 0; k < A[j].length(); k++){
          if('0' <= A[j].at(k) && A[j].at(k) <= '9'){
            // ���ڶ��
            score_j += A[j].at(k) - '0';
          }
        }
        for (int k = 0; k < A[j+1].length(); k++){
          if('0' <= A[j+1].at(k) && A[j+1].at(k) <= '9'){
            // ���ڶ��
            score_next_j += A[j+1].at(k)-'0';
          }
        }
        if(score_j>score_next_j){
          swap(A[j], A[j+1]);
        }
        else if(score_j==score_next_j){
          for (int k = 0; k < A[j].length(); k++){
            int jv = A[j].at(k);
            int jjv = A[j + 1].at(k);
            if(jv > jjv){
              swap(A[j], A[j+1]);
              break;
            }
            else if(jv<jjv){ // �̰� ������ ���� ���� X
              break;
            }
          }    
        }
      }

    }
  }

  for (int i = 0; i < N; i++)
  {
    cout << A[i] << endl;
  }
  
}