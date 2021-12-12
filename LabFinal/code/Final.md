## Self-introduction

- I'm Qing Gao, a student from SMU. This page is used to display the learning results of smu7345. Through this course, I achieved:

1. Building and Analyzing an Emscripten Library / Application.
2. Building a JS library using WebIDL and Emscripten 
3. Building a Multithreaded JS library using Emscripten 
4. Networking with Emscripten
5. Packaging the web into a local app

***If you want to download the complete lab code, data and report***

***[Click Here](https://github.com/Gianna1223/7345Labs.git)***



## Achievement display

### Lab one 

> **Building and Analyzing an Emscripten Library / Application**
>
> > ***overlook***
> >
> > 1. Setup the Emscripten pipeline
> > 2. Verify with hello world project
> > 3. Compare and Contrast execution time between native and wasm based code bases

#### 1. Setup the Emscripten pipeline 

- Download emsdk through git's clone command

`git clone https://github.com/emscripten-core/emsdk.git`

- Enter folder

`cd emsdk`

- Get the latest emsdk version

`git pull`

- Download and install the latest tools

`./emsdk install latest`

- Activate tool

`./emsdk active latest`

- Run to see if the installation is successful

`emcc -v`

![image-20211212093119262](https://tva1.sinaimg.cn/large/008i3skNgy1gxasoar1t1j31z40dgq6d.jpg)

- **Now you have already install the Emscripten successfully!~**

- **If you want to get more information about emscripten, please visit the [Emscripten](https://emscripten.org/) official website** 

  

#### 2. Verify with hello world project

- Create c++ file

```c++
int main(int argc, char ** argv) {
  printf("Hello World\n");
}
```



- Run `emcc hello.c -s WASH=1 -o hello.html`

>Error: ‘zsh command not found: emcc’
>
>Reason: EMCC is not configured in the current path
>
>Solution：Put the hello.c file into emsdk file, and active the emcc

a. Enter emsdk file environment, and activate environment variable

![image-20211212093640106](https://tva1.sinaimg.cn/large/008i3skNgy1gxastu4474j31z405gab2.jpg)

b. Go back to the file path where hello.c is located, and run

![image-20211212093649718](https://tva1.sinaimg.cn/large/008i3skNgy1gxastyypdhj31z402idgb.jpg)

c. File generated successfully

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gxasu58a5sj31gw0u0wgi.jpg" alt="image-20211212093658950" style="zoom:25%;" />

d. Open file with browser

![image-20211212093712458](https://tva1.sinaimg.cn/large/008i3skNgy1gxasudivabj31z40nkt9y.jpg)



#### 3. Compare and Contrast execution time between native and wasm based code bases

- This figure shows the running time of C + + code and converted code

![image-20211212094424657](https://tva1.sinaimg.cn/large/008i3skNgy1gxat1vhaj4j31z407qdhe.jpg)

- These two figures show the analysis of data after many experiments

![截屏2021-12-12 上午9.47.22](https://tva1.sinaimg.cn/large/008i3skNgy1gxat59aauvj31bc0sidl1.jpg)



### Lab Two

> **Building a JS library using WebIDL and Emscripten**
>
> > ***Overlook***
> >
> > 1. UML and overlook of this code
> > 2. Specific codes and explanations
> > 3. Compare and Contrast execution time of the library code between demo application and comparison application

#### Introduce

This is a library lending sales statistics program, including library class and book class. Book class is used to store book information, and library class is used to store library management information. When a student borrows a book, the system will first judge whether there is this book and whether there is enough inventory of this book. If so, students need to pay the corresponding rent to terminate the contract, The program will count the1 total and average borrowing sales of the library.



#### 1. UML and overlook of this code

![image-20211212101314950](https://tva1.sinaimg.cn/large/008i3skNgy1gxatvx0g9ej31hf0u0mze.jpg)

#### 2. Specific codes and explanations

- ***book.h*** and ***book.cpp*** are used to implement book related methods: create books according to basic information (ID, price, number), get / set book number, price ID.

***book.h***

``` c++
#include <iostream>
using namespace std;
#ifndef BOOK_H_
#define BOOK_H_
class Book
{
public:
	Book();
	Book(int id, double price, int number);
	//get
	int get_id();//get book id
	int get_number();//get book stock
	double get_price();//get book price
	//set
	void set_number(int n_number);//set book stock
	void set_id(int id);//set book id
	void set_price(double price);//set book price
	void show(int id);//show book information
private:
	int number;//book stock
	int  id;//book id
	double price;//book price

};
#endif 
```

***book.cpp***

```c++
#include "book.h"

Book::Book()
{
	id = 0;
	number = 0;
	price = 0;
}

Book::Book(int id, double price, int number)
{
	this->number = number;
	this->id = id;
	this->price = price;
}

//get
int Book::get_number(){return number;}
int Book::get_id(){return id;}
double Book::get_price(){return price;}

//set
void Book::set_number(int number){this->number = number;}
void Book::set_id(int id){this->id = id;}
void Book::set_price(double price){this->price = price;}
```




- ***library.h*** and ***library.cpp*** are used to implement library related methods such as creating get/set total book number, showing book information, calculating total sales and average sales. In the library.cpp, borrow_book() function will first search if there are the book that will be borrowed and if there are enough book to be borrowed. When a student borrows n books, the stock of this book will be reduced by n. If there are not enough books for students to borrow, the system will return a prompt.

***library.h***

```c++
#include "book.h"
using namespace std;

#ifndef LIBRARY_H_
#define LIBRARY_H_
class Library
{
public:
	Library();
	int get_m();//get m
	bool search();//search book
    void set_book1(int id, double price, int number);//create a new book
	bool borrow_book(int id, int num);//borrow a book
	void show();//show library information
	double sale_sum();//calculate total sales
	double sale_average();//calculate average sales
	void sale_show(double sum, double average);//show sales information

private:
	int m;//total book number
	int sale_num=0;//total sale number
	Book book1[1000];
	Book book_borrow[1000];
};
#endif 
```

***library.cpp***

```c++
#include "library.h"
#include "book.h"

Library::Library()
{
	m = 0;
}

int Library::get_m()
{
	return m;
}

bool Library::search()
{
	int id;
	cout << "Please enter the ID of the book:" << endl;
	cin >> id;
	for (int i = 0; i < m; i++)
	{
		if (book1[i].get_id() == id)
		{
			cout << "ID:"
				 << "    "
				 << "Price:"
				 << "    "
				 << "Stock:" << endl;
			cout << book1[i].get_id() << "        " << book1[i].get_price() << "          " << book1[i].get_number() << endl;
			return true;
		}
	}
	cout << "The book you are looking for does not exist!" << endl;
	return false;
}

void Library::set_book1(int id, double price, int number)
{
	Book b(id, price, number);
	this->book1[m] = b;
	m++;
	//cout << "Congratulations on completing the storage of the book!" << endl;
}

bool Library::borrow_book(int id, int num) //借书
{
	for (int i = 0; i < m; i++)
	{
		if (book1[i].get_id() == id) //如果查找的书本存在
		{
			if (book1[i].get_number() == 0)
			{
				cout << "The book you are looking for has been borrowed!" << endl;
				return false;
			}
			else
			{
				book1[i].set_number(book1[i].get_number() - num);
				int sale = sale_num;
				sale_num += num;
				int id = book1[i].get_id();
				double price = book1[i].get_price();
				int number = book1[i].get_number();

				for (int i = 0; i < sale_num; i++)
				{
					Book c(id, price, number);
					this->book_borrow[sale + i] = c;
					//cout << "book_borrow[sale_num]:  " << book_borrow[i].get_id() << endl;
				}

				return true;
			}
		}
	}
	cout << "The book you are looking for does not exist/ Finished borrowing！" << endl;
	return false;
}

void Library::show()
{

	cout << "ID:"
		 << "    "
		 << "Price:"
		 << "    "
		 << "Stock:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << book1[i].get_id() << "        " << book1[i].get_price() << "          " << book1[i].get_number() << endl;
	}
	return;
}

double Library::sale_sum()
{
	double sum = 0.0;
	double average;
	for (int i = 0; i < sale_num; i++)
	{
		sum += book_borrow[i].get_price();
	}
	average = sum / sale_num;
	return sum;
}
double Library::sale_average()
{
	double sum = 0.0;
	double average;
	for (int i = 0; i < sale_num; i++)
	{
		sum += book_borrow[i].get_price();
	}
	average = sum / sale_num;
	
	return average;
}
void Library::sale_show(double sum, double average)
{
	cout << "Sales:"
		 << "    "
		 << "sum:"
		 << "    "
		 << "average:" << endl;
	cout << sale_num << "        " << sum  << "     " << average << endl;
	return ;
}
```




- ***test.cpp*** realizes the process of borrowing books and calculating sales volume in the form of C ++ and main.js realizes the process of borrowing books and calculating sales volume in the form of JavaScript.

```c++
#include "book.h"
#include "library.h"
#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	Library lib;
	int i;
	clock_t start,end;
	start=clock();
    lib.set_book1(7316,05,10);
    lib.set_book1(7450,01,10);
    lib.set_book1(7320,15,10);
    lib.set_book1(7319,10,10);
    lib.set_book1(7345,05,10);

		lib.borrow_book(7316,1);
		lib.borrow_book(7450,2);
		lib.borrow_book(7320,4);
		lib.borrow_book(7319,3);
		lib.borrow_book(7345,1);
		lib.show();

	double sum = lib.sale_sum();
	double average = lib.sale_average();
	lib.sale_show(sum, average);
	end=clock();

	cout<<"The execution time is: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s";
    return 0;
}
```




- ***my_classes.idl*** is the webIDL. This file includes the interfaces of all public methods.

  ```idl
  interface Book{
  	void Book();
  	void Book(long id, double price, long number);
  
  	long get_id();
  	long get_number();
  	double get_price();
  
  	void set_number(long n_number);
  	void set_id(long id);
  	void set_price(double price);
  };
  
  interface Library {
      void Library();
  	long get_m();
  	boolean search();
      void set_book1(long id, double price, long number);
  	boolean borrow_book(long id, long num);
  	void show();
  	double sale_sum();
  	double sale_average();
  	void sale_show(double sum, double average);
  };
  ```

  


- ***my_glue_wrapper.cpp*** includes all .h file of class and glue.cpp.

  ```c++
  #include "book.h"
  #include "library.h"
  #include "glue.cpp"
  ```

   

- ***glue.cpp and glue.js*** are created by ‘python tools/webidl_binder.py my_classes.idl glue’ under emscripten.

 

- ***output.js*** is a JS format file that C + + programs are packaged into. By reference, we can call the encapsulated method.

 

- ***main.js*** is the logical implementation of web pages; index.js is the page construction of web pages.

 

#### 3. Compare and Contrast execution time of the library code between demo application and comparison application

![image-20211212102417385](https://tva1.sinaimg.cn/large/008i3skNgy1gxau7ffzp0j31z407ggn7.jpg)

![截屏2021-12-12 上午10.24.36](https://tva1.sinaimg.cn/large/008i3skNgy1gxau7xyu9sj31cr0u0dka.jpg)

- I use Visual Studio Code to run make file to run the local programs, and Visual Studio Code and live server to run web programs.

  It can be seen from the above data that the running speed of the local program is obviously faster than that of the web end, and it is more stable than that of the web end.