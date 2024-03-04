#include "tree.h"


node* create_tree(int value)
{
    node* root = (node*) calloc(1, sizeof(node)); // if 0
    
    root->value_        = value;
    root->height_       =     0;  
    root->total_height_ =     0;

    return root;
}

node* insert(node** root, int value)
{
    if (!*root)
    {
        printf("Your ptr is NULL, I'm sending it back \n");
        return NULL;
    }

    node* old_parent = *root;

    node* son = (node*) malloc(sizeof(node));

    if (!son)
    {
        printf("problems with memory allocation \n");
        return NULL;
    }
                                              
    while (1)
    {
        if (value == old_parent->value_)
            return old_parent;  
        
                                                   
        if (value < old_parent->value_)
        {
            if (!old_parent->left_)
            {
                son->left_         =                      NULL;
                son->right_        =                      NULL;
                son->parent_       =                old_parent;
                son->value_        =                     value;
                son-> left_height_ =                         0;
                son->right_height_ =                         0;
                son->total_height_ =      *root->total_height_;
                son->height_       = old_parent->height_   - 1;
                son->position_     = old_parent->position_ * 2;
                son->is_right_     =                     false;

                
                old_parent->left_ = son;
                break;
            }

            old_parent = old_parent->left_;
        }
        else
        {
            if (!old_parent->right_)
            {
                son->left_         =                          NULL;
                son->right_        =                          NULL;
                son->parent_       =                    old_parent;
                son->value_        =                         value;
                son-> left_height_ =                             0;
                son->right_height_ =                             0;
                son->total_height_ =           root->total_height_;
                son->height_       = old_parent->height_       - 1;
                son->position_     = old_parent->position_ * 2 + 1;
                son->is_right_     =                          true;

                old_parent->right_ = son;
                break;
            }

            old_parent = old_parent->right_;
        }
        
    }

    
    
    node* problem_leave = raise_part_heights(son);   /// all this might be simplified

    if (problem_leave)
    {
        node* parent = problem_leave->parent_;                                                     
        bool is_right = problem_leave->is_right_;
        printf("problem in %d, son_value = %d \n", problem_leave->value_, son->value_);
        node* new_leave = balance(problem_leave);

        printf("just balanced \n");
        if (!parent) //not needed seems
        {
            root = new_leave;
        }
        else if (is_right)
        {
            parent->right_ = new_leave;
        }
        else
        {
            parent->left_  = new_leave;
        }
    
        return son;
    } 
    
    if (son->height_ < 0)
        raise_heights(root, 2);

    return son;

}


void print_tree(node* root)
{
    if (!root) return;

    if (root->left_) 
    {
        print_tree(root->left_);
    }
    
    if (root->right_)
    {
        print_tree(root->right_);
    }

    printf("%d \n", root->value_);

}


node* is_in_tree(node* root, int value) ///NULL if no, pointer if yes/////// node + node->left
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->value_ == value)
        return root;

    node* to_find = NULL;


    if (value < root->value_)
        return is_in_tree(root->left_, value);

    return is_in_tree(root->right_, value);

}


//  better redo without recursion
int raise_heights(node* root, int param_one)  /// height++ in the whole tree,  if param = 1, total height not touched, if 2, touched
{
    if (!root) return 0;

    if (root->left_) 
    {
        raise_heights(root->left_, param_one);
    }
    
    if (root->right_)
    {
        raise_heights(root->right_, param_one);
    }
    
    root->height_++;

    if (param_one == 2)
        root->total_height_++;

    return root->height_;
}

int decrease_heights(node* root)  /// height-- in the whole tree under the mentioned root
{
    if (!root) 
        return 0;

    if (root->left_) 
    {
        printf("1 cycle \n");
        decrease_heights(root->left_);
    }
    
    if (root->right_)
    {
        printf("1 cycle \n");
        decrease_heights(root->right_);
    }
    
    root->height_--;

    return root->height_;
}

node* raise_part_heights(node* new_leave) // returns NULL if no balancing needed
{
    node* cur_leave = new_leave;

    while(cur_leave->parent_)
    {
        if (cur_leave->is_right_)
        {
            cur_leave->parent_->right_height_++;
            if (cur_leave->parent_->right_height_ <= cur_leave->parent_->left_height_)
                break;
        }
        else
        {
            cur_leave->parent_->left_height_++;
            if (cur_leave->parent_->right_height_ >= cur_leave->parent_->left_height_)
                break;
        }
       
        if (abs(cur_leave->parent_->right_height_ - cur_leave->parent_->left_height_) >= 2)
            return cur_leave->parent_;

        cur_leave = cur_leave->parent_;
    }

    return NULL;
}


