#include "tests.h"
#include <sstream>
#include <fstream>

using namespace std;

void Tests::testAll() {
	testDomain();
	testRepo();
	testValidator();
	testService();
	testRepoFile();
}

void Tests::testDomain() {
	testConstructor_Getters();
	testCopyConstructor();
	testSetters();
	testToString();
	testOperatori();
	testComparatori();
	testDTO();
	testCopyDTO();
	testGetDTO();
	testSplit();
}

void Tests::testRepo() {
	testAdaugaRepo();
	testModificaRepo();
	testCautaRepo();
	testStergeRepo();
	testGet_disciplina();
	testRepoProb();
	testBadLuck();
	testAdaugaRepoProb();
	testModificaRepoProb();
	testCautaRepoProb();
	testStergeRepoProb();
	testGet_disciplinaProb();
	testGetAll();
}

void Tests::testRepoFile() {
	testFile();
	testEmptyFile();
	testSetPath();
}

void Tests::testService() {
	testAdaugaSrv();
	testUndoAdauga();
	testModificaSrv();
	testUndoModifica();
	testStergeSrv();
	testUndoSterge();
	testCautaSrv();
	testFiltrare();
	testSortare();

	///teste contract in service
	testContract();
	testAdaugaContract();
	testCautaContract();
	testGenereazaContract();
	testExportaContract();
	testEmptyContract();
	testGetAllContract();

	///teste contract
	test_genereaza_contract();
	test_exporta_contract();
	test_empty_contract();
	test_adauga_la_contract();
	test_getContractsize();
	testRaport();
	testFilterDenumire(); 
}

void Tests::testValidator() {
	Validator val;
	Disciplina test{ "mate", 3, "real", "Alexe" };
	Disciplina invalid{};

	val.valideazaDisciplina(test);
	try {
		val.valideazaDisciplina(invalid);
	}
	catch (ValidatorException& mesaj) {
		assert(mesaj.get_mesaj() == "Denumire invalida!\nNumar de ore invalid!\nTip invalid!\nNumele profesorului este invalid!\n");
	}
}

/// 
/// DOMAIN
/// 

void Tests::testConstructor_Getters() {
	Disciplina test_disciplina{ "mate",3,"real","Alexe" };
	assert(test_disciplina.get_denumire() == "mate");
	assert(test_disciplina.get_ore() == 3);
	assert(test_disciplina.get_tip() == "real");
	assert(test_disciplina.get_profesor() == "Alexe");

	Disciplina test_implicit{};
	assert(test_implicit.get_denumire().empty());
	assert(test_implicit.get_ore() == 0);
	assert(test_implicit.get_tip().empty());
	assert(test_implicit.get_profesor().empty());
}

void Tests::testCopyConstructor() {
	Disciplina test_disciplina{ "mate",3,"real","Alexe" };
	Disciplina test_copy(test_disciplina);
	assert(test_copy.get_denumire() == "mate");
	assert(test_copy.get_ore() == 3);
	assert(test_copy.get_tip() == "real");
	assert(test_copy.get_profesor() == "Alexe");
}

void Tests::testSetters() {
	Disciplina test_disciplina{ "mate",3,"real","Alexe" };

	test_disciplina.set_tip("uman");
	assert(test_disciplina.get_tip() == "uman");

	test_disciplina.set_ore(4);
	assert(test_disciplina.get_ore() == 4);

	test_disciplina.set_profesor("Ionescu");
	assert(test_disciplina.get_profesor() == "Ionescu");

	test_disciplina.set_denumire("info");
	assert(test_disciplina.get_denumire() == "info");
}

void Tests::testToString() {
	Disciplina test_disciplina{ "mate",3,"real","Alexe" };
	assert(test_disciplina.to_string_print() == "\t\033[1;33mDenumire: \033[0mmate;   \033[1;33mOre: \033[0m3;   "
		"\033[1;33mTip: \033[0mreal;   \033[1;33mProfesor: \033[0mAlexe.");
}

