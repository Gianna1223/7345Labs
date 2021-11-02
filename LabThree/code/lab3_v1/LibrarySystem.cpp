#include<iostream>
#include<vector>
#include<cstring>
#include"LibrarySystem.hpp"
#include"LibraryThread.hpp"
BorrowSystem* BorrowSystem::book_BorrowSystem=nullptr;

BorrowSystem::BorrowSystem(){
}

//create borrow event system 
BorrowSystem* BorrowSystem::CreateOrGet(){
    if(!book_BorrowSystem){
        book_BorrowSystem=new BorrowSystem();
    }
    return book_BorrowSystem;
}

//create borrow event thread
void BorrowSystem::CreateBorrowThread(int num,int BookNumber,Book* book){
        BorrowThread* newBorrow=new BorrowThread(num,BookNumber,book);
        book_BorrowThreadsMutex.lock();
        book_BorrowThreads.push_back(newBorrow);
        newBorrow->Startup();
        book_BorrowThreadsMutex.unlock();
}


