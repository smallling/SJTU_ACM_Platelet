# 杜教筛

求：$\sum_{i=1}^N \phi(i)$

设$\Phi(N)=\sum_{i=1}^N \phi(i)$,再设一个辅助函数$P(N)=\sum_{i=1}^N\sum_{d|i}\phi(d)$

$\because \sum_{d|i}\phi(d)=i$

$\therefore P(N)=\sum_{i=1}^N i={(N + 1) \times N \over 2}$

同时，

$\because \sum_{d|i}\phi(d)=\sum_{d|i}\phi({i\over d})$

又有$P(N)=\sum_{i=1}^N\sum_{d|i}\phi({i\over d})$

交换求和次序，将枚举因数变为枚举倍数，$P(N)=\sum_{d=1}^N\sum_{i=1}^{\lfloor {N \over d}\rfloor} \phi(i)$

即：$P(N)=\sum_{d=1}^N \Phi(\lfloor {N \over d}\rfloor)$

我们将$d=1​$那一项移到另一边：

$\Phi(N)=P(N)-\sum_{d=2}^N \Phi(\lfloor {N \over d}\rfloor)={(N + 1) \times N \over 2} -\sum_{d=2}^N \Phi(\lfloor {N \over d}\rfloor) $

然后我们发现右边的根号分段的，所以递归下去算乘上个数就好了。