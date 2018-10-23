线段树上维护两个值：Cover和Len

Cover意为这个区间被覆盖了多少次（不是有没有被覆盖）

Len意为区间被覆盖的总长度

Maintain的时候，如果Cover>0，Len直接为区间长

否则从左右子树递推Len

修改的时候直接改Cover就好
