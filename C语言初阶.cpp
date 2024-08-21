#include <stdio.h>

//enum sex
//{
//	male,
//	famale,
//	secret
//};
//int main()
//{
	//printf("%d\n" ,male);
	//printf("%d\n", famale);
	//printf("%d\n", secret);
	//return 0;


	//int num1 = 0;
	//int num2 = 0;
	//int sum = 0;


	//scanf("%d%d", &num1, &num2);
	//sum = num1 + num2;
	//printf("sum = %d/n", sum);

	//return 0;



////}
//#define max 2
#include <string.h>
#include<windows.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>
#include<assert.h>






//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6 };
//	//for (i = 0; i <= 12; i++)
//	//{
//	//	arr[i] = { 0 };
//	//	printf("%d\n", i);//局部变量存放在栈区，习惯是先从高地址存放，由高往低存放；但是release版本会对代码进行优化，i的地址低于arr的地址
//	//}
//	printf("%p\n", &i);
//	printf("%p\n", arr);
//	return 0;
//}
//int main()//交换两个数的值，不建立临时变量
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}
//int main()//从左向右依次打印n的二进制位中的偶数位和奇数位
//{
//	int i = 0;
//	int a = 0;
//	scanf("%d", &i);
//	//打印偶数位
//	for (a = 31; a >= 1; a -= 2)
//	{
//		printf("%d  ", (i >> a) & 1);
//	}
//	printf("\n");
//	//打印奇数位
//	for (a = 30; a >= 0; a -= 2)
//	{
//		printf("%d  ", (i >> a) & 1);
//	}
//	return 0;
//}
//int main()//计算两个数的二进制位不同的个数
//{
//	int m, n;
//	int count = 0;
//	scanf("%d%d", &m, &n);
//	/*for (int i = 0; i < 32; i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			count++;
//		}
//
//	}*/
//	int ret = m ^ n;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int cifang2(int n)//计算是不是2的n次方，（n为正整数）
//{
//	if ((n & (n - 1)) == 0)
//		return 1;
//}
//int main()
//{
//	int i = 8;
//	int a = cifang2(i);
//	if (a == 1)
//	{
//		printf("是2的次方\n");
//	}
//	else
//	{
//		printf("不是2的次方\n");
//	}
//	return 0;
//}
//int Number1(int a)//计算二进制补码中的1的个数
//{
//	int count = 0;
//	while (a)
//	{
//		a = a & (a - 1);
//		count++;
//	}
//	return count;
//}
//int Number1(int a)//计算二进制补码中的1的个数
//{
//	int b = 0;
//	int count = 0;
//	for (b = 0; b < 32; b++)
//	{
//		if (((a >> b) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int i = -1;
//	int ret = Number1(i);
//	printf("%d\n", ret);
//	return 0;
//}
//int main()
//{
//	int a = -1;
//	int b = a % 2;
//	printf("%d\n", b);
//	return 0;
//}
//size_t my_strlen(const char* p)//size_t是unsigned int  无符号整型
//{
//	assert(p != NULL);
//	size_t ret = 0;
//	while (*p++ != '\0')
//	{
//		ret++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[10] = "fjkad";
//	int a = my_strlen(arr1);
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int m = 20;
//	int n = 10;
//	const int* p = &m;
//	printf("%d\n", *p);
//	p = &n;
//	printf("%d\n", *p);
//	return 0;
//}
//int main()
//{
//	int n = 10;
//	int m = 100;
//	int* const p = &n;//const修饰指针变量的时候，在*的右边，修饰指针变量，不能改变指针变量
//	//*p = 100;
//	//p = &m;
//	//int** paa = &p;//二级指针const能放的位置有三种……
//	//**paa = 1;
//	const int* pa = &m;//如果在*的左边，表示指针所指向的内容，不能通过指针来改变
//	//*pa = 1;
//	pa = &n;//指针pa所指向的内容并不会改变！
//	printf("%d\n", m);
//	return 0;
//}
//char* mystrcpy(char* a1,const char* a2)//const修饰变量 不能被修改，但本质上还是变量；修饰指针变量的时候，在*的左边，表示指针所指向的内容，不能通过指针来改变，如果在*的右边，修饰指针变量，不能改变指针变量
//{
//	assert(a1 != NULL);//断言：表达式为假就报错，利于调试时发现错误位置
//	assert(a2 != NULL);
//	char* ret = a1;
//	while (*a1++ = *a2++)//既copy了‘\0’，又停止
//	{
//		;
//	}
//	return ret;//strcpy返回值是目标空间的起始地址
//}
//void mystrcpy(char* a1, char* a2)
//{
//	do
//	{
//		*a1 = *a2;
//		a1++;
//		a2++;
//	} while (*a2 != '\0');
//	*a1 = *a2;
//}
//int main()
//{
//	char arr1[10] = { "xxxxxxxxx" };
//	char arr2[] = { "hello" };
//	//mystrcpy(arr1, arr2);
//	//printf("%s\n",arr1);
//	printf("%s\n", mystrcpy(arr1, arr2));//strcpy返回值是目标空间的起始地址
//	return 0;
//}
//struct stu
//{
//	char a[20];
//	int b;
//	double c;
//};
//void print1(struct stu t)
//{
//	printf("%s  %d  %lf\n", t.a, t.b, t.c);
//}
//void print2(struct stu* p)
//{
//	printf("%s  %d  %lf\n", (*p).a, p->b, p->c);
//}
//int main()
//{
//	struct stu s1 = { "232",45,3.3 };
//	print1(s1);//传值调用    浪费空间，效率低，但不会改变s1内部的值
//	print2(&s1);//传址调用    节省空间，效率高，并且可以该病s1内部的值
//	//上面的print1和print2函数哪个好些？答案是：首选print2函数。
//	//原因：函数传参的时候，参数是需要压栈的。如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。
//	//结论：结构体传参的时候，要传结构体的地址。
//	
//	//函数调用的参数压栈：
//	//栈，是一种数据结构
//	//	先进的后出，后进的先出
//	//	压栈：向栈中存放数据
//	//	出栈：从栈中删除数据
//	return 0;
//}