void Tests::testOperatori() {
	Disciplina test1{ "mate",3,"real","Alexe" };
	assert(test1.operator==(test1));

	Disciplina test2;
	test2.operator=(test1);
	assert(test2.get_denumire() == "mate");
	assert(test2.get_ore() == 3);
	assert(test2.get_tip() == "real");
	assert(test2.get_profesor() == "Alexe");

	Disciplina test3{ "info",4,"uman","Ionescu" };
	assert(test1.operator!=(test3));

	//teste pt operatorii citire si afisare
	Disciplina test4{};
	istringstream input("mate,3,real,Alexe");
	input >> test4;
	assert(test4.get_denumire() == "mate");
	assert(test4.get_ore() == 3);
	assert(test4.get_tip() == "real");
	assert(test4.get_profesor() == "Alexe");

	ostringstream output;
	output << test4;
	string outp = output.str();
	assert(outp == "mate,3,real,Alexe\n");
}

void Tests::testComparatori() {
	Disciplina test1{ "info",3,"real","Alexe" };
	Disciplina test2{ "mate",6,"real","Ionescu" };

	assert(cmpDenumire(test1, test2) == true);
	assert(cmpDenumire(test2, test1) == false);

	assert(cmpOre(test1, test2) == true);
	assert(cmpOre(test2, test1) == false);

	assert(cmpProfesor(test1, test2) == true);
	assert(cmpProfesor(test2, test1) == false);

	assert(cmpProfTip(test1, test2) == true); 
	assert(cmpProfTip(test2, test1) == false);

	Disciplina test3{ "mateM2",4,"uman","Alexe" };

	assert(cmpProfTip(test1, test3) == true);
	assert(cmpProfTip(test3, test1) == false);
}

void Tests::testDTO() {
	DTO test{ "real", 3 };
	assert(test.get_count() == 3);
}

void Tests::testCopyDTO() {
	DTO test{ "real", 3 };
	DTO test_copy(test);
	assert(test_copy.get_count() == 3);
}

void Tests::testGetDTO() {
	DTO test{ "real", 3 };
	assert(test.get_entity_type() == "real");
	assert(test.get_count() == 3);
}

void Tests::testSplit() {
	string test = "mate,3,real,Alexe";
	vector<string> rezultat = split(test, ',');
	assert(rezultat[0] == "mate");
	assert(rezultat[1] == "3");
	assert(rezultat[2] == "real");
	assert(rezultat[3] == "Alexe");

}
///
/// REPO
/// 

void Tests::testAdaugaRepo() {
	vector<Disciplina> teste;
	Repo repo(teste);
	Disciplina test{ "info",3,"real","Alexe" };

	repo.adaugaRepo(test);
	try {
		repo.adaugaRepo(test);
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina deja exista!\n");
	}

	assert(test.operator == (repo.get_disciplina("info", "Alexe")));
}

void Tests::testCautaRepo() {
	vector<Disciplina> teste;
	Repo repo(teste);
	Disciplina test{ "info",3,"real","Alexe" };
	repo.adaugaRepo(test);
	assert(repo.cautaRepo("info", "Alexe") == 0);
	assert(repo.cautaRepo("mate", "Ionescu") == -1);
}

void Tests::testModificaRepo() {
	vector<Disciplina> teste;
	Repo repo(teste);
	Disciplina test{ "info",3,"real","Alexe" };
	Disciplina test1{ "info",4,"uman","Alexe" };
	Disciplina test2{ "mate", 2, "real", "Ionescu" };

	repo.adaugaRepo(test);
	repo.modificaRepo(test1);

	assert(repo.cautaRepo("info", "Alexe") == 0);

	try {
		repo.modificaRepo(test2);
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}

	const vector<Disciplina> discipline = repo.getAll();
	assert(discipline.size() == 1);
}

void Tests::testStergeRepo() {
	vector<Disciplina> teste;
	Repo repo(teste);
	Disciplina test{ "info",3,"real","Alexe" };

	repo.adaugaRepo(test);
	repo.stergeRepo("info", "Alexe");
	try {
		repo.stergeRepo("info", "Alexe");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}
}

void Tests::testGet_disciplina() {
	vector<Disciplina> teste;
	Repo repo(teste);
	Disciplina test{ "info",3,"real","Alexe" };

	repo.adaugaRepo(test);
	assert(test.operator == (repo.get_disciplina("info", "Alexe")));
	try {
		repo.get_disciplina("mate", "Ionescu");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}
}

