int list[100]; //정렬되어 있음

int search_binary(int key, int low, int high) {
	int middle;

	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle]) return middle;
		else if (key < list[middle]) return search_binary(key, low, middle - 1);
		else return search_binary(key, middle-1, high);
	}
	return -1;
}
