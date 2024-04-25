#ifndef REPO_H_
#define REPO_H_

#include "domain.h"
#include "exceptions.h"

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <utility>
#include <random>
#include <iostream>

using std::vector;
using std::string;
using std::find_if;
using std::make_pair;

class RepoAbs {
public:
	virtual void adaugaRepo(const Disciplina& disciplina) = 0;

	virtual void modificaRepo(const Disciplina& disciplina_noua) = 0;

	virtual void stergeRepo(const string& denumire, const string& profesor) = 0;

	virtual int cautaRepo(const string& denumire, const string& profesor) = 0;

	virtual Disciplina& get_disciplina(const string& denumire, const string& profesor) = 0;

	virtual vector<Disciplina>& getAll() = 0;

	virtual ~RepoAbs() = default;
};

class RepoProb : public RepoAbs {

private:
	float probabilitate;
	map<int, Disciplina> elemente;
	void det_luck();

public:
	RepoProb() = default;

	explicit RepoProb(float probabilitate);

	void adaugaRepo(const Disciplina& disciplina) override;

	void modificaRepo(const Disciplina& disciplina_noua) override;

	void stergeRepo(const string& denumire, const string& profesor) override;

	int cautaRepo(const string& denumire, const string& profesor) override;

	Disciplina& get_disciplina(const string& denumire, const string& profesor) override;

	vector<Disciplina>& getAll() override;
};

class Repo : public RepoAbs{
private:
	//vectorul nostru
	vector<Disciplina> discipline;

public:

	Repo() = default;

	explicit Repo(const vector<Disciplina>& discipline) :discipline{ discipline } {};

	/*
	* adaugam discipline la lista de obiecte
	* 
	* param: disciplina
	* arunca exceptii daca exista deja un obiect egal cu disciplina
	*/
	virtual void adaugaRepo(const Disciplina& disciplina) override;

	/*
	* modificam o disciplina din lista de obiecte
	* 
	* param: disciplina_noua
	* arunca exceptii daca nu exista obiectul de modificat
	*/
	virtual void modificaRepo(const Disciplina& disciplina_noua) override;

	/*
	* stergem o disciplina din lista de obiecte
	* 
	* param: denumirea disciplinei + numele profesorului
	* arunca exceptii daca nu gaseste disciplina de sters
	*/
	virtual void stergeRepo(const string& denumire, const string& profesor) override;

	/*
	* cauta o disciplina in lista de obiecte
	* 
	* param: denumirea disciplinei + numele profesorului
	* returns: i != -1 daca disciplina exista (indexul)
	*		   i = -1 daca disciplina NU exista
	*/
	virtual int cautaRepo(const string& denumire, const string& profesor) override;

	/*
	* returneaza disciplina daca exista, altfel arunca exceptie
	*/
	virtual Disciplina& get_disciplina(const string& denumire, const string& profesor) override;

	/*
	* returneaza toate disciplinele salvate
	*/
	virtual [[nodiscard]] vector<Disciplina>& getAll() override;

	virtual ~Repo()=default;

};

#endif /* REPO_H_ */
