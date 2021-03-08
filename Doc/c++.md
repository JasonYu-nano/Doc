**内存**

* 代码段:包括只读存储区和文本区，其中只读存储区存储字符串常量，文本区存储程序的机器代码。
* 数据段：存储程序中已初始化的全局变量和静态变量
* bss 段：存储未初始化的全局变量和静态变量（局部+全局），以及所有被初始化为0的全局变量和静态变量。
* 堆区：调用new/malloc函数时在堆区动态分配内存，同时需要调用delete/free来手动释放申请的内存。
* 映射区:存储动态链接库以及调用mmap函数进行的文件映射
* 栈：使用栈空间存储函数的返回地址、参数、局部变量、返回值

**转型**

* static_cast、dynamic_cast、const_cast、reinterpret_cast
* static_cast是静态转换，编译期确定，子类到基类安全，反过来不保证安全
* dynamic_cast是运行期确定，基类到子类是安全的，无法转换返回nullptr

**static**

* 加了static关键字的全局变量只能在本文件中使用。例如在a.c中定义了static int a=10;那么在b.c中用extern int a是拿不到a的值得，a的作用域只在a.c中。
* static定义的静态局部变量分配在数据段上，普通的局部变量分配在栈上，会因为函数栈帧的释放而被释放掉。
* 对一个类中成员变量和成员函数来说，加了static关键字，则此变量/函数就没有了this指针了，必须通过类名才能访问

**const**

* 修饰普通类型变量
* 修饰指针
* const参数和返回值
* 修饰成员函数

**strcpy和strlen**

```c++
//strcpy是字符串拷贝函数，原型：
char *strcpy(char* dest, const char *src);
//从src逐字节拷贝到dest，直到遇到'\0'结束，因为没有指定长度，可能会导致拷贝越界，造成缓冲区溢出漏洞,安全版本是strncpy函数。
//strlen函数是计算字符串长度的函数，返回从开始到'\0'之间的字符个数。
```

**++i和i++的实现**

```c++
//++i
int& int::operator++（）
{
	*this +=1；
	return *this；
}

//i++
const int  int::operator（int）
{
	int oldValue = *this；
	++（*this）；
	return oldValue；
}
```

**main函数前执行的代码**

* 在`main()`函数中的显示代码执行之前，会由编译器生成_main函数，其中会进行所有全局对象的构造以及初始化工作。简单来说对静态变量、全局变量和全局对象来说的分配是早在`main()`函数之前就完成的，所以`C/C++`中并非所有的动作都是由于`main()`函数引起的。

```c++
int a = ()[]{
    //do something
    return 0;
}
// call func before main
int main(int argc, char** args)
{
    return 0;
}
```

**智能指针**

* shared_ptr、unique_ptr、weak_ptr、auto_ptr（弃用）

```c++
//shared_ptr 实现

template<typename T>
class SharedPtr
{
public:
    SharedPtr(T* ptr)
    {
        m_Ptr = ptr;
        try
        {
            m_Count = new int(1);
        }
        catch(...)
        {
            delete m_Ptr; m_Ptr = nullptr;
            delete m_Count = m; m_Count = nullptr;
        }
    }
    
    SharedPtr(const SharedPtr& ptr)
    {
        m_Count = ptr.m_Count;
        m_Ptr = ptr.m_Ptr;
        *(m_Count)++;
    }
    
    SharedPtr& operator=(const SharedPtr &rhs)
    {
        ++*(rhs.m_Count); 
        if((--*(m_Count))==0) 
        { 
            delete m_Ptr; m_Ptr= nullptr; 
            delete m_Count; m_Count= nullptr; 
        } 		
        ptr=rhs.ptr; 
        m_Ptr = rhs.m_Ptr; 
        return *this;
    }
    
private:
    T* m_Ptr{nullptr};
    uint32_t* m_Count{nullptr};
};
```

**常量**

* 常量在C++里的定义就是一个top-level const加上对象类型，常量定义必须初始化。对于局部对象，常量存放在栈区，对于全局对象，常量存放在全局/静态存储区。对于字面值常量，常量存放在常量存储区。

**extern "C"**

* 指示编译器这部分代码按C语言的进行编译。由于C++支持函数重载，因此编译器编译函数的过程中会将函数的参数类型也加到编译后的代码中，而不仅仅是函数名；而C语言并不支持函数重载，因此编译C语言代码的函数时不会带上函数的参数类型，一般之包括函数名。

**RTTI**

**虚函数表实现**

* 编译的过程中编译器就为含有虚函数的类创建了虚函数表，并且编译器会在构造函数中插入一段代码，这段代码用来给虚函数指针赋值。因此**虚函数表是在编译的过程中创建**。

**迭代器失效**

