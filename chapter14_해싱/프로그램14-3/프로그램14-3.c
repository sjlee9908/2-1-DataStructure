#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct {
	char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];

//���ڷ� �� Ű�� ���ڷ� ��ȯ
int transform(char* key) {
	int number = 0;
	while (*key) number = 31 * number + *key++;
	return number;
}

//�����Լ��� ����� �ؽ��Լ�
int hash_function(char* key) {
	return transform(key) % TABLE_SIZE;
}