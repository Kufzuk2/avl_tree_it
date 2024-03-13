    if (new_root->right_)
    {
        new_root->right_->parent_ = root;
        root->left_ = new_root->right_; 
        root->left_->is_right_ = false;
    }

    if (new_root->left_)
    {
        new_root->left_->parent_ = root;
        root->right_ =  new_root->left_; 
        root->right_->is_right_ =  true;
    }
