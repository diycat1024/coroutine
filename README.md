## 云风
It's an asymmetric coroutine library (like lua).

You can use coroutine_open to open a schedule first, and then create coroutine in that schedule. 

You should call coroutine_resume in the thread that you call coroutine_open, and you can't call it in a coroutine in the same schedule.

Coroutines in the same schedule share the stack , so you can create many coroutines without worry about memory.

But switching context will copy the stack the coroutine used.

Read source for detail.

Chinese blog : http://blog.codingnow.com/2012/07/c_coroutine.html

## 更新日志
1.coroutine_yield增加一个void*参数，coroutine_resume增加一个void*类型的返回值。
模仿lua的协程，可以通过coroutine_yield和coroutine_resume配合来写出消费者和生产者模式的代码。

2.test.c 是一个生产者消费者协程使用的代码。
使用方式：
```
$ make test
$ ./test
```