#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinTreeNode {
    char key;
    struct BinTreeNode *left;
    struct BinTreeNode *right;
} BinTreeNode;

BinTreeNode *BinTreeRebuild(char preordemEst[], int rootIndex, int *qtdNos) {
    BinTreeNode *root;
    int qtdNosSubarv;
    if (rootIndex < 0) {
        return NULL;
    }
    root = malloc(sizeof(BinTreeNode));
    root->key = preordemEst[rootIndex];
    root->left = NULL;
    root->right = NULL;

    *qtdNos = 1;

    if (preordemEst[rootIndex + 1] != '0') {
        root->left = BinTreeRebuild(preordemEst, rootIndex + 3, &qtdNosSubarv);
        *qtdNos += qtdNosSubarv;
    }

    if (preordemEst[rootIndex + 2] != '0') {
        root->right = BinTreeRebuild(preordemEst, rootIndex + (*qtdNos * 3), &qtdNosSubarv);
        *qtdNos += qtdNosSubarv;
    }

    return root;
}

void showTreeIn(BinTreeNode *root)
{
	if (root==NULL) return;
	showTreeIn(root->left);
	printf("%c",root->key);
	showTreeIn(root->right);
}

void showTreePos(BinTreeNode *root)
{
	if (root==NULL) return;
	showTreePos(root->left);
  showTreePos(root->right);
	printf("%c",root->key);

}

void freeTree(BinTreeNode *root)
{
	if (root==NULL) return;
	freeTree(root->left);
  freeTree(root->right);
  free(root);
	printf("0");
}

int main() {
    int qtdNos;
    int tamPreordemEst;
    char *preordemEst = NULL;
    BinTreeNode *root;


    scanf("%d", &qtdNos);

    tamPreordemEst = qtdNos * 3;
    preordemEst = malloc((tamPreordemEst + 1) * sizeof(char));

    scanf("\n");
    fgets(preordemEst, tamPreordemEst + 1, stdin);
    preordemEst[strcspn(preordemEst, "\n")] = '\0';


    if (qtdNos > 0) {

        root = BinTreeRebuild(preordemEst, 0, &qtdNos);
    }
    else {
        root = NULL;
    }
    //imprimindo in-order
    showTreeIn(root);
    printf("\n");
    //imprimindo pos-order
    showTreePos(root);
    printf("\n");
    //reset
    freeTree(root);

    return 0;
}
