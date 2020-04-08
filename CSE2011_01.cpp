#include <iostream>

/*
 * Question
 * �� ������ ���� (1 < n < 30,000) ������ �Ѱ蹫��(1 < m < 30,000)�� �Է�
 * ������ ����(1 < p < 50,000) �Է�
 * �� ������ �ִ� �������� 2
 * Input
 * ������ �Ѱ蹫��, ������ ����
 *
 * Output
 * ������ �ּҰ���
 */

void GetDataWhileAvailable( unsigned& data , unsigned min , unsigned max );
void Sort( unsigned data[] , unsigned size );

int main( int argc , char* argv[] )
{
	unsigned itemNumber = 0; // ������ ����(p)
	unsigned maximumWeight = 0; // ������ �Ѱ蹫��(m)
	unsigned* items = nullptr; // ���ǵ��� ���Ե�
	unsigned result = 0; // ������ �����.
	unsigned used = 0; // �չ����� ���������� �ö� ���� ĳ��

	/*m�� ���� ����� ���Ë����� �޴´�.*/
	GetDataWhileAvailable( maximumWeight, 1, 30000 );
	/*p�� ���� ����� ���Ë����� �޴´�.*/
	GetDataWhileAvailable( itemNumber, 1, 50000 );

	items = new( std::nothrow ) unsigned[itemNumber]; // Allocation memory dynamically.
	if (!items) // Check std::Bad_allocation.
		return 0;

	/*
	 * ������ ���Ը� ������ŭ �޾ƿ´�.
	 * ���������� 1�ٷ� �޾ƿ����� ���ڿ��Ľ��� �ʿ��ϹǷ� �����ƿ�
	 */
	for (unsigned i = 0; i < itemNumber; i++)
	{
		GetDataWhileAvailable( items[i], 0, 30000 );
	}

	/*������ ���� Ǯ������ ����*/
	Sort( items, itemNumber );

	for (unsigned i = itemNumber - 1; i > 0; i--)
	{
		/*�ִ� ���Ժ��� Ŭ�� -1�� ó��*/
		if (items[i] > maximumWeight)
		{
			result = -1;
			break;
		}
		/*���� ���԰� �ִ밪�϶� �ٷ� �߰�*/
		if (items[i] == maximumWeight)
		{
			result++;
			continue;
		}
		for (; used < itemNumber - 1; used++)
		{
			/*�ε��� ������ �Ͼ�� ��������*/
			if (used >= i)
				break;
			
			unsigned value = items[i] + items[used]; // ���濡 �ִ´�.

			/*�����ѵ��� ������ ���� �ε��� üũ*/
			if (value > maximumWeight)
				continue;

			/*��밡���� ���϶� ����� �߰�*/
			used++; // �̹� ���� ���̹Ƿ� j�� �ε����� used�� �־�� ���� ����.
			result++;
			break;
		}
	}

	printf( "Result : %d", result );

	/*Safe delete*/
	delete[] items;
	items = nullptr;

	return 0;
}

/**
 * ������ Ǯ�����ؼ��� ������ �ʿ������� �������� ��������
 * @param data ���ĵ� ������ �迭
 * @param size ���ĵ� ������ �迭�� ũ��
 * @note ���� ���Ĺ���� ������ �����Ƿ� �ٸ� ���Ĺ������ �ٲٴ°� �� BigO : O(n^2)
 */
void Sort( unsigned data[] , const unsigned size )
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

/**
 * @brief ������ ���� ���� ���� ���ö����� ���� �޴� �Լ�
 * @param data Ȯ���� �������� ���۷���
 * @param min �ּڰ�
 * @param max �ִ�
 */
void GetDataWhileAvailable( unsigned& data , const unsigned min , const unsigned max )
{
	while (true)
	{
		std::cin >> data;
		if (data > min && data < max)
			break;
		std::cout << "���� ���� ���� ���� �ʽ��ϴ�!" << std::endl;
	}
}
