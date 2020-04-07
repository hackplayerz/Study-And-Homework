#pragma warning(disable:4996) // Disable CRT_SECURE_WARNING error.
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
	int Row; ///< 행
	int Column; ///< 열
	int Value; ///< 값
}*PMatrix, Matrix;

/**
 * @brief 전치행렬 수행 메서드
 * @param a : 바뀔 행렬 a
 * @param b : 바뀔 행렬 b
 * O(column * (column * rows)) => column = n이라고 치환
 *													 rows = m이라고 치환
 *													 일때
 *	BigO : O(n^2 * m)
 */
void Transpose(Matrix* a, Matrix* b)
{
	int current = 1; ///< 현재 바뀔 원소의 인덱스. 1번부터 바뀌는 이유는 0번 인덱스는 피벗라인에 있기 때문에 바뀌지 않아서 1번부터 연산을 수행한다.
	
	/*전치행렬을 수행해 행과 열을 교환.*/
	b[0].Column = a[0].Row;
	b[0].Row = a[0].Column;
	b[0].Value = a[0].Value;

	/*0이 아닌 원소가 있는 경우에만 전치연산 수행.*/
	if(a[0].Value > 0)
	{
		/*희소 행렬 a의 열별로 전치 반복 수행.*/
		for (int i=0;i<a[0].Column;i++)
		{
			/*희소행렬a의 원소 수가 0이 아닐 반복 수행.*/
			for (int j = 1; j<=a[0].Value;j++)
			{
				/*현재 열에 속하는 원소가 있으면 b에 삽입.*/
				if(a[j].Column == i)
				{
					/*
					 * 원소 Swap
					 * 전치연산 수행
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
	}; ///<전치행열을 위한 데이터를 임의로 설정.
	
	Matrix* swapMatrix = nullptr; ///< 전치행열이 끝난 데이터가 저장될 변수.
	swapMatrix = (Matrix*)malloc( sizeof(Matrix) * MATRIX_DATA_SIZE ); // Set memory dynamically.

	Transpose(originalMatrix, swapMatrix); // 전치연산을 수행.

	/*Show Result.*/	
	for (int i = 0;i<MATRIX_DATA_SIZE;i++)
	{
		printf("행 : %d\t열 : %d\t0이 아닌 항 : %d\n", 
			originalMatrix[i].Row, originalMatrix[i].Column, originalMatrix[i].Value);		
	}
	printf("\n\n");
	for (int i = 0; i < MATRIX_DATA_SIZE; i++)
	{
		printf("행 : %d\t열 : %d\t0이 아닌 항 : %d\n", swapMatrix[i].Row, swapMatrix[i].Column, swapMatrix[i].Value);
	}

	/*
	 * Safe delete pointer.
	 * Disable access to dangling pointer.
	 */
	SAFE_DELETE(swapMatrix);
	
	return 0;
}
