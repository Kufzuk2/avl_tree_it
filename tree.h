#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
{
    bool        is_right_;
    struct node*  parent_;
    struct node*   right_;
    struct node*    left_;
    int            value_;
    int           height_;
    int         position_;
    int     total_height_; 
    int      left_height_;
    int     right_height_;

} node;


node* create_tree(int value);

node* insert(node** root, int value);

 
node* balance(node* root);  /// returns a new root

node* right_big_turn(node* root);
                            
node* right_small_turn(node* root);

node*  left_big_turn(node* root);
                            
node*  left_small_turn(node* root);


int raise_heights(node* root, int param_one); // param = 1 -> only heights, param = 2 -> also 

int decrease_heights(node* root);  /// height-- in the whole tree under the mentioned root

node* raise_part_heights(node* new_leave); // returns NULL if no balancing needed
#if 0 
node* delete_leave(int value);
#endif

void print_tree(node* root); 

node* is_in_tree(node* root, int value);

void smart_print(node* root);

int recalc_positions(node* root); // must not be problems wight parent, cause balancing leaves at least 2 levels

int to_degree(int value, int degree);

void print_space(int space_num); /// problems with big numbers

/// queue   **************************************
typedef struct queue
{
    struct queue*  next_;
    node*         leave_;

} queue;


queue* add_elem(queue* end, node* leave);

queue* dequeue(queue* front);

void q_print(queue* front);
/// queue    *************************************
