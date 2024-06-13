#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct {
	char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];

//문자로 된 키를 숫자로 변환
int transform(char* key) {
	int number = 0;
	while (*key) number = 31 * number + *key++;
	return number;
}

//제산함수를 사용한 해싱함수
int hash_function(char* key) {
	return transform(key) % TABLE_SIZE;
}