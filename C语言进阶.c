#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


//int main()
//{
//	int i = 0x11223344;//十六进制
//	//大端字节序：0x44为数据的低位字节序，内容存放在内存的高地址处；0x11为数据的高位字节序，内容存放在内存的低地址处    即11 22 33 44
//	//小端字节序：0x44为数据的低位字节序，内容存放在内存的低地址处；0x11为数据的高位字节序，内容存放在内存的高地址处    即44 33 22 11
//	//x86结构采用的是小端字节序
//	return 0;
//}

//int main()//写代码判断当前机器字节序
//{
//	int a = 1;
//	char* p = (char*)&a;//char* p其实就是访问一个字节
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int check_sys()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	//if (*p == 1)
//	//{
//	//	return 1;
//	//}
//	return *p;
//}
//int main()//写一个代码函数判断当前机器字节序
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	//10000000000000000000000000000001
//	//11111111111111111111111111111110
//	//11111111111111111111111111111111
//	//11111111   char类型一个字节
//	//11111111111111111111111111111111 整型提升，高位补符号位（补码）
//	signed char b = -1;//同上
//	//11111111
//	unsigned char c = -1;//无符号位，即最高位不是符号位
//	//11111111
//	//00000000000000000000000011111111   整型提升(是按照变量的数据类型的符号位来提升的)无符号整型提升，高位补0
//	//255
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//补充：
//1. char 到底是signed char 还是 unsigned char，C语言没有规定，取决于编译器，大部分是signed char
//2. int 是 signed int
//3. short 是 signed short

//int main()
//{
//	char a = -128;
//	//10000000000000000000000010000000
//	//11111111111111111111111101111111
//	//11111111111111111111111110000000
//	//10000000
//	//11111111111111111111111110000000  整型提升（补码）
//	printf("%u\n", a);//%u打印无符号整形，以十进制整数的形式输出，最高位不是符号位，补码就是原码
//	printf("%d\n", a);//%d打印有符号整形  以十进制整数的形式输出
//	return 0;
//}
//int main()
//{
//	char a = 128;
//	//00000000000000000000000010000000
//	//10000000
//	//11111111111111111111111110000000
//	printf("%u\n", a);//%u打印无符号整形，最高位不是符号位，补码就是原码
//	return 0;
//}
//补充：char类型的取值范围为 -128~127
//   00000000 ->0
//	 00000001 ->1
//	 00000002 ->2
//	 ....
//	 01111111 ->127
//
//	 10000000 ->-128 直接解译成-128 
//	 10000001 -> 11111110 -> -127
//	 .....
//	 11111110 -> 10000010 -> -2
//	 11111111 -> 10000001 -> -1

//int main()
//{
//	int i = -20;
//	//10000000000000000000000000010100
//	//11111111111111111111111111101011
//	//11111111111111111111111111101100
//	unsigned int j = 10;
//	//00000000000000000000000000001010
//	printf("%d\n", i + j);//%d打印有符号整形
//	//11111111111111111111111111110110
//	//11111111111111111111111111110101
//	//10000000000000000000000000001010   -> -10
//	if (i + j > 0)//int 和 unsigned 相加，int类型要转化为unsigned类型,存的是无符号数字
//	{
//		printf("大于0\n");
//	}
//	return 0;
//}
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);//死循环
//		//printf("%d\n", i);//死循环，但是打印的是有符号的数字，unsigned int i 一直大于零
//	}
//	return 0;
//}

//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	//a[i]= -128 -> 10000000
//	//a[i+1]     -> 01111111  -> 127
//	//-1 -2 -3 ... -128 127 126 ... 3 2 1 0 -1 -2 -3 ... -128 127 126 ... 3 2 1 0 ...
//	printf("%d", strlen(a));//找到'\0',ASCLL码值为0
//	//128+127=255
//	//有符号的char取值范围是-128~127
//	//无符号的char取值范围是0~255
//	return 0;
//}

//int main()
//{
//	char a = 128;
//	printf("%d\n", a);
//	//return 0;
//}

//unsigned char i = 0;//范围是0~255
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("ddd\n");
//	}
//	return 0;
//}


//浮点数在内存中的存储

//1E10 表示的是1.0 X 10的十次方
//int main()
//{
//	int n = 9;
//	//00000000000000000000000000001001
//	float* p = (float*)&n;//float占四个字节，double占八个字节
//	//0  00000000  00000000000000000001001
//	//0.00000000000000000001001 * 2^(-126）
//	printf("%d\n", n);
//	printf("%f\n", *p);
//	*p = 9.0;//把浮点数存在内存中
//	//1001.0  --  1.001 * 2^3
//	//0  10000010  00100000000000000000000
//	//01000001000100000000000000000000
//	//即1091567616
//	printf("%d\n", n);//从内存中取出，以整形打印
//	printf("%f\n", *p);
//	return 0;
//}
//浮点数的存储到内存的方式：
//根据国际标准IEEE（电气和电子工程协会）754，任意一个二进制浮点数V可以转化成下面的形式
//（-1）^S * M * 2^E
//（ - 1） ^ S  表示符号位，当S=0时，V为正数；当S=1时，V为负数
//M表示有效数字，大于等于1，小于2
//2^E 表示指数位
//例：浮点数： 5.5  - 十进制											0.5 -十进制
//    二进制： 101.1 （小数点后面的1表示位2的负一次方）					（-1）^0 * 1.0 * 2^(-1)
//			 101.1  --> 1.011 * 2^2 --> (-1)^0 *1.011 * 2^2
//										即s=0,M=1.011,E=2
//单精度浮点数存储模型  float：S（1bit） E（8bit） M（23bit）
//双精度浮点数存储模型  double：S（1bit） E（11bit） M（52bit）
//因为1<=M<2,即1.xxxxx；计算机存储时会默认第一位为1，因此可以舍去，只保存后面的xxxxxx部分,节省了一位有效数字，更精确
//指数E：
//		 首先， E 为一个无符号整数（ unsigned int ）这意味着，如果 E 为8位，它的取值范围为0~255；如果 E 为11位，它的取值范围为0~2047。
//	 但是，我们知道，科学计数法中的 E 是可以出现负数的，所以 IEEE 754规定，存入内存时 E 的真实值必须再加上一个中间数，
//	 对于8位的 E ，这个中间数是127；对于11位的 E ，这个中间数是1023。
//	 比如，2^10的 E 是10，所以保存成32位浮点数时，必须保存成10+127=137，即10001001
//int main()
//{
//	float a = 5.5f;
//	//(-1)^0 *1.011*2^2
//	//s=0, M=1.011, E=2
//	//在内存中存储的是：s=0, M=011, E=2+127=129
//	//01000000101100000000000000000000	  -- M不够后面补0
//	//0100 0000 1011 0000 0000 0000 0000 0000  
//	//十六进制：40 b0 00 00   --也有大小端字节序
//	return 0;
//}
//浮点数从内存中取出的方式：
//指数 E 从内存中取出还可以再分成三种情况：
//1.	E 不全为0或不全为1
//这时，浮点数就采用下面的规则表示，即指数 E 的计算值减去127（或1023)，得到真实值，再将有效数字 M 前加上第一位的1。
//比如：0.5(1 / 2）的二进制形式为0.1，由于规定正数部分必须为1，即将小数点右移1位，则为1.0 * 2 ^(- 1)，
//	    其阶码为﹣1 + 127 = 126，表示为01111110，而尾数1.0去掉整数部分为0，补齐0到23位00000000000000000000000，
//	    则其二进制表示形式为：
//	    0  01111110  00000000000000000000000
//2.  E 全为0  
//	  这时，浮点数的指数 E 等于1 - 127（或者1 - 1023）即为真实值，有效数字 M 不再加上第一位的1，而是还原为0.xxxxxx的小数。
//	  这样做是为了表示±0，以及接近于0的很小的数字。
//3.  E 全为1 （真实的E=128 或 1024）
//	   这时，如果有效数字M全为0，表示+-无穷大（正负取决于符号位s）
	  

//指针进阶