node* balance(node* root)  // returns new root of the given subtree
{
    if (root->left_height_ < root->right_height_)
    {
        printf("inside 1 cycle \n");

        if (root->right_->left_height_ <= root->right_->right_height_)
        {
            printf("must fall after this \n");
            return left_small_turn(root);
        }
        return left_big_turn(root);
    }

    printf("1 cycle skipped \n");
    if (root->left_->right_height_ <= root->left_->left_height_)
        return right_small_turn(root);
    return right_big_turn(root);
}

node* left_small_turn(node* root)
{
    int root_pos = root->position_;
    node* new_root = root->right_;
    new_root->parent_ = NULL;


    if (root->right_->left_)
    {
        root->right_->left_->parent_ = root;
    }
    

    root->right_   = root->right_->left_;
    new_root->left_ = root;
    root->parent_ = new_root;
    printf("here 6, root_height = %d \n", root->height_);

    decrease_heights(root->left_);
    root->height_--;

    printf("here 6, root_height = %d \n", root->height_);
    raise_heights(new_root->right_, 1);
    new_root->height_++;

    new_root->right_->is_right_ = true;
    new_root->left_height_++;

    root->right_height_ = root->left_height_;

    if(new_root->left_->is_right_)
        printf("beda left \n");

    if(!new_root->right_->is_right_)
        printf("beda right \n");
#if 0 
    root->is_right = false; 
# endif  // already false

    
    new_root->position_ = root_pos;
    printf("root-pos = %d  \n", root_pos);
    if (!recalc_positions(new_root))
        return NULL;

    printf("for 6: h = %d  l_h = %d, r_h = %d, pos = %d \n", root->height_, root->left_height_, root->right_height_, root->position_);
    printf("for 7: h = %d  l_h = %d, r_h = %d, pos = %d \n", new_root->height_, new_root->left_height_, new_root->right_height_, new_root->position_);
    printf("for 8: h = %d  l_h = %d, r_h = %d, pos = %d \n", new_root->right_->height_, new_root->right_->left_height_, new_root->right_->right_height_, new_root->right_->position_);
    return new_root;
}

node* left_big_turn(node* root)
{
    int root_pos = root->position_;

    printf("here 1 \n");
    node* new_root = root->right_->left_;
    printf("here 1 \n");
    new_root-> left_->parent_ = root;
    printf("here 2 \n");
    new_root->right_->parent_ = new_root->parent_;
    printf("here 3 \n");

    root->right_ = new_root->left_;
    printf("here 4 \n");
    root->right_->is_right_ = true;
    printf("here 5 \n");
    new_root->parent_->left_ = new_root->right_;
    printf("here 6 \n");
    new_root->parent_->left_->is_right_ = false;
    printf("here 7 \n");
    
    new_root->left_ = root;
    new_root->left_->parent_ = new_root;
    
    new_root->right_ = new_root->parent_;
    new_root->right_->parent_ = new_root;

    new_root->parent_ = NULL;

    raise_heights(root->right_, 1);
    raise_heights(root->right_, 1);

    decrease_heights(root);
    raise_heights(new_root->right_->left_, 1);

    new_root->height_   += 2;

    root->right_height_ -= 2;
    new_root->right_->left_height_--;
    new_root-> left_height_ = root->left_height_ + 1;  // right height must not be higher than left
    new_root->right_height_ = new_root->right_->right_height_ + 1;

    new_root->position_ = root_pos;

    if (!recalc_positions(new_root))
        return NULL;

    return new_root;
}

node* right_small_turn(node* root)
{
    node* new_root = root->left_;
    new_root->parent_ = NULL;

    root->left_->right_->parent_ = root;
    root->left_   = root->left_->right_;
    new_root->right_ = root;
    root->parent_ = new_root;

    decrease_heights(root->right_);
    raise_heights(new_root->left_, 1);
    new_root->right_->is_right_ = false;
    new_root->right_height_++;

    root->is_right_ = true; 


    
    if (!recalc_positions(new_root))
        return NULL;

    return new_root;
}

