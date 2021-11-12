#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//DeadLock With Example In C++ (https://www.youtube.com/watch?v=VG2Va80XZdo) ����

//deadlock�� �� �� �̻��� ���μ����� ���� ���ҽ��� ������ �� �߻��ϴ� �����̴�.
//���� ���ҽ�1�� �����ϰ� �ִ� ���μ��� 1�� ���ҽ� 2�� �ʿ�� �ϰ�,
//���ҽ�2�� �����ϰ� �ִ� ���μ��� 2�� ���ҽ� 1�� �ʿ�� �� �� �߻��� �� �ִ�.
//�̷� �� �� ���μ����� ���� ���ҽ��� ��ٸ��� �ִ� �����¿� ���� �� �ִ�.


std::mutex m1;
std::mutex m2;

void thread1() {
	m1.lock();
	m2.lock();
	m1.unlock();
	m2.unlock();
}

void thread2() {
	m2.lock();
	m1.lock();//m2 �� m1�� ������ �ٲٴ� ������ �ش� �ڵ��� deadlock �ؼҰ� �����ϴ�
	m2.unlock();
	m1.unlock();
}

int main() {
	thread t1(thread1);
	thread t2(thread2);

	t1.join();
	t2.join();
	return 0;
}

//deadlock�� deadlock�� �߻� ���ɼ��� ���ִ� prevention
//deadlock�� �߻��� ������ ���� �� �����ϴ� avoidance
//deadlock�� �߻����� �� detection and recovery�� ���� �ذ��ϴ� ���� �������
//������ �ذ��� �� �ִ�.
