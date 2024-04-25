#include "repo.h"

#include <iostream>

RepoProb::RepoProb(float probabilitate) {
	this->probabilitate = probabilitate;
	elemente.clear();
}

void RepoProb::adaugaRepo(const Disciplina& disciplina) {
	det_luck();
	elemente.insert(make_pair(elemente.size(), disciplina));
}

void RepoProb::modificaRepo(const Disciplina& disciplina_noua) {
	det_luck();
	for (auto& [key, value] : elemente) {
		if (value == disciplina_noua) {
			value = disciplina_noua;
			return;
		}
	}
}

void RepoProb::stergeRepo(const string& denumire, const string& profesor) {
	det_luck();
	for (auto& [key, value] : elemente) {
		if (value.get_denumire() == denumire && value.get_profesor() == profesor) {
			elemente.erase(key);
			return;
		}
	}
}

int RepoProb::cautaRepo(const string& denumire, const string& profesor) {
	det_luck();
	for (const auto& [key, value] : elemente) {
		if (value.get_denumire() == denumire && value.get_profesor() == profesor) {
			return key;
		}
	}
	return -1;
}

Disciplina& RepoProb::get_disciplina(const string& denumire, const string& profesor) {
	det_luck();
	for (auto& [key, value] : elemente) {
		if (value.get_denumire() == denumire && value.get_profesor() == profesor) {
			return value;
		}
	}
	throw RepoException("Disciplina nu exista!\n");
}
vector<Disciplina> discipline;
vector<Disciplina>& RepoProb::getAll() {
	discipline.clear();
	for (const auto& [key, value] : elemente) {
		discipline.push_back(value);
	}
	return discipline;
}

void RepoProb::det_luck() {
	auto prb = int(probabilitate * 10);
	int nr = rand() % 10;
	if (nr <= prb) {
		return;
	}
	throw BadLuckException("Teapa curata!\n");
}

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

Disciplina& Repo::get_disciplina(const string& denumire, const string& profesor) {

	const int index = cautaRepo(denumire, profesor);

	if (index != -1) {
		return this->discipline[index];
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

vector<Disciplina>& Repo::getAll() {
	return this->discipline;
}
