#include"Account.h"
#include"include.h"
using std::cin;
using std::cout;                               //temporary object 3ne 7aga mo
using std::endl;
using std::getline;
using std::ws;                            // dh bta3 l white space 
using std::vector;
using namespace std;
void clearScreen();
void displayTitle();
void pauseScreen();


Account::Account()                   // defult constructor 
{
}
Account::Account(accountType_t c_atype)
	:my_typeOfAccount(c_atype),
	my_accountNumber(new accNum_t),
	my_customerSocial(new field_t),
	my_customerFullName(new field_t),
	my_customerAddress(new field_t),
	my_customerCity(new field_t),
	my_customerHomePhone(new field_t),
	my_customerWorkPhone(new field_t),
	my_pinNumber(new pin_t),
	my_balance(new currency_t),
	
	my_loan(new double),
	my_pay_l(new pay_l),
	my_cur_l(new int)
{
}
Account::Account(accountType_t c_atype, accNum_t c_actnum, field_t c_ssn,
	field_t c_fn, field_t c_adr, field_t c_cty, field_t c_hph, field_t c_wph, pin_t c_pin,
	currency_t c_bal,double _my_loan,pay_l _my_pay_l,int _my_cur_l)
	:my_typeOfAccount(c_atype),
	my_accountNumber(new accNum_t(c_actnum)),
	my_customerSocial(new field_t(c_ssn)),
	my_customerFullName(new field_t(c_fn)),
	my_customerAddress(new field_t(c_adr)),
	my_customerCity(new field_t(c_cty)),
	my_customerHomePhone(new field_t(c_hph)),
	my_customerWorkPhone(new field_t(c_wph)),
	my_pinNumber(new pin_t(c_pin)),
	my_balance(new currency_t(c_bal)),
	
	my_loan(new double(_my_loan)),
	my_pay_l(new pay_l(_my_pay_l)),
	my_cur_l(new int(_my_cur_l))
{
}
Account::~Account()
{
	delete my_accountNumber;
	delete my_customerSocial;
	delete my_customerFullName;
	delete my_customerAddress;
	delete my_customerCity;
	delete my_customerHomePhone;
	delete my_customerWorkPhone;
	delete my_pinNumber;
	delete my_balance;
	delete my_cur_l;
	delete my_pay_l;
	delete my_loan;
}
void Account::show_message(){cout<<CL_SEC<<endl;}
void Account::createAccount()
{
	clearScreen();
	displayTitle();

	// Account Number
	cout << '\n' << CUSTOMERS_ACCOUNT_NUMBER << ACCOUNT_PREFIX
		<< this->accountNumber() << endl;

	// Social Security Number
	cout << ENTER_SOCIAL_SECURITY;
	cin >> ws;
	getline(cin, *my_customerSocial);

	// Full Name
	cout << ENTER_CUSTOMERS_FULL_NAME;
	cin >> ws;
	getline(cin, *my_customerFullName);

	// Address
	cout << ENTER_ADDRESS;
	cin >> ws;
	getline(cin, *my_customerAddress);

	// City
	cout << ENTER_CITY;
	cin >> ws;
	getline(cin, *my_customerCity);


	// Home Phone
	cout << ENTER_HOME_PHONE;
	cin >> ws;
	getline(cin, *my_customerHomePhone);

	// Work Phone
	cout << ENTER_WORK_PHONE;
	cin >> ws;
	getline(cin, *my_customerWorkPhone);

	// Pin
	cout << ENTER_PIN;
	cin >> ws;
	getline(cin, *my_pinNumber);

	// Balance
	cout << ENTER_INITIAL_BALANCE;
	cin >> *my_balance;
}

void Account::depositMoney()
{
	clearScreen();
	displayTitle();

	currency_t amt = (0);

	cout << '\n' << HOW_MUCH_DEPOSIT;
	cin >> amt;

	*my_balance += (amt);
}

void Account::withdrawMoney()
{
	clearScreen();
	displayTitle();

	currency_t amt = (0);
	bool isOver = (false);

	do
	{
		cout << '\n' << HOW_MUCH_WITHDRAWAL;
		cin >> amt;

		if (amt > balance())
		{
			cout << '\n' << INSUFFICIENT_FUNDS << '\n' << endl;

			isOver = (true);

			pauseScreen();

			continue;
		}
		else
		{
			*my_balance -= (amt);
		}
	} while (isOver == true);
}
void Account::insertAccNum(accNum_t accNum)
{
	*my_accountNumber = (accNum);
}

