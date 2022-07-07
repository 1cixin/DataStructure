/*线性表(a1,a2,..,an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
完成最少时间在表中查找数值为x的元素，若找到，则将其与后续元素位置想交换，若找不到，
则将其插入表中并使表中元素仍递增有序。*/
void FindOrInsert(ElemType A[], ElemType x) {
    	int n=A.length;
    	int low=0,high=n-1,mid;
    	while(low<=high){
    		mid = (low+high)/2;
    		if(A[mid]=x)
    			break;
    		else if(A[mid]<x)	low=mid+1;
    		else high=mid-1;
		}
    	if(A[mid]=x&&min!=n-1){
    		ElemType t=A[mid];
    		A[mid]=A[mid+1];
    		A[mid+1]=ElemType;
		}
    	if(low>high){
    		for(int i=n-1;i>high;i--)	A[i+1]=A[i];
    		A[i+1]=x;
		}
	}
