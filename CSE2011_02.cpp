#include <iostream>

/*
 * Question
 * Input
 * 폭주기관차의 갯수(미정)
 * 폭주기관차의 성능을 가진 배열(2 < n < 1000 && n != 0)
 * Output
 * 치킨뜯은 기관차
 */

void Sort( int data[] , const int size );

int main( int argc , char* argv[] )
{
	int* trains = nullptr; // 폭주기관차 배열
	int size = 0; // 폭주기관차 갯수
	int last = 0; // 만약 반대편에 같은 성능의 기차가 올때 중복비교 못하도록 설정
	int result = 0; // 최종생존자의 인덱스

	/*기관차의 갯수를 받아옴*/
	while (true)
	{
		std::cin >> size;
		if(size >= 2 && size < 1000 && size !=0 )
			break;
		std::cout <<"잘못된 값이 입력되었습니다."<<std::endl;
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
		std::cout << "모든 기차가 한 방향을 보고 있습니다" << std::endl;
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
		int left = trains[head] * trains[head]; // 왼쪽기차의 제곱
		int right = trains[last] * trains[last]; // 오른쪽기차의 제곱
		
		/*정렬된 데이터에서 절댓값이 가장 큰 값이 최종 승리자*/
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
		/*둘이 성능이 같으므로 다음 인덱스 비교*/
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