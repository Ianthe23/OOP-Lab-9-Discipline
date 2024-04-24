#ifndef CONTRACT_H_
#define CONTRACT_H_

#include "domain.h"

#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <fstream>

using std::vector;
using std::string;
using std::shuffle;

class Contract {

private:
	vector<Disciplina> contract;

public:
	void emptyContract() noexcept;

	void adaugaContract(const Disciplina& discipina);

	void genereazaContract(int nr_discipline, const vector<Disciplina>& memorie);

	void exportContract(const string& nume_fisier);

	const vector<Disciplina>& get_contract();

	int cautaContract(const string& denumire, const string& profesor);
};


#endif /* CONTRACT_H_ */
