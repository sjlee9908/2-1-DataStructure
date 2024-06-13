#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct {
	char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];