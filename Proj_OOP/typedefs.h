#pragma once
class CheckingAccount;
class SavingAccount;
class Account;
class central_proxy;

#include <string>

typedef unsigned int		uint_t;        // bto3 l client 
typedef long int			lint_t;
typedef unsigned int		accNum_t;
typedef double				currency_t;
typedef char				accountType_t;
typedef std::string			field_t;
typedef std::string			pin_t;
typedef float               pay_l;
typedef CheckingAccount		checkingRecord_t;
typedef SavingAccount		savingRecord_t;
typedef Account             acc_t;   

typedef central_proxy       loan_cp;

typedef std::string         field_t2;  // bto3 l employee 
typedef double		        salary_t2;
typedef long int            Lint_t2;