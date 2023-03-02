#include <iostream>
using namespace std;

void printNewLine() {
	cout << "\n";
}

class Monster {
public:
	explicit Monster() {
		this->type = "Monster";
		this->name = "Monster";
		this->hp = 100;
		this->damage = 10;
	}

	explicit Monster(string name) {
		this->type = "Monster";
		this->name = name;
		this->hp = 100;
		this->damage = 10;
	}

	void printMonster() {
		cout << "Type: " << this->type << "\n";
		cout << "Name: " << this->name << "\n";

		if (this->hp > 0)
			cout << "Hp: " << this->hp << "\n";
		else
			cout << "Hp: " << "Dead..." << "\n";

		cout << "Damage: " << this->damage << "\n";

		printNewLine();
	}

	void Attack(Monster& monster) {
		if (this->hp > 0 && monster.hp > 0)
			monster.hp -= this->damage;
		else
			return;

		if (monster.hp > 0) {
			cout << "\"" << this->name << "\"" << " Attacked " << "\"" << monster.name << "\"" << " for " << this->damage << "hp"; printNewLine(); printNewLine();
		}
		else {
			cout << "\"" << this->name << "\"" << " Killed " << "\"" << monster.name << "\""; printNewLine(); printNewLine();
		}
	}
protected:
	string type;
	string name;
	int damage;
	int hp;
};

class Orc : public Monster {
public:
	explicit Orc() {
		this->type = "Orc";
		this->hp = 130;
		this->damage = 20;
	}
	explicit Orc(string name) {
		this->type = "Orc";
		this->name = name;
		this->hp = 130;
		this->damage = 20;
	}
};

class Troll : public Monster {
public:
	explicit Troll() {
		this->type = "Troll";
		this->hp = 145;
		this->damage = 5;
	}
	explicit Troll(string name) {
		this->type = "Troll";
		this->name = name;
		this->hp = 145;
		this->damage = 5;
	}
};

class Zombie : public Monster {
public:
	explicit Zombie() {
		this->type = "Zombie";
		this->hp = -90;
		this->damage = 25;
	}
	explicit Zombie(string name) {
		this->type = "Zombie";
		this->name = name;
		this->hp = -90;
		this->damage = 25;
	}
};

class Goblin : public Monster {
public:
	explicit Goblin() {
		this->type = "Goblin";
		this->hp = 20;
		this->damage = 60;
	}
	explicit Goblin(string name) {
		this->type = "Goblin";
		this->name = name;
		this->hp = 40;
		this->damage = 160;
	}
};


int main() {
	Goblin gobl("goblin Alex");
	Zombie zomb("zombie Alex");
	Troll trl("troll Alex");

	decltype(auto) goblin = gobl;
	decltype(auto) zombie = zomb;
	decltype(auto) troll = trl;

	goblin.printMonster();
	zombie.printMonster();
	troll.printMonster();

	troll.Attack(goblin); //orc.printMonster();
	goblin.Attack(troll); //troll.printMonster();

	return 0;
}

/*
В грі мають бути монстри, тому що всім подобається бити їх. Оголосіть клас, який описує монстра. Монстри можуть
бути різними: орки, тролі, зомбі, ґобліни. Можна зробити перелік констант, який відповідатиме типу монстра.
Кожен монстр має мати ім’я (використовуйте std::string) і кількість здоров’я, яке відображає, скільки шкоди він може
отримати, перш ніж помре. Напишіть функцію printMonster(), яка виведе відомості про монстра. 
Оголосіть монстрів кількох типів, ініціалізуйте їх (зокрема з використанням auto і присвоєнням конструктора). 
У випадках оголошення складних типів даних використовуйте ключове слово auto. П
ри створення нових монстрів використовуйте decltype для їх оголошення.
*/
