#include "repo.h"

#include <iostream>

int Repo::cautaRepo(const string& denumire, const string& profesor) {

	auto iterator = find_if(this->discipline.begin(),
		this->discipline.end(), [denumire, profesor](const Disciplina& disciplina) noexcept{
			if (disciplina.get_denumire() == denumire && disciplina.get_profesor() == profesor)
				return true;
			return false;
		});

	auto const poz = std::distance(this->discipline.begin(), iterator);

	if (iterator != this->discipline.end()) {
		return poz;
	}
	
	return -1;
	
}

void Repo::adaugaRepo(const Disciplina& disciplina) {

	const string& nume = disciplina.get_denumire();
	const string& profesor = disciplina.get_profesor();

	if (cautaRepo(nume, profesor) == -1) {
		this->discipline.push_back(disciplina);
	}
	else {
		throw RepoException("Disciplina deja exista!\n");
	}
}

void Repo::modificaRepo(const Disciplina& disciplina_noua) {

	const string& denumire = disciplina_noua.get_denumire();
	const string& profesor = disciplina_noua.get_profesor();

	int const index = cautaRepo(denumire, profesor);

	if (index != -1) {
		this->discipline[index] = disciplina_noua;
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

void Repo::stergeRepo(const string& denumire, const string& profesor) {

	const int index = cautaRepo(denumire, profesor);

	if (index != -1) {
		auto first = this->discipline.begin();
		this->discipline.erase(first + index);
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

const Disciplina& Repo::get_disciplina(const string& denumire, const string& profesor) {

	const int index = cautaRepo(denumire, profesor);

	if (index != -1) {
		return this->discipline[index];
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

const vector<Disciplina>& Repo::getAll() const noexcept {
	return this->discipline;
}
