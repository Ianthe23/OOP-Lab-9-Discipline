#ifndef DOMAIN_H_
#define DOMAIN_H_

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class DTO {
	string entity_type;
	int count;

public:
	DTO(const string& entity_type, int count) : entity_type{ entity_type }, count{ count } {};

	DTO(const string& entity_type) : entity_type{ entity_type }, count{ 0 } {};

	DTO() : entity_type{ "" }, count{ 0 } {};

	[[nodiscard]] const string& get_entity_type() const noexcept {
		return entity_type;
	}

	[[nodiscard]] int get_count() const noexcept {
		return count;
	}
	
};

class Disciplina {

private:
	string denumire;
	int ore;
	string tip;
	string profesor;

public:
	/*
	* Constructorul disciplinei
	* 
	* O disciplina contine: 
		-	denumire 
		-	ore pe saptamana 
		-	tip
		-	profesor
	*/
	Disciplina(const string& denumire, int ore, const string& tip, const string& profesor);

	/*
	* Constructorul implicit
	*/
	Disciplina();

	/*
	* Destructorul
	*/
	~Disciplina();

	/*
	* Copia constructorului - pt copiere
	*/
	Disciplina(const Disciplina& disciplina);


	/// GETTERS

	//get numele disciplinei
	[[nodiscard]] const string& get_denumire() const noexcept;/// nodiscard - valoarea returnata trb folosita si NU ignorata

	//get numarul de ore
	[[nodiscard]] int get_ore() const noexcept;

	//get tipul disciplinei
	[[nodiscard]] const string& get_tip() const noexcept;

	//get numele profesorului
	[[nodiscard]] const string& get_profesor() const noexcept;


	/// SETTERS -> modificabili sunt doar tipul si orele pe saptamana!!

	//set numarul de ore
	[[maybe_unused]] void set_ore(int ore_noi) noexcept;///maybe_unused - este OK daca valoarea returnata NU este folosita

	//set tipul disciplinei
	[[maybe_unused]] void set_tip(const string& tip_nou);

	[[maybe_unused]] void set_profesor(const string& profesor_nou);

	[[maybe_unused]] void set_denumire(const string& denumire_noua);


	/*
	* functie de printare
	*/
	string to_string_print() const;


	/// OPERATORI

	//operator de asignare a copiei
	Disciplina& operator=(const Disciplina& copie);

	//operator de egalitate dintre 2 obiecte -> 2 obiecte sunt egale
	// daca numele si profesorul fiecaruia sunt egale
	bool operator==(const Disciplina& copie) noexcept;
	bool operator!=(const Disciplina& copie) noexcept;
	friend std::istream & operator>>(std::istream &input, Disciplina &disciplina);
};

/// COMPARATORI

//returneaza TRUE daca disc_1.denumire < disc_2.denumire
bool cmpDenumire(const Disciplina& disc_1, const Disciplina& disc_2) noexcept;

//returneaza TRUE daca disc_1.ore < disc_2.ore
bool cmpOre(const Disciplina& disc_1, const Disciplina& disc_2) noexcept;

//returneaza TRUE daca disc_1.profesor < disc_2.profesor
bool cmpProfesor(const Disciplina& disc_1, const Disciplina& disc_2) noexcept;

//returneaza TRUE daca disc_1.profesor < disc_2.profesor && daca disc_1.profesor == disc_2.profesor,
// atunci disc_1.tip < disc_2.tip
bool cmpProfTip(const Disciplina& disc_1, const Disciplina& disc_2) noexcept;

std::ostream& operator <<(std::ostream& output, const Disciplina& disciplina);

vector<string> split(const string& input, char delimiter);

#endif /* DOMAIN_H_ */
