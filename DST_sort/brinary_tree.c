#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* new_node(int x){
  struct node *p;
  p = (struct node*)malloc(sizeof(struct node));
  p->data=x;
  p->left=NULL;
  p->right=NULL;
  return p;
}
struct node* insert(struct node *root, int x){
  if(root==NULL)
  return new_node(x);
  else if(x>root->data)
  root->right=insert(root->right,x);
  else
  root->left = insert(root->left,x);
  return root;
}
struct node* search(struct node *root,int x){
  if(root==NULL|| root->data==x)
  return root;
  else if(x>root->data)
  return search(root->right,x);
  else
  return search(root->left,x);
}
struct node* find_min(struct node*root){
  if(root==NULL)
  return NULL;
  else if(root->left!=NULL){
  return find_min(root->left);
  }
  return root;
}

struct node* Delete(struct node *root, int x){
  if(root==NULL)
  return NULL;
  if(x>root->data)
  root->right = Delete(root->right, x);
  else if(x<root->data)
  root->left = Delete(root->left, x);
  else{
    if(root->left==NULL && root->right==NULL){
      free(root);
      return NULL;
    }
    else if(root->left == NULL || root->right == NULL){
      struct node *temp;
      if(root->left == NULL)
      temp = root->right;
      else
      temp = root->left;
      free(root);
      return temp;
    }
    else{
      struct node *temp = find_min(root->right);
      root->data=temp->data;
      root->right=Delete(root->right, temp->data);
    }
  }
  return root;
}

void inorder(struct node *root){
  if(root!= NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}

void preorder(struct node *root){
  if(root != NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root){
  if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}

int main(){
  struct node *root, *t;
  int ch, x, a;
  printf("\nEnter data to insert: ");
  scanf("%d",&x);
  root = new_node(x);
  printf("\n1.Insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\n6.Search\n");
  while(1){
    printf("Select your choice: ");
    scanf("%d",&ch);
    
    switch(ch){
      case 1: printf("\nEnter the data to insert: ");
      scanf("%d",&x);
      insert(root, x);
      break;
      
      case 2: printf("\nInorder traversal: ");
      inorder(root);
      break;
      
      case 3 : printf("\nPreorder traversal: ");
      preorder(root);
      printf("\n");
      break;
      
      case 4: printf("\nPostorder traversal: ");
      postorder(root);
      printf("\n");
      break;
      case 5: printf("\nEnter element to be deleted: ");
      scanf("%d",&a);
      root = Delete(root,a);
      break;
      case 6: printf("\nEnter search element: ");
              scanf("%d",&x);
              t = search(root,x);
              if(t==NULL)
              printf("Element not found");
              else
              printf("Element found");
              break;
              
      case 7: exit(0);
      default : printf("Invalid option");
      break;
    }
  }
}