int list[100] = {0,};

int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		if (list[i] == key) return i;	//탐색에 성공하면 index반환
	}
	return -1;	//탐색에 실패하면 -1반환
}