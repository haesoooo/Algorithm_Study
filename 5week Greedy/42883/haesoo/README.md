
## Info
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/42883" rel="nofollow"> 큰 수 만들기 </a>

## ❗풀이
- k개의 수를 제거한다 == (number.length() - k)개의 수 
뽑아야 되는 숫자의 자릿수를 n이라고 하면, number에서 뒤에서부터 (n - 1)개의 수를 남겨두고 나머지 수 중에서 제일 큰 수를 뽑으면 된다. 다음 수는 방금 뽑은 수 다음부터 뒤에서 (n - 2)개의 수를 남겨두고 제일 큰 수를 뽑는다. 이를 n개 수를 뽑을 때까지 반복한다. 

## 마무리
그리디가 제일 어려운 것 같다.. (number.length() - k)라는 개념을 떠올리는데 제일 오래걸렸다.