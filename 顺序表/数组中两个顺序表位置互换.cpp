  typedef inf DataType;
  void Reverse(DataType A[],int left,int right,int arraySize) {
    	//逆转(aleft,aleft+1,aleft+2...,aright)为(aright,aright-1,...,aleft)
		if(left>right||right>arraySize)
			return;
		int mid=(right+left)/2;
		for(int i=0;i<=mid-left;i++){
			DataType temp=A[left+i];
			A[left+i]=A[right-i];
			A[right-i]=temp;
		}
  }
  void Exchange(DataType A[],int m,int n,int arraySize){
	/*数组 A[m+n]中,从0到m-1存放顺序表(a1,a2,a3,...,am),从m到m+n-1存放顺序表
	(b1,b2,b3,...,bn),算法将这两个表的位置互换 */
    	Reverse(A,0,m+n-1,arraySize);
    	Reverse(A,0,m-1,arraySize);
    	Reverse(A,m,m+n-1,arraySize);
  }
