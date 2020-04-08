#include <iostream>

/*
 * Question
 * Input
 * ���ֱ������ ����(����)
 * ���ֱ������ ������ ���� �迭(2 < n < 1000 && n != 0)
 * Output
 * ġŲ���� �����
 */

void Sort( int data[] , const int size );

int main( int argc , char* argv[] )
{
	int* trains = nullptr; // ���ֱ���� �迭
	int size = 0; // ���ֱ���� ����
	int last = 0; // ���� �ݴ��� ���� ������ ������ �ö� �ߺ��� ���ϵ��� ����
	int result = 0; // ������������ �ε���

	/*������� ������ �޾ƿ�*/
	while (true)
	{
		std::cin >> size;
		if(size >= 2 && size < 1000 && size !=0 )
			break;
		std::cout <<"�߸��� ���� �ԷµǾ����ϴ�."<<std::endl;
	}
	
	/*Safe allocation*/
	trains = new(std::nothrow) int[size];	
	if(!trains)
		return 0;

	for (int i=0;i<size;i++)
	{
		std::cin >> trains[i];
	}

	Sort( trains,size );
	if(trains[0] > 0)
	{
		std::cout << "��� ������ �� ������ ���� �ֽ��ϴ�" << std::endl;
		return 0;
	}
	
	last = size - 1;
	for (int head=0;head<size;head++)
	{
		if(head == last)
		{
			result = head;
			break;
		}
		int left = trains[head] * trains[head]; // ���ʱ����� ����
		int right = trains[last] * trains[last]; // �����ʱ����� ����
		
		/*���ĵ� �����Ϳ��� ������ ���� ū ���� ���� �¸���*/
		if( left > right )
		{
			result = head;
			break;
		}
		else if(left < right)
		{
			result = last;
			break;
		}
		/*���� ������ �����Ƿ� ���� �ε��� ��*/
		last--;
	}


	printf( "Result : %d",trains[result] );

	/*Safe delete*/
	delete[] trains;
	trains = nullptr; // Never access to dangling pointer.
}


void Sort( int data[] , const int size )
{
	for (unsigned i = size - 1; i > 0; i--)
	{
		for (unsigned j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				unsigned temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}