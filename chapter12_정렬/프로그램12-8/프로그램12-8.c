#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int patition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];				//����Ʈ�� ���� ���� �����͸� �ǹ����� ����
	do {
		do
			low++;					//left+1���� low ���
		while (list[low] < pivot);	//list[low]�� �ǹ����� ������, low ����
		do
			high--;					//right���� high ���
		while (list[high] > pivot);	//list[high]�� �ǹ����� ũ��, high ����
		if (low < high) SWAP(list[low], list[high], temp);		//low�� high�� �������� ������ ��ȯ
	} while (low < high);										//low�� high�� �����Ǹ� ����
	SWAP(list[left], list[high], temp);		//�ǹ��� �߾ӿ� ��ġ
	return high;		//�ǹ��� �ε��� ��ȯ
}