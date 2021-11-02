#include"Book.hpp"
#include<iostream>
using namespace std;
Book::Book(int n,double p,int fn) {
	num = n;
	price = p;
	BookNumber = fn;
}

//get inventory of books
int Book::getNum() {
	return num;
}

//get book price
double Book::getPrice() {
	return price;
}

//get book id number
int Book::getBookNumber() {
	return BookNumber;
}

//borrow a book, book inventory minus 1
void Book::borrow() {
	num--;
	cout<<"The Book:  "<<BookNumber<<"has been borrowed"<<endl;
}