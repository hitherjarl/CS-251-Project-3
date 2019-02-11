#include <stdio.h>
#include <assert.h>
#include "bst.h"

/**
    BARE-BONES DEMO PROGRAM.
    You may use this as a starting point for developing your
    testing code
**/

int main(){
    int i;
    int h;
    int n;
    int size;

    int a[] = {8, 2, 6, 9, 11, 3, 7};

    BST * t = bst_create();

    for(i=0; i<7; i++)
        bst_insert(t, a[i]);

    assert(bst_size(t) == 7);
    
    /* ****************** */
    //test size and height
    /* ****************** */

    printf("The height of the tree is: %d\n", bst_height(t));
    
    printf("The size of the tree is: %d\n", bst_size(t));

    printf("AFTER SEQUENTIAL INSERTION OF  {8, 2, 6, 9, 11, 3, 7}\n\n");; 
    bst_inorder(t);
    //bst_preorder(t);
    
     printf("\n\nTEST BST_TO_ARRAY():\tExpected: (see above INORDER)\n");
     int *arr = bst_to_array(t);
     for(i = 0; i < bst_size(t); i++){
      printf("\t[%d]\n", arr[i]);
     }

    
    /* ****************** */
    //test bst_get_ith(...)
    /* ****************** */
    printf("\n\nTEST BST_GET_ITH():\n");
    n = 7;
    printf("\t%dth smallest: %d\n\tExpected: 11\n", n, bst_get_ith(t, n));
    n = 1;
    printf("\n\t%dth smallest: %d\n\t\tExpected: 2\n", n, bst_get_ith(t, n));
    n = 3;
    printf("\n\t%dth smallest: %d\n\t\tExpected: 6\n", n, bst_get_ith(t, n));
    n = 0;
    printf("\t%dth smallest: %d\n\t\tExpected: -999\n", n, bst_get_ith(t, n));
    n = 10;
    printf("\t%dth smallest: %d\n\t\tExpected: -999\n\n", n, bst_get_ith(t, n));
    
    
    /* ****************** */
    //test bst_get_nearest(...)
    /* ****************** */
    printf("\n\nTEST BST_GET_NEAREST():\n");
    BST * x = bst_create();
    n = 5;
    printf("\tValue in tree nearest %d: %d\n\t\tExpected: -999\n", n, bst_get_nearest(x, n));
    n = 5;
    printf("\tValue in tree nearest %d: %d\n\t\tExpected: 6\n", n, bst_get_nearest(t, n));
    n = -9;
    printf("\tValue in tree nearest %d: %d\n\t\tExpected: 2\n", n, bst_get_nearest(t, n));
    n = 14;
    printf("\tValue in tree nearest %d: %d\n\t\tExpected: 11\n", n, bst_get_nearest(t, n));
    n = 8;
    printf("\tValue in tree nearest %d: %d\n\t\tExpected: 8\n", n, bst_get_nearest(t, n));
    
    /* ****************** */
    //test bst_num_geq(...)
    /* ****************** */
    printf("\nTEST BST_NUM_GEQ():\n");
    n = 2;
    printf("\tNumber of elements greater than or equal to %d: %d\n\t\tExpected: 7\n", n, bst_num_geq(t,n));
    n = 11;
    printf("\tNumber of elements greater than or equal to %d: %d\n\t\tExpected: 1\n", n, bst_num_geq(t,n));
    n = 15;
    printf("\tNumber of elements greater than or equal to %d: %d\n\t\tExpected: 0\n", n, bst_num_geq(t,n));
    n = 0;
    printf("\tNumber of elements greater than or equal to %d: %d\n\t\tExpected: 7\n", n, bst_num_geq(t,n));
    n = 5;
    printf("\tNumber of elements greater than or equal to %d: %d\n\t\tExpected: 5\n", n, bst_num_geq(t,n));
    
    /* ****************** */
    //test bst_num_leq(...)
    /* ****************** */
    printf("\n\nTEST BST_NUM_LEQ():\n");
    n = 2;
    printf("\tNumber of elements less than or equal to %d: %d\n\t\tExpected: 1\n", n, bst_num_leq(t, n));
    n = 11;
    printf("\tNumber of elements less than or equal to %d: %d\n\t\tExpected: 7\n", n, bst_num_leq(t, n));
    n = 12;
    printf("\tNumber of elements less than or equal to %d: %d\n\t\tExpected: 7\n", n, bst_num_leq(t, n));
    n = 0;
    printf("\tNumber of elements less than or equal to %d: %d\n\t\tExpected: 0\n", n, bst_num_leq(t, n));
    n = 5;
    printf("\tNumber of elements less than or equal to %d: %d\n\t\tExpected: 2\n", n, bst_num_leq(t, n));
    
    
    bst_num_range(t, 3, 5);
    bst_num_range(t, 1, 7);
    
    
    if(bst_contains(t, 3) == 1){
        printf("It exists\n");
    }
    else {
        printf("Value not found in Tree\n");
    }
    
    
    if(bst_max(t) == 11){
        printf("It is the max\n");
    }
    else {
        printf("it is not the max\n");
    }
    
    if(bst_min(t) == 1){
        printf("It is the max\n");
    }
    else {
        printf("It is not the min\n");
    

    
    
    //bst_postorder(t)

    
    bst_free(t);
    
    
    
    
    /*printf("NOW TRYING bst_from_sorted_arr()\n\n");
    int sorted_a[] = {2, 3, 6, 7, 8, 9, 11};
    
    t = bst_from_sorted_arr(sorted_a, 7);
    
    bst_inorder(t);
    bst_preorder(t);
    bst_postorder(t);
    bst_free(t);

    t = bst_create();
    printf("NOW INSERTING 1...10 in ordern\n");

    for(i=1; i<=10; i++) 
       bst_insert(t, i);

    bst_inorder(t);
    bst_preorder(t);
    bst_free(t); */


    return 0;
}
}
