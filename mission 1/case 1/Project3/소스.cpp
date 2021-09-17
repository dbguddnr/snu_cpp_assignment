#include "std_lib_facilities.h"

//자연수 n에 대하여 1부터 n-1까지의 자연수를 대입하여 소수인지 판단하기


int prime(int x)
{
	int abx;
	if (x >= 0)
		abx = x;
	else
		abx = -x;


	if (abx == 1 || abx == 0)
	{
		cout << x <<"은(는) 소수가 아닙니다.\n";
		return 0;
	}
	else
	{
	int count = 0;
		for (int i = 1; i < abx; i++) 
		{
			if (abx % i == 0)
				count++;
		}
		if (count == 1)
			cout << x <<"은(는) 소수입니다.\n";
		else
			cout << x << "은(는) 소수가 아닙니다.\n";

		return 0;
	}

}

int main() 
{
	int number;

	

	cout << "정수를 입력하세요.\n";
	cin>>number;

	prime(number);

	return 0;
}