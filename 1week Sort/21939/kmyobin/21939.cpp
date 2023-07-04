#include <iostream>
#include <set>
#include <string>
using namespace std;

multiset<pair<int, int>> MM;
int A[100001];
int N, M;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int P, L;
    cin >> P >> L; // ���� ��ȣ, ���̵� ��
    MM.insert(make_pair(L, P));
    A[P] = L; // A[���� ��ȣ]�� ���̵� �ֱ�
  }
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    string input;
    cin >> input;

    if(input=="recommend"){
      int x;
      cin >> x;
      if(x==1){
        // ������
        cout << prev(MM.end())->second << endl;
      }
      else{
        // ���� ��
        cout << MM.begin()->second << endl;
      }
    }

    else if(input=="add"){
      int p, l;
      cin >> p >> l;
      
      MM.insert(make_pair(l,p));
      A[p] = l;
    }

    else{
      // ����
      int p;
      cin >> p;
      auto it = MM.find(make_pair(A[p], p)); // �ش� ���̵�, ���� ��ȣ ã��

      MM.erase(it);
    }
  }
  
}