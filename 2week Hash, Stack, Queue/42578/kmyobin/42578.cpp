#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    multimap<string, string> um; // key : string (�� ����), value : string (�� �̸�)
    string x[30]; // ���� ������ ��� �迭
    int k = 0; // ���� ������ ���� x �迭�� index

    for (int i = 0; i < clothes.size(); i++)
    {
      um.insert(make_pair(clothes[i].back(), clothes[i].front()));

      bool isIter = false;
      for (int j = 0; j < k; j++){
        if(x[j]==clothes[i].back()){
          isIter = true;
          break;
        }
      }

      if(!isIter){
        x[k] = clothes[i].back();
        k++;
      }
    }

    answer = 1; // ���ϴ� ���̹Ƿ� 1�� ����

    for (int i = 0; i < k; i++){
      answer *= (um.count(x[i]) + 1);
    }

    answer--; // �ƹ��͵� �������� �ȵǹǷ�

    return answer;
}

int main(){
    vector<vector<string>> clothes;
    //clothes.push_back({"yellow_hat", "headgear"});
    //clothes.push_back({"blue_sunglasses", "eyewear"});
    //clothes.push_back( {"green_turban", "headgear"} );

    clothes.push_back({"crow_mask", "face"});
    clothes.push_back({"blue_sunglasses", "face"});
    clothes.push_back( {"smoky_makeup", "face"} );
    cout << solution(clothes) << endl;

    return 0;
}