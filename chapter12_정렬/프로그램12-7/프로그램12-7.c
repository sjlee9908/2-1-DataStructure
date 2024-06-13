void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);	//�ǹ��� �������� 2���� ����Ʈ�� ����
												//q�� �ǹ��� ��ġ
		quick_sort(list, left, q - 1);	//left���� �ǹ� �ٷ� �ձ����� ������� ��ȯȣ��
		quick_sort(list, q + 1, right);	//�ǹ���ġ �ٷ� �������� right������ ������� ��ȯȣ��
	}
}