int list[100]; //정렬되어 있음

int search_binary(int key, int low, int high) {
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle]) return middle;
		else if (key > list[middle]) low = middle + 1;
		else high = middle - 1;
	}
	return -1;
}