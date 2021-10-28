# include <iostream>
# include <thread>

//Youtube 채널 Neso Academy의 Process Management(Processes and Threads) 영상 참고 https://www.youtube.com/watch?v=OrM7nZcxXZU
//코드는 https://modoocode.com/269 참고

//Process: 프로그램이 진행중인 상태
//Thread: 프로세스 내의 한 진행 단위. 한 프로세스는 여러 개의 스레드를 포함할 수 있음
//프로세스끼리는 메모리를 공유하지 않고, 스레드끼리는 메모리를 공유함


//스레드를 구현하는 코드


using std::thread;

void func1() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 1 작동중 \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 2 작동중 \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 3 작동중 \n";
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