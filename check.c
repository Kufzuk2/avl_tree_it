#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct a
{
    bool ifis;
};

int main()
{
    struct a* b = (struct a*) calloc(1, sizeof(struct a));

    if (b->ifis)
        printf("true");

    if (!b->ifis)
        printf("false");

    printf("%d \n", abs(-5));
}
