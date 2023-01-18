#include<iostream>
#include<string>
//#include<direct.h>
using namespace std;
class data{
protected:
 string name[5]={"Prem","Vicky","Himanshu","Radha","Ram"};
 int balance_left[5]={122300,103465,989230,123567,234562};
int password[5]={1111,2222,3333,4444,5555};
};
class wish: virtual public data{
	public:
	int pin;
	int index;
 wish(void){
	cout<<"WELCOME!!!"<<endl<<"Please enter your pin:";
	cin>>(this->pin);
	int count=0;
	for(int i=0;i<5;i++){
	if((this->pin)!=password[i]){
count++;
		}
		else{
			index=i;
		}
	}
	if(count>4){
		cout<<"ENTER CORRECT PASSWORD!!!"<<endl;
		exit(0);
	}
}
};
class cashwithdrawl:virtual public data,virtual public wish{
public:
int cashwithdrawl_option;
void show_cashwithdrawl(){
	cout<<"----Write no to select cashwithdrawl----"<<endl;
	cout<<"1:Saving"<<endl;
	cout<<"2:Current"<<endl;
	cout<<"Enter Here:";
	cin>>cashwithdrawl_option;
	
	
}
void amount_withdrawl(){
	switch (cashwithdrawl_option)
	{
	case 1:
	int amount1;
	cout<<"ENTER AMOUNT:";
	cin>>amount1;
	cout<<endl;
	cout<<"Wait you transaction is proceding....."<<endl<<endl;
//	_sleep(1000);
	cout<<"CONGRATES YOUR TRANSACTION DONE SUCCESFULLY"<<endl;
	cout<<endl;
	cout<<"Amount withdrawl:"<<amount1<<endl;
	cout<<"Total Balance left before withdrawl in account:"<<balance_left[index]<<endl;
	cout<<"Total Balance left after withdrawl in account:"<<balance_left[index]-amount1<<endl;
		break;
	
	case 2:
	int amount2;
	cout<<"ENTER AMOUNT:";
	cin>>amount2;
	cout<<"YOUR TRANSACTION DONE SUCCESFULLY"<<endl;
	cout<<endl;
	cout<<"Amount withdrawl:"<<amount2<<endl;
		break;
	default :
	cout<<"INVALID-------INVALID------INVALID"<<endl;
	show_cashwithdrawl();
	amount_withdrawl();
	break;
	}
}
};
class cashdeposit:virtual public data,virtual public wish{
public:
int amount;
void cash_amount(){
	cout<<"Enter amount to be deposited:";
	cin>>amount;
	int total=amount+balance_left[index];
	cout<<"Wait we depositing your money in your account....."<<endl;
  
	if(total>=balance_left[index]){
		balance_left[index]=total;
	cout<<"-----Your money deposited successfully------"<<endl;
	cout<<"Balance left in account before cash deposite:"<<balance_left[index]-amount<<endl;
	cout<<"Balance left in account after cash deposite:"<<balance_left[index]<<endl;
	}
else{
	cout<<"!!!!!!Money is not deposited please go to bank with in 2days!!!!!!"<<endl;
}}
};
class balanceinquiry:virtual public cashdeposit,virtual public data,virtual public wish{
	public:
	void account_detail(){
		cout<<"Wait we are collecting details of the card owner......"<<endl;
//		_sleep(2000);
		cout<<"Name of account holder:"<<name[index]<<endl;
		cout<<"Balance left:"<<balance_left[index]<<endl;
	}
};
class pinreset:virtual public wish,virtual public data{
public:
int newpin1,newpin2;
void setpin(){
	cout<<"Enter new pin:";
	cin>>newpin1;
	cout<<"Re-enter the new pin:";
	cin>>newpin2;
	cout<<endl;
	cout<<"Wait we reset your account pin....."<<endl;
	
	}
	void check_pin(){
	if(newpin1==newpin2){
		cout<<"Your pin is reset successfully"<<endl;
		pin=newpin1;
		cout<<" Your New-Pin is:"<<pin<<endl;
	}
	else{
		cout<<"please enter the pin carefully"<<endl;
		setpin();
		check_pin();
	}
}
};
class select_transaction:virtual public wish, virtual public pinreset, virtual public cashwithdrawl, virtual public balanceinquiry{
public:
int transaction_code;
void show_transaction(void){
	cout<<"---------------Select your transaction----------------"<<endl;
	cout<<endl;
	cout<<"!!!!Write the number written in front of Transaction method showing for selecting transaction method!!!!"<<endl;
	cout<<"1:Cash Withdrawl"<<endl;
	cout<<"2:Cash Deposit"<<endl;
	cout<<"3:Balance Inquiry"<<endl;
	cout<<"4:Pin reset"<<endl<<endl;
	cout<<"Enter here:";
	cin>>transaction_code;
}
void afterselection(){
	if(transaction_code==1){
		show_cashwithdrawl();
		amount_withdrawl();
	}
	else if(transaction_code==2){
cash_amount();
	}
	else if(transaction_code==3){
account_detail();
	}
	else if(transaction_code==4){
		setpin();
check_pin();
	}
	else{
		cout<<"Work is in progress"<<endl;
	}
}
};
int main(){
	select_transaction s1;
	s1.show_transaction();
	s1.afterselection();
	return 0;
}