//struct a
//{
//	char a;
//	int b;
//}a1 = {'2',4};//a1是全局变量
//struct stu
//{
//	struct a a1;
//	char name[20];
//	int a;
//	char id[20];
//	struct stu* pa;
//}s1 = { {'s',5},"三十",18,"23232",NULL};//s1是全局变量；
//int main()
//{
//	struct stu s2;//s2是局部变量
//	//printf("%s", s1.name);
//	//printf("%c", s1.a1.a);
//
//	struct stu* p = &s1;
//	printf("%c\n", (*p).a1.a);
//	printf("%d\n", p->a1.b);
//	printf("%c\n", a1.a);
//	printf("%d\n", a1.b);
//	return 0;
//}
//int main()
//{
//	int arr[10];//整形数组：存放整形的数组
//	char ch[10];//字符数组
//	//指针数组：存放指针的数组
//	int* pa[3];
//	char* ppa[2];
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int* pa = &a;//这里pa也是个变量，是指针变量，一级指针，是变量就有自己的地址
//	*pa = 1;
//	//二级指针
//	int** ppa = &pa;//pa是变量，&pa是取出pa在内存中的起始地址
//	**ppa = 2;
//	//三级指针
//	int*** pppa = &ppa;
//	***pppa = 3;
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 2,3,4,5,6,7,0,8,9 };
//	int* p = arr;
//	printf("%d\n", arr[2]);
//	printf("%d\n", 2[arr]);
//	printf("%d\n", 2[p]);
//	printf("%d\n", p[2]);
//	//[]是一个双目操作符，2[arr]中2和arr是两个操作数
//	//arr[2] --> *(arr+2) --> *(2+arr) --> 2[arr]
//	//arr[2] --> *(arr+2) --> *(p+2) --> *(2+p) --> 2[p] --> p[2]
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%p  %p  %p \n", &arr[i], p + i, arr + i);//下标为i的地址
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3] = { 0,2,3 };
//	int* p = arr;
//	/*for (p = &arr[2]; p >= &arr[0]; p--)
//	{
//		*p = 0;//实际上绝大部分编译器都可以执行，然而应避免写这样的代码。
//			   //标准规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针进行比较，但是不允许与指针第一个元素之前的那个内存位置的指针进行比较
//	}*/
//	//for (p = &arr[3]; p > &arr[0];)
//	//{
//	//	*--p = 0;
//	//}
//	/*for (p = &arr[0]; p < &arr[3];p++)
//	{
//		*p = 0;
//	}*/
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 2,3,4,5,6 };
//	int* p = arr;
//	int* pa = arr + 1;
//	printf("%p\n", p);
//	printf("%p\n", pa);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", &arr[6] - &arr[0]);//两个指针相减 结果是两个地址之间的元素个数；前提是两个指针指向同一块空间，不能是不同的空间 
//	return 0;
//}
//int mystrlen(char* str)
//{
//	int count = 0;
//	char* start = str;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return str - start;//两个指针相减 结果是两个地址之间的元素个数；前提是两个指针指向同一块空间，不能是不同的空间
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = mystrlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int* pend = arr + 9;
//	while (p <= pend)
//	{
//		printf("%d\n", *p);
//		p++;
//	}
//	return 0;
//}
//int* test()
//{
//	int a = 1;
//	return &a;//a是局部变量，出去就销毁了
//}
//int main()
//{
//	//野指针
//	
//	//1. 这里p就是一个野指针
//	//int* p;//p是一个局部的指针变量，局部变量不初始化的话，默认是随机值
//	//*p = 20;//非法访问内存
//
//	//2. 越界指针也是野指针
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//int i;
//	//for (i = 0; i <= 10; i++)//循环11次，而arr只有10个元素，最后一个越界了
//	//{
//	//	*p = i;
//	//	p++;
//	//}
//
//	//3. 指针指向的空间释放
//	//int* p = test();
//	//*p = 20;
// 
//	//为了避免出现野指针：
//	//1.指针初始化（不知道初始化对象时  可以先初始化空指针int* p=NULL;但空指针没有地址，不能对其进行使用)  2.小心指针越界  3.指针指向释放空间及时放置NULL  4.指针使用之前检查有效性
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;//p+i 是下标为i的地址
//	}
//	//int a = 0x11223344;
//	//int* p = &a;
//	//char* pa = &a;
//	//*pa = 0;//指针类型决定了指针的权限有多大
//	//printf("%c", p);
//	//printf("%c", p+1);//+4   
//	//printf("%c", pa);
//	//printf("%c", pa+1);//+1    指针类型决定了，指针走一步，能走多远（步长）。 
//	return 0;
//}
//void print(int a[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d  ", a[i]);
//	}
//	printf("\n");
//}
//void change(int arr1[], int arr2[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 5,6,7,8 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	change(arr1, arr2, sz);
//	print(arr1, sz);
//	print(arr2, sz);
//	return 0;
//}
//void init(int a[],int sz)
//{
//	int i;
//
//	for (i = 0; i < sz; i++)
//	{
//		a[i] = 0;
//	}
//}
//void print(int a[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d  ", a[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int i = 0;
//	int j = sz / 2;
//	for (i = 0; i < j; i++)
//	{
//		int tmp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i-1] = tmp;
//	}
//	//int left = 0;
//	//int right = sz-1;
//	//while (left < right)
//	//{
//	//	int tmp = arr[left];
//	//	arr[left] = arr[right];
//	//	arr[right] = tmp;
//	//	left++;
//	//	right--;
//	//}
//}
//int main()
//{
//	int arr[] = {1,2,3,3,1,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	reverse(arr, sz);//对数组进行逆置
//	print(arr, sz);
//	init(arr,sz);
//	print(arr, sz);
//	return 0;
//}

