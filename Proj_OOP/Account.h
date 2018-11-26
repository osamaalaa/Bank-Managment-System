#pragma once
#include"include.h"
// Strategy Pattern
class Bank{void virtual show_message()=0;};
class Account:public Bank
{
private:
	accountType_t	my_typeOfAccount;
	accNum_t*		my_accountNumber;
	field_t*		my_customerSocial;
	field_t*		my_customerFullName;
	field_t*		my_customerAddress;
	field_t*		my_customerCity;
	field_t*		my_customerHomePhone;
	field_t*		my_customerWorkPhone;
	pin_t*			my_pinNumber;
	currency_t*		my_balance;

	int*            my_cur_l;	
	pay_l*          my_pay_l;
	double*         my_loan; 
	   
public:
	Account();

	Account(accountType_t c_atype);
	Account(accountType_t c_atype, accNum_t c_actnum, field_t c_ssn,
		field_t c_fn, field_t c_adr, field_t c_cty, field_t c_hph, field_t c_wph, pin_t c_pin,
		currency_t c_bal,double my_loan,pay_l my_pay_l,int my_cur_l);
	virtual ~Account();

	void createAccount();
	void depositMoney();
	void withdrawMoney();
	void set_Loan(Account* );
    void set_PayLoan(Account* );
	void view_loan(Account* );
	void show_message();
	void set_loan(double);
	void set_pay(pay_l);
	void set_cur(int);

	void insertAccNum(accNum_t accNum);

	void viewAccount() const;



	accountType_t typeOfAccount()	const;                                 // constant l 2ne 2na m4 h3dl 3leh b function hwa hyge mn l user w h7ot feh z ahwa 
	accNum_t accountNumber()		const;
	field_t	customerSocial()		const;
	field_t	customerFullName()		const;
	field_t	customerAddress()		const;
	field_t	customerCity()			const;
	field_t	customerHomePhone()		const;
	field_t	customerWorkPhone()		const;
	field_t customerPinNumber()		const;
	currency_t balance()			const;
	int mcur_l()             const;
	pay_l mpay_l()                const;
	double mloan()            const;
};

class SavingAccount : public Account
{
public:
	SavingAccount();
	SavingAccount(accNum_t c_actnum, field_t c_ssn, field_t c_fn,
		field_t c_adr, field_t c_cty, field_t c_hph, field_t c_wph, pin_t c_pin, currency_t c_bal,double my_loan,pay_l my_pay_l,int my_cur_l);
	virtual ~SavingAccount();
};
class CheckingAccount : public Account
{
public:
	CheckingAccount();
	CheckingAccount(accNum_t c_actnum, field_t c_ssn,
		field_t c_fn, field_t c_adr, field_t c_cty, field_t c_hph,
		field_t c_wph, pin_t c_pin, currency_t c_bal,double my_loan,pay_l my_pay_l,int my_cur_l);
	virtual ~CheckingAccount();
};
class Employee
{
private:
	int EmpID;
	char EmpName[50], Post[50], Department[10], College[60], TotalGrade[20];
	float Salary;
public:
	void ReadData();
	int GetID();
	void DisplayRecord();
	char* GetDepartment();
	
};

class central_proxy:public Account{
 double Total_balance;
double LoanValue;
pay_l m_fee;
pay_l pay;
acc_t* acc;
int cur_l;
public:

central_proxy();
void show_message();
void set_Loan(acc_t* );
void set_PayLoan(acc_t* );
void view_loan(acc_t* );
acc_t* get_acc();


};