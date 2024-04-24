#include "repoFile.h"
#include <fstream>

FileRepo::FileRepo(const string& numeFisier) {
		this->numeFisier = numeFisier;
		loadFromFile();
}

void FileRepo::loadFromFile() {
	std::ifstream fin(numeFisier);
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
	std::ofstream fout(numeFisier);

	for (const auto& disciplina : this->getAll()) {
		fout << disciplina;
	}

	fout.close();
}

void FileRepo::emptyFile() {
	std::ofstream fout(numeFisier);
	fout << "";
	fout.close();
}
