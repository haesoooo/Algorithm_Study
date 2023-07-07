#include <iostream>
#include <stack>
using namespace std;

string a;
stack<char> c; // ��ȣ, ��ȣ ���

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a;

  for (int i = 0; i < a.length(); i++){
    if('A'<=a[i] && a[i]<='z'){
      // ���� �״�� ���
      cout << a[i];
    }
    else if(a[i]=='+' || a[i]=='-'){
      // ����, ������ ��� �켱������ ����
      if(!c.empty() && (c.top()=='*' || c.top()=='/')){
        // ���� stack�� �ִ� ���� �켱������ �� ���� ��� ���� �������
        while(!c.empty()){
          char temp = c.top();
          if(temp=='('){
            break;
          }
          cout << temp;
          c.pop();
        }
      }
      else if(!c.empty() && (c.top()=='+' ||c.top()=='-')){
        // stack�� �ִ� ���� ����, ������ ��� �����̹Ƿ� pop
        char temp = c.top();
        cout << temp; 
        c.pop();
      }
      c.push(a[i]);
    }
    else if(a[i]=='*' || a[i]=='/'){
      if(!c.empty() && (c.top()=='*' || c.top()=='/')){
        // ������ �켱�����̹Ƿ� pop
        char temp = c.top();
        cout << temp; 
        c.pop();
      }
      c.push(a[i]);
    }
    else if(a[i]=='('){
      // �����ϴ� ��ȣ�� ������ push
      c.push(a[i]);
    }
    else {
      // a[i]==')'
      while(!c.empty()){
        char temp = c.top();
        if(temp=='('){
          // '('�� ���� ������ pop
          c.pop();
          break;
        }
        cout << temp;
        c.pop();
      }
    }
  }

  // �����ִ� �� ���� �� �����Ƿ� pop
  if(!c.empty()){
    while(!c.empty()){
      char temp = c.top();
      if(temp=='('){
        c.pop();
        continue;
      }
      cout << temp;
      c.pop();
    }
  }
}