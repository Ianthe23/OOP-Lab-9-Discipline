#include "domain.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "tests.h"

#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <crtdbg.h>

/*
5. Contract de studii
Creați o aplicație care permite:
· gestiunea unei liste de discipline. Disciplina: denumire, ore pe săptămâna, tip, cadru
didactic
· adăugare, ștergere, modificare și afișare discipline
· căutare disciplina
· filtrare discipline după: nr ore, cadru didactic
· sortare discipline după: denumire, nr ore, cadru didactic + tip
*/

using namespace std;

void creeare() {
	Tests tests;
	tests.testAll();

	vector<Disciplina> vector;
	//Repo repo{ vector };
	FileRepo repo("discipline.txt");
	//RepoProb repo(0.67);

	Validator validator;
	Contract contract;
	Service controller(repo, validator, contract);
	Ui ui{ controller };

	cout << GREEN << "Teste finalizate cu succes!\n\n" << RESET;
	ui.run();
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	creeare();
	_CrtDumpMemoryLeaks();
	
}