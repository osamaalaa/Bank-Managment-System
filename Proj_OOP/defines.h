#pragma once


 // macro definations b replace beha l cout b #define l 2na 3mlha 
// zy msln lama #ifdef TABLE_SIZE
//int table[TABLE_SIZE];
  
#define ACCOUNT_PREFIX				"No : "

#define CLEAR_SCREEN				"cls"
#define PAUSE_SCREEN				"pause"

#define PROGRAM_TITLE				"\\/********* Welcome To BANK Managment System *********\\/ "
#define CL_SEC                      "********Welcome to the Client Section of the Bank************"
#define CP_SEC                      "***********Welcome to the Central Section of the Bank**********"

#define EXCEPTION					"Exception: "
#define UNKNOWN_ERROR				"Unknown internal error!"

#define CHECKING_CODE				'C'
#define SAVING_CODE					'S'
#define CREATE_CODE					'N'
#define DEPOSIT_CODE				'D'
#define WITHDRAWAL_CODE				'W'
#define VIEW_CODE					'V'
#define EXIT_CODE					'X'
#define GO_BACK_CODE				'G'
#define ERASE_CODE					'E'
#define EMPLOYEE_CODE               'M'
#define Save_CODE                   'S'
#define LOAD_FILE_CODE				'L'
#define SEARCH_CODE                 'P'
#define FIND_CODE                   'F'
#define PROCEED                     'R'
#define LOAN                        'O' 
#define PLOAN                       'A'
#define VDLoan                      'J'  

#define CREATE_NEW_ACCOUNT			"(N) Create new account"
#define DEPOSIT_INTO_ACCOUNT		"(D) Deposit into account"
#define WITHDRAWAL_FROM_ACCOUNT		"(W) Withdraw from account"
#define VIEW_LOANS                  "(J) View Loan and the required payment months"
#define VIEW_ACCOUNT				"(V) View account information"
#define ADD_LOAN                    "(O) Add Loan" 
#define PAY_LOAN                    "(A) Pay Loan"
#define EXIT_PROGRAM				"(X) Exit Program"
#define CREATE_EMPLOYEE_ACCOUNT     "(M) Create Employee account "
#define ERASE_ACCOUNT				"(E) (Employee) Delete account"
#define LOAD_FILE					"(L) (Employee) Add accounts of clients into Bank System "
#define FIND_EMPLOYEE               "(F) (Admin) Find Employee Data "


#define SAVE_ACCOUNT                "(S) (Employee) Save Accounts of clients into File  "

#define SEARCH_EMPLOYEE             "(P) ( ADMIN )Search about Employee "

          
#define ENTER_CHOICE				"Please choose an option: __\b\b" // bl sla4 b by3ml back space 

#define OUTPUT_FILENAME				"Enter file name to output or -1 to go back: __________\b\b\b\b\b\b\b\b\b\b"
#define INPUT_FILENAME				"Enter file name to load data from or -1 to go back: __________\b\b\b\b\b\b\b\b\b\b"

#define IS_QUIT						"Are you sure you want to exit? (Y)es, (N)o: __\b\b"

#define WHAT_TYPE_OF_ACC			"(C)hecking, (S)aving account, or (G)o back? __\b\b"

#define ENTER_ACC_NUMBER			"Enter your account number or -1 to go back: ___\b\b\b"   
#define ENTER_SSN					"Enter your social security number or -1 to go back: ___________\b\b\b\b\b\b\b\b\b\b\b"


#define ERROR			            	  "Error, please try again!"


#define CHECKING_ACCOUNT			"Checking Account"
#define SAVING_ACCOUNT				"Saving Account"

#define ACCOUNT_TYPE				"Account Type         : "
#define ACCOUNT_NUMBER				"Account #            : "
#define SOCIAL_SECURITY_NUMBER		"Password Security #  : "
#define FULL_NAME					"Customer Full Name   : "
#define ADDRESS						"Full Address         : "
#define CITY						"City                 : "
#define HOME_PHONE					"Home Phone           : "
#define WORK_PHONE					"Work Phone           : "
#define BALANCE						"Balance              : $"

#define INSUFFICIENT_FUNDS			"Insufficient funds, please try again!"

#define RECORD_ERASED				"Record has been successfully erased!"
#define SAVE_COMPLETED			    "Accounts have been successfully Saved!"
#define LOAD_COMPLETED				"Record(s) have been successfully loaded!"
#define FILE_REMOVED				"File has been successfully removed!"

#define HOW_MUCH_WITHDRAWAL			"How much would you like to withdrawal or -1 to go back: $_______\b\b\b\b\b\b\b"
#define HOW_MUCH_DEPOSIT			"How much would you like to deposit or -1 to go back: $_______\b\b\b\b\b\b\b"

#define CUSTOMERS_ACCOUNT_NUMBER	"Customers account number     : "

#define ENTER_SOCIAL_SECURITY		"Enter Password Security     : ___________\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_CUSTOMERS_FULL_NAME	"Enter Your full name         :____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
#define	ENTER_ADDRESS				"Enter Your address    : ____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_CITY					"Enter Your city       : __________\b\b\b\b\b\b\b\b\b\b"
#define ENTER_HOME_PHONE			"Enter Your home phone  : ____________\b\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_WORK_PHONE			"Enter Your work phone  : ____________\b\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_PIN					"Enter a four digit pin #   : ____\b\b\b\b"
#define ENTER_INITIAL_BALANCE		"Enter initial deposit amount : $_______\b\b\b\b\b\b\b"
#define DATA_DIRECTORY				"UserData"

#define LOAN_M                      "Enter the current month    :__\b\b "
#define LOAN_ENT                    "Enter the value of Loan   : __\b\b" 
#define GO_BACK                     "System is going back to previous menu" 
#define LOAN_EXC                    "Only one Loan can be requested for one client"
#define	LOAN_FEES_EXC				"Insuffucient funds for paying Loan fees"
#define	DISP_FEES					"The Monthly fee is: "
#define	DISP_PROC					" Rs ,press 'R' to proceed, 'X' to cancel :__\b\b "
#define	CONF_ADD					"Successfully Added to Balance"
#define	LOAN_DURA					"the deadline for paying the Loan is: "
#define	MON							" Months"
#define	DISP_WITH					"if you want to Withdraw it press 'W':__\b\b "
#define	INSUFF_BALNACE				"The central Bank's balance can't hold that loan"
#define	LOAN_APAID					"You have already paid your Loan"
#define	LOAN_PAID					"Loan has been paid successfully"
#define	MONE_REM					" Rs Remaining"
#define LOAN_CON                    "For Loan control,Switch to the central? (Y/N)"
#define INV_REC                     "Invalid Employee ID"
#define GET_EMP                     "Enter Employee ID:__ \b\b"



#define TRUE						'Y'
#define FALSE						'N'

#define	RECORD_FOUND				100
#define RECORD_NOT_FOUND			-100

#define MENU_BORDER					"(\\/*********************************\\/)"

