# 程序员的自我修养—链接、装载与库 笔记

## 内存管理

### 直接使用物理内存

    假设我们的的计算机有128MB内存，程序A运行需要10MB，程序B需要100MB，程序C需要20MB.
如果我们需要同时运行A和B，直接的做法是将内存的前10MB分给程序A，10MB~110MB分配给B。
这样就可以实现A和B两个程序的同时运行，但这种简单的内存分配策略问题很多

- 缺点：

```
1、地址空间不隔离；
2、内存使用率低；
3、程序运行不够稳定
```

### 虚拟内存分段

以程序为单位，对内存进行映射，如将A的0-1G地址对应内存中某个1G的内存，可以做到隔离和地址确定，但内存使用率低。
如果内存不足，换出的是整个文件。根据程序局部性原理，一个程序运行时，某个时间段只用到了一小部分数据，大部分数据都没用到，需要更小的粒度分割和映射。

### 虚拟内存-分页

对程序的数据和代码段进行分割，常用的放到内存，不常用的扔在磁盘，需要的时候放入内存。

### 分页和分段的主要区别


- 相同点：

```
采用离散分配方式，通过地址映射机构实现地址变换
```

- 不同点：

```
页是信息的物理单位，分页是为了满足系统的需要；段是信息的逻辑单位，含有意义相对完整的信息，是为了满足用户的需要。
页的大小固定且由系统确定，由系统把逻辑地址分为页号和页内地址，由机器硬件实现；段的长度不固定，取决于用户程序，编译程序对源程序编译时根据信息的性质划分。
分段系统的一个突出优点是易于实现段的共享和保护，允许若干个进程共享一个或多个分段，，且对段的保护十分简单易行。分页系统中虽然也能实现程序和数据的共享，但远不如分段系统方便。
```

### 段页式

段页式管理机制结合了段式管理和页式管理的优点。简单来说段页式管理机制就是把主存先分成若干段，每个段又分成若干页，也就是说 段页式管理机制中段与段之间以及段的内部的都是离散的。

## 代码生成过程

在linux下，使用 gcc 编译hello.c源文件，会在当前目录下默认生成 a.out 可执行文件，在终端输出hello，world！。

![img/code_prom.png](img/code_prom.png)

### 预处理

```
gcc -E hello.c -o hello.i
```

得到预处理文件，其中，-E 表示只进行预编译。
源文件在预编译阶段会被编译器生成.i文件，主要处理源代码文件中以“#”开头的预编译指令。如：宏定义展开，将被包含的文件插入到该编译指令的位置等

### 编译

```
gcc -S hello.i -o hello.s 
```

得到汇编文件，其中，-S 表示生成汇编文件。
编译就是把预处理完的文件，进行语法分析、词法分析、语义分析及优化后生成相应的汇编代码文件，这个过程是整个程序构建的核心过程，也是最复杂的部分。

### 汇编

```
gcc -c hello.s -o hello.o
```

其中，-c 表示只编译不链接。
将汇编代码文件转变成机器可以执行的指令文件，即目标文件。也可以直接使用：gcc -c hello.c -o hello.o 经过预处理、编译、汇编直接输出目标文件。

### 链接

随着代码量的增多，所有代码若是都放在同一个文件里，那将是一场灾难。现代大型软件，动辄由成千上万的模块组成，每个模块相互依赖又相互独立。将这些模块组装起来的过程就是链接。
这些模块如何形成一个单一的程序呢？无非就是两种方式：1、模块间的函数调用；2、模块间的变量访问。函数访问必须知道函数地址，变量访问必须知道变量地址，所以终归到底就是一种方式，不同模块间符号的引用。


## Linux下的静态链接库和动态链接库

Linux下得库有动态与静态两种，动态通常用.so为后缀，静态用.a为后缀。下面对比一下两者：

- 静态链接库

```
当要使用时，连接器会找出程序所需的函数，然后将它们拷贝到执行文件，由于这种拷贝是完整的，所以一旦连接成功，静态程序库也就不再需要了。
```

- 动态链接库

```
某个程序在运行中要调用某个动态链接库函数的时候，操作系统首先会查看所有正在运行的程序，看在内存里是否已有此库函数的拷贝了。
如果有，则让其共享那一个拷贝；只有没有才链接载入。在程序运行的时候，被调用的动态链接库函数被安置在内存的某个地方，所有调用它的程序将指向这个代码段。
因此，这些代码必须使用相对地址，而不是绝对地址。在编译的时候，我们需要告诉编译器，这些对象文件是用来做动态链接库的，所以要用地址无关代码(Position Independent Code (PIC))。
```

动态链接库的加载方式有两种：隐式加载和显示加载。

linux下进行连接的缺省操作是首先连接动态库，也就是说，如果同时存在静态和动态库，不特别指定的话，将与动态库相连接。

### 静态链接库

#### 编辑测试文件

两个文件：add.c、 sub.c、add.h 、sub.h 和 main.c

```
/*add.h */
#ifndef _ADD_H_
#define _ADD_H_
int add(int a, int b);
#endif

/*add.c*/
#include "add.h"
int add(int a, int b)
{
    return a+b;
}

/*sub.h*/
#ifndef _SUB_H_
#define _SUB_H_
int sub(int a, int b);
#endif

/*sub.c*/
#include "add.h"
int sub(int a, int b)
{
    return a-b;
}

/*main.c*/
#include <stdio.h>
#include "add.h"
#include "sub.h"
int main(void)
{
       printf("1 + 2 =%d\n", add(1, 2));
       printf("1 - 2 =%d\n", sub(1, 2));
       return 0;
}
```

#### 将.c 编译生成 .o文件

```
gcc -c add.c
gcc -c sub.c
```

生成的文件：sub.o ，add.o

无论是静态库文件还是动态库文件，都是由 .o 文件创建的。

#### 由 .o 文件创建.a静态库

```
ar cr libmymath.a sub.o add.o
```

- ar：静态函数库创建的命令

    ```
    -c :create的意思

    -r :replace的意思，表示当前插入的模块名已经在库中存在，则替换同名的模块。如果若干模块中有一个模块在库中不存在，ar显示一个错误信息，并不替换其他同名的模块。默认的情况下，新的成员增加在库的结尾处。
    ```

库文件的命名规范是以lib开头(前缀)，紧接着是静态库名，以 .a 为后缀名。

#### 在程序中使用静态库

```
gcc -o main main.c -L. -lmymath
```


