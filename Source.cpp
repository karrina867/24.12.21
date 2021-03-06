#include "Creature.h"
#include"Player.h"
#include"Monster.h"
#include<ctime>
using namespace std;
/*class Fruit {
protected:
	string m_name;
	string m_color;
public:
	Fruit(string name,string color):m_name{name}, m_color{color}
	{}
	string getName() { return m_name; }
	string getColor() { return m_color; }
};
class Apple :public Fruit {
public:
	Apple(string color, string name = "apple" ):Fruit(name,color)
	{}
};
class Banana :public Fruit {
public:
	Banana(string color = "yellow", string name = "banana") :Fruit(name, color)
	{}
};
class GrannySmith :public Apple {
public:
	GrannySmith(string color = "green", string name = "GrannySmith apple"):Apple(color,name)
	{}
};*/
void attackMonster (Player& p, Monster& m);
void attackPlayer(Player& p, Monster m);
int main() {
	/*Apple a("red");
	Banana b;
	GrannySmith c;
	cout << "my " << a.getName() << " is " << a.getColor() << ".\n";
	cout << "my " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "my " << c.getName() << " is " << c.getColor() << ".\n";*/
	srand(time(0));
	rand();
	Player p("vova");
	while (!p.isDead() && !p.hasWon()) {
		Monster m = Monster::getRandomMonster();
		cout << "You have encountered a " << m.getName() << endl;
		char input;
		cout << "(R)un or (F)ight:";
		cin >> input;
		if (input == 'R' || input == 'r') {
			if (rand() % 100 < 50) {
				cout << "You seccessfull fled" << endl;
				continue;
			}
			else {
				//монстр бьёт игрока
				attackPlayer(p, m);
			}
		}
		//выбрал сражение
		if (input == 'F' || input == 'f') {
			attackMonster(p, m);
			attackPlayer(p, m);
		}
			//игрок бьёт монстра
			//монстр вьёт игрока
		}
	if (p.isDead ()){
		cout << "You died!" << endl;
	}
	else if (p.hasWon()) {
		cout << "You win!" << endl;
	}
	return 0;
}
void attackMonster(Player& p, Monster& m) {
	cout << "You hit " << m.getName() << " for " << p.getDamage() << " damage " << endl;
	m.reduceHealth(p.getDamage());
	if (m.isDead()) {
		cout << "You kill " << m.getName() << endl;
		p.levelUp();
		cout << "Your Level is " << p.getLevel() << endl;
		p.addGold(m.getGold());
		cout << "You found " << p.getGold() <<" gold "<< endl;
	}
}
void attackPlayer(Player& p, Monster m) {
	if (m.isDead())return;
	cout << m.getName() << "hit you for " << m.getDamage() << " damage " << endl;
	p.reduceHealth(m.getDamage());
}