void Tests::testFile() {
	Disciplina test{ "info",3,"real","Alexe" };
	Disciplina test1{ "mate",4,"uman","Ionescu" };

	FileRepo file("test_file.txt");
	file.adaugaRepo(test);
	file.adaugaRepo(test1);

	const vector<Disciplina>& discipline = file.getAll();
	assert(file.getAll().size() == 2);

	file.emptyFile();
}

void Tests::testEmptyFile() {
	Disciplina test{ "info",3,"real","Alexe" };

	FileRepo file("test_file.txt");
	file.emptyFile();
	file.adaugaRepo(test);

	const vector<Disciplina>& discipline = file.getAll();
	assert(discipline.size() == 1);

	file.emptyFile();
	const vector<Disciplina>& discipline1 = file.getAll();
	assert(discipline1.size() == 1);

	file.emptyFile();

}

void Tests::testSetPath() {
	Disciplina test{ "info",3,"real","Alexe" };

	FileRepo file("test_file.txt");
	file.emptyFile();

	file.adaugaRepo(test);
	file.setPath("test_file1.txt");
	
	const vector<Disciplina>& discipline = file.getAll();
	assert(discipline.size() == 1);

	file.emptyFile();

	file.setPath("test_file.txt");
	file.emptyFile();
}

void Tests::testRepoProb() {
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };
	Disciplina test1{ "mate",4,"uman","Ionescu" };

	repo.adaugaRepo(test);
	repo.adaugaRepo(test1);

	const vector<Disciplina>& discipline = repo.getAll();
	assert(discipline.size() == 2);

	repo.modificaRepo(test1);
	assert(discipline[1].get_ore() == 4);

	repo.stergeRepo("info", "Alexe");
	const vector<Disciplina>& discipline1 = repo.getAll();
	assert(discipline1.size() == 1);
}

void Tests::testBadLuck() {
	RepoProb repo(0);
	Disciplina test{ "info",3,"real","Alexe" };

	try {
		repo.adaugaRepo(test);
	}
	catch (BadLuckException& mesaj) {
		assert(mesaj.get_mesaj() == "Teapa curata!\n");
	}

}

void Tests::testAdaugaRepoProb() {
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };

	repo.adaugaRepo(test);

	assert(repo.getAll().size() == 1);
}

void Tests::testModificaRepoProb() {
	vector<Disciplina> teste;
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };
	Disciplina test1{ "info",4,"uman","Alexe" };
	Disciplina test2{ "mate", 2, "real", "Ionescu" };

	repo.adaugaRepo(test);
	repo.modificaRepo(test1);

	assert(repo.cautaRepo("info", "Alexe") == 0);

	const vector<Disciplina> discipline = repo.getAll();
	assert(discipline.size() == 1);
}

void Tests::testCautaRepoProb() {
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };
	repo.adaugaRepo(test);
	assert(repo.cautaRepo("info", "Alexe") == 0);
	assert(repo.cautaRepo("mate", "Ionescu") == -1);
}

void Tests::testStergeRepoProb() {
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };

	repo.adaugaRepo(test);
	repo.stergeRepo("info", "Alexe");

	assert(repo.getAll().size() == 0);	
}

void Tests::testGet_disciplinaProb() {
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };

	repo.adaugaRepo(test);
	assert(test.operator == (repo.get_disciplina("info", "Alexe")));
	try {
		repo.get_disciplina("mate", "Ionescu");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}
}

void Tests::testGetAll() {
	RepoProb repo(1);
	Disciplina test{ "info",3,"real","Alexe" };
	Disciplina test1{ "mate",4,"uman","Ionescu" };

	repo.adaugaRepo(test);
	repo.adaugaRepo(test1);

	const vector<Disciplina>& discipline = repo.getAll();
	assert(discipline.size() == 2);

	repo.stergeRepo("info", "Alexe");
	repo.stergeRepo("mate", "Ionescu");
	const vector<Disciplina>& discipline1 = repo.getAll();
	assert(discipline1.size() == 0);
}

///
/// SERVICE
///