//int main()
//{
//	short c = 12;
//	printf("%d\n", sizeof(c));
//	printf("%d\n", sizeof(!c));//!这里属于编译器的问题，在gcc里是4，vs是1
//	printf("%d\n", sizeof(-c));//char和short只要进行运算就会整型提升
//	printf("%d\n", sizeof(+c));
//	return 0;
//}
//int main()
//{
//	char a = 3;
//	char b = 127;//char 一个字节，8位，存的是-128~127！
//	char c = a + b;//因为char和short小于int类型的字节，且CPU内是按int来进行运算，为了提高精度，这里就会先进行“整形提升”！高位补符号位：正数高位补0，负数高位补1，无符号为补0
//	printf("%d\n", c);
//	return 0;
//}
//struct person 
//{
//	char name[20];
//	float longth;
//	int length;
//
//};
//int main()
//{
//	struct person a = { "蔡文俊",150,120};
//	struct person* pa = &a;
//	printf("%s\n", (*pa).name);
//	printf("%f\n", pa->longth);
//	printf("名字：%s\n", a.name);
//	printf("身高：%f\n", a.longth);
//	printf("体重：%d\n", a.length);
//	return 0;
//}
//int main()
//{
//	printf("%d", (2, 2 + 1, 66));//逗号表达式：从左到右依次进行，整个表达式的结果是最后一个表达式的结果！
//	return 0;
//}
//int main()
//{
//	int a = 0, b = 0, c = 1, d = 2;
//	//a = b++ && ++c && d++;/从左往右运算，有一个为假后面的就不运算了，但本身要递增
//	a = b++ || ++c || d++;//从左往右运算，有一个为真后面的就不运算了，但本身要递增
//	printf("%d %d %d ", b, c, d);
//	return 0;
//}
//int main()
//{
//	int a = 11;
//	int c = 15;
//	int b = a | (1<<2);//“~”按位取反。
//	int d = c & (~(1 << 2));
//	int e = c ^ (1 << 2);
//	printf("%d  %d  %d ", b,d,e);
//	printf("%d  ", sizeof(a = ++a));//sizeof()单目操作符，括号内的运算没有真正进行
//	printf("%d ", a=++a);//++a先++，再使用；a++先使用，再++
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	int a;
//	scanf("%d", &a);
//	//for (int i = 0; i < 32; i++)
//	//{
//	//	if (1 == ((a >> i) & 1))
//	//		count++;
//	//}
//	while (a)
//	{
//		count++;
//		a = a & (a - 1);
//	}
//	printf("%d", count);
//	return 0;
	//int a = 3;
	//int b = 5;
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;
	//printf("%d %d", a, b);
	//return 0;
	//int a = 6;
	//int b = a << 30;
	//printf("%d\n", b);
	//return 0;
