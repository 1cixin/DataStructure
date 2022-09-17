//递归
void PostOrder(BiTree T){
  if(T!=NULL){
    PostOrder(T->lchild);     //递归遍历左子树
    PostOrder(T->rchild);     //递归遍历右子树
    visit(T);                 //访问根结点
}
