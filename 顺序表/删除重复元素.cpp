//有序顺序表删除所有重复元素
void OnlyElem(lqList &L) {
        int k=0;
        for(int i=0;i<L.length-1;i++){
            if(L.data[i]==L.data[i+1])
                k++;
            else
                L.data[i-k]=L.data[i];
        }
        L.length-=k;
    }
