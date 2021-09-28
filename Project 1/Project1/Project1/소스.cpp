#include "std_lib_facilities.h"
#include <time.h>
#include <cmath>



int main() {
	
	clock_t startTime  =  clock();
	
	unsigned int number = 1000000000;
	vector<unsigned int>myVector(number);
	unsigned int numberOfPrime = 0;
	unsigned int nonprimenumbers = 0;
	
	//변수 초기화

	


	
	for (unsigned int i = 3; i < number; i = i + 2)
	{
		myVector[i] = 1;
	}
	//2를 제외한 짝수 항들을 1로

	
	for (unsigned int j = 2; j < sqrt(number); j=j+2)//10억의 루트 값 이하의 홀수에 대하여 진행
	{
		for (unsigned int k = j+2; k < number; k=k+2)
		{
			if (myVector[k] == 0 && ( k+ 1) % (j + 1) == 0)
			{
				myVector[k] = 1;
			}
		}
		//j값 이상의 홀수에 대하여 j로 나누어 떨어질 경우 1로
	}

	for (unsigned int m= 0; m < number; m++) {
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