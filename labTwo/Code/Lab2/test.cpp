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
