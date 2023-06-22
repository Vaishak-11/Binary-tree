#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int value){
    struct node *new = malloc(sizeof(struct node));
    new->data = value;
    if(root == NULL){
        root = new;
        root->left = NULL;
        root->right = NULL;

        return root;
    }
    else{
        if(value < root->data){
            root->left = insert(root->left , value);
        }
        else{
            root->right = insert(root->right , value);
        }

    return root;
    } 
}

void printtree(struct node *root){
    if(root == NULL){
        return;
    }
    printtree(root->left);
    printf("%d ",root->data);
    printtree(root->right);
}

int main() {
    int i,count,a[100],i_num,option,print_opt,d_num;
    struct node *root = NULL;
    printf("enter the element count: ");
    scanf("%d",&count);
    printf("\nenter the elements: ");
    for(i=0;i<count;i++){
        scanf("%d",&a[i]);
        root = insert(root,a[i]);
    }
    printf("1.Insert   2.DFS   3.Height   4.Diameter   5.BFS   6.Delete   7.Print\n");
    while(1){
        printf("\nEnter the choice:");
        scanf("%d",&option);
        switch(option){
            case 1: printf("enter the element to be inserted: ");
                    scanf("%d",&i_num);
                    insert(root,i_num);
                    printtree(root);
                    break;
            case 2: printf("1.Pre-order   2.In-order   3.Post_order     \n");
                    printf("enter the print order: ");
                    scanf("%d",&print_opt);
                    switch(print_opt){
                        case 1: dfs_preorder(root);
                                break;
                        case 2: dfs_inorder(root);
                                break;
                        case 3: dfs_postorder(root);
                                break;
                    }
                    break;
            case 3: int h = calculateHeight(root);
                    printf("The height of the tree is %d", h);
                    break;
            case 4: int d = diameter(root);
                    printf("The diamter of the tree is %d", d);
                    break;
            case 5: BFS(root);
                    break;
            case 6: printf("enter the element to be deleted: ");
                    scanf("%d",&d_num);
                    deleting(root,d_num);
                    break;
            case 7: printtree(root);
                    break;        
        }
    }
        
    return 0;
}