void Account::viewAccount() const
{
	clearScreen();
	displayTitle();

	cout << '\n' << " ***** -Account information -*****" << '\n' << endl;
	cout << ACCOUNT_TYPE;
	(this->typeOfAccount() == CHECKING_CODE)
		? cout << CHECKING_ACCOUNT
		: cout << SAVING_ACCOUNT;
	endl(cout);

	cout << ACCOUNT_NUMBER << ACCOUNT_PREFIX << this->accountNumber() << '\n'
		<< SOCIAL_SECURITY_NUMBER << this->customerSocial() << '\n'
		<< FULL_NAME << this->customerFullName() << '\n'
		<< ADDRESS << this->customerAddress() << '\n'
		<< CITY << this->customerCity() << '\n'
		<< HOME_PHONE << this->customerHomePhone() << '\n'
		<< WORK_PHONE << this->customerWorkPhone() << '\n'
		<< '\n' << BALANCE << this->balance() << '\n';
	cout << '\n' << MENU_BORDER << '\n' << endl;;

	pauseScreen();
}
void Account::set_loan(double a)
{
	*my_loan=a;
}
	void Account::set_pay(pay_l a)
	{
	*my_pay_l=a;
	
	}
	void Account::set_cur(int a)
	{
	*my_cur_l=a;
	
	}
accountType_t Account::typeOfAccount() const
{
	return(my_typeOfAccount);
}

accNum_t Account::accountNumber() const
{
	return(*my_accountNumber);
}

field_t	Account::customerSocial() const
{
	return(*my_customerSocial);
}

field_t	Account::customerFullName() const
{
	return(*my_customerFullName);
}

field_t Account::customerAddress() const
{
	return(*my_customerAddress);
}
field_t	Account::customerCity() const
{
	return(*my_customerCity);
}

field_t	Account::customerHomePhone() const
{
	return(*my_customerHomePhone);
}

field_t	Account::customerWorkPhone() const
{
	return(*my_customerWorkPhone);
}


field_t Account::customerPinNumber() const
{
	return(*my_pinNumber);
}

currency_t Account::balance() const
{
	return(*my_balance);
}
pay_l Account::mpay_l() const
{
	if(my_pay_l==NULL)
		return 0;
	return (*my_pay_l);
}
int Account::mcur_l() const
{
	if(my_cur_l==NULL)
		return 0;
	return (*my_cur_l);
}
double Account::mloan() const
{
	if(my_loan==NULL)
		return 0;
	return *my_loan; 
}
void Account::set_Loan(Account* ){cout<<LOAN_CON<<endl;}
void Account::set_PayLoan(Account* ){cout<<LOAN_CON<<endl;}
void Account::view_loan(Account* ){cout<<LOAN_CON<<endl;};

SavingAccount::SavingAccount()
	:Account(SAVING_CODE)
{
}
SavingAccount::SavingAccount(accNum_t c_actnum, field_t c_ssn,
	field_t c_fn, field_t c_adr, field_t c_cty,
	field_t c_hph,
	field_t c_wph, pin_t c_pin, currency_t c_bal,double my_loan,pay_l my_pay_l,int my_cur_l)
	: Account(SAVING_CODE, c_actnum, c_ssn, c_fn, c_adr, c_cty, c_hph, c_wph, c_pin, c_bal, my_loan, my_pay_l, my_cur_l)
{
}
SavingAccount::~SavingAccount()
{
}
CheckingAccount::CheckingAccount()
	:Account(CHECKING_CODE)
{
}
CheckingAccount::CheckingAccount(accNum_t c_actnum, field_t c_ssn,
	field_t c_fn, field_t c_adr, field_t c_cty, field_t c_hph,
	field_t c_wph, pin_t c_pin, currency_t c_bal,double my_loan,pay_l my_pay_l,int my_cur_l)
	: Account(CHECKING_CODE, c_actnum, c_ssn, c_fn, c_adr, c_cty, c_hph, c_wph, c_pin, c_bal, my_loan, my_pay_l, my_cur_l)
{
}
CheckingAccount::~CheckingAccount()
{
}

void Employee::ReadData()
{
	cout << endl << "Employee ID : ";
	cin >> EmpID;
	cout << "Employee Name : ";
	cin >> EmpName;
	cout << "Employee’s Postion : ";
	cin >> Post;
	cout << "Enter The College : ";
	cin >> College;
	cout << "Employee’s Department : ";
	cin >> Department;
	cout << "Enter the Total Grade:";
	cin >> TotalGrade;

	cout << "Salary:";
	cin >> Salary;
}

