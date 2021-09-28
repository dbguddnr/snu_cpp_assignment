#include "std_lib_facilities.h"
#include <time.h>

int main() {
	
	clock_t startTime  =  clock();
	
	int number = 1000000000;
	int numberOfPrime = 0;
	int nonprimenumbers = 0;
	vector<int>myVector(number);
	//변수 초기화

	

	
	for (int i = 3; i < number; i = i + 2)
	{
		myVector[i] = 1;
	}
	//2를 제외한 짝수 항들을 1로

	
	for (int j = 2; j < 31622; j=j+2)//10억의 루트 값 이하의 홀수에 대하여 진행
	{
		for (int k = j+2; k < number; k=k+2)
		{
			if (myVector[k] == 0 && ( k+ 1) % (j + 1) == 0)
			{
				myVector[k] = 1;
			}
		}
		//j값 이상의 홀수에 대하여 j로 나누어 떨어질 경우 1로
	}

	for (int m= 0; m < number; m++) {
		nonprimenumbers+= myVector[m];
	}
	//1인 항들의 개수를 구함

	numberOfPrime = number - nonprimenumbers - 1;
	//1을 고려하여 마지막에 제외해 줌

	cout << "소수의 개수: " << numberOfPrime << endl;
	clock_t endTime = clock();
	double elapsedTime = (double)(endTime - startTime);

	cout << "프로그램 수행 시간: " << elapsedTime << endl;
	
	return 0;
}