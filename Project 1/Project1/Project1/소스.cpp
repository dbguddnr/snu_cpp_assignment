#include "std_lib_facilities.h"
#include <time.h>

int main() {
	
	clock_t startTime  =  clock();
	
	int number = 1000000000;
	int numberOfPrime = 0;
	int nonprimenumbers = 0;
	vector<int>myVector(number);
	//���� �ʱ�ȭ

	

	
	for (int i = 3; i < number; i = i + 2)
	{
		myVector[i] = 1;
	}
	//2�� ������ ¦�� �׵��� 1��

	
	for (int j = 2; j < 31622; j=j+2)//10���� ��Ʈ �� ������ Ȧ���� ���Ͽ� ����
	{
		for (int k = j+2; k < number; k=k+2)
		{
			if (myVector[k] == 0 && ( k+ 1) % (j + 1) == 0)
			{
				myVector[k] = 1;
			}
		}
		//j�� �̻��� Ȧ���� ���Ͽ� j�� ������ ������ ��� 1��
	}

	for (int m= 0; m < number; m++) {
		nonprimenumbers+= myVector[m];
	}
	//1�� �׵��� ������ ����

	numberOfPrime = number - nonprimenumbers - 1;
	//1�� ����Ͽ� �������� ������ ��

	cout << "�Ҽ��� ����: " << numberOfPrime << endl;
	clock_t endTime = clock();
	double elapsedTime = (double)(endTime - startTime);

	cout << "���α׷� ���� �ð�: " << elapsedTime << endl;
	
	return 0;
}