//int main()
//{
//	//字符指针是一个变量，用于存放字符串的首地址。
//	char* ps = "dad";//本质上是把字符串的首字符的地址存储在指针中
//	char arr[] = "aaa aa";
//	//字符串中每个字符都有一个内存地址，而字符串的首字符地址就代表了整个字符串的位置。
//	printf("%s\n", ps);//%s打印字符：给出首字符地址，就可以打印整个字符串。
//	printf("%s\n", arr);
//	printf("%c\n", *ps);
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello C";//数组先开辟一块空间，再存放内容
//	char str2[] = "hello C";
//	const char* str3 = "hello C";
//	//*str3 = 'w';//常量字符串的内容不能改变
//	char* str4 = "hello C";
//	//*str4 = 'w';
//	if (str1 == str2)
//	{
//		printf("1=2");
//	}
//	if (str3 == str4)
//	{
//		printf("3=4");
//	}
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int b[] = { 0,1,2,3,4,5 };
//	int c[] = { 3,44,5,6,7 };
//	int* arr[3] = { a,b,c };//指针数组
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(arr[i] + j));
//			printf("%d ", arr[i][j]);// []表示指针运算符，用来计算指针加上或减去一个整数后所指向的地址。例如，p[0]等价于*p，p[1]等价于*(p+1)
//		}
//		printf("\n");
//	}
//	return 0;
//}

//数组指针
//int main()
//{
//	//int arr[10] = {2,23,4,5};
//	//int(*parr)[10] = &arr;//数组指针  (*parr)就是指针    指向数组的指针
//	////如果写成int *parr[10],指针数组：装着指针的数组,parr会先于[]结合,[]优先级高于*,优先级顺序：()>[]>*
//	//printf("%p\n", parr);
//	double* d[5];
//	double* (*pa)[5] = &d;
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//	printf("%p\n", *p);
//	printf("%p\n", *p + 1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	return 0;
//}
//数组名表示首元素地址，但有两个例外
//1. sizeof（arr），整个数组的大小，单位为字节
//2. &arr  整个数组的地址

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8 };
//	int(*p)[10] = &arr;
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *((*p) + i));
//	}
//	return 0;
//}

//void print1(int arr[3][5], int a, int b)
//{
//	int i, j;
//	for (i = 0; i < a; i++)
//	{
//		for (j = 0; j < b; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int(*p)[5], int a, int b)
//{
//	int i,j;
//	for (i = 0; i < a; i++)
//	{
//		for (j = 0; j < b; j++)
//		{
//			printf("%d ", *((*p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,1,2}, {1,1,1,1,1}, {2,3,4,2,3} };
//	//print1(arr, 3, 5);
//	//二维数组的数组名代表的是一个指向行的指针，也就是指向二维数组第一行的地址。
//	print2(arr, 3, 5);
//	return 0;
//}

//int (*parr3[10])[5];
//parr3是一个存储数组指针的数组，该数组能够存放十个数组指针，每个数组指针能够指向一个数组，数组五个元素，每个元素为int类型

//一维数组传参
//void test (int arr[])
//void test(int arr[10])//[]内数字可写可不写
//void test(int *arr)
//void test2(int *arr[20])
//void test2(int **arr)//arr2是首元素的地址，即int* 的地址，也就是一个二级指针
//int main()
//{
//	int arr[10];
//	int *arr2[20];//存放指针的数组,也就是存放 int* 的数组
//	test(arr);
//	test2(arr2);//arr2是首元素的地址，即int*的地址，也就是一个二级指针
//	return 0;
//}

//二维数组传参
//void test(int arr[3][5])
//void test(int arr[][5])
//void test(int arr[][])//错的，行能省略但列不可省略
//void test(int *arr)//错的，此时是一维数组
//void test(int* arr[5])//错的，此时是指针数组，既不是整形二维数组，也不是指针
//void test(int (*arr)[5])
//void test(int** arr)//错的，传的是一行一维数组，不是二级数组
//int main()
//{
//	int arr[3][5];
//	test(arr);//二维数组的数组名代表的是一个指向行的指针，也就是指向二维数组第一行的地址。
//	return 0;
//}

//一级数组传参
//void test(int *p)
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	test(arr);
//	test(p);
// 
//  int a = 1;
//	int* p1 = &a;
//	test(&a);
//	test(p1);
//	return 0;
//}

//二级数组传参
//void test(int **p)
//int main()
//{
//	int a = 1;
//	int* p = &a;
//	int** p1 = &p;//二级指针：存放一级指针变量的地址
//	test(p1);
//	test(&p);//传一级指针的地址
//	int* arr[10];
//	test(arr);//传指针数组的数组名
//	return 0;
//}

//函数指针
//int Add(int x, int y)
//{
//	return x + y;
//}	
//int main()
//{
//	int arr[10] = { 0 };
//	int (*parr)[10] = &arr;//取出数组的地址
//	//parr是指向数组的指针，存放的的是数组的地址
//	
//	//函数指针：存放函数地址的指针
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	//数组名 != &数组名
//	//函数名 == &函数名 == 函数的地址
//	int (*pf)(int, int) = &Add;
// 	int (*pf)(int, int) = Add;//Add === pf
//	//pf就是一个函数指针变量
//	//函数指针的调用：
//	int ret = (*pf)(4, 4);//1
//	int ret = pf(3, 3);//2
//	int ret = Add(2, 2);//3
//	int ret = (********pf)(5, 5);
//	//以上三种方式一摸一样，在函数指针里，（*pf）里的*只是一个摆设，没有意义，写成（***pf）也一样，注意只有在函数指针调用里才是这样
//	//但不能写成int ret= * pf(2,2);相当于 * 4，err
//	printf("%d\n", ret);
//	return 0;
//}
//void test(char* s)
//{
//
//}
//int main()
//{
//	void (*p)(char*) = &test;
//	return 0;
//}

    //(*(void (*)())0)();
	//()0   强制类型转换，这里()内是函数地址类型，是把函数地址强制转换为0 地址
	//实际上是调用0地址处的函数
	//该参数无参，返回类型为void
	//void (*)()  - 函数指针类型
	//(void (*)())0  - 对0进行强制类型转换，被解释为一个函数地址
	//* (void (*)())0  - 对0地址进行了解引用操作
	//(*(void (*)())0)()  - 调用0地址处的函数

	//void (*signal(int, void (*)(int)))(int);
	//void(*)(int) signal(int, void (*)(int));//实际上不能这样编写 
	// typedef void(*pfun_t)(int);  - 对void (*)()的函数指针类型重命名为pfun_t
	// 也就等价于 pfun_t signal(int,pfun_t);
	//	
	//1. signal先于()结合 - 说明signal是一个函数名
	//2. signal函数的第一个参数类型是int ，第二个参数类型是函数指针
	//	该函数指针，指向一个参数为int，返回类型为void的函数
	//3. signal函数的返回类型也是一个函数指针
	//	该函数指针，指向一个参数为int，返回类型为void的函数
	//signal是一个函数声明

//函数指针数组 - 存放函数指针的数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int (*pf1)(int, int) = Add;
//	int (*pf2)(int, int) = Sub;
//	int (*pfarr[2])(int,int) = { Add,Sub };//pfarr就是函数指针数组 同类型的函数
//	int (*pfarr[2])(int, int) = { pf1,pf2 };
//  int (*pfarr[3])(int,int) = { NULL,Add,Sub };//pfarr[1]==Add;pfarr[2]==Sub;
//	return 0;
//}

//指向函数指针数组的指针 - 
//int (*p1)(int, int);//函数指针
//int (* p2[3])(int, int);//函数指针数组
//int (* (*p3)[3])(int, int) = &p2;//取出的是函数指针数组的地址
//p3就是一个指向【函数指针数组】的指针

//int arr[2];
//数组类型：int[2]
//数组元素类型：int

//回调函数 - 一个通过函数指针调用的函数
//int Calc(int (*pf)(int, int))//Calc函数就是一个回调函数
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	return pf(x, y);
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int ret = 0;
//	ret = Calc(Add);
//	printf("%d\n", ret);
//	ret = Calc(Sub);
//	printf("%d\n", ret);
//	return 0;
//}

//qsort  排序函数 头文件是stdlib
//void qsort(void* base,//base中存放的待排序数据中第一个对象的地址
//		size_t num,//排序数据元素的个数
//		size_t size,//排序数据中一个元素的大小，单位为字节
//		int (*compare)(const void* e1, const void* e2)//是用来比较待排序数据中的2个元素的函数
//		);//如果第一个元素大于第二个元素，返回值大于0；相等，返回值等于0；第一个元素小于第二个元素，返回值小于0

//qsort的使用

//int compare(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = {9,8,7,6,5,4,3,2,1};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), compare);
//	print(arr, sz);
//	return 0;
//}

