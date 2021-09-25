#include <stdio.h>
#include <stdlib>


struct student{
  int enroll; //matricula
  char name[41];
  float perfom; //media de notas
};

struct std_node{
  struct student info;
  struct std_node *right;
  struct std_node *left;
};

struct Tree {
  struct node *root;
};

typedef struct std_node StdNode;
typedef struct Tree tree;

Tree *newNode(Tree *mytree)

StdNode *newStdNode()

void insertNode(tree *tree, StdNode *node){

}

int main(){

	return 0;
}
