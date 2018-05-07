//*****************************************************************************
// Filename:  Sullivan_Creg_Assignment10
// Purpose:   To design a generic class to handle a bank account
// Author:    Creg C. Sullivan Sr.
// Date:      April 22, 2010
//****************************************************************************

// Headers and other Technical Items


#include <iostream>
#include <conio>
#include <iomanip>
#include <fstream>
#include <stdlib>
#include <dir>
#include <string>

using namespace std;

class Account {
protected:
  double bal;
  double dep;
  double with;
  double interest;
  double charges;
  double Balance;
  double deposit;
  double withdraw;
  double calcInt;
  double monthlyProc;
  double monthlyint;
  double monthlyintrate;
  double annintrate;
public:
  Balance() { getBalance(); return balance; }
  NumDeposits()
  {
    getNumDep();
    deposit++;

    return deposit;
  }
  NumWithdrawals()
  {
    getNumWith();
    withdraw++;

    return withdraw;
  }
  Interest()
  {
    getInt();
    if(bal >= 25)
    monthlyintrate = (annintrate/12);
    monthlyint = bal * monthlyintrate;
    bal = bal + monthlyint;

    return calcInt;
  }
  Charges()
  {
    getCharges();
    if(withdraw >= 4)
    {
      withdraw++;
      bal = bal - 1;
    }
    
//These are all the functions used
void Deposit(double bal);
void Withdrawals(double bal);
void Balance(double bal);
void Interest(double bal);
void Menu();
void Charges(double bal);
void Exit();

//These are the variables used
double Dnum;
double bal;
double Wnum;
char select;

int main(){

Menu();

getch();
return 0;
}


//The deposit function handles deposits coming into the program
void Deposit(){
clrscr();

cout <<"\n\tEnter an amount: $";
cin >> Dnum;
Interest(bal);
Charges(bal);

ifstream balin("Bank.txt");
balin >> bal;
balin.close();

bal = bal + Dnum;

if(Dnum != 0)
{
ofstream Depo("Bank.txt");
Depo << bal;
Depo.close();

cout <<"\n\tAmount deposited: $" << Dnum << endl;
cout <<"\n\n\tYour balance is now: $" << bal << endl;
}

else
{
cout <<"\n\tIncorrect amount, try again." << endl;
getch();
Menu();
}

cout <<"\n\n\tPress any key to contine..." << endl;
getch();
Menu();
}


void Withdrawal(){
clrscr();

cout <<"\n\tEnter an amount: ";
cin >>Wnum;
Interest(bal);
Charges(bal);

if(Wnum != 0)
{
ifstream Without("Bank.txt");
Without >> bal;
Without.close();

bal = bal - Wnum;

if(bal < 0){
cout <<"Your account can not be negative, please enter another amount." << endl;
getch();
Withdrawal();
}

ofstream Within("Bank.txt");
Within << bal;
Within.close();
}

cout <<"\n\n\tAmount withdrawn: $" << Wnum;
cout <<"\n\n\tYour balance is now: $" << bal;

cout <<"\n\n\tPress any key to continue..." << endl;
getch();
Menu();
}

void Interest(double){

double bal;
double monthlyintrate;
double monthlyint;
double annintrate;

  if(bal >= 25)
  monthlyintrate = (annintrate/12);
  monthlyint = bal * monthlyintrate;
  bal = bal + monthlyint;
}

void Charges(double){

double withdraw;
double bal;

  if(withdraw >= 4)
  {
    withdraw++;
    bal = bal - 1;
  }
  else
  {
    withdraw++;
    bal = bal - (5 + 0.10);
  }
}


void Balance(){
clrscr();
double bal;


ifstream Balout("Bank.txt");
Balout >> bal;
Balout.close();

if(bal >= 25)
{
bal = bal;
}
ofstream Balin("Bank.txt");
Balin << bal;
Balin.close();

cout <<"\n\tYour current balance is: " << bal;
cout <<"\n\nPress any key to continue..." << endl;
getch();
Menu();
}


void Exit(){
cout <<"\n\n\tEnd of program. Press any key to exit..." << endl;
}


void Menu(){
clrscr();

cout <<"\t\t\tBanking Program" << endl;
cout <<"\t\t\t================" << endl;

cout <<"\n\n\t1) Make a Deposit" << endl;
cout <<"\n\t2) Make a Withdrawal" << endl;
cout <<"\n\t3) Check your Balance" << endl;
cout <<"\n\t4) Quit" << endl;

cout <<"\n\n\tEnter your selection: ";
cin >> select;

if(select == '1')
{
Deposit();
}
else if(select == '2')
{
Withdrawal();
}
else if(select == '3')
{
Balance();
}
else if(select == '4')
{
Exit();
}
}
