# C++强制类型转换

## C语言强制类型转换

### 作用

- 用于基础的数据类型间的转换

### 语法

- (type-id)expression
- type-id(expression)

## C++强制类型转换

### C语言强制类型转换C++也可以使用

### static_cast

- 语法

	- static_cast<new_type>(expression)

- 作用

	- 相当于传统的C语言里的强制转换，该运算符把expression转换为new_type类型，用来强迫隐式转换，例如non-const对象转为const对象，编译时检查，用于非多态的转换，可以转换指针及其他，但没有运行类型检查来保证转换的安全性。

- 用法

	- 用于类的层次结构中积累和派生类之间指针或引用的转换

		- 把派生类的指针或引用转换成基类表示是安全的
		- 把基类指针或引用转换成派生类表示，由于没有动态的类型检查，所以是不安全的

	- 用于基本数据类型之间转换，如把int转换成char。

		- 这种转换也是需要开发人员来保证安全的

	- 用于把空指针转换成目标类型的空指针
	- 用于把任何类型的表达式转换成void类型

- 注意

	- static_cast不能转换掉expression中的const、volatile或者__unaligned属性

### reinterpret_cast

- 作用

	- 指针、引用、算术；类型、函数指针或者成员指针之间的转换。比如把指针转换成整数，在把整数转换成指针，还是可以得到原来的指针值。

- 注意

	- reinterpert_cast意图执行低级转型，实际动作结果可能取决与编译器，表明reinterpert_cast是不可移植的
	- 推荐使用reinterpret_cast的方式是将转换后的类型值再转换回原始类型使用，避免出错

- 语法

	- reinterpret_cat<type>(e)

### reinterpret_cast和static_cast的区别

- 主要体现在多重继承，static_cast会计算父类指针转换的偏移量，并得到正确的地址，而reinterpret_cast不会计算偏移量，需要谨慎使用reinterpret_cast

### dynamic_cast

- 语法

	- dynamic_cast<type*>(e)

		- type必须是一个有效的指针，如果失败了则结果为0

	- dynamic_cast<type&>(e)

		- type必须是一个左值，失败了抛出std::bad_casta异常

	- dynamic_cast<type&&>(e)

		- type必须是一个右值

- 作用

	- 用于类层次间的上行（派生类指针转基类指针）或下行（基类指针转派生类）转换

		- 上行转换时和static_cast是一样的安全的
		- 下行转换的时候dynamic_cast具有类型检查功能，所以比static_cast安全

	- 用于类之间的交叉转换

- 注意

	- dynamic_cast是唯一一个无法由旧式语法执行的动作
	- dynamic_cast可能导致耗费重大运行成本去转换

### const_cast

- 作用

	- 用来修改类型的const（唯一有能力修改const类型的）或volatile属性

- 用法

	- 常量指针被转换为非常量指针，并且仍然指向原来的对象
	- 常量引用转换为非常量引用，并且指向原来的对象
	- const_cast一般用于修改底指针，如const char *p

- 语法

	- const_cast<type*>(e)
	- const_cast<type&>(e)

*XMind - Trial Version*