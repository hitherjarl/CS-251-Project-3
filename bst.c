/*
 * Mohamed Imran Mohamed Siddique
 * Program 3 - Binary Search Tree
 * UIN: 656951860
 */

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct bst_node {
    int val;
    struct bst_node *left;
    struct bst_node *right;
        int Nleft;
        int Nright;
    int total;

};
typedef struct bst_node NODE;


struct bst {
    NODE *root;
    int size;
    int max;
    int min;
    
};

BST * bst_create(){
  BST * t = malloc(sizeof(struct bst));
  t->root = NULL;
    t->size = 0;
    t->max = INT_MIN;
    t->min = INT_MAX;
  return t;
}


static void free_r(NODE *r){
    if(r==NULL) return;
    free_r(r->left);
    free_r(r->right);
    free(r);
}
void bst_free(BST * t){
    free_r(t->root);
    free(t);
}

static NODE * insert(NODE *r, int x){
    NODE *leaf;
    if(r == NULL){
      leaf = malloc(sizeof(NODE));
      leaf->left = NULL;
      leaf->right = NULL;
        leaf->Nright = 0;
        leaf->Nleft = 0;
      leaf->val = x;
      return leaf;
    }
    
    
    if(r->val == x)
        return r;
    if(x < r->val){
        r->left = insert(r->left, x);
            r->Nleft++;
        return r;
    }
    else {
        r->right = insert(r->right, x);
            r->Nright++;
        return r;
    }
    
    
}

// how about an iterative version?
static NODE *insert_i(NODE *r, int x){

  return NULL;

}


void bst_insert(BST * t, int x){
    NODE *tmp;
    t->root = insert(t->root, x);
    t->size++;
    if (x > t->max)
        t->max = x;
    if (x < t->min)
        t->min = x;
    
}

int bst_contains(BST * t, int x){
    NODE *p = t->root;

    while(p != NULL){
        
        if(p->val == x)
            return 1;
        if(x < p->val){
            p = p->left;
        }
        else
            p = p->right;
    }
    return 0;  
}

static int min_h(NODE *r){
  if(r==NULL)
    return -1; // should never happen!
  while(r->left != NULL)
      r = r->left;
  return r->val;
}

static int max_h(NODE *r){
  if(r==NULL)
    return -1; // should never happen!
  while(r->right != NULL)
      r = r->right;
  return r->val;
}

static NODE *remove_r(NODE *r, int x, int *success){
NODE   *tmp;
int sanity;

  if(r==NULL){
    *success = 0;
    return NULL;
  }
  if(r->val == x){
    *success = 1;

    if(r->left == NULL){
        tmp = r->right;
        free(r);
        return tmp;
    }
    if(r->right == NULL){
        tmp = r->left;
        free(r);
        return tmp;
    }
    // if we get here, r has two children
    r->val = min_h(r->right);
    r->right = remove_r(r->right, r->val, &sanity);
    if(!sanity)
        printf("ERROR:  remove() failed to delete promoted value?\n");
    return r;
  }
  if(x < r->val){
    r->left = remove_r(r->left, x, success);
      r->Nleft--;
  }
  else {
    r->right = remove_r(r->right, x, success);
      r->Nright--;
  }
  return r;

}


int bst_remove(BST * t, int x){
    int success;
    t->root = remove_r(t->root, x, &success);
    return success;
}
static int size(NODE *r){

    if(r==NULL) return 0;
    return size(r->left) + size(r->right) + 1;
}
int bst_size(BST * t){

    return size(t->root);
}

static int height(NODE *r){
    int l_h, r_h;

    if(r==NULL) return -1;
    l_h = height(r->left);
    r_h = height(r->right);
    return 1 + (l_h > r_h ? l_h : r_h);

}
int bst_height(BST * t){
    return height(t->root);

}

int bst_min(BST * t){
    return min_h(t->root);
}

int bst_max(BST * t){
    return max_h(t->root);
}

static void indent(int m){
    int i;
    for(i=0; i<m; i++)
        printf("-");
}

static void inorder(NODE *r){
  if(r==NULL) return;
  inorder(r->right);
  printf("[%d]\n", r->val);
  inorder(r->left);

}
void bst_inorder(BST * t){

  printf("========BEGIN INORDER============\n");
  inorder(t->root);
  printf("=========END INORDER============\n");

}

static void preorder(NODE *r, int margin){
  if(r==NULL) {
    indent(margin);
    printf("NULL \n");
  } else {
    indent(margin);
    printf("%d\n", r->val);
    preorder(r->left, margin+3);
    preorder(r->right, margin+3);
  }
}

void bst_preorder(BST * t){

  printf("========BEGIN PREORDER============\n");
  preorder(t->root, 0);
  printf("=========END PREORDER============\n");

}

/* 
 * Complete the (recursive) helper function for the post-order traversal.
 * Remember: the indentation needs to be proportional to the height of the node!
 */
static void postorder(NODE *r, int margin){
    if(r==NULL) {
        indent(margin);
        printf("NULL \n");
    }
    else {
        
        postorder(r->left, margin+3);
        postorder(r->right, margin+3);
        indent(margin);
        printf("%d\n", r->val);
        
    }
}

// indentation is proportional to depth of node being printed
//   depth is #hops from root.
void bst_postorder(BST * t){

  printf("\n========BEGIN POSTORDER============\n");
  postorder(t->root, 0);
  printf("=========END POSTORDER============\n");

}

