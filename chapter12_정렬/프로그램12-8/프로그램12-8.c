#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int patition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];				//리스트의 가장 왼쪽 데이터를 피벗으로 선택
	do {
		do
			low++;					//left+1에서 low 출발
		while (list[low] < pivot);	//list[low]가 피벗보다 작으면, low 증가
		do
			high--;					//right에서 high 출발
		while (list[high] > pivot);	//list[high]가 피벗보다 크면, high 증가
		if (low < high) SWAP(list[low], list[high], temp);		//low와 high가 교차되지 않으면 교환
	} while (low < high);										//low와 high가 교차되면 종료
	SWAP(list[left], list[high], temp);		//피벗을 중앙에 위치
	return high;		//피벗의 인덱스 반환
}