#include "tree.h"
#include <time.h>
#include <string.h>

int main()
{
    int max_ord = 3;
    printf("func started \n");

    printf("\n");

#ifdef RAND
    srand(time(NULL));

    node* tree = create_tree(rand() % 950);
    int leave_num = 25;

    

    for (int i = 0; i < leave_num; i++)
    {
        int val = rand() % 100;
        insert(&tree, val);


        printf("new digit = %d \n", val);
        smart_print(tree, max_ord);
        printf("\n");
    }

#endif

#ifdef FIXRAND
    printf("type number of the file, you want to write the test in \n");
    char test_num[10];
    scanf("%s", ((char*) test_num));
    char name[5] = "test";

    strcat(name, test_num);
    strcat(name, ".txt");


    srand(time(NULL));

    node* tree = create_tree(rand() % 950);
    int leave_num = 25;
    int leaves[leave_num];
    
    FILE* file = fopen(name, "w");

    fprintf(file, "%d ", leave_num);
    for (int i = 0; i < leave_num; i++)
    {
        int val = rand() % 100;
        fprintf(file, "%d ", val);
        insert(&tree, val);


        printf("new digit = %d \n", val);
        smart_print(tree, max_ord);
        printf("\n");
    }

    
    fclose(file);
#endif

#ifdef CONSOL
    
    int root = -1;
    int num = 0;
    
    scanf("%d", &num);
    scanf("%d", &root);

    node* tree = create_tree(root);

    for (int i = 0; i < num - 1; i++)
    {
        int cur_val = -1;
        scanf("%d", &cur_val);
        insert(&tree, cur_val);
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

char* int_to_str(int val)
{

    if (val < 0)
    {
        printf("beda, we dont work with negative \n");
        return 0;
    }

    char str_num[4];

    if (val == 0)
    {
        str_num[2] = 0 + '0';    
    }


    int a = val;
    
    int hund = val / 100;
    int dec  = (val / 10) / 10;
    int unit = val % 10;

    if (hund)
    {
        str_num[0] = hund + '0';
    }

    if (dec)
    {
        str_num[1] = dec + '0';
    }
    if (unit)
    {
        str_num[2] = unit + '0';
    }

}
