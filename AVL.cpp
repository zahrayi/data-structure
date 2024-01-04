int Balance(struct node *p)
{
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}

struct node* add(struct node* p, int key)
{
    if (p == NULL)
        return(create(key));
 
    if (key < p->data)
        p->left  = add(p->left, key);
    else if (key > p->data)
        p->right = add(p->right, key);
    else // Equal datas are not allowed in BST
        return p;
 
    p->height = 1 + max(height(p->left), height(p->right));
 
    int b = Balance(p);
 
    // Left Left 
    if (b >=2 && key < p->left->data)
        return rightRotate(p);
 
    // Right Right 
    if (b <=-2 && key > p->right->data)
        return leftRotate(p);
 
    // Left Right 
    if (b >=2 && key > p->left->data)
    {
        p->left =  leftRotate(p->left);
        return rightRotate(p);
    }
 
    // Right Left 
    if (b <=-2 && key < p->right->data)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }
 
    return p;
}


 
struct node* remove(struct node* r, int key)
{
    struct node* t;
	if (r == NULL)
        return r;
    if ( key < r->data )
        r->left = remove(r->left, key);
     else if( key > r->data )
        r->right = remove(r->right, key);
     else
    {
        if( (r->left == NULL) || (r->right == NULL) )
        {
            t = r->left ? r->left : r->right;
            if (t == NULL)
            {
                t = r;
                r = NULL;
            }
            else 
             *r = *t; 
            free(t);
        }
        else
        {
             t = min(r->right);
             r->data = t->data;
             r->right = remove(r->right, t->data);
        }
    }
     if (r == NULL)
      return r;
 
     r->height = 1 + max(height(r->left), height(r->right));
 
    int b = Balance(r);
 
    if (b > 1 && Balance(r->left) >= 0)
        return rightRotate(r);
 
    if (b > 1 && Balance(r->left) < 0)
    {
        r->left =  leftRotate(r->left);
        return rightRotate(r);
    }
 
    if (b < -1 && Balance(r->right) <= 0)
        return leftRotate(r);
 
    if (b < -1 && Balance(r->right) > 0)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
 
    return r;
}
 