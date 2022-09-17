//递归
void InOrder(BiTree T){
  if(T!=NULL){
    InOrder(T->lchild);     //递归遍历左子树
    visit(T);               //访问根结点
    InOrder(T->rchild);     //递归遍历右子树
  }
}

//非递归
void InOrder2(BiTree T){
  InitStack(S); BiTree p=t;             //初始化栈S; p是遍历指针
    while(p||!IsEmpty(S)){              //栈不空或p不空时循环
      if(p){                            //一路向左
        Push(S,p);                      //当前结点入栈
        p=p->lchild;                    //左孩子不空，一直向左走
      }
      else{                             //出栈，并转向出栈结点的右子树
        Pop(S,p);visit(p);              //栈顶元素出栈，访问出栈结点
        p=p->rchild;                    //向右子树走，p赋值为当前结点的右孩子
      }                                 //返回while循环继续进入if-else语句
}
