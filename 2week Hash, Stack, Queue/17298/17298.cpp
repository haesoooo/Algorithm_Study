#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;

stack<int> A; 
vector<int> B; 
stack<int> ANS; // ����

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    B.push_back(input);
  }

  for (int i = N-1; i >= 0; i--)
  {
    // ���������� Ž��
    while(1){
      if(A.empty()){
        // ���� ��������� B[i]���� ū ���� B[i] �����ʿ� ���ٴ� ��
        ANS.push(-1); // ���� 1 ����
        break;
      }
      if(!A.empty() && B[i]<A.top()){ // �����ʿ� �ִ� ���� B[i]���� ũ�� ����
        ANS.push(A.top());
        break;
      }
      else{
        A.pop(); // ������ ������ pop
      }
    }
    A.push(B[i]); // ���⼭ ������ ���ŵ�
  }

  while(1){
    // ���������� Ž�������Ƿ� pop�ϸ� ���
    if(ANS.empty())
      break;
    cout << ANS.top() << " ";
    ANS.pop();
  }
}