void Tests::testAdaugaSrv() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();

	service.adaugaSrv("info", 3, "real", "Alexe");

	const vector<Disciplina>& discipline = service.getAll();
	assert(discipline.size() == 1);

	try {
		service.adaugaSrv("info", 3, "real", "Alexe");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina deja exista!\n");
	}

	repo.emptyFile();
}

void Tests::testUndoAdauga() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.undo();
	const vector<Disciplina>& discipline = service.getAll();
	assert(discipline.size() == 0);

	try {
		service.undo();
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Nu mai exista actiuni de undo!\n");
	}

	repo.emptyFile();
}

void Tests::testCautaSrv() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };

	service.adaugaSrv("info", 3, "real", "Alexe");

	const vector<Disciplina>& discipline = service.getAll();
	assert(discipline.size() == 1);

	assert(test.operator==(service.cautaSrv("info", "Alexe")));
	try {
		service.cautaSrv("mate", "Ionescu");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}

	repo.emptyFile();
}

void Tests::testModificaSrv() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "info", 4, "uman", "Alexe" };

	service.adaugaSrv("info", 3, "real", "Alexe");

	service.modificaSrv("info", 4, "uman", "Alexe");
	assert(test1.operator==(service.cautaSrv("info", "Alexe")));

	try {
		service.modificaSrv("mate", 4, "uman", "Ionescu");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}

	repo.emptyFile();
}

void Tests::testUndoModifica() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.modificaSrv("info", 4, "uman", "Alexe");
	service.undo();
	const vector<Disciplina>& discipline = service.getAll();
	assert(discipline.size() == 1);

	Disciplina modificat = service.cautaSrv("info", "Alexe");
	assert(modificat.get_ore() == 3);
	assert(modificat.get_tip() == "real");

	repo.emptyFile();
}

void Tests::testStergeSrv() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "info", 4, "uman", "Alexe" };

	service.adaugaSrv("info", 3, "real", "Alexe");

	const vector<Disciplina>& discipline = service.getAll();
	assert(discipline.size() == 1);
	service.stergeSrv("info", "Alexe");
	assert(discipline.size() == 0);

	try {
		service.stergeSrv("info", "Alexe");
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}

	repo.emptyFile();

}

void Tests::testUndoSterge() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.stergeSrv("info", "Alexe");

	const vector<Disciplina>& discipline = service.getAll();
	assert(discipline.size() == 0);

	service.undo();
	const vector<Disciplina>& discipline1 = service.getAll();
	assert(discipline1.size() == 1);

	repo.emptyFile();
}

void Tests::testSortare() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };
	service.adaugaSrv("mate", 4, "uman", "Ionescu");
	service.adaugaSrv("info", 3, "real", "Alexe");

	vector<Disciplina> sortat_nume = service.sortDenumire();
	assert(test.operator == (sortat_nume[0]));
	assert(test1.operator == (sortat_nume[1]));

	vector<Disciplina> sortat_ore = service.sortOre();
	assert(test.operator == (sortat_ore[0]));
	assert(test1.operator == (sortat_ore[1]));

	vector<Disciplina> sortat_ProfTip = service.sortProfTip();
	assert(test.operator == (sortat_ProfTip[0]));
	assert(test1.operator == (sortat_ProfTip[1]));

	service.stergeSrv("info", "Alexe");
	vector<Disciplina> sortat= service.sortDenumire();
	assert(test1.operator==(sortat[0]));
	service.stergeSrv("mate", "Ionescu");

	repo.emptyFile();

}

void Tests::testFiltrare() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	vector<Disciplina> filtrat_ore = service.filterOre(3);
	assert(test.operator==(filtrat_ore[0]));

	vector<Disciplina> filtrat_profesor = service.filterProfesor("Ionescu");
	assert(test1.operator==(filtrat_profesor[0]));

	repo.emptyFile();

}

void Tests::testContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	contract.adaugaContract(test);
	contract.adaugaContract(test1);

	const vector<Disciplina>& discipline = contract.get_contract();
	assert(discipline.size() == 2);

	contract.emptyContract();
	assert(discipline.size() == 0);

	contract.genereazaContract(1, service.getAll());
	assert(discipline.size() == 1);

	repo.emptyFile();
}

