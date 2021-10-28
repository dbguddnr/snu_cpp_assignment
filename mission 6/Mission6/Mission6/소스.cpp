# include <iostream>
# include <thread>

//Youtube ä�� Neso Academy�� Process Management(Processes and Threads) ���� ���� https://www.youtube.com/watch?v=OrM7nZcxXZU
//�ڵ�� https://modoocode.com/269 ����

//Process: ���α׷��� �������� ����
//Thread: ���μ��� ���� �� ���� ����. �� ���μ����� ���� ���� �����带 ������ �� ����
//���μ��������� �޸𸮸� �������� �ʰ�, �����峢���� �޸𸮸� ������


//�����带 �����ϴ� �ڵ�


using std::thread;

void func1() {
	for (int i = 0; i < 10; i++) {
		std::cout << "������ 1 �۵��� \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		std::cout << "������ 2 �۵��� \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		std::cout << "������ 3 �۵��� \n";
	}
}

int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.join();
	t2.join();
	t3.join();
}