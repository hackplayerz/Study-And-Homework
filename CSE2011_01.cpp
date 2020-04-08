#include <iostream>

/*
 * Question
 * 산 물건의 무게 (1 < n < 30,000) 봉투의 한계무게(1 < m < 30,000)를 입력
 * 물건의 갯수(1 < p < 50,000) 입력
 * 각 봉투당 최대 수납갯수 2
 * Input
 * 봉투의 한계무게, 물건의 무게
 *
 * Output
 * 봉투의 최소갯수
 */

void GetDataWhileAvailable( unsigned& data , unsigned min , unsigned max );
void Sort( unsigned data[] , unsigned size );

int main( int argc , char* argv[] )
{
	unsigned itemNumber = 0; // 물건의 갯수(p)
	unsigned maximumWeight = 0; // 봉투의 한계무게(m)
	unsigned* items = nullptr; // 물건들의 무게들
	unsigned result = 0; // 문제의 결과값.
	unsigned used = 0; // 앞번부터 순차적으로 올라갈 변수 캐싱

	/*m의 값이 제대로 들어올떄까지 받는다.*/
	GetDataWhileAvailable( maximumWeight, 1, 30000 );
	/*p의 값이 제대로 들어올떄까지 받는다.*/
	GetDataWhileAvailable( itemNumber, 1, 50000 );

	items = new( std::nothrow ) unsigned[itemNumber]; // Allocation memory dynamically.
	if (!items) // Check std::Bad_allocation.
		return 0;

	/*
	 * 물건의 무게를 갯수만큼 받아온다.
	 * 문제에서는 1줄로 받아왔지만 문자열파싱이 필요하므로 귀찮아오
	 */
	for (unsigned i = 0; i < itemNumber; i++)
	{
		GetDataWhileAvailable( items[i], 0, 30000 );
	}

	/*문제를 쉽게 풀기위해 정렬*/
	Sort( items, itemNumber );

	for (unsigned i = itemNumber - 1; i > 0; i--)
	{
		/*최대 무게보다 클때 -1로 처리*/
		if (items[i] > maximumWeight)
		{
			result = -1;
			break;
		}
		/*현재 무게가 최대값일때 바로 추가*/
		if (items[i] == maximumWeight)
		{
			result++;
			continue;
		}
		for (; used < itemNumber - 1; used++)
		{
			/*인덱스 교차가 일어나면 강제종료*/
			if (used >= i)
				break;
			
			unsigned value = items[i] + items[used]; // 가방에 넣는다.

			/*무게한도를 넘으면 다음 인덱스 체크*/
			if (value > maximumWeight)
				continue;

			/*사용가능한 값일때 결과에 추가*/
			used++; // 이미 사용된 값이므로 j번 인덱스를 used에 넣어둬 재사용 방지.
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
 * 문제를 풀기위해서는 정렬이 필요하지만 귀찮으니 버블정렬
 * @param data 정렬될 데이터 배열
 * @param size 정렬될 데이터 배열의 크기
 * @note 현재 정렬방식은 굉장히 느리므로 다른 정렬방식으로 바꾸는게 남 BigO : O(n^2)
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
 * @brief 변수의 값이 범위 내에 들어올때까지 값을 받는 함수
 * @param data 확인할 데이터의 레퍼런스
 * @param min 최솟값
 * @param max 최댓값
 */
void GetDataWhileAvailable( unsigned& data , const unsigned min , const unsigned max )
{
	while (true)
	{
		std::cin >> data;
		if (data > min && data < max)
			break;
		std::cout << "값이 범위 내에 있지 않습니다!" << std::endl;
	}
}