void Employee::DisplayRecord()
{
	cout << endl << "_______________________________";
	cout << endl << setw(5) << EmpID << setw(15) << EmpName << setw(15) << Post << setw(15) << Department << setw(8) << Salary;
}
int Employee::GetID()
{
	return EmpID;
}


char* Employee::GetDepartment()
{
	return Department;
}
bool find_rec(vector<Employee*>*&pca,int sn)
{
	int i=0;
	while(i<pca->size())
	{
	if(pca->at(i)->GetID()==sn)
		return true;
	i++;
	
	}
return false;
}

lint_t findRecord(vector<Account*>*& pv_pca, const field_t ssn)    // find record bl social number 
{
	for (uint_t i = 0; i < pv_pca->size(); ++i)
	{
		if (pv_pca->at(i)->customerSocial() == ssn)
		{
			return (lint_t(i));
		}
	}

	return(RECORD_NOT_FOUND);
}
bool verifyDuplicateEntries(vector<Account*>*& pv_pca, const accNum_t accNum)            // de bta3t l account mtkrr 
{
	bool isDuplicate = (false);

	for (uint_t i = 0; i < pv_pca->size(); ++i)
	{
		if (pv_pca->at(i)->accountNumber() == accNum) {
			isDuplicate = true;
		}
	}

	return(isDuplicate);
}




// quit 

char quit()
{
	char isQuit = (FALSE);

	do
	{
		cout << '\n' << IS_QUIT;
		cin >> isQuit;

		isQuit = toupper(isQuit);

		if (isQuit == TRUE || isQuit == FALSE)  //true= Y or Flase= N 
		{
			break;
		}
	} while (isQuit != TRUE && isQuit != FALSE);

	return(isQuit);
}

//Virtual Proxy Pattern for maintaining Loans.
// Or Data Access Object Pattern to gaurantee that no clients access that section.
// Or Transfer Object Pattern from the client to the central. 

central_proxy::central_proxy()
{
	Total_balance=99999999;
	LoanValue=0;
	m_fee=0.1*LoanValue;
	pay=LoanValue+m_fee;
	acc=NULL;
	cur_l=10;
	


}

void central_proxy::show_message(){cout<<CP_SEC<<endl;}
void central_proxy::set_Loan(Account* ac){
acc=ac;
LoanValue=acc->mloan();
if(LoanValue!=0)
{
    LOAN_EXC;
cout<<GO_BACK<<endl;
}
else
{
cout<<LOAN_ENT<<endl;
cin>>ws;
cin>>LoanValue;
if(LoanValue<0.01*Total_balance)
{
if(m_fee<acc->balance())
{
cout<<LOAN_FEES_EXC<<endl;
cout<<GO_BACK<<endl;
}
else
{

cout<<DISP_FEES<<m_fee<<DISP_PROC<<endl;
accountType_t c;
cin>>c;
c=toupper(c);
cin>>c;
if(c==PROCEED)
{
	
*acc->balance+=LoanValue;
acc->set_loan(LoanValue);
acc->set_cur(cur_l);
cout<<CONF_ADD<<LOAN_DURA<<cur_l<<MON<<endl<<DISP_WITH;

if(c==WITHDRAWAL_CODE)
acc->withdrawMoney();

}
else
    cout<<GO_BACK<<endl;
}
}
else
{
    cout<<INSUFF_BALNACE<<endl;
   cout<<GO_BACK<<endl;
}
}
}


acc_t* central_proxy::get_acc(){if(acc!=NULL)return acc;}
void central_proxy::view_loan(acc_t* acc){cout<<acc->mloan()<<" Rs"<<endl;
                                          cout<<acc->mcur_l()<<MON<<endl;}


void central_proxy::set_PayLoan(acc_t* ac) 
{
    acc=ac;
    LoanValue=acc->mloan();
    pay=acc->mpay_l();
    cur_l=acc->mcur_l();
if(pay==0)
{
    cout<<LOAN_APAID<<endl;
cout<<GO_BACK<<endl;
}
else
{
double paid;
cin>>ws;
cin>>paid;
if(paid>=pay)
{
cout<<LOAN_PAID<<endl;
acc->set_loan(0);
cout<<GO_BACK<<endl;
}
else
{int mons;
*acc->balance-=paid;     // Please test this statement
pay-=paid;
mons=paid/m_fee;
cur_l-=mons;
acc->set_pay(pay);
acc->set_cur(cur_l);
cout<<pay<<MONE_REM<<endl;
cout<<GO_BACK<<endl;
}
}
}
