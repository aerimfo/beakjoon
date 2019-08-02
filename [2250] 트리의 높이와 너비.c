/*https://www.acmicpc.net/problem/2250 */

#include <stdio.h>
#define MAX 10001
typedef struct tree_node* tree_node_ptr;
struct tree_node
{
	int data;
	tree_node_ptr left;
	tree_node_ptr right;
};

tree_node_ptr tree; /*root*/
tree_node_ptr MakeNode(char data);
int in[MAX]; /*중위순회로 매긴 번호*/
void inorder(tree_node_ptr ptr);
int in_index; /*중위 순회 인덱스*/

int main(void)
{
	int levelwidth[MAX];
	int tree_index[MAX];
	int n, root, left, right;
	int min = 0, max = 0; /*각 레벨의 가장 왼쪽, 가장 오른쪽*/
	int point = 0;
	int maxwidth = 0;
	tree_node_ptr tree_root[MAX];
	int node[MAX][2];
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d %d %d", &root, &left, &right);
		node[root][0] = left;
		node[root][1] = right;
		tree_root[root] = MakeNode(root);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (node[i][0] == tree_root[j]->data)
				tree_root[i]->left = tree_root[j];
			if (node[i][1] == tree_root[j]->data)
				tree_root[i]->right = tree_root[j];
		}
	}
	inorder(tree);
	for (int i = 1; i <= n; i++) /*각 레벨에서 가장 왼쪽, 오른쪽 노드 열 번호 찾기*/
	{
		for (int j = 1; j <= n; j++) /*열 시작*/
			if (in[j] != 0)
			{
				min = j;
				break;
			}
		for (int k = n; k >= 1; k--) /*열 끝*/
			if (in[k] != 0)
			{
				max = k;
				break;
			}
		levelwidth[i] = max - min;
	}

	for (int i = 1; i <= n; i++)
	{
		if (levelwidth[i] > maxwidth)
		{
			maxwidth = levelwidth[i];
			point = i;
		}
	}
	printf("%d %d", point, maxwidth);
}

void inorder(tree_node_ptr ptr)
{
	in_index++;
	if (ptr == NULL)
		return;
	inorder(ptr->left);
	in[ptr->data] = in_index;
	inorder(ptr->right);
}

tree_node_ptr MakeNode(int data)
{
	tree_node_ptr temp;
	temp = (tree_node_ptr)malloc(sizeof(struct tree_node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
