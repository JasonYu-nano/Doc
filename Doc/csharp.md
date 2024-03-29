**Lamada表达式**

**委托和事件**

* [委托](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/builtin-types/reference-types)是安全封装方法的类型

  ```c#
  public delegate void Del(string message);
  
  public delegate void Action<T...>();
  public delegate TResult Func<T..., out TResult>();
  ```

* 事件是对多播委托的封装

* 事件只能+=来连接，事件确保只有包容类才能触发事件通知

  ```c#
  public delegate void EventHandler(...);
  public event EventHandler PubEvent;
  ```

  

**闭包原理**

**弱引用和强引用**

* ```c#
  WeakReference ref1 = new WeakReference(new MyObject());
  ```

**GC 优化**

**非托管资源回收**

- 托管资源：int、string、float等大多数应用程序创建的对象，系统管理回收
- 非托管资源：Stream、数据库的连接等，需要手动去释放。最常见的一类非托管资源就是包装操作系统资源的对象，如文件、网络连接等
- 释放非托管资源的2种方法：
  - 析构函数
  - 实现System.IDisposable接口
- 在删除C++对象时，其析构函数会立即执行。但C#对象的析构函数，是要等垃圾收集器来释放该对象才调用的，所以也就无法确定其何时执行
- IDisposable接口定义了一个模式，为释放未托管的资源提供了确定的机制，并避免产生析构函数固有的与垃圾收集器相关的问题，其提供了一个方法Dispose()
- Finalize：用于释放非托管资源，被GC调用
- Dispose：需要同时释放托管和非托管的资源，该函数是被其它代码显示调用并要求释放资源的
- Finalize和Dispose重复调用没有问题

**反射**

**值类型和引用类型**

