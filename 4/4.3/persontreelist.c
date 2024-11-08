#include "persontreelist.h"

void initTree(person_tree *newtree)
{
  newtree->root = NULL;
}

person_node_tree *insertNode(person_node_tree *newnode, person pers)
{
  if(newnode == NULL)
  {
    newnode = (person_node_tree *)malloc(sizeof(person_node_tree));
    newnode->left   = NULL;
    newnode->right  = NULL;

    newnode->pn = pers;
  }
  else
  {
    if(pers.keyfortree < newnode->pn.keyfortree)
    {
      person_node_tree *added = NULL;
      added = insertNode(newnode->left, pers);
      newnode->left = added;
      newnode = balanceTree(newnode);
    }

    if(pers.keyfortree > newnode->pn.keyfortree)
    {
      person_node_tree *added = NULL;
      added = insertNode(newnode->right, pers);
      newnode->right = added;
      newnode = balanceTree(newnode);
    }
  }
  return newnode;
}

person_node_tree* balanceTree(person_node_tree *temp)
{
  int bal_factor = diff(temp);
  if (bal_factor > 1)
  {
    if (diff(temp->left) > 0)
      temp = ll_rotation(temp);
    else
      temp = lr_rotation(temp);
  }
  else if (bal_factor < -1)
  {
    if (diff(temp->right) > 0)
      temp = rl_rotation(temp);
    else
      temp = rr_rotation(temp);
  }
  return temp;
}

person *searchNode(person_node_tree *searchnode, int *key)
{
  if( searchnode != NULL )
  {
    if(*key == searchnode->pn.keyfortree)
      return &(searchnode->pn);

    if(*key < searchnode->pn.keyfortree)
      return searchNode(searchnode->left, key);

    if(*key > searchnode->pn.keyfortree)
      return searchNode(searchnode->right, key);
  }
  return NULL;
}

void destroyTree(person_node_tree *node)
{
  if( node != NULL )
  {
      destroyTree(node->left);
      destroyTree(node->right);
      free( node );
  }
}

char height(person_node_tree *node)
{
  int h = 0;

  if (node != NULL)
  {
      int l_height = height(node->left);
      int r_height = height(node->right);
      int max_height = l_height > r_height ? l_height : r_height;
      h = max_height + 1;
  }
  return h;
}

char diff(person_node_tree *node)
{
  int l_height = height(node->left);
  int r_height = height(node->right);
  int b_factor = l_height - r_height;
  return b_factor;
}

person_node_tree* ll_rotation(person_node_tree *node)
{
  person_node_tree *temp;
  temp = node->left;
  node->left = temp->right;
  temp->right = node;
  return temp;
}

person_node_tree* rr_rotation(person_node_tree *node)
{
  person_node_tree *temp;
  temp = node->right;
  node->right = temp->left;
  temp->left = node;
  return temp;
}

person_node_tree* lr_rotation(person_node_tree *node)
{
  person_node_tree *temp;
  temp = node->left;
  node->left = rr_rotation(temp);
  return ll_rotation(node);
}

person_node_tree* rl_rotation(person_node_tree *node)
{
  person_node_tree *temp;
  temp = node->right;
  node->right = ll_rotation(temp);
  return rr_rotation(node);
}

person_node_tree* deleteNode(person_node_tree* node, int key){
    if(node == NULL)
        return node;
 
    if(key == node->pn.keyfortree){
 
        person_node_tree* tmp;
        if(node->right == NULL)
            tmp = node->left;
        else {
 
            person_node_tree* ptr = node->right;
            if(ptr->left == NULL){
                ptr->left = node->left;
                tmp = ptr;
            } else {
 
                person_node_tree* pmin = ptr->left;
                while(pmin->left != NULL){
                    ptr  = pmin;
                    pmin = ptr->left;
                }
                ptr->left   = pmin->right;
                pmin->left  = node->left;
                pmin->right = node->right;
                tmp = pmin;
            }
        }
 
        free(node);
        return tmp;
    } else if(key < node->pn.keyfortree)
        node->left  = deleteNode(node->left, key);
    else
        node->right = deleteNode(node->right, key);
    return node;
}