//}
//int main()
//{
//	int arr[] = { 0,1,2,3,4,1,2,4,3 };
//	int i;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret = ret ^ arr[i];
//	}
//	printf("%d\n", ret);
//	//for (i = 0; i <sz ; i++)
//	//{
//	//	int j;
//	//	int count = 0;
//	//	for (j = 0; j < sz; j++)
//	//	{
//	//		if (arr[i] == arr[j])
//	//		{
//	//			count++;
//	//		}
//	//	}
//	//	if (count == 1)
//	//	{
//	//		printf("%d\n", arr[i]);
//	//		break;
//	//	}
//	//}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 0,2,3,4 };
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("%d\n", *arr);
//	//数组名是首元素地址！！！但是有两个例外！
//	//1.sizeof(数组名)是计算整个数组的大小，单位为字节。
//	//2.&数组名，是取出整个数组的地址，数组名代表整个数组。整个数组的地址其实是首元素的地址。
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1);
//	return 0;
//
//}
//void paixu(int* pa,int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (int a = 0; a < (sz-i-1); a++)
//		{
//			if (pa[a] > pa[a+1])
//			{
//				int tmp;
//				tmp = pa[a];
//				pa[a] = pa[a+1];
//				pa[a+1] = tmp;
//				j++;
//			}
//		}
//		if (j == 0)
//			break;
//	}
//}
//int main()
//{
//	int arr[] = { 2,3,1,5,2,5,6,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	paixu(arr,sz);
//	for (int b = 0; b < sz; b++)
//	{
//		printf("%d ", arr[b]);
//
//	}
//	return 0;
//}
//int main()
//{
//	printf("%d  %d", (100, 200,2,2,2,4,4,5,6),3);
//	return 0;
//}
//int main()
//{
//	char a[][3] = { {1,2},{123,2,2},1,2,3,4 };
//	int i;
//	for (i = 0; i < 4; i++)
//	{
//		int j;
//		for (j = 0; j < 3; j++)
//		{
//			printf("&a[%d][%d]=%p\n", i, j, &a[i][j]);
//		}
//	}
//	return 0;
//}
//int feibo(int i)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (i >= 3)
//	{
//		c = a + b;
//		a = b; b = c;
//		i--;
//		
//	}
//	return c;
//}
//int feibo(int i)
//{
//	if (i <= 2)
//		return 1;
//	else
//		return feibo(i - 1) + feibo(i - 2);
//}
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	feibo(i);
//	printf("%d ", feibo(i));
//	return 0;
//}
//int jie(int n)
//{
//	if (n > 0)
//	{
//		return n * jie(n - 1);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	jie(n);
//	printf("%d\n", jie(n));
//	return 0;
//}
//int len(char* p)
//{
//	if (*p != '\0')
//	{
//		return 1 + len(++p);//不能p++？！！！可以p+1.因为++在后会先执行str，此时往下进行的实际一直是str，导致每次递归没有逼近结束值，最后以栈溢出结束
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = { "aaa" };
//	len(arr);
//	printf("%d\n", len(arr));
//	return 0;
//}
//void print(int a)
//{
//	if (a > 9)
//	{
//		print(a/10);
//
//	}
//	printf("%d ", a % 10);
//}
//int main()
//{
//	unsigned int i;
//	scanf("%d", &i);
//	print(i);
//	return 0;
//}
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 22)));//printf函数的返回值为字符的个数。
//	return 0;
//}
//void function(int* pa)
//{
//	*pa+=1;
//	(*pa)++;//不能直接*p++，这是直接对地址加1了。。。
//}
//int main()
//{
//	int a=0;
//	function(&a);
//	printf("%d\n",a);
//	return 0;
//}
//int serch(int x[],int c,int sz)
//{
//	
//	int left = 0;
//	int right = sz-1;
//	while(left<=right)
//	{
//		int mid = (left+right) / 2;
//		if (c > x[mid])
//		{
//			left = mid + 1;
//		}
//		else if (c < x[mid])
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return 1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int c;
//	scanf("%d", &c);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret=serch(arr, c,sz);
//	if (ret == 1)
//		printf("没有找到了，\n");
//	else
//		printf("找到了，下标是%d\n", ret);
//	return 0;
//}
//int pd(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//		return 1;
//}
//int main()
//{
//	int i;
//	for (i = 1000; i <= 2000; i++)
//	{
//		pd(i);
//		if (pd(i) == 1)
//			printf("%d ", i);
//
//	}
//	return 0;
//}
//int pd(int x)
//{
//	int i;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//			return 0;
//			//break;
//	}
//	return 1;
//	//if (i > sqrt(x))
//	//	return 1;
//	//else
//	//	return 0;
//}
//int main()
//{
//	int a;
//	//scanf("%d", &a);
//	for(a = 101; a <= 200; a+=2)
//	{
//		int b = pd(a);
//		if (b == 1)
//			printf("%d是素数\n", a);
//		else
//			printf("%d不是素数\n", a);
//	}
//
//	return 0;
//}
//void EX(int* pa, int* pb)
//{
//	int temp;
//	temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	EX(&a, &b);
//	printf("%d  %d", a, b);
//	return 0;
//}
//void EX(int x, int y)
//{
//	int temp;
//	temp = x;
//	x = y;
//	y = temp;
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	printf("%d %d", a, b);
//	EX(a, b);
//	printf("%d  %d", a, b);
//	return 0;
//}
//int MAX(int x, int y)
//{
//	if (x <= y)
//		return y;
//	else
//		return x;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int max = MAX(a, b);
//	printf("%d\n", max);
//	printf("%d  %d", a, b);
//	return 0;
//}
//int main()
//{
//	char arr1[] = "aaaaaaa";
//	char arr2[20] = "1323567575";
//	strcpy(arr2, arr1);
//	printf("%s \n", arr2);
//	return 0;
//}
//int main()
//{
//	int a = 3;
//	while (1)
//	{
//
//		printf("%d\n", a);
//		goto aaa;
//	}
//	aaa:
//	return 0;
//}
//void test()
//{
//	static int b = 0;
//	b++;
//	printf("%d\n", b);
//void menu()
//{
//	printf("***************************************\n");
//	printf("**** 1.进入游戏    2.退出游戏  *****\n");
//	printf("***************************************\n");
//
//}
//void game()
//{
//	rand();
//	int a = rand();
//	int b;
//	while (1)
//	{
//		printf("输入数字->");
//		scanf("%d", &b);
//		if (b == a % 100 + 1)
//		{
//			printf("选对啦\n");
//			break;
//		}
//		else if (b < a % 100 + 1)
//			printf("小啦！行不行啊？！\n");
//		else
//			printf("大啦！白得！\n");
//	}
//
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int i = 0;
//	do
//	{
//		menu();
//		scanf("%d", &i);
//		switch (i)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("再见\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		
//		}
//
//	} while (i);
//	return 0;
//}
//int main()
//{
//	rand();
//	int i = 0;
//	int a = rand();
//	srand((unsigned int)time(NULL));
//
//	while (1)
//	{
//		scanf("%d", &i);
//		if (a < i)
//			printf("大了\n");
//		else if(a>i)
//			printf("小了\n");
//		else
//		{
//			printf("对了\n");
//			printf("是否再来一局？->Y/N");
//			int b;
//			scanf("%d", &b);
//			if (b == 'N')
//				break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int a = 1;
//	int n;
//	for (; i <= 9; i++)
//	{
//		for (a = 1; a <= i; a++)
//		{
//			n = a * i;
//			printf("%d*%d=%-2d      ", a, i, n);
//		}
//		printf("\n");
//		//if (a == i)
//		//{
//		//	n = a * i;
//		//	printf("%d*%d=%d\n", i, a, n);
//
//		//}
//
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { -2,45, 3, 2, 1 };
//	int max = arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 1;
//	for (; i < sz; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	double sum = 0;
//	int flag = 1;
//	for (; i <= 100; i++)
//	{
//		sum += flag * (1.0 / i);
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//int main()
//{
//	double a = 0;
//	int i = 1;
//	double b = 0;
//
//	for (; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			b = b - 1.0 / i;
//		}
//		else
//		{
//			a = a + 1.0 / i;
//		}
//		double c = a + b;
//		if (i == 100)
//			printf("%lf\n", c);
//	}
//
//	return 0;
//
//}
//int main()
//{
//	int a = 1;
//	int i = 0;
//	for (; a <= 100; a++)
//	{
//		if (a % 10 == 9)
//			i++;
//		if (a/10 == 9)
//			i++;
//
//	}
//	printf("%d\n", i);
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	for (; a <= 100; a++)
//	{
//		if (a % 3 == 0)
//			printf("%d  ", a);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 100;
//	int b = 0;
//	int i = 0;
//	for (a=101; a <= 200; a+=2)
//	{
//		for (i = 2; i <=sqrt(a); i++)
//		{
//			if (a % i != 0)
//				continue;
//			else
//				break;
//		}
//		if (i > sqrt(a))
//		{
//			b++;
//			printf("%d  ", a);
//		}
//	}
//	printf(" \n共有%d个", b);
//	return 0;
//}
//int main()
//{
//	int i = 1000;
//	int a = 0;
//	for (; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0)||i%400==0)
//		{
//			printf("%d  ", i);
//			a++;
//		}
//		//if (i % 400 == 0)
//		//{
//
//		//	printf("%d  ", i);
//		//	a++;
//		//}
//	}
//	printf("\n共有%d个\n", a);
//	return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	while (a%b)
//	{
//		int i = a % b;
//		a = b;
//		b = i; 
//	}
//	printf("%d\n", b);
//
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		int i = a;
//		a = b;
//		b = i;
//	}
//	if (a < c)
//	{
//		int i = a;
//		a = c;
//		c = i;
//	}
//	if (b < c)
//	{
//		int i = b;
//		b = c;
//		c = i;
//	}
//	printf("%d  %d  %d", a, b, c);
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a >= b && a >= c)
//	{
//		printf("%d>", a);
//		if (b >= c)
//			printf("%d>%d", b, c);
//		else
//			printf("%d>%d", c, b);
//	}
//	else if (b >= a && b >= c)
//	{
//		printf("%d>", b);
//		if (a >= c)
//			printf("%d>%d", a, c);
//		else
//			printf("%d>%d", c, a);
//
//	}
//	else
//	{
//		printf("%d>", c);
//		if (b >= a)
//			printf("%d>%d", b, a);
//		else
//			printf("%d>%d", a, b);
//	}
//		
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int b = 2;
//	char arr1[22] = { 0 };
//	for (;i < 3; i++)
//	{
//		printf("请输入密码：\n");
//		scanf("%s", arr1);
//		if (strcmp(arr1,"123")==0)
//		{
//			printf("right");
//			break;
//		}
//		else
//		{
//			printf("输入错误，剩余次数%d\n",b);
//			b--;
//		}
//	}
//	if (i == 3)
//		printf("wrong");
//	return 0;
//}
//int main()
//{
//	char arr1[] = "wwwwwwwwwwwww";
//	char arr2[] = "#############";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		system("cls");
//		printf("%s\n", arr2);
//		Sleep(1000);
//		left++;
//		right--;
//	}
//	//printf("%s\n", arr2);
//
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int i;
//	scanf("%d", &i);
//	for (;left<=right;)
//	{
//		int mid = (left + right) / 2;