//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
// //strcmp对两个字符串进行比较大小,e1<e2,返回值小于0；相等，返回值等于0；e1>e2,返回值大于0
// //是对应位置上的ASCLL码值的比较
// //例：abcd
// //    adc
// //a=a，b<d,所以abcd < adc
//int cmp_age(const void* e1, const void* e2)
//{
//	return (-1)* (((struct stu*)e1)->age - ((struct stu*)e2)->age);//乘以-1就是以降序排序，或者e1和e2交换下位置
//}
//int main()
//{
//	//对结构体进行排序
//	struct stu a[] = { {"zhangsan", 44}, {"lisi",33}, {"wanger",11} };
//	int sz = sizeof(a) / sizeof(a[0]);
//	//按名字来排序
//	qsort(a, sz, sizeof(a[0]), cmp_name);
//	//按年龄来排序
//	qsort(a, sz, sizeof(a[0]), cmp_age);
//	return 0;
//}


//模仿qsort函数实现一个冒泡排序的通用算法
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i=0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp;
//		tmp = * buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//
//}
//void bubble_sort(void* base,
//				int sz,
//				int width,
//				int (*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			//两个元素比较
//			if ((*cmp)((char*)base+j*width, (char*)base+(j+1)*width) > 0)
//			{
//				//交换	
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//
//				//char tmp;
//				//tmp = *((char*)base + j * width);
//				//*((char*)base + j * width) = *((char*)base + (j + 1) * width);
//				//*((char*)base + (j + 1) * width) = tmp;
//			}
//		}
//	}
//}
//int  cmp_int(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *(int*)e2;
//}
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test1()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int width = sizeof(arr[0]);
//	bubble_sort(arr, sz, width, cmp_int);
//	print_arr(arr, sz);
//}
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int cmp_age(const void* e1, const void* e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//void test2()
//{
//	struct stu a[] = { {"zhangsan", 44}, {"lisi",33}, {"wanger",11} };
//	int sz = sizeof(a) / sizeof(a[0]);
//	qsort(a, sz, sizeof(a[0]), cmp_name);
//}
//void test3()
//{
//	struct stu a[] = { {"zhangsan", 44}, {"lisi",33}, {"wanger",11} };
//	int sz = sizeof(a) / sizeof(a[0]);
//	qsort(a, sz, sizeof(a[0]), cmp_age);
//}
//
//int main()
//{
//	test1();
//	//test2();
//	//test3();
//	return 0;
//}

//一个表达式具有值属性和类型属性
//sizeof（）内部的表达式不会真正进行计算，只需要知道类型就可以计算大小，所以数组越界也可以计算出结果：不存在，可以通过类型进行计算
//int main()
//{
//	short a = 4;
//	int b = 3;
//	int arr[3][4];
//	printf("%d\n", sizeof(a = 3 + b));//2  表达式的类型最终由a决定
//	printf("%d\n", a);//4
//	printf("%d\n", sizeof(arr[-1]));//16 
//	return 0;
//}

//struct test			//结构体类型大小为32个字节
//{
//	char a[2];
//	short i[4];
//	int arr[4];
//	int* pa = arr;
//}* p;//结构体后加* 表示为结构体指针，p为指针变量
//int main()
//{
//	//指针类型决定了指针的运算
//	printf("%d\n", sizeof(*p));
//	printf("%p\n", p);
//	printf("%p\n", p + 0x1);//p+32
//	printf("%p\n", (unsigned long)p + 0x1);//p+1  (整形）
//	printf("%p\n", (unsigned int*)p + 0x1);//p+4
//	return 0;
//}

//int main()
//{
//	int arr[4] = { 1,2,3,4 };
//	int* p1 = (int*)(&arr + 1);
//	int* p2 = (int*)((int)arr + 1);//小端字节序：01 00 00 00	02 00 00 00		03 00 00 00		04 00 00 00
//	printf("%x\n", p1[-1]);
//	printf("%x\n", *p2);//访问四个字节：00 00 00 02  又因为是小端字节序，所以是 02 00 00 00
//	return 0;
//}

//int main()
//{
//	int a[3][2] = { (0,1),(1,2),(3,4) };//逗号表达式
//	int* p = a[0];
//	printf("%d\n", p[0]);
//	return 0;
//}

//int main()
//{
//	int a[5][5];
//	int(*p)[4] = (int(*)[4])a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//&p[4][2]-&a[4][2]  地址相减，为之间的元素个数		低地址减高地址 结果是 -4
//	//10000000000000000000000000000100
//	//11111111111111111111111111111011
//	//11111111111111111111111111111100
//	//%p 以地址打印，无正负之分，按11111111111111111111111111111100打印，十六进制为FFFFFFFC
//	return 0;
//}

//int main()
//{
//	int a[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p1 = (int*)(&a + 1);
//	int* p2 = (int*)(*(a + 1));
//	printf("%d  %d\n", *(p1 - 1), *(p2 - 1));
//	return 0;
//}

//int main()
//{
//	char* a[] = { "work","at","efwff" };//把三个字符串首元素地址放在指针数组里
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);//%s 需传字符串的首元素地址
//	printf("%c\n", *(*pa));//%s 二级解引用
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}

//字符串函数

//1.长度不受限制的函数
//字符串长度
//int main()
//{
//	//strlen返回值类型为size_t无符号数始终大于0
//  //返回值是字符串中‘\0'前面出现的字符个数，不包括'\0'
//	if (strlen("abf") - strlen("afsdfs") < 0)
//		printf("<0");
//	else
//		printf(">0");
//	return 0;
//}

//字符串拷贝
//int main()
//{
//	char arr[20] = "#############";
//	//arr = "hello";//err
//	strcpy(arr, "hello");//arr是目标地址，hello是copy的值的地址，原字符串大小不能大于目标空间的的大小，目标空间必须可变，足够大
//	char* p = "%%%%%%%%%%%";//这里字符串是个常量，不可变,字符数组内容可变
//	strcpy(p, "hello");
//	printf("%s\n", arr);
//	char arr2[] = { 'a','b','c' };
//	strcpy(arr, arr2);//strcpy会将源字符串中的'\0'copy到目标空间中，没有‘\0'会出错，所以源字符串必须以'\0'结束
//	printf("%s\n", arr);
//	return 0;
//}

//字符串追加（连接）strcat
//int main()
//{
//	char arr[20] = "hello \0$$$$$$$$$$$";//目标空间必须可变，足够大
//	char arr2[] = "world";// 源字符串必须以'\0'结束
//	strcat(arr, arr2);//把arr2内容追加到arr内，arr2第一个字符放进arr的第一个\0上，arr2的\0也会追加到arr内
//	printf("%s\n", arr);//返回值是目标字符串的地址
//	return 0;
//}
//模拟实现strcat
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret =  dest;
//	assert(dest && src);//不能为空指针
//	//先找到目标空间的\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//把原字符串追加到目标空间中，包括\0
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//返回的目标空间的起始地址
//}
//int main()
//{
//	char arr[20] = "hello ";
//	char arr2[] = "world";
//	//my_strcat(arr, arr2);
//	printf("%s\n", arr);
//	printf("%s\n", my_strcat(arr, arr2));
//	return 0;
//}
//strcat不能自己追加自己
//int main()
//{
//	char arr[20] = "abcd";//为什么少于三个字符就可以追加？
//	strcat(arr, arr);
//	printf("%s\n", arr);
//	return 0;
//}

//字符串比较
//int main()
//{
//	char* p = "abf";
//	char* q = "dsffs";
//	//p>q 和 “abf">"dsffs" 都是比较两字符串的地址，不是比较字符串
//	int ret = strcmp(p,q);//一一对应比较：q的第一个字符的ASCLL码值与p的第一个字符的ASCLL码值比较，如果相等，就对第二个字符的ascll码值进行比较，直到比出大小
//	//返回值类型为int：当第一个字符串小于第二个，返回值小于0；相等，返回值为0；大于 返回值大于0		具体的值由编译器决定，VS是+-1
//	printf("%d\n", ret);
//	return 0;
//}
//模拟实现strcmp
//int my_strcmp(const char* s1,const char* s2)
//{
//	assert(s1 && s2);
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//	/*if (*s1 > *s2)
//		return 1;
//	else
//		return -1;*/
//	return *s1 - *s2;
//}
//int main()
//{
//	char* p = "agc";
//	char* q = "avc";
//	int ret = my_strcmp(p, q);
//	if (ret > 0)
//		printf("p>q");
//	else if (ret < 0)
//		printf("p<q");
//	else
//		printf("p==q");
//	return 0;
//}

