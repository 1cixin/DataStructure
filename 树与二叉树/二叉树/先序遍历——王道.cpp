//递归
void PreOrder(BiTree T){
  if(T!=NULL){
    visit(T);             //访问根结点
    PreOrder(T->lchild);  //递归遍历左子树
    PreOrder(T->rchild);  //递归遍历右子树
  }
}


//非递归
void PreOrder2(BiTree T){
  InitStack(S); BiTree p=T;       //初始化栈S； p是遍历指针
    while(p||!IsEmpty(S)){        //栈不空或p不空时循环
       if(p){                     //一路向左
         visit(p);Push(S,p);      //访问当前节点，并入栈
         p=p->lchild;             //左孩子不空，一直想左走
       }
      else{                       //出栈，并转向出栈节点的右子树
        Pop(S,p);                 //栈顶元素出栈
        p=p->rchild;              //向右子树走，p赋值为当前结点的右孩子
      }                           //返回while循环继续进入if-else语句
}
