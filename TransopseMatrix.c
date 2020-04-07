#pragma warning(disable:4996) // Disable CRT_SECURE_NO_WARNING error.
#include <stdio.h> // For console input output header.
#include <malloc.h> // For dynamic memory allocation.

/*Matrix max size define*/
#define MATRIX_DATA_SIZE 11

/*Safe delete pointer. Disable access to danging pointer.*/
#define SAFE_DELETE(x)\
{\
	free(x);\
	(x) = nullptr;\
}

/*
 * Matirx data definition.
 */
typedef struct FMatrix
{
	int Row; ///< ��
	int Column; ///< ��
	int Value; ///< ��
}*PMatrix, Matrix;

/**
 * @brief ��ġ��� ���� �޼���
 * @param a : �ٲ� ��� a
 * @param b : �ٲ� ��� b
 * O(column * (column * rows)) => column = n�̶�� ġȯ
 *													 rows = m�̶�� ġȯ
 *													 �϶�
 *	BigO : O(n^2 * m)
 */
void Transpose(Matrix* a, Matrix* b)
{
	int current = 1; ///< ���� �ٲ� ������ �ε���. 1������ �ٲ�� ������ 0�� �ε����� �ǹ����ο� �ֱ� ������ �ٲ��� �ʾƼ� 1������ ������ �����Ѵ�.
	
	/*��ġ����� ������ ��� ���� ��ȯ.*/
	b[0].Column = a[0].Row;
	b[0].Row = a[0].Column;
	b[0].Value = a[0].Value;

	/*0�� �ƴ� ���Ұ� �ִ� ��쿡�� ��ġ���� ����.*/
	if(a[0].Value > 0)
	{
		/*��� ��� a�� ������ ��ġ �ݺ� ����.*/
		for (int i=0;i<a[0].Column;i++)
		{
			/*������a�� ���� ���� 0�� �ƴҋ� �ݺ� ����.*/
			for (int j = 1; j<=a[0].Value;j++)
			{
				/*���� ���� ���ϴ� ���Ұ� ������ b�� ����.*/
				if(a[j].Column == i)
				{
					/*
					 * ���� Swap
					 * ��ġ���� ����
					 */
					b[current].Row = a[j].Column;
					b[current].Column = a[j].Row;
					b[current].Value = a[j].Value;
					current++;
				}
			}
		}
		
	}
}

int main()
{
	Matrix originalMatrix[MATRIX_DATA_SIZE] =
	{
		{8,7,10},
		{0,2,2},
		{0,6,12},
		{1,4,7},
		{2,0,23},
		{3,3,31},
		{4,1,14},
		{4,5,25},
		{5,6,6},
		{6,0,52},
		{7,4,11}
	}; ///<��ġ�࿭�� ���� �����͸� ���Ƿ� ����.
	
	Matrix* swapMatrix = nullptr; ///< ��ġ�࿭�� ���� �����Ͱ� ����� ����.
	swapMatrix = (Matrix*)malloc( sizeof(Matrix) * MATRIX_DATA_SIZE ); // Set memory dynamically.

	Transpose(originalMatrix, swapMatrix); // ��ġ������ ����.

	/*Show Result.*/	
	for (int i = 0;i<MATRIX_DATA_SIZE;i++)
	{
		printf("�� : %d\t�� : %d\t0�� �ƴ� �� : %d\n", 
			originalMatrix[i].Row, originalMatrix[i].Column, originalMatrix[i].Value);		
	}
	printf("\n\n");
	for (int i = 0; i < MATRIX_DATA_SIZE; i++)
	{
		printf("�� : %d\t�� : %d\t0�� �ƴ� �� : %d\n", swapMatrix[i].Row, swapMatrix[i].Column, swapMatrix[i].Value);
	}

	/*
	 * Safe delete pointer.
	 * Disable access to dangling pointer.
	 */
	SAFE_DELETE(swapMatrix);
	
	return 0;
}