//2.长度受限制的函数
//strncpy
//int main()
//{
//	char arr[20] = "abcdefghhhh";
//	char arr2[] = "qeqr";
//	strncpy(arr, arr2, 6);//指定拷贝源字符串多少个字符，超过的部分会copy \0
//	printf("%s\n", arr);
//	return 0;
//}

//strncat
//int main()
//{
//	char arr[20] = "abcdefg\0########";
//	char arr2[] = "qeqr";
//	strncat(arr, arr2,6);//指定追加源字符串多少个字符，最后会默认加一个\0,就结束了，超过的部分不会额外添加\0
//	printf("%s\n", arr);
//	return 0;
//}

//strncmp
//int main()
//{
//	char arr[20] = "abcdefg";
//	char arr2[] = "abqeqr";
//	int ret = strncmp(arr, arr2, 5);//指定比较多少个字符
//	printf("%d\n", ret);
//	return 0;
//}

//strstr   - 在arr1中查找是否包含arr2
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	char* cp = (char*)str1;
//	if (*s2 == '\0')
//	{
//		return (char*)str1;
//	}
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	} 
//	return NULL;
//}
//int main()
//{
//	char arr1[20] = "abbbbbbcd";
//	char arr2[] = "bbc";
//	//在arr1中查找是否包含arr2
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return  0;
//}

//strtok - 用分隔符分割字符串
//cahr* strtok(char* str,const char* sep)  sep参数是个字符串，定义了用作分隔符的字符集合
// 此函数会改变被操作的字符串（把分隔符改成\0)，所以在使用此函数时一般都是对临时拷贝的内容进行修改
// 当strtok第一个参数不为NULL，函数将找到str中第一个标记，并保存它在字符串中的位置
// 当strtok第一个参数为NULL， 函数将在同一个字符串被保存的位置开始，查找下一个标记
// 如果字符串中不存在更多的标记，则返回NULL指针
// 也就是说，使用此函数只有第一次使用字符串参数，之后都用NULL
//int main()
//{
//	char arr[] = "afdfdsf@sf.sf";
//	char* sep = "@.";
//	char tmp[40] = { 0 };
//	strcpy(tmp, arr);
//	//afdfdsf\0sf\0sf
//	char* ret = NULL;
//	for (ret = strtok(tmp, sep); ret != NULL;ret=strtok(NULL,sep))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strerror
// char* strerror (int errnum)
// 返回错误码所对应的错误信息
// 
//调用函数失败时，都会设置错误码
//全局的错误码
//int errno
#include <errno.h>  // 头文件
//int main()
//{
//	//printf("%s\n", strerror(0));
//	//printf("%s\n", strerror(1));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(3));
//	//printf("%s\n", strerror(4));
//	//printf("%s\n", strerror(5));
//	FILE* pf = fopen("C语言进阶.c", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	return 0;
//}

//strerror 把错误码转换成错误信息
//perror 头文件为stdio.h
// 1.先把错误码转换成错误信息   2.再打印错误信息 (包含了自定义的信息)
//- 打印时会在开头添加()内的内容，和一个冒号：，和一个空格 ，之后的是错误信息
//int main()
//{
//	//打开文件失败的时候，会返回NULL
//	FILE* pf = fopen("Cyuyan.c","r");//r 表示是只读
//	if(pf==NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//字符分类函数
//isdigit 判断字符是否为数字字符
#include<ctype.h>
//int isdigit (int c)	c为ASCLL码值
//int main()
//{
//	char ch = '#';
//	int ret = isdigit(ch);
//	//如果为非数字字符，返回值0；如果是数字字符，返回值为非零
//	printf("%d\n", ret);
//	return 0;
//}

//islower  判断字符是否为小写字母,
//int main()
//{
//	char ch = 'a';
//	int ret = islower(ch);
//	//如果为大写字母，返回值为0，反之为非零
//	printf("%d\n", ret);
//	return 0;
//}

//字符转换函数
//tolower  把大写字符转换成小写字符
// int tolower (int c)
//toupper  把小写字符转换成大写字符
// int toupper (int c)
//int main()
//{
//	char arr[20] = { 0 };
//	scanf("%s", arr);
//	int i = 0;
//	while (arr[i] != 0)
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//			//printf("%c ", arr[i]);
//		}
//		printf("%c ", arr[i]);
//		i++;
//	}
//	return 0;
//}

//内存操作函数

//内存拷贝
//memcpy - 拷贝不重叠的内存
//memmove - 处理内存重叠的情况
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if (dest < src)
//	{
//		//从前往后拷贝
//		while (num--)
//		{
//			*((char*)dest) = *((char*)src);
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后往前拷贝
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[10]= { 0,1,2,3,4,5,6,7,8,9 };
//	int arr2[10] = { 0 };
//	//memcpy(arr2, arr1, 20);//把arr1中的20个字节的内容拷贝到arr2的内存中
//	//my_memcpy(arr2, arr1, 20);
//	//my_memcpy(arr1 + 2, arr1, 20);//0 1 0 1 0 1 0 7 8 9  -- 
//	//memcpy(arr1 + 2, arr1,20);//memcpy应该拷贝不重叠的内存	
//  //memcpy - 只要实现了不重叠拷贝就行了，而VS中的实现既可以拷贝不重叠，也可以拷贝重叠内存，就是按memmove运行的，但其他编译器不一定对
//	//memmove(arr1 + 2, arr1, 20);//memmove可以处理内存重叠的情况
//	my_memmove(arr1 + 2, arr1, 20);
//	return 0;
//}

//memcmp - 内存比较
// int memcmp(const void* s1,const void* s2,size_t num)
//int main()
//{
//	float arr1[] = { 1.0,2.0,3.0 };
//	float arr2[] = { 1.0 ,3.0};
//	int ret = memcmp(arr1, arr2, 5);//比较四个字节
//	//arr1 == arr2，返回值为0，arr1 > arr2 ,返回值大于零，否则小于零
//	printf("%d\n", ret);
//	return 0;
//}

//memset 内存设置
//void* memset(void* ptr, int value,size_t num)
//int main()
//{ 
//	int arr[20] = { 0 };
//	memset(arr, 1, 20);//以字节为单位设置内存 - 这里是把arr前20个字节设置为1
//	//0x01010101
//	return 0;
//}

//结构体

//匿名结构体（创建好只能用一次）
//struct
//{
//	int age;
//	char arr[20];
//	char a[];
//}s;//创建好只能用这一次，以后不能使用
//struct
//{
//	int age;
//	char arr[20];
//	char a[];
//}* ps;
//int main()
//{
//	ps = &s;//编译器会把上面两个匿名结构体当成完全不同的两个类型，所以是非法的
//  struct s;//不能创建变量，没有结构体标签不能构成一个类型
//	return  0;
//}

//错误的结构体自引用
/*struct N
{
	int a;
	struct N s1;
};*///结构体内部不能包含自己，如果能的话，所占内存无穷大
//结构体能自己找到自己的下一个节点 （每个节点有数据域和指针域，指针域指向下一个节点）
//正确的结构体自引用（通过指针来实现）
//struct node
//{
//	int date;
//	struct node* next; //找到自己同类型的下一个数据节点
//};

//结构体的内存对齐
//规则如下：
//1. 结构体的第一个成员，放在结构体变量在内存中存储位置的0偏移处开始
//2. 从第二个成员往后的所有成员，都放在一个对齐数（成员的大小和编译器默认对齐数的较小值）的整数的整数倍的地址处
//VS默认对齐数是8       Linux无默认值
//3. 结构体的总大小是结构体的所有成员的对齐数中最大的那个对齐数的整数倍
//struct S
//{
//	char a;
//	int i;
//	char s2;
//};
//struct n
//{
//	char c1;
//	int i;
//	double c3;
//}n1;
////4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己内部成员的最大对齐数的整数倍处，
// //   结构体的整体大小就是所有最大对齐数(含嵌套结构体内部成员的对齐数)的整数倍
//struct s3
//{
//	char a;
//	struct n s2;//最大对齐数是8
//	double d;
//}s4;//最大对齐数是8	
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s)); //12
//	printf("%d\n", sizeof(n1));//16
//	printf("%d\n", sizeof(s4));//32
//	return 0;
//}
// 
//struct n
//{
//	int a;
//	char g;
//}s2;//结构体大小为8
//struct s3
//{
//	char a;
//	struct n s2;//最大对齐数是4
//}s4;//最大对齐数是4  
//int main()
//{
//	printf("%d\n", sizeof(s4));//12
//	return 0;
//}
//为什么存在内存对齐？
//大部分的参考资料都是如是说的：
//1．平台原因（移植原因）：不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
//2．性能原因：数据结构（尤其是栈）应该尽可能地在自然边界上对齐。原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问。
//总体来说：
//结构体的内存对齐是拿空间来换取时间的做法
//所以，为了节省空间，在设计结构体的时候，让占用空间小的成员尽量集中在一起