void Tests::testAdaugaContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	contract.adaugaContract(test);
	contract.adaugaContract(test1);

	const vector<Disciplina>& discipline = contract.get_contract();
	assert(discipline.size() == 2);

	//adauga la contract o disciplina care exista deja
	try {
		contract.adaugaContract(test);
	}
	catch (ContractException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina deja exista!");
	}

	repo.emptyFile();
}

void Tests::testCautaContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };

	service.adaugaSrv("info", 3, "real", "Alexe");

	contract.adaugaContract(test);
	assert(contract.cautaContract("info", "Alexe") == 0);
	assert(contract.cautaContract("mate", "Ionescu") == -1);

	repo.emptyFile();
}

void Tests::testGenereazaContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	contract.genereazaContract(1, service.getAll());
	const vector<Disciplina>& discipline = contract.get_contract();
	assert(discipline.size() == 1);

	//genereaza contract cu mai multe discipline decat exista in memorie
	try {
		contract.genereazaContract(3, service.getAll());
	}
	catch (ContractException& mesaj) {
		assert(mesaj.get_mesaj() == "Nu exista suficiente discipline in memorie!");
	}

	repo.emptyFile();
}

void Tests::testExportaContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	contract.genereazaContract(1, service.getAll());
	contract.exportContract("contract1");

	contract.exportContract("contract.html");

	repo.emptyFile();
}

void Tests::testEmptyContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	contract.genereazaContract(1, service.getAll());
	contract.emptyContract();
	const vector<Disciplina>& discipline = contract.get_contract();
	assert(discipline.size() == 0);

	repo.emptyFile();
}

void Tests::testGetAllContract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	contract.genereazaContract(1, service.getAll());
	const vector<Disciplina>& discipline = service.getAllContract();
	assert(discipline.size() == 1);

	repo.emptyFile();
}

void Tests::test_adauga_la_contract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	// Add disciplines to the repository
	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");
	service.adaugaSrv("info", 4, "real", "Popescu");

	// Add discipline to the contract that exists in the repository
	service.adauga_la_contract("mate", "Ionescu", {});

	const vector<Disciplina>& discipline = contract.get_contract();

	// Assert that the contract contains the added discipline
	assert(discipline.size() == 1);

	try {
		service.adauga_la_contract("info", "Ionescu", {});
	}
	catch (RepoException& mesaj) {
		assert(mesaj.get_mesaj() == "Disciplina nu exista!\n");
	}

	auto filtru = service.filterDenumire("info");
	service.adauga_la_contract("info", "Pop", filtru);
	assert(discipline.size() == 2);

	repo.emptyFile();
}

void Tests::test_genereaza_contract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	service.genereaza_contract(1);
	const vector<Disciplina>& discipline = contract.get_contract();
	assert(discipline.size() == 1);

	repo.emptyFile();
}

void Tests::test_exporta_contract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	service.genereaza_contract(1);
	service.exporta_contract("contract.txt");

	repo.emptyFile();
}

void Tests::test_empty_contract() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	service.genereaza_contract(1);
	service.empty_contract();
	const vector<Disciplina>& discipline = contract.get_contract();
	assert(discipline.size() == 0);

	repo.emptyFile();
}

void Tests::test_getContractsize() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	service.genereaza_contract(1);
	assert(service.getContractsize() == 1);

	repo.emptyFile();
}

void Tests::testRaport() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	map<string, DTO> raport = service.raport();
	assert(raport["real"].get_count() == 1);
	assert(raport["uman"].get_count() == 1);

	repo.emptyFile();
}

void Tests::testFilterDenumire() {
	FileRepo repo("test_service.txt");
	Validator validator;
	Contract contract;
	Service service(repo, validator, contract);

	repo.emptyFile();
	Disciplina test{ "info", 3, "real", "Alexe" };
	Disciplina test1{ "mate", 4, "uman", "Ionescu" };

	service.adaugaSrv("info", 3, "real", "Alexe");
	service.adaugaSrv("mate", 4, "uman", "Ionescu");

	vector<Disciplina> filtrat = service.filterDenumire("info");
	assert(test.operator==(filtrat[0]));

	repo.emptyFile();
}