//		if (arr[mid] < i)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > i)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到%d了，下标是%d", i, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("没有找到%d", i);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int j = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	scanf("%d", &i);
//	for (; j < sz; j++)
//	{
//
//		if (i != arr[j])
//			continue;
//		printf("找到%d了\n", arr[j]);
//		break;
//	}
//	if (j == sz)
//		printf("没找到%d\n",arr[j]);
//	return 0;
//}
//int main()
//{
//	int a, b, c, d;
//	d = 0;
//	c = 1;
//	for (a = 1; a <= 10; a++)
//	{
//		c = c * a;
//		//c = 1;
//		//for (b = 1; b <= a; b++)
//		//{
//		//	c = c * b;
//		//}
//		d = d + c;
//	}
//	printf("%d\n", d);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int n;
//	int j = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		j = j * i;
//	}
//	printf("%d\n",j);
//	return 0;
//}
//int main()
//
//{
//	int x = 0;
//	int y = 0;
//	y = ++x;
//	printf("%d  %d", x,y);
//	//int i;
//	//for (i=1; i <= 10; i += 2)
//	//{
//	//	printf("%d  ",i);
//	//}
//	return 0;
//}

//int main()
//{
//	int ret = 0;
//	char password[20] = { 0 };
//	scanf("%s", password);
//	//while ((getchar()) != '\n')
//	//{
//	//	;
//	//}
//	printf("是否确认-》Y/N\n");
//	ret = getchar();
//	if (ret == 'Y')
//		printf("完成输入");
//	else
//		printf("退出输入");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	while ((a = getchar()) != EOF)
//		putchar(a);
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	while (a <= 10)
//	{
//		printf("%d \n", a);
//		a++;
//	}
//		return 0;
//}

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	default:
//		printf("输入错误");
//		break;
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日");
//		break;
//	case 6:
//	case 7:
//		printf("休息日");
//		break;
//
//	}
//	int a = 0;
//	while(a<=100)
////	scanf("%d\n", &a);
//	if (a % 2 == 1 && a<=100)
//	{		printf("奇数%d\n",a);
//	a++;
//	}
//	else 
//	{
//		printf("偶数%d\n",a);
//		a++;
//	}
//	return 0;
	//int a = 2;
	//int b = 5;
	//if (a == 1)
	//	;
	//else if (1==b)
	//		printf("ww");
	//	else
	//		printf("ddd");
	//int length = 10;
	//if (length < 150)
	//{
	//	printf("侏儒症\n");
	//	printf("要治疗\n");
	//}
	//else if (length >= 150 && length < 200)
	//	printf("正常人\n");
	//else
	//	printf("不正常");
	//return 0;