//修改默认对齐数  - 结构在对齐方式不合适的时候，我们可以自己更改默认对齐数
//#pragma pack(2)//设置默认对齐数为2
//struct n 
//{
//	char a;
//	int i;
//	char b;
//}s1;
// #pragma pack()//取消设置的默认对齐数，还原为默认
//int main()
//{
//	printf("%d\n", sizeof(s1));//8
//	return 0;
//}
//#pragma pack(1)//设置默认对齐数为1
//struct n
//{
//	char a;
//	int i;
//	char b;
//}s1;
//#pragma pack()//取消设置的默认对齐数，还原为默认
//struct m
//{
//	char a;
//	int i;
//	char b;
//}s2;
//int main()
//{
//	printf("%d\n", sizeof(s1));//6
//	printf("%d\n", sizeof(s2));//12
//	return 0;
//}

//offsetof - 计算结构体中某变量相对于首地址的偏移量
//offsetof(type,member)
//头文件为stddef
//#include<stddef.h>
//struct n
//{
//	char c1;
//	int i;
//	char c2;
//}s;
//int main()
//{
//	printf("%d\n", offsetof(s, c1));
//	printf("%d\n", offsetof(s, i ));
//	printf("%d\n", offsetof(s, c2));
//	return 0;
//}

//结构体传参
//struct S
//{
//	int arr[100];
//	char c;
//}s;
////传值  参数压栈的系统开销较大，导致性能下降
//void print1(struct S s)
//{
//	printf("%d\n", s.arr);
//}
////传址 （节省空间和时间）
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->arr);
//}
//int main()
//{
//	print1(s);
//	print2(&s);
//	return 0;
//}

//位段  （节省空间）

//位段的成员类型必须为int ,unsigned int ,signed int ,char（属于整形家族）,位段成员后边有一个冒号和一个数字
// 位段的空间上是按照需要以4个字节（int）或1个字节（char)的方式来开辟的
//位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段
//struct S
//{
//	//先开辟4个字节  - 32个bit位
//	int _a : 2;//占2个bit位
//	int _b : 5;//占5个bit位
//	int c : 10;//占10个bit位
//	//17
//	//因为17+30>32，所以要再开辟4个字节 - 32个bit位
//	//但是d的30个bit位是否占用第一次开辟的未使用的15个bit位是不确定的，所以位段涉及很多不确定因素，不能跨平台使用，不同平台的实现是不一样的
//	int d : 30;//占30个bit位
//	//int i : 33;//err 不能超过32个bit位
//}s;
//int main()
//{
//	printf("%d\n", sizeof(s));//8
//	return 0;
//}

//位段的内存分配
//在VS中,一个字节内部的数据是从低bit位到高bit位使用，即从右向左使用，当剩下的bit位不够下一个成员使用时，剩下的bit位就浪费掉了
//其他的编译器不一定这样分配
//struct s
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 6;
//}s;
//int main()
//{
//	s = { 0 };
//	s.a = 10;//1010  但是a只有三个bit位，所以放010
//	//00000010
//	s.b = 12;//1100
//	//01100010
//	s.c = 3;//00011
//	//01100010   00000011
//	s.d = 4;//000100
//	//01100010   00000011   00000100
//	//0x62       0x03       0x04
//	return 0;
//}

//位段的跨平台问题
//1. int 位段被当成有符号数还是无符号数是不确定的。
//2．位段中最大位的数目不能确定。(16位机器最大16, 32位机器最大32，写成27，在16位机器会出问题。
//3．位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
//4. 当一个结构包含两个位，第二个位成员比较大，无法容纳于第一个位段剩余的位时，是舍弃剩余的位还是利用，这是不确定的。
//总结：
//跟结构相比，位段可以达到同样的效果，但是可以很好的节省空间，但是有跨平台的问题存在。

//枚举  - 一一列举
//声明枚举类型
//枚举的优点
//为什么使用枚举？
//我们可以使用＃ define 定义常量，为什么非要使用枚举？枚举的优点：
//1．增加代码的可读性和可维护性
//2．和＃ define 定义的标识符比较枚举有类型检查，更加严谨。
//3．防止了命名污染（封装）
//4．便于调试
//5．使用方便，一次可以定义多个常量
//enum Color
//{
//	//RED,	//0
//	//GREEN,  //1
//	//BLUE    //2
//	//递增1
//	RED=5,	//5
//	GREEN=8,  //8
//	BLUE    //9
//};
//int main()
//{
//	enum Color c = BLUE;
//	printf("%d\n", c);
//	printf("%d\n", sizeof(c));
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//	return 0;
//}

//联合体
//联合也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）
//联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）。
//union Un
//{
//	char a;
//	int i;
//}s;
//int main()
//{
//	s = { 10 };//a和i都放进10
//	printf("%p\n", &s);
//	printf("%p\n", &(s.a));
//	printf("%p\n", &(s.i));
//	printf("%d\n", sizeof(s));
//	return 0;
//}

//判断系统大小端存储形式
//int check_sys()
//{
//	int a = 1;
//	if ((*(char*)&a) == 1)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int check_sys()
//{
//	union un
//	{
//		char a;
//		int i;
//	}s ;
//	s.i = 1;
//	return s.a;
//}
//int main()
//{
//	int ret=check_sys();
//	if (ret = 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}

//联合体大小的计算
//·联合的大小至少是最大成员的大小。
//·当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
//union un
//{
//	char a[5];//1  5
//	int i;//4
//}s;//8  是最大对齐数4的倍数
//union u
//{
//	short a[5];//2  10
//	int i;//4
//}s2;//10不是最大对齐数4的倍数，所以是12
//int main()
//{
//	printf("%d\n", sizeof(s));//8
//	printf("%d\n", sizeof(s2));//12
//	return 0;
//}

//堆区  - 动态内存开辟（malloc  free  realloc  calloc)程序员自己管理的内存

//malloc
//void* malloc(size_t size)
//开辟成功返回开辟好空间的地址，开辟失败返回NULL
//int main()
//{
//	//开辟10个整形空间 - 10*sizeof（int）
//	int arr[10];//栈区
//	//动态内存开辟
//	int* p = (int*)malloc(10 * sizeof(int));//malloc默认返回值位void*
//	//使用这些空间的时候
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d  ", p[i]);//p[i] -> *(p+i)
//	}
//	//回收空间
//	free(p);//把p所指向的空间设为空，但是p变量的内容没变
//	//void free(void* ptr) 
//	//如果参数ptr所指向的空间不是动态开辟的，则free函数的行为是未定义的；如果参数位NULL，则free函数什么事不做	
//	//malloc 和 free 头文件都在stdlib.h中
//	p = NULL;
//	return 0;
//}

//calloc
//void* calloc(size_t num,size_t size)
//为num个大小为size的元素开辟一块空间，并且把空间每个字节初始化为0
//int main()
//{
//	//int* p = (int*)malloc(40);
//	int* p = (int*)calloc(40, sizeof(int));
//	if (p == NULL)
//		return 0;
//	int i = 0;
//	for (i = 0; i < 40; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc - 重新开辟空间
//void* realloc(void* ptr,size_t size)  返回值是调整后的内存初始位置
//情况1 - 原空间后面有足够的空间开辟新的空间
//当是情况1的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发生变化。
//情况2	- 原空间后面没有足够的空间开辟新的空间
//当是情况2的时候，原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小的连续空间来使用。这样函数返回的是一个新的内存地址。
//情况3 - 堆空间内没有合适的空间来使用，返回值为NULL
//由于上述的三种情况， realloc 函数的使用就要注意一些。
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));//malloc默认返回值位void*
//	//使用这些空间的时候
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d  ", p[i]);//p[i] -> *(p+i)
//	}
//	//这里需要p指向的空间更大，需要20个整形的空间
//	//realloc调整空间
//	int* ptr =(int*) realloc(p, 20 * sizeof(int));
//	if (ptr != NULL)
//		p = ptr;
//	//回收空间
//	free(p);
//	return 0;
//}
//int main()
//{
//	int* p =(int*) realloc(NULL, 40);//这里功能类似于malloc，就是直接在堆区开辟40个字节的空间
//	return 0;
//}

