#include "std_lib_facilities.h"
#include <time.h>
#include <vector>

int N=11;
int col[11]; //col[i]=j 이면 i행 j열에 말을 두었다는 뜻
int finish = 0;


bool location(int i)//인접 열, 혹은 대각선에 다른 말이 있는 지 확인하는 함수
{
	for (int j = 0; j < i; j++) {
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j)) {
			return false;
		}
	}
	return true;
}


 void Queen(int i)
{
	 if (i == N) {
		 finish = 1;
		 return;//다 차면 시행을 종료하고, 최초의 답을 찾았다는 표기를 해 준다.
	}
	 else {
		
			 for (int j = 0; j < N; j++) {
				 
				 if (finish == 1) {
					 //최초의 답을 찾았을 경우 시행을 종료한다.
					 return;
				 }
				 else
				 {
					 col[i] = j;
					 if (location(i)) {

						 Queen(i + 1);
					 }
				 }
			 }
		 
	 }
	
		
	
}

	 int main()
	 {

		 double startTime = clock();
		 // 11-queens의 해답을 찾는 코드를 작성한다.
		 // 발견한 첫번째 11-queens의 해답을 출력한다. (형식 무관)


		 Queen(0);
		 for (int i = 0; i < N; i++) {
			 cout << col[i] << "\n";
		 }//답 출력은 각 행에 말이 있는 열을 출력하는 방식으로 한다.



		 double endTime = clock();
		 double elapsedTime = (double)(endTime - startTime);


		 cout << "프로그램 수행시간 :" << elapsedTime << endl;
		 return 0;


	 }