
#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    struct queue*  next_;
    int           value_;
    int            size_;

} queue;


queue* add_elem(queue* end, int value);

queue* dequeue(queue* front);

void q_print(queue* front);