//动态内存开辟常见的错误
//1.对NULL指针的解引用错误 
//开辟一块内存后，要对其进行NULL判断，然后再使用
//2. 对动态内存的越界访问
//3. 使用free释放非动态开辟的空间
//4. 使用free释放动态内存的一部分
//5. 对同一块动态开辟的空间，多次释放
//	  所以在使用完free后，要对其赋值NULL，再次释放也不会进行任何操作
//6. 动态开辟的内存空间忘记释放（内存泄漏）比较严重
//	 动态开辟的空间有两种回收方式：主动free，程序结束
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//	int i = 0;
//	//for (i = 0; i < 40; i++)
//	//{
//	//	*(p + i) = i;//越界访问：p实际上是40个字节的空间，10个整形，而不是40个整形 
//	//}
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;//p在递增
//	}
//	free(p);//err  -  p不再是动态开辟空间的起始地址，指向动态开辟内存的一部分
//	p = NULL;
//	return 0;
//}

//动态内存 的笔试题

 
//void GetMemory(char* ptr)
//{
//	ptr = (char*)malloc(100);
//}
//void test()
//{
//	char* p = NULL;
//	GetMemory(p);
//	strcpy(p, "hello world");
//	printf("%s\n", p);
//}
//int main()
//{
//	test();
//	return 0;
//}
//str 传给 GetMemory 函数的时候是值传递，所以GetMemory 函数的形参 p 是 str 的一份临时拷贝。
//在 GetMemory 函数内部动态申请空间的地址，存放在 p 中，不会影响外边 str ，所以当 GetMemory 函数返回之后， str 依然是 NULL 。所以 strcpy 会失败。
//当 GetMemory 函数返回之后，形参 p 销毁，使得动态开辟的100个字节存在内存泄漏。无法释放。
//改正1：
//char* GetMemory(char* ptr)
//{
//	ptr = (char*)malloc(100);
//	return ptr;
//}
//void test()
//{
//	char* p = NULL;
//	p = GetMemory(p);
//	strcpy(p, "hello world");
//	printf("%s\n", p);
//	printf(p);//printf("hello world") - 实际上是把首字符‘h'的地址传给printf函数
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
//改正2：
//void GetMemory(char** ptr)
//{
//	*ptr = (char*)malloc(100);
//}
//void test()
//{
//	char* p = NULL;
//	GetMemory(&p);
//	strcpy(p, "hello world");
//	printf(p);
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//char* GetMemory()
//{
//	char ptr[] = "hello world";
//	return ptr;//ptr为局部变量，是栈区开辟的，函数结束后，p就回收了，内容不存在了
//}
//void test()
//{
//	char* p = NULL;
//	p = GetMemory();
//	printf(p);//随机值
//}
//int main()
//{
//	test();
//	return 0;
//}
//GetMempry 函数内部创建的数组是在栈区上创建的
//出了函数， p 数组的空间就还给了操作系统
//返回的地址是没有实际的意义，如果通过返回的地址，去访问内存就是非法访问内存的

//void test()
//{
//	char* p = (char*)malloc(100);
//	strcpy(p, "hello");
//	free(p);//free并不会消除p所指向空间的地址，只是释放此空间，但是此空间已经释放给系统了，不能再对其操作了，不然就是非法访问
//	if (p != NULL)
//	{
//		strcpy(p, "world");
//		printf(p);
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}

//C / C + ＋程序内存分配的几个区域：
//1．栈区（ stack )：在执行函数时，函数内部局部变量的存储单元都可以在栈上创建，函数执行结束时些存储单元自动被释放。
//	栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。
//	栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
//2. 堆区（ heap )：一般由程序员分配释放，若程序员不释放，程序结束时可能由 OS 回收。分配方式类似于链表。
//3．数据段（静态区）（static ）存放全局变量、静态数据。程序结束后由系统释放。
//4．代码段：存放函数体（类成员函数和全局函数）的二进制代码，可执行代码/只读常量

//柔性数组  - 结构体的最后一个成员是一个未知大小的数组

//柔性数组的特点：
//·结构中的柔性数组成员前面必须至少一个其他成员。
//· sizeof 返回的这种结构大小不包括柔性数组的内存。
//·包含柔性数组成员的结构用 malloc(）函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

//struct S
//{
//	int n;
//	//int arr[];//未知大小
//	int arr[0];//未知大小
//};
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));//4
//
//	//期望arr大小是10个int
//	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	p->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	//增容
//	struct S* ptr=(struct S*)realloc(p, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	int* arr;
//}s;
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	p->n = 10;
//	p->arr = (int*)malloc(10 * sizeof(int));
//	if (p->arr == NULL)
//		return 1;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	//增加容量
//	int* ptr = (int*)realloc(p->arr, 20 * sizeof(int));
//	if (ptr == NULL)
//		return 1;
//	p->arr = ptr;
//	//使用
//	//释放
//	free(p->arr);
//	p->arr = NULL;
//	free(p);
//	p = NULL;
//	return 0;
//}

//以上两种代码都可以完成同样的功能，但是方法一有两种好处
//第一个好处是：方便内存释放
//如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。
//用户调用 free 可以释放结构体，但是用户并不知道这个结构体内成员也需要 free ，所以你不能指望用户来发现这个事。
//所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体指针，用户做一次 free 就可以把所有的内存也给释放掉。
//第二个好处是：这样有利于访问速度．
//连续的内存有益于提高访问速度，也有益于减少内存碎片。

//文件

//磁盘上的文件是文件。
//但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件（从文件功能的角度来分类的）。
//2.1 程序文件
//包括源程序文件（后缀为． c )，目标文件（ windows 环境后缀为． obj )，可执行程序（ windows 环境后缀为． exe )。
//2.2 数据文件
//文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件。
//本章讨论的是数据文件。
//在以前各章所处理数据的输入输出都是以终端为对象的，即从终端的键盘输入数据，运行结果显示到显示器上。
//2.3 文件名
//一个文件要有一个唯一的文件标识，以便用户识别和引用。文件名包含3部分：文件路径＋文件名主干＋文件后缀
//例如：c:\code\test.txt
//为了方便起见，文件标识常被称为文件名。
//3．文件的打开和关闭
//3.1 文件指针
//缓冲文件系统中，关键的概念是"文件类型指针"，简称"文件指针"。
//每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等），
//这些信息是保存在一个结构体变量中的。该结构体类型是有系统声明的，取名FILE .
//不同的 C 编译器的 FILE 类型包含的内容不完全相同，但是大同小异。
//每当打开一个文件的时候，系统会根据文件的情况自动创建一个 FILE 结构的变量，并填充其中的信息，使用者不必关心细节。
//一般都是通过一个 FILE 的指针来维护这个 FILE 结构的变量，这样使用起来更加方便。
//下面我们可以创建一个 FILE*的指针变量：
//FILE* pf ;//文件指针变量
//定义 pf 是一个指向 FILE 类型数据的指针变量。
//可以使 pf 指向某个文件的文件信息区（是一个结构体变量）。
//通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关的文件。
//3.2文件的打开和关闭
//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
//在编写程序的时候，在打开文件的同时，都会返回一个 FILE* 的指针变量指向该文件，也相当于建立了指针和文件的关系。
//ANSIC 规定使用 fopen 函数来打开文件， fclose 来关闭文件。
//打开文件 - （打开失败则返回一个NULL）
//FILE * fopen(const char* filename , const char* mode);
//关闭文件
//int fclose(FILE * stream);
//打开方式：
//文件使用方式					含义								如果指定文件不存在
//" r "（只读）			为了输入数据，打开一个已经存在的文本文件							出错
//" w "（只写）			为了输出数据，打开一个文本文件							建立一个新的文件
//" a "（追加）			向文本文件尾添加数据								建立一个新的文件
//" rb "（只读）		为了输入数据，打开一个二进制文件								出错
//" wb "（只写）		为了输出数据，打开一个二进制文件							建立一个新的文件
//" ab "（追加）		向一个二进制文件尾添加数据								出错
//" r +"（读写）		为了读和写，打开一个文本文件								出错
//" w +"（读写）		为了读和写，建议一个新的文件							建立一个新的文件
//" a +"（读写）		打开一个文件，在文件尾进行读写							建立一个新的文件
//" rb +"（读写）		为了读和写打开一个二进制文件								出错
//" wb +"（读写）		为了读和写，新建一个新的二进制文件						建立一个新的文件
//" ab +"（读写）		打开一个二进制文件，在文件尾进行读和写						建立一个新的文件
//函数名			功能				  适用于
//fgetc			字符输入函数(一个字符)		所有输入流
//fputc			字符输出函数(一个字符)		所有输出流
//fgets			文本行输入函数(一行字符)		所有输入流
//fputs			文本行输出函数(一行字符)		所有输出流
//fscanf		格式化输入函数			所有输入流
//fprintf		格式化输出函数			所有输出流
//fread			二进制输入				文件
//fwrite		二进制输出				文件

