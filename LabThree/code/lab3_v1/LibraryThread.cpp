#include<mutex>
#include<map>
#include<deque>
#include<vector>
#include<thread>
#include<iostream>
#include"LibraryThread.hpp"
#include"LibrarySystem.hpp"
using namespace std;
//Initialize borrow event thread
BorrowThread::BorrowThread(int num,int BookNumber,Book* book){
    book_num=num;
    book_bookNumber=BookNumber;
    book_book=book;
}

//start a borrow event thread
void BorrowThread::Startup(){
    book_thread=new thread(BorrowThreadMain,this);
}

void BorrowThread::Work(){
    int num=book_book->getNum();
    while(num>0){
        book_StatusMutex.lock();
        book_book->borrow();
        num--;
        book_StatusMutex.unlock();
    }
}

void BorrowThread::BorrowThreadMain(void* BorrowThreadObject){
    BorrowThread* thisBorrow=(BorrowThread*)BorrowThreadObject;
    thisBorrow->Work();
}


