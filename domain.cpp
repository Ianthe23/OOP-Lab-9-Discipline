#include "domain.h"

#include <iostream>
#include <sstream>

using namespace std;

// constructor implicit
Disciplina::Disciplina() {
	this->denumire = "";
	this->ore = 0;
	this->tip = "";
	this->profesor = "";
}

// constructorul disciplinei
Disciplina::Disciplina(const string& denumire, int ore, const string& tip, const string& profesor) {
	this->denumire = denumire;
	this->ore = ore;
	this->tip = tip;
	this->profesor = profesor;
}

// destructorul
Disciplina::~Disciplina() = default;

// copia constructorului
Disciplina::Disciplina(const Disciplina& disciplina) {
	this->denumire = disciplina.denumire;
	this->ore = disciplina.ore;
	this->tip = disciplina.tip;
	this->profesor = disciplina.profesor;

	cout << "HELLO\n";
}


/// GETTERS

const string& Disciplina::get_denumire() const noexcept{
	return this->denumire;
}

int Disciplina::get_ore() const noexcept{
	return this->ore;
}

const string& Disciplina::get_tip() const noexcept{
	return this->tip;
}

const string& Disciplina::get_profesor() const noexcept{
	return this->profesor;
}


/// SETTERS

[[maybe_unused]] void Disciplina::set_ore(int ore_noi) noexcept{
	this->ore = ore_noi;
}

[[maybe_unused]] void Disciplina::set_tip(const string& tip_nou) {
	this->tip = tip_nou;
}

[[maybe_unused]] void Disciplina::set_profesor(const string& profesor_nou) {
	this->profesor = profesor_nou;
}

[[maybe_unused]] void Disciplina::set_denumire(const string& denumire_noua) {
	this->denumire = denumire_noua;
}

/// TO STRING PRINTARE

string Disciplina::to_string_print() const{
	return "\t\033[1;33mDenumire: \033[0m" + this->denumire + ";   \033[1;33mOre: \033[0m" + to_string(this->ore) + 
		   ";   \033[1;33mTip: \033[0m" + this->tip + ";   \033[1;33mProfesor: \033[0m" + this->profesor + ".";
}


/// OPERATORI

Disciplina& Disciplina::operator=(const Disciplina& copie) = default;

bool Disciplina::operator==(const Disciplina& copie) noexcept{
	return this->denumire == copie.denumire && this->profesor == copie.profesor;
}

bool Disciplina::operator!=(const Disciplina& copie) noexcept{
	return !operator==(copie);
}

/// COMPARATORI

bool cmpDenumire(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_denumire() < disc_2.get_denumire()) {
		return true;
	}
	return false;
}

bool cmpOre(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_ore() < disc_2.get_ore()) {
		return true;
	}
	return false;
}

bool cmpProfesor(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_profesor() < disc_2.get_profesor()) {
		return true;
	}
	return false;
}

bool cmpProfTip(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_profesor() > disc_2.get_profesor()) {
		return false;
	}
	else if (disc_1.get_profesor() < disc_2.get_profesor()) {
		return true;
	}
	else {
		if (disc_1.get_tip() < disc_2.get_tip()) {
			return true;
		}
		return false;
	}
}

vector<string> split(const string& input, char delimiter) {
	vector<string> result;
	stringstream stream(input);
	string item;
	while (std::getline(stream, item, delimiter)) {
		result.push_back(item);
	}
	return result;
}

std::istream& operator>>(std::istream& input, Disciplina& disciplina) {
	string linie;
	std::getline(input, linie);
	vector<string> tokens = split(linie, ',');

	if (tokens.size() != 4) {
		return input;
	}

	disciplina.set_denumire(tokens[0]);
	disciplina.set_ore(std::stoi(tokens[1]));
	disciplina.set_tip(tokens[2]);
	disciplina.set_profesor(tokens[3]);

	return input;
}

std::ostream& operator<<(std::ostream& output, const Disciplina& disciplina) {
	output << disciplina.get_denumire() << "," << disciplina.get_ore() << "," << disciplina.get_tip() << "," << disciplina.get_profesor() << "\n";
	return output;
}