/* 
 * Write the (recursive) helper function from_arr, used by
 * bst_from_sorted_arr(...). The function must return a sub-tree that is
 * perfectly balanced, given a sorted array of elements a.
 */
static NODE * from_arr(int *a, int n){
int m;
NODE *root;

    if(n <= 0) return NULL;
    m = n/2;
    root = malloc(sizeof(NODE));
    root->val = a[m];
    root->left = from_arr(a, m);
    root->right = from_arr(&(a[m+1]), n-(m+1));
    return root;

}

BST * bst_from_sorted_arr(int *a, int n){

  BST * t = bst_create();

  t->root = from_arr(a, n);

  return t;
}

/* helper function for bst_to_array */
void returnInOrder(NODE *r, int a[], int *i){
    //check to see if node is null
    if(r==NULL)
        //do nothing
        return;
    //recursive call on the left child
    returnInOrder(r->left, a, i);
    //assign the current index as the node's value
    a[*i] = r->val;
    //increase to the next index
    (*i)++;
    //recursive call on the right child
    returnInOrder(r->right, a, i);
}

int * bst_to_array(BST * t) {
    //allocate an integer array the same size as the bst
    int *arr = malloc(sizeof(int) * 74);
    //fill the array with values from the tree in order (left, parent, right)
    int i = 0;
    //call helper function
    returnInOrder(t->root, arr, &i);
    //returned filled-in array
    return arr;
}

/* helper function for bst_get_ith */
int ith_smallest(NODE *r, int a){
    //check if the node is empty
    if(r == NULL)
        return r->val;
    //if the size of left plus 1 is equal to i or a then return the current val
    if(r->Nleft + 1 == a)
        return r->val;
    //if the size of the left side is less than a, then move onto the right side
    if (r->Nleft < a)
        return ith_smallest(r->right, a - r->Nleft - 1);
        //move to the left side if the above condition does not meet
        return ith_smallest(r->left, a);
    
}
/* returns the ith smallest element in t. i ranges from 1..n where n is the number of elements in the tree */
int bst_get_ith(BST * t, int i) {
    if(i < 1 || i > size(t->root)){
        fprintf(stderr, "\nERROR: i must range between 1 and the number of elements in the tree.\n");
        return -999;
    }
    
    return ith_smallest(t->root, i);
}


int nearest(NODE *r, int a, NODE *near){
    //if root is nothing
    if(r == NULL)
        return near->val;
    //value is exactly
    if(r->val == a)
        return r->val;
    
    if(near == NULL || (abs(r->val - a) < abs(near->val - a)))
        near = r;
    
    //look left
    if(a < r->val)
        return nearest(r->left, a, near);
    //look right
    else
        return nearest(r->right, a, near);
}

/* returns the value in the tree closest to x ie, some y in the tree where |x-y| is minimum. if there are two such y's, one is chosen arbitrarily. */
int bst_get_nearest(BST * t, int x){
    if(t->root == NULL){
        fprintf(stderr, "\n\tERROR: Tree is empty!!\n");
        return -999;
    }
    NODE *closest = t->root;
    
    if(x > max_h(t->root))
        return max_h(t->root);
    if(x < min_h(t->root))
        return min_h(t->root);
    
    return nearest(t->root, x, closest);
}

/* helper function for bst_num_geq */
void geq(NODE *r, int a, int *b){
    if(r == NULL)
        return;
    if(r->val == a){
        (*b)++;
        return geq(r->right, a, b);
    }
    if(r->val > a){
        *b += r->Nright + 1;
        return geq(r->left, a, b);
    }
    return geq(r->right, a, b);
}
/* returns the number of elements in t which are greater than or equal to x */
int bst_num_geq(BST * t, int x) {
    int counter = 0;
    if(x > max_h(t->root))
        return 0;
    if(x <= min_h(t->root))
        return size(t->root);
    geq(t->root, x, &counter);
    return counter;
}

/* helper function for bst_num_leq */
int num_leq(NODE *r, int a, int *b){
    if(r == NULL)
        return 0;
    if(r->val == a){
        (*b)++;
        return num_leq(r->left, a, b);
    }
    if(r->val < a){
        *b += r->Nleft + 1;
        return num_leq(r->right, a, b);
    }
    return num_leq(r->left, a, b);
}
/* returns the number of elements in t which are less than or equal to x */
int bst_num_leq(BST * t, int x) {
    int counter = 0;
    if(x < min_h(t->root))
        return 0;
    if(x >= max_h(t->root))
        return size(t->root);
    num_leq(t->root, x, &counter);
    return counter;
}

int  range(NODE *tmp, int min, int max) {
   // check is the current node is empty
    if (tmp == NULL)
    {
        return 0;
    }
    else
    { // go into checking if the tmp is in between the min and max
        int num = 0;
        
    if (tmp->val > min && tmp->val < max)
    {
    //if it is in between, it proceeds to print the value in between it
        num++;
        printf("%d \n", tmp->val);
    }
    //recursively go through the function
    return num + range(tmp->left, min, max) + range(tmp->right, min, max);
        
    }
}

/* returns the number of elements in between max and min*/
int bst_num_range(BST * t, int min, int max) {
    printf("The Elements in between %d and %d are: \n",min, max);
    return range(t->root, min, max);
}



//main function that does the size_blancing
int bst_sb_work(BST *t) {
    return 0;
   
}


