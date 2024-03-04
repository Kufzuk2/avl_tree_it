#include "queue.h"

int main()
{
    
    queue* front = (queue*) calloc(1, sizeof(queue));
    queue*   end = (queue*) malloc(sizeof(queue));


    end = front;

    queue* cur_elem = add_elem(front, 1);
    cur_elem = add_elem(cur_elem, 2);
    cur_elem = add_elem(cur_elem, 3);
    cur_elem = add_elem(cur_elem, 3);
    cur_elem = add_elem(cur_elem, 4);
    cur_elet = add_elem(cur_elem, 5);

    printf("%d \n", front->next_->value_);

    front = dequeue(front);
    front = dequeue(front);

    q_print(front);
}
