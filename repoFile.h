#ifndef REPOFILE_H_
#define REPOFILE_H_

#include "repo.h"

class FileRepo : public Repo {
private:
	string numeFisier;
	void loadFromFile();
	void saveToFile();
	void emptyFile();
public:
	
	explicit FileRepo(const string& numeFisier);

	[[maybe_unused]] void setPath(const string& numeFisier) {
		this->numeFisier = numeFisier;
	}

	void adaugaRepo(const Disciplina& disciplina) override {
		Repo::adaugaRepo(disciplina);
		saveToFile();
	}

	void modificaRepo(const Disciplina& disciplina_noua) override {
		Repo::modificaRepo(disciplina_noua);
		saveToFile();
	};

	void stergeRepo(const string& denumire, const string& profesor) override {
		Repo::stergeRepo(denumire, profesor);
		saveToFile();
	};

	~FileRepo() override = default;
};

#endif /* REPOFILE_H_ */