node* right_big_turn(node* root)
{
    node* new_root = root->left_->right_;

    new_root->right_->parent_ = root;
    new_root-> left_->parent_ = new_root->parent_;

    root->left_ = new_root->right_;
    root->left_->is_right_ = false;
    new_root->parent_->right_ = new_root->left_;
    new_root->parent_->right_->is_right_ = true;
    
    new_root->right_ = root;
    new_root->right_->parent_ = new_root;
    
    new_root->left_ = new_root->parent_;
    new_root->left_->parent_ = new_root;

    new_root->parent_ = NULL;

    raise_heights(root->left_, 1);
    raise_heights(root->left_, 1);

    decrease_heights(root);
    raise_heights(new_root->left_->right_, 1);

    new_root->height_   += 2;

    root->left_height_ -= 2;
    new_root->left_->right_height_--;
    new_root-> right_height_ = root->right_height_ + 1;  // left height must not be higher than right
    new_root->left_height_ = new_root->left_->left_height_ + 1;

    if (!recalc_positions(new_root))
        return NULL;

    return new_root;
}
int recalc_positions(node* root) // must not be problems wight parent, cause balancing leaves at least 2 levels
{
    if (!root)
        return 0;


    if (root->left_)
    {
        printf("work wigh left \n");
        root->left_->position_ = root->position_ * 2;
        if (!recalc_positions(root->left_))
            return 0;
    }

    if (root->right_)
    {
        printf("work wigh rigth \n");
        root->right_->position_ = root->position_ * 2 + 1;
        if (!recalc_positions(root->right_))
            return 0;
    }

    return 1;

}

///************************************
/// about queue
queue* add_elem(queue* end, node* leave)
{
    if (!end)        
        return NULL;

    if (!leave)
        return  end;


    queue* cur_obj = (queue*) malloc(sizeof(queue));
    if (!cur_obj)
    {
        printf("problems with memory allocation in add_elem funtion \n");
        return NULL;
    }


    cur_obj->next_  =  NULL;
    cur_obj->leave_ = leave;

    end->next_ = cur_obj;

    return cur_obj;
}


queue* dequeue(queue* front)
{
    if (!front)
        return front;       

    return front->next_;
}


void q_print(queue* front)   // prints queue
{
    if (!front->next_)
        return;

    queue* cur_elem = front->next_;
    
    while (cur_elem)
    {
        printf("%d ", cur_elem->leave_->value_);
        cur_elem = cur_elem->next_;
    }
    printf("\n");
}
///***************************************


void smart_print(node* root)
{
    if (!root)
        return;

    queue* front = (queue*) calloc(1, sizeof(queue));
    queue*   end = (queue*) malloc(   sizeof(queue));
    if (!front || !end)
    {
        printf("problems with memory allocation in smart_print funtion \n");
        return;
    }
    end = front;

    
    queue* cur_leave = add_elem(front, root);

    cur_leave = add_elem(cur_leave, root-> left_);
    cur_leave = add_elem(cur_leave, root->right_);

    int total_h = root->total_height_;
    int width = to_degree(2, total_h + 1) - 1; 
    
    int d = width / 2;
    int print_pos = d;

    print_space(d);
    printf("%d (%d %d)", root->value_, root->left_height_, root->right_height_);
    print_space(d);
    printf("\n");

    front = dequeue(front);

    if (!front->next_)
        return;

    int  cur_pos =           0;
    int line_pos =           0;
    int  cur_h   = total_h - 1;

    while (front->next_)
    {
        if (front->next_->leave_->height_ != cur_h)
        {
            print_space(width - cur_pos - 1);
            printf("\n");
            cur_pos = 0;
            cur_h--;


            if (cur_h < 0)  /// must not happen
                return;
        }

        cur_leave = add_elem(cur_leave, front->next_->leave_-> left_);
        cur_leave = add_elem(cur_leave, front->next_->leave_->right_);  ///  if NULL  returns cur_leave
        
        d = width / to_degree(2, total_h - cur_h + 1);
        print_pos = d + front->next_->leave_->position_ * 2 * (d + 1);

        print_space(print_pos - cur_pos);
        printf("%d", front->next_->leave_->value_);
        cur_pos = print_pos + 1;
        front = dequeue(front);

    }   
    print_space(width - cur_pos - 1);
    printf("\n");
}



int to_degree(int value, int degree)
{
    int res = 1;

    for (int i = 0; i < degree; i++)
    {
        res *= value;
    }

    return res;

}

void print_space(int space_num)
{
    for (int i = 0; i < space_num; i++)
    {
        printf("-");
    }
}


