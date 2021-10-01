# include "std_lib_facilities.h"
# include <stack>

//stack: 후입선출의 자료구조

int main() {

	stack<int> s; //stack를 생성하기.

	s.push(1); //생성된 stack에 1, 2, 3, 4, 5를 차례대로 넣는다
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop(); //stack에 입력한 원소를 삭제하는 함수로 후입선출의 자료구조이기 때문에 마지막에 입력한 원소를 삭제함

	while (!s.empty()/*stack가 비었는지를 확인하는 함수*/) {
		cout << s.top();
		s.pop(); //처음 넣은 원소를 출력한 후 queue에서 삭제
	}
	//처음에 5을 삭제했으므로 4, 3, 2, 1이 순서대로 출력된다.

	return 0;

}