//struct people
//{
//	char name[10];
//	int age;
//	int length;
//};
//int main()
//{
//	struct people a = { "陈冉",18,175 };
//	struct people* p = &a;
//	printf("%d\n", p->age);
//	printf("%d\n", (*p).length);
//	printf("名字：%s\n", a.name);	
//	printf("年龄：%d\n", a.age);
//	a.length = 180;	
//	printf("身高：%d\n", a.length);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* c = &a;
//	*c = 30;
//	printf("%d\n", sizeof(c));
//	printf("%p\n", c);
//	return 0;
//}
	
	//int a = 5;
	//while (a < 10)
	//{
	//	test();
	//	a++;
	//}
	//printf("%d\n", a);
	//return 0;
	//
//int main()
//{typedef int au;
//
//	unsigned int a = -2;
//	au b = 1;
//	int c = a + b;
//	printf("%u\n", c);
//	return 0;
//}
	
	//int a = 10;
	//int b = 20;
	//int max = (a > b ? a : b);
	//printf("%d\n", max);
	//return 0;

	//int a = 3;
	//int b = 4;
	//int c = a ^ b;
	//printf("%d\n", c);

	//return 0;
//}
//int main() {
//	int a = 1;
//	int b = a++;
//	int c = ++a;
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//int main()
//{
//	int a = (int)2.2;
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = ~a;
//  无论0或1，异或1取反，异或0不变
//  异或性质：异或两次不变
//	printf("%d\n", b);
//	return 0;
//}
//int main()
//{
//	int A[] = { 0,1,2,3,4,5,6 };
//	printf("%d\n", sizeof(A) / sizeof(A[2]));
//	return 0;
//}
//int MAX(int x, int y)
//{
//	if (x < y)
//		return y;
//	else
//		return x;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int max = 0;
//	scanf("%d %d", &a,&b);
//	max = MAX(a, b);
//	printf("最大值=%d\n",max);
//	//if (a <= b)
//	//	printf("%d\n", b);
//	//else
//	//	printf("%d\n", a);
//
//	return 0;
//}
//int main()
//{
//	int a = 5;//101
//	int b = 4;//100
//	int c = a ^ b;
//	printf("%d", c);
//	return 0;
//}
//
// 
//int main()
//{
//	int a = 3;
//	int b = a << 2;
//	printf("%d", b);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	printf("%d\n", a);
//	printf("%d", ~a);
//	return 9;
//}
////
//
//int main()
//{
//	int ar[10] = { 0,1,3,4,5,2,5,6,7,8 };
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d ",ar[i]); 
//		i++;
//	}
//	/*printf("%d\n", ar[4]);*/
//
//	return 0;
//
//}

//int add(int x, int y)
//{
//	int z = x +  y;
//	return z;
//}
//int main()
//{
//	int sum = 0;
//	int a = 100;
//	int b = 200;
//	sum = add(a, b);
//	printf("sum = %d\n", sum);
//	return 0;
	//int line = 0;
	//printf("练习C语言\n");
	//while (line < 20000)
	//{
	//	printf("练习一行代码：%d\n", line);
	//	line++;
	//}
	//if (line >= 20000)
	//	printf("过上幸福生活\n");
	//return 0;



	//int a = 0;
	//printf("你是煞笔吗？\n");
	//scanf("%d", &a);
	//if (a == 0)
	//	printf("相信自己能行\n");
	//else
	//	printf("你就是一个大傻子\n");
	//return	0;


	/*	a==0
		printf("大傻子")；*/


	//printf("\11");
	// 
	/*char  arr1[] =  "abc" ;
	char  arr2[] = { 'a','b','c',97,};
	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));


	printf("%s\n", arr1);
	printf("%s\n", arr2);*/
	//return 0;


	//int a[] = { 0 };
	//printf("%d\n", a);
	//return 0;

//}
