# include "std_lib_facilities.h"
# include <queue>

//queue: ���Լ����� �ڷᱸ��

int main(){

	queue<int> q; //queue�� �����ϱ�.

	q.push(1); //������ queue�� 1, 2, 3, 4, 5�� ���ʴ�� �ִ´�
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop(); //queue�� �Է��� ���Ҹ� �����ϴ� �Լ��� ���Լ����� �ڷᱸ���̱� ������ ó�� �Է��� ���Ҹ� ������

	while (!q.empty()/*queue�� ��������� Ȯ���ϴ� �Լ�*/) {
		cout << q.front(); 
		q.pop(); //ó�� ���� ���Ҹ� ����� �� queue���� ����
	}
	//ó���� 1�� ���������Ƿ� 2, 3, 4, 5�� �� ������� ��µȴ�.

	return 0;

}