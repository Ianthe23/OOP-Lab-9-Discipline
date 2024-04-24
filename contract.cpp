#include "contract.h"
#include "exceptions.h"

void Contract::adaugaContract(const Disciplina& disciplina) {
	const string& denumire = disciplina.get_denumire();
	const string& profesor = disciplina.get_profesor();

	if (cautaContract(denumire, profesor) != -1) {
		throw ContractException("Disciplina deja exista!");
	}
	else {
		this->contract.push_back(disciplina);
	}
}

int Contract::cautaContract(const string& denumire, const string& profesor) {
	auto iterator = find_if(this->contract.begin(),
		this->contract.end(), [denumire, profesor](const Disciplina& disciplina) noexcept {
			if (disciplina.get_denumire() == denumire && disciplina.get_profesor() == profesor)
				return true;
			return false;
		});

	auto const poz = std::distance(this->contract.begin(), iterator);

	if (iterator != this->contract.end()) {
		return poz;
	}

	return -1;
}

void Contract::emptyContract() noexcept{
	this->contract.clear();
}

void Contract::genereazaContract(int nr_discipline, const vector<Disciplina>& memorie) {
	if (nr_discipline > memorie.size()) {
		throw ContractException("Nu exista suficiente discipline in memorie!");
	}
	emptyContract();
	auto to_contract = memorie;
	shuffle(to_contract.begin(), to_contract.end(), std::default_random_engine(time(0)));

	while (nr_discipline && !to_contract.empty()) {
		adaugaContract(to_contract.back());
		to_contract.pop_back();
		nr_discipline--;
	}
}

const vector<Disciplina>& Contract::get_contract() {
	return this->contract;
}

void Contract::exportContract(const string& nume_fisier) {
	string filename = nume_fisier;
	auto poz = filename.find_first_of(".");

	if (poz < filename.size()) {
		auto file_extension = nume_fisier.substr(poz);
		if (file_extension != ".html") {
			filename = filename + ".html";
		}

	}
	else {
		filename += ".html";
	}

	std::ofstream fout(filename);
	fout << "<html>\n"
		"<body>\n"
		"<head>\n"
		"	<h3 style=\" font-family: 'Cascadia Mono',serif; color: #81A40D; \">Discipline contractate</h3>\n"
		"	</head>\n"
		"<style>\n"
		"	p {\n"
		"		color: #D7BDE2 ;\n"
		"		background-color: #A9CCE3 ;\n"
		"		border: 1px solid black; }\n"
		"	table,th,td{\n"
		"		border: 1px solid black;\n"
		"       font-size: 20px;\n" // Set the font size to 20px
		"	}\n"
		"	th{\n"
		"		color: RosyBrown;\n"
		"	}\n"
		"	body{\n"
		"		background-color: #FFEFD5 ;\n"
		"   }\n"
		"</style>\n";

	fout << "<table>\n"
		"\n"
		"		<th>Denumire</th>\n"
		"		<th>Ore</th>\n"
		"       <th>Tip</th>\n"
		"		<th>Profesor</th>\n";

	for (const Disciplina& disciplina : get_contract()) {
		fout << "<tr>\n";
		fout << "<th>" << disciplina.get_denumire() << "</th>\n"
			<< "<th>" << disciplina.get_ore() << "</th>\n"
			<< "<th>" << disciplina.get_tip() << "</th>\n"
			<< "<th>" << disciplina.get_profesor() << "</th>\n"
			<< "</tr>\n";
	}

	fout << "</table>\n"
		"\n"
		"\n"
		"</body>\n"
		"</html>";

}
