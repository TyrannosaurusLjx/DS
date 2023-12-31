# 表，栈和队列

## ADT(Abstract Data Type): 

#### 表〈list〉:形如$A_0,A_1,\cdots ,A_n$的有限序列，其中$A_i$是表中的元素，$n$为表的长度，$n=0$时，表为空表.

##### 表的数组实现
使用std::vector实现表的数组实现，其中$A_i$对应于$A[i]$，$n$对应于$A.size()$.


##### 表的链表实现    
单链表:为了避免插入和删除的线性开销,使用结构link来表示表中元素的逻辑顺序,而不是物理顺序.$link = \{element| next\}$,其中$element$是表中的元素,$next$是指向下一个元素的指针.

双链表:在单链表的基础上,增加一个指向前驱元素的指针$pre$.

    可以验证,他们的插入和删除操作的时间复杂度都是$O(1)$.

表的两种常用实现是vector和list,其中vector用的是数组实现,而list用的是链表实现.vector容易索引,但是插入和删除开销高昂,list则相反.

#### 栈〈stack〉:是一种特殊的表,只能在表的一端进行插入和删除操作,这一端称为栈顶(top),另一端称为栈底(bottom).栈的插入和删除操作称为进栈和出栈,又称为压栈和弹栈.栈的特点是后进先出(LIFO,Last In First Out).

#### 队列〈queue〉:是一种特殊的表,只能在表的一端进行插入,在另一端进行删除.队列的插入操作称为入队,删除操作称为出队.队列的特点是先进先出(FIFO,First In First Out).

    由于stack和queue都是特殊的表,因此任何一种表的实现方式都可以用来实现stack和queue.