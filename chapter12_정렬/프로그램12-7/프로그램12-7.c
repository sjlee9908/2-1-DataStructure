void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);	//피벗을 기준으로 2개의 리스트로 분할
												//q는 피벗의 위치
		quick_sort(list, left, q - 1);	//left에서 피벗 바로 앞까지를 대상으로 순환호출
		quick_sort(list, q + 1, right);	//피벗위치 바로 다음부터 right까지를 대상으로 순환호출
	}
}