* 序列式容器(如vector,deque)，删除当前的iterator会使后面所有元素的iterator都失效。vector push_back碰上大小再分配也会失效。
* list型的数据结构，使用了不连续分配的内存，删除运算使指向删除位置的迭代器失效，但是不会失效其他迭代器.解决办法两种，erase(*iter)会返回下一个有效迭代器的值，或者erase(iter++)。
* 关联容器(如map, set,multimap,multiset)，删除当前的iterator，仅仅会使当前的iterator失效，只要在erase时，递增当前iterator即可。这是因为map之类的容器，使用了红黑树来实现，插入、删除一个结点不会对其他结点造成影响。erase迭代器只是被删元素的迭代器失效，但是返回值为void，所以要采用erase(iter++)的方式删除迭代器。

**左值右值**

**编译流程**

* 预处理阶段：对源代码文件中文件包含关系（头文件）、预编译语句（宏定义）进行分析和替换，生成预编译文件。

* 编译阶段：将经过预处理后的预编译文件转换成特定汇编代码，生成汇编文件

* 汇编阶段：将编译阶段生成的汇编文件转化成机器码，生成可重定位目标文件

* 链接阶段：将多个目标文件及所需要的库连接成最终的可执行目标文件

**红黑树、AVL树、B树**

* AVL树：任一节点对应的两棵子树的最大高度差为1。查找、插入和删除在平均和最坏情况下的时间复杂度都是O(logN)
  * **左子树**根节点的**左子树**上破坏平衡 -> 右旋转 
  * **右子树**根节点的**右子树**上破坏平衡 -> 左旋转 
  * **左子树**根节点的**右子树**上破坏平衡 -> 先左旋后右旋 
  * **右子树**根节点的**左子树**上破坏平衡 -> 先右旋后左旋

```c++
TreeNode* LRotate(TreeNode* node){ //node为离操作结点最近的失衡的结点
    TreeNode* parent = node->parent; //获取失衡结点的父节点
    TreeNode* son = node->lchild;
   
    if (son->rchild != nullptr)  son->rchild->parent=node; //失衡结点的左孩子变更为son的右孩子
    node->lchild = son->rchild; //更新失衡结点的高度信息
    update_depth(node); //失衡结点变成son的右孩子
    son->rchild = node; //设置son的父结点为原失衡结点的父结点
    son->parent = parent;
    if (parent != NULL){
        if (parent->lchild == node) //如果父节点的左孩子是失衡结点，指向现在更新后的新孩子son
            parent->lchild = son;
        else //父节点的右孩子是失衡结点
            parent->rchild=son;
     }
    node->parent=son; //设置失衡结点的父亲
    update_depth(son); //更新son结点的高度信息
    return son;
}
```

* 红黑树
  * 搜索O(logN)，最坏2O(logN)，不如AVL
  * 增删节点的性能优于AVL树
* B树
  * 减少树高，减少IO消耗
  * B+ 树则将数据都保存在叶子节点，同时通过链表的形式将他们连接在一起。B+树相比B树减少了随机IO，顺序IO效率更高

**unorder_map冲突处理**

* 开链法（c++采用）：小于一定数量使用链表存储，大于使用红黑树存储
* 线性探测法：当遇到冲突后，将这个数据插到下一个位置，要是下个位置也已存储数据，就继续到下一个，直到找到正确的可以插入的数据。
* 二次探索法：当遇到冲突后 ，下次所找到的位置为当前的位置加上n的二次方

**类型萃取**

**lambda原理**

**堆**

```c++
//父结点: i / 2（i ≠ 1）
//左子结点: 2i（2i ≤ n）
//右子结点: 2i + 1(2i + 1 ≤ n)
```

**编译器优化**

* O0、Og、O1、O2、Os、O3、Ofast

**内存对齐**

**空类大小为1**

**stl 组件**

- 容器(containers):vector.list.deque,set,map等数据存放的类。
- 算法(algorithms):各种排序算法;sort、search、copy、erase..等
- 迭代器(iterators)：扮演容器与算法之间的胶合剂，即泛型指针
- 功能函数(functors)：行为类似函数，可以视为算法的某种策略
- 配接器(adapters)：一种用来修饰容器(containers)或仿函数(functors)或迭代器(iterators)借口的东西
- 配置器(allocators):负责空间配置与管理

**thread**

**sizeof**

sizeof 是编译器求值

**vector**

clear()只清除元素，容量没变，resize()可以改变容量

**进程间通信**

- 管道、消息队列、信号量、共享存储、Socket等
- 管道
  - 半双工（即数据只能在一个方向上流动），具有固定的读端和写端
  - 只能用于类似父子进程或兄弟进程之间
  - 它可以看成是一种特殊的文件，对于它的读写也可以使用普通的read、write等。但它不是普通的文件，并不属于其他任何文件系统，并且只存在于内存中
- FIFO
  - 可以在无关的进程之间交换数据
- 消息队列
  - 面向记录的
  - 独立于发送与接受进程
  - 可以实现消息的随机查询
- 信号量
  - 信号量用于进程间同步，若要在进程间传递数据需要结合共享内存
- 共享内存
  - 共享内存是最快的一种IPC，因为进程是直接对内存进行存取的
  - 因为多个进程可以同时操作，所以需要进行同步
  - 信号量+共享内存通常结合在一起使用，信号量用来同步对共享内存的访问