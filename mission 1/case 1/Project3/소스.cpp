#include "std_lib_facilities.h"

//�ڿ��� n�� ���Ͽ� 1���� n-1������ �ڿ����� �����Ͽ� �Ҽ����� �Ǵ��ϱ�


int prime(int x)
{
	int abx;
	if (x >= 0)
		abx = x;
	else
		abx = -x;


	if (abx == 1 || abx == 0)
	{
		cout << x <<"��(��) �Ҽ��� �ƴմϴ�.\n";
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
			cout << x <<"��(��) �Ҽ��Դϴ�.\n";
		else
			cout << x << "��(��) �Ҽ��� �ƴմϴ�.\n";

		return 0;
	}

}

int main() 
{
	int number;

	

	cout << "������ �Է��ϼ���.\n";
	cin>>number;

	prime(number);

	return 0;
}