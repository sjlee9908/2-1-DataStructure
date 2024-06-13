#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct TreeNode {
	int key;
	char name[20];
	char num[20];
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(int key, char name[20], char num[20]) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = key;
	strcpy(tmp->name, name);
	strcpy(tmp->num, num);
	tmp->left = tmp->right = NULL;
	return tmp;
}

TreeNode* insert_node(TreeNode* root, int key , char name[20], char num[20]) {
	if (root == NULL) return new_node(key, name, num);
	if (key < root->key) root->left = insert_node(root->left, key, name, num);
	else if (key > root->key) root->right = insert_node(root->right, key, name, num);
	return root;
}

TreeNode* search_(TreeNode* root, char name[20]) {
	if (root) {
		if (!strcmp(root->name, name)) printf("친구의 전화번호: %s\n", root->num);
		search_(root->right, name);
	}
}


TreeNode* delete_(TreeNode* root, char name[20]) {
	if (root) {
		if (!strcmp(root->name, name)) {
			strcpy(root->name, "removed");
			strcpy(root->num, "removed");
		}
		delete_(root->right, name);
	}

}

int main() {
	TreeNode* root = NULL;
	char ch;
	char name[20];
	char num[20];
	int i=0;

	while (1) {
		printf("삽입(i), 탐색(s), 삭제(d): ");
		scanf("%c", &ch);
		getchar();

		if (ch == 'i') {
			printf("친구의 이름: ");
			scanf("%s", name);
			getchar();
			printf("친구의 전화번호: ");
			scanf("%s", num);
			getchar();
			root = insert_node(root, i, name, num);
		}

		else if (ch == 's') {
			printf("친구의 이름: ");
			scanf("%s", name);
			getchar();
			search_(root, name);
		}

		else if (ch == 'd') {
			printf("친구의 이름: ");
			scanf("%s", name);
			getchar();
			delete_(root, name);
		}
		i++;
	}
	
}