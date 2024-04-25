#ifndef UNDO_H_
#define UNDO_H_

#include "domain.h"
#include "repo.h"

class UndoActiuni {
public:
		virtual void doUndo() = 0;
		virtual ~UndoActiuni() = default;
};

class UndoAdauga : public UndoActiuni {
	Disciplina disciplinaAdaugata;
	RepoAbs& repo;

public:
	UndoAdauga(RepoAbs& repo, const Disciplina& disciplina) : repo{ repo }, disciplinaAdaugata{ disciplina } {
	}

	void doUndo() override {
		this->repo.stergeRepo(disciplinaAdaugata.get_denumire(), disciplinaAdaugata.get_profesor());
	}
};

class UndoSterge : public UndoActiuni {
	Disciplina disciplinaStearsa;
	RepoAbs& repo;

public:
	UndoSterge(RepoAbs& repo, const Disciplina& disciplina) : repo{ repo }, disciplinaStearsa{ disciplina } {
	}

	void doUndo() override {
		this->repo.adaugaRepo(disciplinaStearsa);
	}
};

class UndoModifica : public UndoActiuni {
	Disciplina disciplinaModificata;
	RepoAbs& repo;

public:
	UndoModifica(RepoAbs& repo, const Disciplina& disciplina) : repo{ repo }, disciplinaModificata{ disciplina } {
	}

	void doUndo() override {
		this->repo.modificaRepo(disciplinaModificata);
	}
};

#endif /* UNDO_H_ */
