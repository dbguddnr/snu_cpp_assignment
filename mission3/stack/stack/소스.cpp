# include "std_lib_facilities.h"
# include <stack>

//stack: ���Լ����� �ڷᱸ��

int main() {

	stack<int> s; //stack�� �����ϱ�.

	s.push(1); //������ stack�� 1, 2, 3, 4, 5�� ���ʴ�� �ִ´�
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop(); //stack�� �Է��� ���Ҹ� �����ϴ� �Լ��� ���Լ����� �ڷᱸ���̱� ������ �������� �Է��� ���Ҹ� ������

	while (!s.empty()/*stack�� ��������� Ȯ���ϴ� �Լ�*/) {
		cout << s.top();
		s.pop(); //ó�� ���� ���Ҹ� ����� �� queue���� ����
	}
	//ó���� 5�� ���������Ƿ� 4, 3, 2, 1�� ������� ��µȴ�.

	return 0;

}