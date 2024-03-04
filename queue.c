
#include "queue.h"



queue* add_elem(queue* end, int value)
{
    if (!end)        
        return NULL;
    
    queue* cur_obj = (queue*) malloc(sizeof(queue));


    cur_obj->next_  = NULL;
    cur_obj->value_ = value;
    cur_obj->size_  = end->size_ + 1;

    end->next_ = cur_obj;

    return cur_obj;
}


queue* dequeue(queue* front)
{
    if (!front)
    {
        return front;       
    }

    return front->next_;
}


void q_print(queue* front)
{
    if (!front->next_)
        return;

    queue* cur_elem = front->next_;
    
    while (cur_elem)
    {
        printf("%d ", cur_elem->value_);
        cur_elem = cur_elem->next_;
    }
    printf("\n");
}
