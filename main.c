#include "tree.h"
#include <time.h>
int main()
{
    int max_ord = 3;
    printf("func started \n");

    printf("\n");

#ifdef RAND
    srand(time(NULL));

    node* tree = create_tree(rand() % 950);

    for (int i = 0; i < 15; i++)
    {
        int num = rand() % 100;
        insert(&tree, num);

        printf("new digit = %d \n", num);
        smart_print(tree, max_ord);
        printf("\n");
    }
#endif

#ifdef REORD

    node* tree = create_tree(25);

        insert(&tree, 0);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 65);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 58);
        smart_print(tree, max_ord);
        printf("\n");


#endif

#ifdef ORD
    node* tree = create_tree(25);

        insert(&tree, 81);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 0);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 65);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 70);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 98);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 58);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 4);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 36);
        smart_print(tree, max_ord);
        printf("\n");

        insert(&tree, 76);
        smart_print(tree, max_ord);
        printf("\n");
        
        insert(&tree, 64);
        smart_print(tree, max_ord);
        printf("\n");
#endif




    chop_tree(tree);

}
