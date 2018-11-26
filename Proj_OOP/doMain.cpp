#include "Account.h"

using std::vector;

void mainMenu(vector<Account*>*& pv_pca , vector<Employee*>*& pv_pca2);

void doMain()
{
	
	vector<Account*>* pv_pca;
	vector<Employee*>*pv_pca2;
	pv_pca = new vector<Account*>;
	pv_pca2 = new vector<Employee*>;
	

	mainMenu(pv_pca,pv_pca2);
	

	for (uint_t i = 0; i < pv_pca->size(); ++i)
	{
		delete pv_pca->at(i);
	}

	delete pv_pca;

	for (uint_t i = 0; i < pv_pca2->size(); ++i)
	{
		delete pv_pca2->at(i);
	}

	delete pv_pca2;
	
}