/*https://www.acmicpc.net/problem/1991 */

/*[1991] 트리 순회*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node* tree_node_ptr;
struct tree_node
{
	char data;
	tree_node_ptr left;
	tree_node_ptr right;
};

void PostOrder(tree_node_ptr ptr);
void InOrder(tree_node_ptr ptr);
void PreOrder(tree_node_ptr ptr);
tree_node_ptr MakeNode(char);

int main(void)
{
	int n;
	char root, left, right;
	char node[27][2]; /*[node][left], [node][right]*/
	tree_node_ptr tree[27]; /*node information*/
	tree[0] = NULL;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s(" %c %c %c", &root, 1, &left, 1, &right, 1);
		node[i][0] = left;
		node[i][1] = right;
		tree[i] = MakeNode(root);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (node[i][0] == tree[j]->data)
				tree[i]->left = tree[j];
			if (node[i][1] == tree[j]->data)
				tree[i]->right = tree[j];
		}
	}
	PreOrder(tree[0]); printf("\n");
	InOrder(tree[0]); printf("\n");
	PostOrder(tree[0]);
	return 0;
}

void PostOrder(tree_node_ptr ptr)
{
	if (ptr == NULL)
		return;
	PostOrder(ptr->left);
	PostOrder(ptr->right);
	printf("%c", ptr->data);
}

void InOrder(tree_node_ptr ptr)
{
	if (ptr == NULL)
		return;
	InOrder(ptr->left);
	printf("%c", ptr->data);
	InOrder(ptr->right);
}

void PreOrder(tree_node_ptr ptr)
{
	if (ptr == NULL)
		return;
	printf("%c", ptr->data);
	PreOrder(ptr->left);
	PreOrder(ptr->right);
}

tree_node_ptr MakeNode(char data)
{
	tree_node_ptr temp;
	temp = (tree_node_ptr)malloc(sizeof(struct tree_node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
