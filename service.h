#ifndef SERVICE_H_
#define SERVICE_H_

#include "repoFile.h"
#include "validator.h"
#include "contract.h"
#include "undo.h"

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <random>
#include <algorithm>
#include <memory>
#include <map>

using std::string;
using std::vector;
using std::map;
using std::function;
using std::unique_ptr;
using std::copy_if;
using std::shuffle;

class Service {
	FileRepo& repo;
	Validator& validator;
	Contract& contract;
	std::vector<unique_ptr<UndoActiuni>> undoActiuni;


public:
	void undo();

	const vector<Disciplina>& getAllContract() noexcept;

	int getContractsize();

	void adauga_la_contract(const string& denumire, const string& profesor, const vector<Disciplina>& filtered);

	void genereaza_contract(int nr_discipline);

	void exporta_contract(const string& nume);

	void empty_contract();

	map<string, DTO> raport() noexcept;

	Service(FileRepo& repo, Validator& validator, Contract& contract) noexcept : repo{ repo }, validator{ validator }, contract{ contract } {

	}
	
	//nu putem lasa sa se faca copie
	Service(const Service& copie) = delete;

	/*
	* Adauga o disciplina
	* Arunca exceptie daca: deja exista SAU nu este valida
	*/
	void adaugaSrv(const string& denumire, int ore, const string& tip, const string& profesor);

	/*
	* Sterge o disciplina
	* Arunca exceptie daca: disciplina nu exista
	*/
	void stergeSrv(const string& denumire, const string& profesor);

	/*
	* Modifica o disciplina
	* Arunca exceptie daca: disciplina nu exista SAU nu este valida
	*/
	void modificaSrv(const string& denumire, int ore, const string& tip, const string& profesor);

	/*
	* Cauta o disciplina dupa denumire si profesor
	* Arunca exceptie daca: disciplina nu exista
	*/
	const Disciplina& cautaSrv(const string& denumire, const string& profesor);

	const vector<Disciplina>& getAll() noexcept;

	
	/// FILTRARI

	//filtreaza dupa numarul de ore
	vector<Disciplina> filterOre(int ore);

	//filtreaza dupa numele disciplinei
	vector<Disciplina> filterProfesor(const string& profesor);

	vector<Disciplina> filterDenumire(const string& denumire);


	/// SORTARI

	//sorteaza dupa denumire
	vector<Disciplina> sortDenumire();

	//sorteaza dupa ore
	vector<Disciplina> sortOre();

	//sorteaza dupa profesor si dupa tip
	vector<Disciplina> sortProfTip();

};

#endif /* SERVICE_H_ */
