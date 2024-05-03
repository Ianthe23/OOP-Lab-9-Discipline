#include "repoFile.h"
#include <fstream>

FileRepo::FileRepo(const string& numeFisier) {
		this->numeFisier = numeFisier;
		loadFromFile();
}

void FileRepo::loadFromFile() {
	std::ifstream fin(this->numeFisier);
	Disciplina disciplina{};
	Disciplina disciplina_anterioara{};

	while (fin >> disciplina) {
		if (disciplina != disciplina_anterioara) {
			adaugaRepo(disciplina);
		}
		disciplina_anterioara = disciplina;
	}
}

void FileRepo::saveToFile() {
	std::ofstream fout(this->numeFisier);

	for (const auto& disciplina : this->getAll()) {
		fout << disciplina;
	}

	fout.close();
}

void FileRepo::emptyFile() {
	std::ofstream fout(this->numeFisier);
	fout << "";
	fout.close();
}