//int main()
//{
//	FILE* pf = fopen("test.c", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ret=fgetc(pf);//当文件读取完后或者读取错误，会返回EOF ，即-1
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	/*int ret = fgetc(stdin);
//	fputc(ret,stdout);*/
//	
//	return 0;
//}
//int main()
//{
//	char arr[20] = { 0 };
//	FILE* pf = fopen("test.c", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fputs("sfsf\n", pf);//换行需手动输入
//	fputs("fsfaf\n", pf);
//	fputs("ffff\n", stdout);
//	//读文件
//	int n = 4;
//	fgets(arr, n, pf);//从pf中读取(n-1)个字符到arr中，实际上是读取（n-1）个字符，最后一个必须是\0。
//	fgets(arr, n, stdin);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	char arr[10];
//	int i;
//	char a;
//}s;
//int main()
//{
//	s = { "abvvv",5,'c' };
//	//对格式化的数据进行写文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fprintf(pf, "%s %d %c",s.arr,s.i,s.a);//比printf多了个FILE*，把arr内存中的数据输出到pf文件中
//	//读文件
//	fscanf(pf, "%s %d %c", s.arr, &(s.i), &(s.a));//比scanf多了个FILE*,把pf文件的内容输入到arr内存中
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//二进制读取写入
//struct S
//{
//	char arr[10];
//	int i;
//	float f;
//}s = {"anvnsndf",10,3.3f};
//int main()
//{
//	//二进制的形式书写和读取
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(&s, sizeof(struct S), 1, pf);//从Buffer中把最多为count个大小为elesize字节的内容写到流中
//	//注意：字符串二进制内容和文本内容一致，但整形二进制内容和二进制内容不一样，可以用fread来读取二进制内容
//	//读文件
//	//fread(&s, sizeof(struct S),1,pf);//从流中把最多个count个大小为elesize字节的内容写到Buffer中,返回值是读取的个数
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//sscanf  sprintf (对字符串而言）
//struct S
//{
//	char arr[10];
//	int i;
//	float f;
//}s = { "hello",10,2.2f };
//int main()
//{
//	//sprintf 把一个格式化的数据，转换成字符串
//	char buf[100];
//	sprintf(buf, "%s %d %f", s.arr, s.i, s.f);
//	printf("%s\n", a);
//
//	//sscanf 从buf字符串中还原出一个结构体数据
//	struct S tmp = { 0 };
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.i), &(tmp.f));
//	printf("%s %d %f", tmp.arr, tmp.i, tmp.f);
//	return 0;
//}

//scanf 针对标准输入的格式化的输入语句﹣ stdin
//fscanf 针对所有输入流的格式化的输入语句 - stdin /文件 
//sscanf 从一个字符串中读取一个格式化的数据
//printf 针对标准输出的格式化输出语句 - stdout
//fprintf 针对所有输出流的格式化输出语句 - stdout /文件
//sprintf 把一个格式化的数据，转换成字符串


//文件的随机读写

