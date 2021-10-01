# include "std_lib_facilities.h"
# include <queue>

//queue: 선입선출의 자료구조

int main(){

	queue<int> q; //queue를 생성하기.

	q.push(1); //생성된 queue에 1, 2, 3, 4, 5를 차례대로 넣는다
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop(); //queue에 입력한 원소를 삭제하는 함수로 선입선출의 자료구조이기 때문에 처음 입력한 원소를 삭제함

	while (!q.empty()/*queue가 비었는지를 확인하는 함수*/) {
		cout << q.front(); 
		q.pop(); //처음 넣은 원소를 출력한 후 queue에서 삭제
	}
	//처음에 1을 삭제했으므로 2, 3, 4, 5가 이 순서대로 출력된다.

	return 0;

}