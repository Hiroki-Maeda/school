#include <stdio.h>
#include <stdlib.h>

typedef struct dummy_BankAccount {
  double balance;
}BankAccount;

void Method_BankAccount(double openingBalance, BankAccount *pointer_ba1);
//銀行口座pointer_ba1の預金の初期値を openingBalance に決める関数

void deposit(double amount, BankAccount *pointer_ba1);
//銀行口座pointer_ba1にamountの額のお金を預ける関数

void withdraw(double amount, BankAccount *pointer_ba1);
//銀行口座pointer_ba1からamountの額のお金を引き出す関数

void display(BankAccount *pointer_ba1);
//銀行口座pointer_ba1の現在の預金額を表示する関数
  
int main(){
  BankAccount *pointer_ba1;
  pointer_ba1 = (BankAccount *)malloc(sizeof(BankAccount));

  Method_BankAccount(100.00, pointer_ba1);
  display(pointer_ba1);
  deposit(74.35, pointer_ba1);
  withdraw(20.00, pointer_ba1);

  printf("After transactions,");
  display(pointer_ba1);
  
  return 0;
}

void Method_BankAccount(double openingBalance, BankAccount *pointer_ba1){
  pointer_ba1->balance = openingBalance;
}


void deposit(double amount, BankAccount *pointer_ba1){
  pointer_ba1->balance += amount;
}


void withdraw(double amount, BankAccount *pointer_ba1){
  pointer_ba1->balance -= amount;
}

void display(BankAccount *pointer_ba1){
  printf("balance=%f \n", pointer_ba1->balance);
}

/*********answer************

q238059h@iav059:~/program/network/1013$ ex5
balance=100.000000 
After transactions,balance=154.350000 

*************************************/
  
