#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef enum type {
    LEFT, RIGHT
} TYPE;

typedef struct binary_tree {
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
} TREE;

TREE *createTree(int data) {
    TREE *tree = malloc(sizeof(TREE));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void insertTree(TREE *parent, TREE *insert, TYPE type) {
    if (insert != NULL) {
        if (type == LEFT) {
            parent->left = insert;
        } else if (type == RIGHT) {
            parent->right = insert;
        }
    }
}

TREE *init(void) {
    TREE *init[11];
    for (int i = 0; i < 11; i++) {
        init[i] = createTree(i);
    }

    insertTree(init[0], init[1], LEFT);
    insertTree(init[0], init[2], RIGHT);

    insertTree(init[1], init[3], LEFT);
    insertTree(init[1], init[4], RIGHT);

    insertTree(init[2], init[5], LEFT);
    insertTree(init[2], init[6], RIGHT);

    insertTree(init[3], init[7], LEFT);
    insertTree(init[3], init[8], RIGHT);

    insertTree(init[6], init[9], LEFT);
    insertTree(init[6], init[10], RIGHT);

    return init[0];
}

void preorder(TREE *tree) {
    if (tree != NULL) {
        printf(" %d", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(TREE *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf(" %d", tree->data);
        inorder(tree->right);
    }
}

void postorder(TREE *tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf(" %d", tree->data);
    }
}

void freeTree(TREE *tree) {
    if (tree == NULL)
        return;

    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

int main(void) {
    TREE *head = init();

    // 전위순회
    printf("전위 순회 결과:");
    preorder(head);
    printf("\n");

    // 중위순회
    printf("중위 순회 결과:");
    inorder(head);
    printf("\n");

    // 후위순회
    printf("후위 순회 결과:");
    postorder(head);
    printf("\n");

    freeTree(head);

    return 0;
}