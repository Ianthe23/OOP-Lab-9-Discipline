#ifndef REPOFILE_H_
#define REPOFILE_H_

#include "repo.h"

class FileRepo : public Repo {
private:
	string numeFisier;

public:
	void loadFromFile();
	void saveToFile();
	void emptyFile();
	explicit FileRepo(const string& numeFisier);

	[[maybe_unused]] void setPath(const string& numeFisier) {
		this->numeFisier = numeFisier;
	}

	~FileRepo() = default;
};

#endif /* REPOFILE_H_ */
