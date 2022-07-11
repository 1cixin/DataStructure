	/*可将该问题设为数组ab转换成数组ba（a代表数组的前p个元素，b代表数组中余下的n-p个元素），
	先将a逆置，再将b逆置，最后将整体逆置。
	 */
	void Reverse(int R[],int from,int to){
		int temp,int;
		for(i=from;i<=(from+to)/2;i++){
			temp=R[i];
			R[i]=R[to-i];
			R[to-i]=temp;
		}
	}
	void Converse(int R[],int n,int p){
		Reverse(R,0,p-1);
		Reverse(R,p,n);
		Reverse(R,0,n);
	}
	/*
	三个Reverse的时间复杂度是O(p/2),O((n-p)/2),O(n/2),
	总体时间复杂度为O(n)，空间复杂度为O(1)。
	 */


  /*
  另解，借助辅助数组来实现。
  算法思想:创建大小为p的辅助数组S，将R中前p个整数依次暂存在S中，同时将R中后n-p个整数左移，
  然后将S中暂存的p个数依次放回到R中的后续单元。时间复杂度为O(n)，空间复杂度为O(p)
  */
