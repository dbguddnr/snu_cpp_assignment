#include "std_lib_facilities.h"
#include <time.h>
#include <vector>

int N=11;
int col[11]; //col[i]=j �̸� i�� j���� ���� �ξ��ٴ� ��
int finish = 0;


bool location(int i)//���� ��, Ȥ�� �밢���� �ٸ� ���� �ִ� �� Ȯ���ϴ� �Լ�
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
		 return;//�� ���� ������ �����ϰ�, ������ ���� ã�Ҵٴ� ǥ�⸦ �� �ش�.
	}
	 else {
		
			 for (int j = 0; j < N; j++) {
				 
				 if (finish == 1) {
					 //������ ���� ã���� ��� ������ �����Ѵ�.
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
		 // 11-queens�� �ش��� ã�� �ڵ带 �ۼ��Ѵ�.
		 // �߰��� ù��° 11-queens�� �ش��� ����Ѵ�. (���� ����)


		 Queen(0);
		 for (int i = 0; i < N; i++) {
			 cout << col[i] << "\n";
		 }//�� ����� �� �࿡ ���� �ִ� ���� ����ϴ� ������� �Ѵ�.



		 double endTime = clock();
		 double elapsedTime = (double)(endTime - startTime);


		 cout << "���α׷� ����ð� :" << elapsedTime << endl;
		 return 0;


	 }