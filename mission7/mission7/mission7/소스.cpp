#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//DeadLock With Example In C++ (https://www.youtube.com/watch?v=VG2Va80XZdo) 참고

//deadlock은 두 개 이상의 프로세스가 같은 리소스를 공유할 때 발생하는 현상이다.
//가령 리소스1을 점유하고 있는 프로세스 1이 리소스 2를 필요로 하고,
//리소스2를 점유하고 있는 프로세스 2가 리소스 1을 필요로 할 때 발생할 수 있다.
//이럴 때 두 프로세스가 서로 리소스를 기다리고 있는 대기상태에 빠질 수 있다.


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
	m1.lock();//m2 와 m1의 순서를 바꾸는 것으로 해당 코드의 deadlock 해소가 가능하다
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

//deadlock은 deadlock의 발생 가능성을 없애는 prevention
//deadlock이 발생할 여지가 있을 때 대응하는 avoidance
//deadlock이 발생했을 때 detection and recovery를 통해 해결하는 등의 방법으로
//문제를 해결할 수 있다.
