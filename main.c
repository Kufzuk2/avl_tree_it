#include "tree.h"
#include <time.h>
int main()
{
    printf("func started \n");

    printf("\n");
    
    srand(time(NULL));

    node* tree = create_tree(rand() % 150);

    for (int i = 0; i < 10; i++)
    {
        insert(&tree, rand() % 100);
        smart_print(tree);
        printf("\n");
    }
    

}