//fseek  - 根据文件指针的位置和偏移量来定位文件指针
//SEEK_CUR - 文件指针的当前位置
//SEEK_END - 文件指针指向文件结尾
//SEEK_SET - 文件指针指向文件开头
// 
//ftell - 返回文件指针相对于起始位置的偏移量
//rewind - 调整文件指针到文件的起始位置
//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读取文件
//	char ch = fgetc(pf);
//	printf("%c\n", ch);
//	int ret=ftell(pf);//1
//	printf("%d\n", ret);
//	//调整文件指针
//	fseek(pf, -1, SEEK_CUR);//从文件指针的当前位置偏移-1个字节，即向左偏移一个字节
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ret = ftell(pf);//1
//	printf("%d\n", ret);
//	fseek(pf, 10, SEEK_END);
//	rewind(pf);//调整文件指针到文件的起始位置
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ret=ftell(pf);
//	printf("%d\n", ret);
//	rewind(pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//文本文件和二进制文件
//
//根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
//数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是二进制文件。
//如果要求在外存上以 ASCII 码的形式存储，则需要在存储前转换。以 ASCII 字符的形式存储的文件就是文本文件。
//一个数据在文件中是怎么存储的呢？
//字符一律以 ASCII 形式存储，数值型数据既可以用 ASCII 形式存储，也可以使用二进制形式存储。
//如有整数10000，如果以 ASCII 码的形式输出到磁盘，则磁盘中占用5个字节（每个字符一个字节），而二进制形式输出，则在磁盘上只占4个字节（VS2013测试）。
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(&a, sizeof(int), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//文件读取结束的判定

//被错误使用的 feof
//牢记：在文件读取过程中，不能用 feof 函数的返回值直接用来判断文件的是否结束。而是应用于当文件读取结束的时候，判断读取失败结束，还是遇到文件尾结束。
//1．文本文件读取是否结束，判断返回值是否为 EOF(fgetc ) )，或者 NULL(fgets)
//例如：
//○ fgetc 判断是否为 EOF .
//○ fgets 判断返回值是否为 NULL
//2．二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
//例如：
//○ fread 判断返回值是否小于实际要读的个数。

//fgetc 函数在读取结束的时候，会返回 EOF
//正常读取的时候，返回的是读取到的字符的 ASCII 码值
//fgets 函数在读取结束的时候，会返回 NULL
//正常读取的时候，返回存放字符串的空间起始地址
//fread 函数在读取的时候，返回的是实际读取到的完整元素的个数
//如果发现读取到的完整的元素的个数小于指定的元素个数，这就是最后一次读取了。

//写代码把test.txt文件拷贝一份，生成text2.txt
//int main()
//{
//	FILE* pf = fopen("text.txt","r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	FILE* pf2 = fopen("text2.txt", "w");
//	if (pf2 == NULL)
//	{
//		fclose(pf);
//		perror("fopen2");
//		return 1;
//	}
//	int ch;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		//写文件
//		fputc(ch, pf2);
//	}
//	//判断是什么原因文件结束
//	if (feof(pf))
//		printf("遇到文件结束标志，文件正常结束\n");
//	else if (ferror(pf))
//		printf("文件读取失败结束\n");
//	fclose(pf);
//	pf = NULL;
//	fclose(pf2);
//	pf2 = NULL;
//	return 0;
//}

//文件缓冲区
//ANSIC 标准采用"缓冲文件系统"处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在使用的文件开辟一块"文件缓冲区"。
//从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。
//如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等)。
//缓冲区的大小根据 C 编译系统决定的。
//#include<windows.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", " w ");
//	fputs(" abcdef ", pf); //先将代码放在输出缓冲区
//	printf("睡眠10秒﹣已经写数据了，打开 test . txt 文件，发现文件没有内容\n "); 
//	Sleep(10000);
//	printf("刷新缓冲区\n ");
//	fflush(pf); //刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘） 
//	//注 fflush 在高版本的 vs 上不能使用了
//	printf("再睡眠10秒﹣此时，再次打开 test . txt 文件，文件有内容了\n "); 
//	Sleep(10000);
//	fclose(pf);
//	//注： fclose 在关闭文件的时候，也会刷新缓冲区 
//	pf = NULL;
//	return 0;
//}

//  程序的翻译环境和执行环境
// 
//在 ANSI C 的任何一种实现中，存在两个不同的环境
//第1种是翻译环境，在这个环境中源代码被转换为可执行的机器指令。
//第2种是执行环境，它用于实际执行代码
//详见微信2023.4.8.  21:06聊天记录

//预处理详解

//预定义符号
//int main()
//{
//	printf("%s\n", __FILE__);//进行编译的源文件路径
//	printf("%d\n", __LINE__);//当前的行号
//	printf("%s\n", __DATE__);//文件被编译时的日期
//	printf("%s\n", __TIME__);//文件被编译时的时间
//	printf("%s\n", __FUNCTION__);//当前函数所在的函数名
//	//printf("%s\n", __STDC__);//如果编译器遵循ANSI C，其值为1，否则未定义
//	//这些预定义符号都是语言内置的
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//fprintf(pf, "%s\n%d\n%s\n%s\n%s\n", __FILE__, __LINE__, __DATE__, __TIME__,__FUNCTION__);
//		fprintf(pf, "%s  %d  %s  %s  %s\n", __FILE__, __LINE__, __DATE__, __TIME__, __FUNCTION__);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#define 是定义符号的

//#define 定义标识符
//#define M 100;//注意分号也在替换中
//#define i int
//#define CASE break;case
//#define do_forever for(;;) //死循环
////也可以定义一个代码，如果stuff过长，可以分成几行写，除了最后一行外，每行的后面都加上一个反斜杠（换行符）
//#define pt printf("%s  %s %d",__FILE__,\
//							 __TIME__,\
//							__LINE__)
//int main()
//{
//	//i a;
//	//if (a = 1)
//	//	a = M //加分号就报错了
//	//else
//	//	printf("%d\n", a);
//	/*switch (1)
//	{
//		case 1:
//			printf("%d\n",1);
//		CASE 2:
//			;
//		CASE 3:
//			;
//	}*/
//	pt;
//	return 0;
//}

//#define 定义宏
//#define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro)或定义宏（define macro)。
//下面是宏的申明方式：
//#define name(parament-list) stuff 
//其中的 parament - 1ist是一个由逗号隔开的符号表，它们可能出现在 stuff 中
//注意:
//参数列表的左括号必须与 name 紧邻。
//如果两者之间有任何空白存在，参数列表就会被解释为 stuff 的一部分
//#define SQUARE(x) x*x  //SQUARE与(x)不能分开，x为参数
//#define DOUBLE(X) (X)+(X)
//int main()
//{
//	printf("%d\n", SQUARE(3));//9
//	printf("%d\n", SQUARE(3+1));//7 - 3+1*3+1
//	//宏的参数是完全替换的，参数是不进行任何计算的，直接传进去替换，替换后再计算
//	//如果要得到16，必须加括号：#define SQUARE(x) ((x)*(x)) 
//	//因此，在定义宏的时候括号很重要
//	printf("%d\n", 10 * DOUBLE(4));//44 - 10 * 4 + 4
//	//如果要得到期望的80，必须整体加括号：#define DOUBLE(X) ((X)*(X)) 
//	return 0;
//}

//# define 替换规则
//在程序中扩展＃ define 定义符号和宏时，需要涉及几个步骤。
//1．在调用宏时，首先对参数进行检查，看看是否包含任何由＃ define 定义的符号。如果是，它们首先被替换。
//2．替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
//3．最后，再次对结果文件进行扫描，看看它是否包含任何由＃ define 定义的符号。如果是，就重复上述处理过程。
//注意：
//1．宏参数和＃ define 定义中可以出现其他＃ define 定义的变量。但是对于宏，不能出现递归。
//2.当预处理器搜索＃ define 定义的符号的时候，字符串常量的内容并不被搜索。
//#define M 100
//#define MAX(X,Y) (X>Y?X:Y)
//int main()
//{
//	int max = MAX(101, M);
//	printf("%d\n", max);
//	printf("M==%d\n", M);//字符串常量的内容不会被替换，即“M”不会被替换
//	return 0;
//}

//# 和 ##  只能用于定义宏中  - 把参数插入到字符串中

//#参数  - 把一个宏参数变成所对应的字符串，不会把参数替换
//#define PRINT(X,FORMAT) printf("the value of "#X" is "FORMAT"\n",X)
//#X - X所对应的字符串
//"the value of "   #X相当于"a"    " is "  FORMAT相当于"%d"   "\n"
//int main()
//{
//	printf("abc""def""ghi\n");//printf（）中可以打印多个字符串
//
//	int a = 10;
//	PRINT(a,"%d");
//	printf("the value of ""a"" is %d\n", a);
//	int b = 20;
//	PRINT(b,"%d");
//	printf("the value of ""b"" is %d\n", b);
//	float f = 5.5f;
//	PRINT(f,"%f");
//	printf("the value of ""f"" is ""%f""\n", f);
//	return 0;
//}

//##  - 把位于它两边的符号合成一个符号
//它允许宏定义从分离的文本片段创建标识符
//#define CAT(X,Y) X##Y
//int main()
//{
//	int class101 = 10000;
//	printf("%d\n", CAT(class, 101));
//	printf("%d\n", class101);
//	return 0;
//}
//注：这样的链接必须产生一个合法的标识符，否则其结果就是未定义的。

//带副作用的宏参数
//当宏参数在宏的定义中出现超过一次的时候，如果参数带有副作用，那么你在使用这个宏的时候就可能出现危险，导致不可预测的后果。
//副作用就是表达式求值的时候出现的永久性效果。
// 
//宏和函数对比
//宏通常被应用于执行简单的运算。
//#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
//那为什么不用函数来完成这个任务？原因有二：
//1．用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。所以宏比函数在程序的规模和速度方面更胜一筹。
//2．更为重要的是函数的参数必须声明为特定的类型，所以函数只能在类型合适的表达式上使用。反之这个宏是可以适用于整形、长整型、浮点型等可以用于＞来比较的类型，宏是类型无关的。
//当然和宏相比函数也有劣势的地方：
//1．每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
//2．宏是没法调试的。
//3．宏由于类型无关，也就不够严谨。
//4．宏可能会带来运算符优先级的问题，导致程容易出现错。
//宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到。
//1.
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//2.
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	//x+1   不带有副作用
//	//x++   带有副作用
//	int a = 5;
//	int b = 8;
//	//1.
//	//int max = MAX(a++, b++);
//	//int max=((a++)>(b++)?(a++):(b++));
//	//printf("%d\n", max);//9
//	//printf("%d %d", a, b);//6  10
//	//2.
//	int max = Max(a++, b++);
//	//int max = (5 > 8 ? 5 : 8);
//	printf("%d\n", max);//8
//	printf("%d %d", a, b);//6  9
//	return 0;
//}
//命名约定
//一般来讲函数的宏的使用语法很相似。所以语言本身没法帮我们区分二者。
//那我们平时的一个习惯是：
//把宏名全部大写 , 函数名不要全部大写

//#undef  - 这条指令用于移除一个宏定义
//#define M 100
//int main()
//{
//	int a = M;
////#undef M
//	printf("%d\n", M);
//#undef M
//	return 0;
//}

//命令行定义
//许多 C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。
//例如：
//当我们根据同一个源文件要编译出不同的一个程序的不同版本的时候，这个特性有点用处。
//（假定某个程序中声明了一个某个长度的数组，如果机器内存有限，我们需要很小的数组，但是另外一个机器内存大些，我们需要一个数组能够大些。)

//条件编译

//1. #if 常量表达式   - 常量表达式由预处理器求值
//#if 0
//int main()
//{
//#if 1    //if 后面的表达式为真,下面参与编译，否则不参与编译
//	printf("hehe\n");
//#endif
//	return 0;
//}
//#endif

//2.多个分支的条件编译  - 只编译一个
//int main()
//{
//#if 1==1
//	printf("hehe\n");
//#elif 2==2
//	printf("haha\n");
//#else
//	printf("heihie\n");
//#endif
//	return 0;
//}

//3. 判断是否定义
//#define TEST
//int main()
//{
////如果TEST定义了，则下面参与编译
////1.
//#ifdef TEST
//	printf("test1\n");
//#endif
////2.
//#if defined(TEST)
//	printf("test2\n");
//#endif
//
////如果TEST未定义，则下面参与编译
////3.
//#ifndef TEST
//	printf("test3\n");
//#endif
////4.
//#if !defined(TEST)
//	printf("test4\n");
//#endif
//
////1==2   3==4   1和3相反  2和4相反
//	return 0;
//}

//4. 嵌套指令
//#define TEST
//#define TEST1
//#define TEST2
//int main()
//{
//#if defined(TEST)
//	#ifdef TEST1
//		printf("hehe\n");
//	#endif
//	#ifdef TEST2
//	printf("haha\n");
//	#endif
//
//#elif defined(TEST3)
//	#ifdef TEST4
//	printf("en\n");
//	#endif
//#endif
//
//	return 0;
//}

//文件包含

// ""h和<>包含头文件的本质区别是：查找的策略区别
//1. 本地文件包含 - 自定义的函数的头文件使用 ""
//“”查找策略: 先在自己源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。
//如果找不到就提示编译错误。
//2. 库函数包含  - C语言库中提供的函数的头文件使用<>
//<> 查找策略：直接去库函数头文件所在目录下查找 

//嵌套文件包含
//如何防止多次重复包含头文件
//每个头文件的开头写
//1. #pragam once  
//2. #ifndef __TEST_H__
//	 #define __TEST_H__
//	（头文件内容）
//	 #endif


