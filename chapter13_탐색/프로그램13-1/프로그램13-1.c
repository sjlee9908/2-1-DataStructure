int list[100] = {0,};

int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		if (list[i] == key) return i;	//Ž���� �����ϸ� index��ȯ
	}
	return -1;	//Ž���� �����ϸ� -1��ȯ
}