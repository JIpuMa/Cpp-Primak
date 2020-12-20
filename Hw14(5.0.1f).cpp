#include <iostream>
#include <string>
using namespace std;

typedef struct BookDetails
{
	string code;
	string author;
	string name;
};

typedef struct ReaderInformation
{
	unsigned int numOfTheTicket;
	string surname;
	unsigned int dateOfTheOrder;
};

typedef struct BookClaimsForm
{
	BookDetails bd;
	ReaderInformation ri;
};

int main()
{
	BookClaimsForm bookBlank;
	return 0;
}