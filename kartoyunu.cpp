#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;
class manaColor {
public:
	int green;
	int blue;
	int white;
	int black;
	int red;
	int all;
};


class Effect {
public:

};


class Card :public manaColor {
protected:
	string name;
	string type;
	manaColor manaCost;
	string theMana;
	int attack;
	int HP; // extra attribute for creature cards
	int tap; // 0: untapped 1:tapped
	string ability;
	Effect* Effectt;
	string color;
public:

	Card() {
		color = "None";
		ability = "";
		manaCost.black = 0;
		manaCost.blue = 0;
		manaCost.green = 0;
		manaCost.red = 0;
		manaCost.white = 0;
		manaCost.all = 0;
		tap = 0;
		Effectt = NULL;
		HP = 0;
		attack = 0;
	}
	void setHP(int HP_) {
		HP = HP_;
	}
	int getHP() {
		return HP;
	}
	void setcolor(string color_) {
		color = color_;
	}
	string getcolor() {
		return color;
	}
	void setattack(int attack_) {
		attack = attack_;
	}
	int getattack() {
		return attack;
	}

	virtual void PlayCard() {
		cout << "BASE";

	}
	void setname(string name_) {
		name = name_;
	}

	string getname() {
		return name;
	}
	void settype(string type_) {
		type = type_;
	}
	string gettype() {
		return type;
	}
	string gettap() {
		if (tap == 0) {
			return "Untapped";
		}
		return "Tapped";
	}
	void setability(string ability_) {
		ability = ability_;
	}
	string getability() {
		return ability;
	}

	void settap(int tap_) {
		tap = tap_;
	}
	void settheMana(string theMana_) {
		theMana = theMana_;
	}
	string gettheMana() {
		return theMana;
	}

	void arrangeManaCost() {
		if (type == "Land") {
			if (theMana == "G") {
				manaCost.green = 1;
			}
			else if (theMana == "L") {
				manaCost.blue = 1;
			}
			else if (theMana == "R") {
				manaCost.red = 1;
			}
			else if (theMana == "W") {
				manaCost.white = 1;
			}
			else if (theMana == "B") {
				manaCost.black = 1;
			}

		}
		else {
			int i;
			for (i = 0; i < theMana.size(); i++) {
				if (theMana[i] == 'G') {
					manaCost.green++;
				}
				else if (theMana[i] == 'L') {
					manaCost.blue++;
				}
				else if (theMana[i] == 'W') {
					manaCost.white++;

				}
				else if (theMana[i] == 'R') {
					manaCost.red++;
				}
				else if (theMana[i] == 'B') {
					manaCost.black++;
				}
				else {
					manaCost.all = manaCost.all + (theMana[i] - '0');
				}
			}


		}
	}



};
class DestroyCreatureEffect :public Effect { //Sorcery
public:
	void Affect() {



	}
};
class DestroyEnchantmentEffect :public Effect { //Sorcery
public:
	void Affect() {
		;
	}
};

class DestroyLandEffect :public Effect { //Sorcery
public:
	void Affect() {
		;
	}
};
class TwoDamageEffect :public Effect { //Sorcery
public:
	void Affect() {
		;
	}
};
class ReturnFromDiscardEffect :public Effect { //Sorcery
public:
	void Affect() {
		;
	}
};
class OneDamageAllEffect :public Effect { //Sorcery
public:
	void Affect() {
		;
	}
};

class CreatureTrampleEffect :public Effect { // 1 Target creature gains Trample
public:
	void Affect() {
		;
	}
};

class OneOneToWhiteEffect :public Effect { // All white creatures gain +1/+1
public:
	void Affect() {
		;
	}
};

class OneOneToBlackEffect :public Effect { // All black creatures gain -1/-1
public:
	void Affect() {
		;
	}
};

class TwoZeroToBlackEffect :public Effect { // All black creatures gain +2/+0
public:
	void Affect() {
		;
	}
};

class LoseTrampleGreenEffect :public Effect {
public:
	void Affect() {
		;
	}
};

class TargetLoseStrikeEffect :public Effect {
public:
	void Affect() {
		;
	}
};








class Player :public Card {
protected:
	int HP;
	manaColor Mana;

public:
	vector<Card> hand;
	vector<Card> deck; //library
	vector<Card> Inplay;
	vector<Card> Discards;
		void deck_push_back(Card Added) {
			deck.push_back((Added));
		}
		int getHP() {
			return HP;
		}
		void setHP(int HP_) {
			HP = HP_;
		}
		void getMana() {
			cout << "Green: " << Mana.green << " Black: " << Mana.black << " Red: " << Mana.red << " Blue: " << Mana.blue << " White: " << Mana.white << endl;
		}
		int HandSize() {
			return hand.size();
		}
		int DeckSize() {
			return deck.size();
		}
		int InplaySize() {
			return Inplay.size();
		}
		int DiscardsSize() {
			return Discards.size();
		}

		void GetCardFromDeck() {
			int index;
			if (hand.size() < 7) {
				if (deck.size() > 1) {
					index = rand() % deck.size();
					hand.push_back(deck[index]);
					deck.erase(deck.begin() + index);
				}
				else if (deck.size() == 1) {
					hand.push_back(deck[0]);
					deck.erase(deck.begin());
				}
				else {
					cout << "Deck has no card" << endl;
				}
			}
			else {
				cout << "There are 7 card in hand" << endl;
			}
		}
		void DestroyCardFromInplay(int theindex) {
			int i;
			if (Inplay.size() <= theindex) {
				cout << "Index number is not valid." << endl;
			}
			else {
				Discards.push_back(Inplay[theindex]);
				Inplay.erase(Inplay.begin() + theindex);
				cout << "Creature card is destroyed." << endl;
			}
		}
		void DiscardtoHand(int theindex) {
			int i;
			if (Discards.size() <= theindex) {
				cout << "Index number is not valid." << endl;
			}
			else {
				hand.push_back(Discards[theindex]);
				Discards.erase(Discards.begin() + theindex);
				cout << "Discard card to hand" << endl;
			}
		}

		void GetCardFromHandtoPlay(int choosen) {
			if (hand.size() <= choosen) {
				cout << "Wrong Choose" << endl;
			}
			else if (choosen == -1) {
				;
			}
			else {
				Inplay.push_back(hand[choosen]);
				hand.erase(hand.begin() + choosen);
			}


		}
		void PrintHand() {
			int i;

			for (i = 0; i < hand.size(); i++) {
				if (hand[i].gettype() == "Land") {
					cout << i << "." << hand[i].getname() << " Type: " << hand[i].gettype() << "  " << hand[i].gettap() << endl;
				}
				else if (hand[i].gettype() == "Enchantment") {
					cout << i << "." << hand[i].getname() << " Type: " << hand[i].gettype() << "  " << hand[i].gettap() << endl;
				}
				else if (hand[i].gettype() == "Sorcery") {
					cout << i << "." << hand[i].getname() << " Type: " << hand[i].gettype() << "  " << hand[i].gettap() << endl;
				}
				else if (hand[i].gettype() == "Creature") {
					cout << i << "." << hand[i].getname() << " Type: " << hand[i].gettype() << "  " << hand[i].gettap() << endl;
				}
			}
		}
		void PrintDeck() { //library 
			int i;

			for (i = 0; i < deck.size(); i++) {
				if (deck[i].gettype() == "Land") {
					cout << i << "." << deck[i].getname() << "  " << deck[i].gettap() << endl;
				}
				else if (deck[i].gettype() == "Enchantment") {
					cout << i << "." << deck[i].getname() << "  " << deck[i].gettap() << endl;
				}
				else if (deck[i].gettype() == "Sorcery") {
					cout << i << "." << deck[i].getname() << "  " << deck[i].gettap() << endl;
				}
				else if (deck[i].gettype() == "Creature") {
					cout << i << "." << deck[i].getname() << "  " << deck[i].gettap() << endl;
				}
			}
		}

		void PrintInplay() {
			int i;

			for (i = 0; i < Inplay.size(); i++) {
				if (Inplay[i].gettype() == "Land") {
					cout << i << "." << Inplay[i].getname() << "  " << Inplay[i].gettap() << " " << Inplay[i].gettype() << endl;
				}
				else if (Inplay[i].gettype() == "Enchantment") {
					cout << i << "." << Inplay[i].getname() << "  " << Inplay[i].gettap() << " " << Inplay[i].gettype() << endl;
				}
				else if (Inplay[i].gettype() == "Sorcery") {
					cout << i << "." << Inplay[i].getname() << "  " << Inplay[i].gettap() << " " << Inplay[i].gettype() << endl;
				}
				else if (Inplay[i].gettype() == "Creature") {
					cout << i << "." << Inplay[i].getname() << "  " << Inplay[i].gettap() << " " << Inplay[i].gettype() << endl;
				}
			}

		}
		void PrintDiscards() {
			int i;

			for (i = 0; i < Discards.size(); i++) {
				if (Discards[i].gettype() == "Land") {
					cout << i << "." << Discards[i].getname() << "  " << Discards[i].gettap() << endl;
				}
				else if (Discards[i].gettype() == "Enchantment") {
					cout << i << "." << Discards[i].getname() << "  " << Discards[i].gettap() << endl;
				}
				else if (Discards[i].gettype() == "Sorcery") {
					cout << i << "." << Discards[i].getname() << "  " << Discards[i].gettap() << endl;
				}
				else if (Discards[i].gettype() == "Creature") {
					cout << i << "." << Discards[i].getname() << "  " << Discards[i].gettap() << endl;
				}
			}


		}
	Player() {
		Card buf;
		Inplay.push_back(buf);
		Inplay.pop_back();
		hand.push_back(buf);
		hand.pop_back();
		Discards.push_back(buf);
		Discards.pop_back();
		HP = 15;
		Mana.black = 0;
		Mana.blue = 0;
		Mana.green = 0;
		Mana.red = 0;
		Mana.white = 0;
	}
	void PlayCard(Player& again) { //again is an enemy
		cout << "Player Cards in play" << endl;
		int i;
		int flaggy = 0;
		for (i = 0; i < Inplay.size(); i++) {
			cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << endl;
			flaggy = 1;
		}
		cout << "Enter card that you want to play:";
		int numb;
		cin >> numb;
		cout << "i:" << Inplay.size() - 1 << endl;
		if (Inplay.size() - 1 < numb || numb < 0 || flaggy == 0) {
			cout << "Wrong Index!" << endl;
			return;
		}
		if (Inplay[numb].gettype() == "Land") {
			if (Inplay[numb].gettheMana() == "G") {
				Mana.green++;
			}
			else if (Inplay[numb].gettheMana() == "L") {
				Mana.blue++;
			}
			else if (Inplay[numb].gettheMana() == "R") {
				Mana.red++;
			}
			else if (Inplay[numb].gettheMana() == "W") {
				Mana.white++;
			}
			else if (Inplay[numb].gettheMana() == "B") {
				Mana.black++;
			}
		}
		else if (Inplay[numb].gettype() == "Sorcery") {
			if (Inplay[numb].getname() == "Terror") {
				int flag = 0;
				int indcreature;
				for (i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature") {
						cout << i << ". " << again.Inplay[i].getname() << " Type: " << again.Inplay[i].gettype() << endl;
						flag = 1;
					}

				}
				if (flag == 0) {
					cout << "There is no creature card in enemy cards in play.";
				}
				else {
					cout << "Enter index number of creature card that you want to destroy";
					cin >> indcreature;
					again.DestroyCardFromInplay(indcreature);

				}
			}
			else if (Inplay[numb].getname() == "Lightning Bolt") {
				int dmg;
				int flag = 0;
				int indcreature2;
				cout << "If you want to deal 2 dmg to player press 0, if creature press 1";
				cin >> dmg;
				if (dmg == 0) {
					again.setHP(again.getHP() - 2);
				}
				else if (dmg == 1) {
					for (i = 0; i < again.Inplay.size(); i++) {
						if (again.Inplay[i].gettype() == "Creature") {
							cout << i << ". " << again.Inplay[i].getname() << " Type: " << again.Inplay[i].gettype() << endl;
							flag = 1;
						}

					}
					if (flag == 0) {
						cout << "There is no creature card in enemy cards in play to damage.";
					}
					else {
						cout << "Enter index number of creature card that you want to damage 2 HP point";
						cin >> indcreature2;
						again.Inplay[indcreature2].setHP(again.Inplay[indcreature2].getHP() - 2);

					}


				}

			}
			else if (Inplay[numb].getname() == "Flood") {
				int flag = 0;
				int indland;
				for (i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Land") {
						cout << i << ". " << again.Inplay[i].getname() << " Type: " << again.Inplay[i].gettype() << endl;
						flag = 1;
					}

				}
				if (flag == 0) {
					cout << "There is no land card in enemy cards in play.";
				}
				else {
					cout << "Enter index number of land card that you want to destroy";
					cin >> indland;
					again.DestroyCardFromInplay(indland);

				}
			}
			else if (Inplay[numb].getname() == "Disenchant") {
				int flag = 0;
				int indenc;
				for (i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Enchantment") {
						cout << i << ". " << again.Inplay[i].getname() << " Type: " << again.Inplay[i].gettype() << endl;
						flag = 1;
					}

				}
				if (flag == 0) {
					cout << "There is no enchantment card in enemy cards in play.";
				}
				else {
					cout << "Enter index number of land card that you want to destroy";
					cin >> indenc;
					again.DestroyCardFromInplay(indenc);

				}
			}
			else if (Inplay[numb].getname() == "Plague") {
				cout << "Plague damaged 1 Hp cards below" << endl;
				for (i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature") {
						cout << i << ". " << again.Inplay[i].getname() << " Type: " << again.Inplay[i].gettype() << endl;
						again.Inplay[i].setHP(again.Inplay[i].getHP() - 1);

					}

				}
			}
			else if (Inplay[numb].getname() == "Reanimate") {
				int inddisc;
				for (i = 0; i < Discards.size(); i++) {
					cout << i << ". " << Discards[i].getname() << " Type: " << Discards[i].gettype() << endl;
				}
				if (Discards.size() == 0) {
					cout << "There is any card in discard." << endl;
				}
				else {
					cout << "Enter the index of card that you want to move from discard to hand";
					cin >> inddisc;
					DiscardtoHand(inddisc);
				}

			}
		}
		else if (Inplay[numb].gettype() == "Enchantment") {
			if (Inplay[numb].getname() == "Rage") {
				int flag = 0;
				int indtrample;
				for (i = 0; i < Inplay.size(); i++) {
					if (Inplay[i].gettype() == "Creature") {
						cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << " HP/Attack " << Inplay[i].getHP() << "/" << Inplay[i].getattack() << endl;
						flag = 1;
					}
				}
				if (flag == 0) {
					cout << "There is not any creature card to gain Trample" << endl;
				}
				else {
					cout << "Enter Index of creature card from above that you want to gain Trample";
					cin >> indtrample;
					Inplay[indtrample].setability("Trample");
				}

			}
			else if (Inplay[numb].getname() == "Holy War") {
				int flag = 0;
				for (i = 0; i < Inplay.size(); i++) {
					if (Inplay[i].gettype() == "Creature" && Inplay[i].getcolor() == "White") {
						cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << " HP/Attack " << Inplay[i].getHP() << "/" << Inplay[i].getattack() << endl;
						Inplay[i].setHP(Inplay[i].getHP() + 1);
						Inplay[i].setattack(Inplay[i].getattack() + 1);
						flag = 1;
					}
				}
				if (flag == 0) {
					cout << "There is not any white creature card to gain +1/+1" << endl;
				}
				else {
					cout << "Creatures above gain +1/+1" << endl;
				}
			}
			else if (Inplay[numb].getname() == "Holy Light") {
				int flag = 0;
				for (i = 0; i < Inplay.size(); i++) {
					if (Inplay[i].gettype() == "Creature" && Inplay[i].getcolor() == "Black") {
						cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << " HP/Attack " << Inplay[i].getHP() << "/" << Inplay[i].getattack() << endl;
						Inplay[i].setHP(Inplay[i].getHP() - 1);
						Inplay[i].setattack(Inplay[i].getattack() - 1);
						flag = 1;
					}
				}
				if (flag == 0) {
					cout << "There is not any Black creature card to gain -1/-1" << endl;
				}
				else {
					cout << "Creatures above gain -1/-1" << endl;
				}

			}
			else if (Inplay[numb].getname() == "Unholy War") {
				int flag = 0;
				for (i = 0; i < Inplay.size(); i++) {
					if (Inplay[i].gettype() == "Creature" && Inplay[i].getcolor() == "Black") {
						cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << " HP/Attack " << Inplay[i].getHP() << "/" << Inplay[i].getattack() << endl;
						Inplay[i].setHP(Inplay[i].getHP() + 2);
						Inplay[i].setattack(Inplay[i].getattack() + 0);
						flag = 1;
					}
				}
				if (flag == 0) {
					cout << "There is not any Black creature card to gain +2/+0" << endl;
				}
				else {
					cout << "Creatures above gain +2/+0" << endl;
				}

			}
			else if (Inplay[numb].getname() == "Restrain") {
				int flag = 0;
				for (i = 0; i < Inplay.size(); i++) {
					if (Inplay[i].gettype() == "Creature" && Inplay[i].getcolor() == "Green") {
						cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << " HP/Attack " << Inplay[i].getHP() << "/" << Inplay[i].getattack() << endl;
						Inplay[i].setability("");
						flag = 1;
					}
				}
				if (flag == 0) {
					cout << "There is not any Green creature card to lose Trample" << endl;
				}
				else {
					cout << "Creatures above lose their Trample effect if they got" << endl;
				}

			}
			if (Inplay[numb].getname() == "Slow") {
				int flag = 0;
				int indslow;
				for (i = 0; i < Inplay.size(); i++) {
					if (Inplay[i].gettype() == "Creature" && Inplay[i].getability() == "First Strike") {
						cout << i << ". " << Inplay[i].getname() << " Type: " << Inplay[i].gettype() << " HP/Attack " << Inplay[i].getHP() << "/" << Inplay[i].getattack() << endl;
						flag = 1;
					}
				}
				if (flag == 0) {
					cout << "There is not any creature card to lose First Strike" << endl;
				}
				else {
					cout << "Enter Index of creature card from above that you want to gain Trample";
					cin >> indslow;
					Inplay[indslow].setability("");
				}

			}



		}
		else if (Inplay[numb].gettype() == "Creature") {
			if (Inplay[numb].getname() == "Soldier") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}


			}
			else if (Inplay[numb].getname() == "Armored Pegasus") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}

			}
			else if (Inplay[numb].getname() == "White Knight") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}

			}
			else if (Inplay[numb].getname() == "Angry Bear") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
				}

			}
			else if (Inplay[numb].getname() == "Guard") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}

			}
			else if (Inplay[numb].getname() == "Werewolf") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
				}

			}
			else if (Inplay[numb].getname() == "Skeleton") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}


			}
			else if (Inplay[numb].getname() == "Ghost") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}


			}
			else if (Inplay[numb].getname() == "Black Knight") {
				int flag = 0;
				for (int i = 0; i < again.Inplay.size(); i++) {
					if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						if (again.Inplay[i].getHP() == 0) {
							cout << "YOU LOST THE GAME" << endl;
							break;
						}
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
					else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
						Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
						again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
						flag = 1;
					}
				}
			}

		}
		else if (Inplay[numb].getname() == "Orc Maniac") {
			int flag = 0;
			for (int i = 0; i < again.Inplay.size(); i++) {
				if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
					flag = 1;
				}
				else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					flag = 1;
				}
				else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
					flag = 1;
				}
			}

		}
		else if (Inplay[numb].getname() == "Hobgoblin") {
			int flag = 0;
			for (int i = 0; i < again.Inplay.size(); i++) {
				if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
					flag = 1;
				}
				else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					flag = 1;
				}
				else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
					flag = 1;
				}
			}


		}
		else if (Inplay[numb].getname() == "Vampire") {
			int flag = 0;
			for (int i = 0; i < again.Inplay.size(); i++) {
				if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
					flag = 1;
				}
				else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "First Strike") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					flag = 1;
				}
				else if (again.Inplay[i].gettype() == "Creature" && again.Inplay[i].getability() == "Trample") {
					Inplay[i].setHP(Inplay[i].getHP() - again.Inplay[i].getattack());
					again.Inplay[i].setHP(again.Inplay[i].getHP() - Inplay[i].getattack());
					flag = 1;
				}
			}





		}
	
	}
};





class landCard :public Card {
protected: // there is no manacost,color,attack power since it is land card

	string mana; //land cards do not have any mana cost !!
public:
	landCard() {
		;
	}
	void PlayCard() {
		cout << "LANDCARD" << endl; ;
	}
	void setmana(string mana_) {
		mana = mana_;
	}
	string getmana() {
		return mana;
	}

};

class creatureCard :public Card {
protected:

public:
	creatureCard() {
		tap = 0;

	}
	void PlayCard() {

		cout << "CREATURECARD" << endl;

	}






};

class enchantmentCard :public Card {
protected:

	string effect;

public:

	enchantmentCard() {
		;
	}

	void PlayCard() {
		cout << "ENCHANMENTCARD" << endl; ;
	}


	void seteffect(string effect_) {
		effect = effect_;
	}

	string geteffect() {
		return effect;
	}
	void ArrangeEffect() {
		if (effect == "1 Target creature gains Trample") {
			Effectt = new CreatureTrampleEffect();

		}
		else if (effect == "All white creatures gain +1/+1") {
			Effectt = new OneOneToWhiteEffect();
		}
		else if (effect == "All black creatures gain -1/-1") {
			Effectt = new OneOneToBlackEffect();
		}
		else if (effect == "All black creatures gain +2/+0") {
			Effectt = new TwoZeroToBlackEffect();
		}
		else if (effect == "All green creatures lose Trample") {
			Effectt = new LoseTrampleGreenEffect();
		}
		else if (effect == "1 Target creature loses First Strike") {
			Effectt = new TargetLoseStrikeEffect();
		}
	}



};

class sorceryCard :public Card {
protected:



	string effect;

public:

	sorceryCard() {
		;
	}
	void PlayCard() {
		cout << "SORCCARD" << endl; ;
	}

	void seteffect(string effect_) {
		effect = effect_;
	}
	string geteffect() {
		return effect;
	}
	void ArrangeEffect() {

		if (effect == "Destroy 1 Target Enchantment") {

			Effectt = new DestroyEnchantmentEffect();
		}
		else if (effect == "Deal 2 dmg to target creature or player") {
			Effectt = new TwoDamageEffect();
		}
		else if (effect == "Destroy 1 Target Land") {
			Effectt = new DestroyLandEffect();
		}
		else if (effect == "Return 1 character card from discard to hand") {
			Effectt = new ReturnFromDiscardEffect();
		}
		else if (effect == "Deal 1 dmg to all creatures") {
			Effectt = new OneDamageAllEffect();
		}
		else if (effect == "Destroy 1 Target Creature") {
			cout << "!!!!!!!!!!!!!!!!!!" << endl;
			Effectt = new DestroyCreatureEffect();
		}
	}


};



int main() {

	srand(time(NULL));
	vector<creatureCard> creaturs;
	vector<enchantmentCard> enchant;
	vector<sorceryCard> sorc;
	vector<landCard> land;
	int i;
	creatureCard buff;
	landCard buff2;
	sorceryCard buff3;
	enchantmentCard buff4;
	//Enchantment
	buff4.setname("Rage"); buff4.seteffect("1 Target creature gains Trample"); buff4.setcolor("Green"); buff4.settheMana("G"); buff4.settype("Enchantment");
	buff4.ArrangeEffect();
	buff4.arrangeManaCost();
	enchant.push_back(buff4);

	buff4.setname("Holy War"); buff4.seteffect("All white creatures gain +1/+1"); buff4.setcolor("White"); buff4.settheMana("1W"); buff4.settype("Enchantment");
	buff4.ArrangeEffect();
	buff4.arrangeManaCost();
	enchant.push_back(buff4);

	buff4.setname("Holy Light"); buff4.seteffect("All black creatures gain -1/-1"); buff4.setcolor("White"); buff4.settheMana("1W"); buff4.settype("Enchantment");
	buff4.ArrangeEffect();
	buff4.arrangeManaCost();
	enchant.push_back(buff4);

	buff4.setname("Unholy War"); buff4.seteffect("All black creatures gain +2/+0"); buff4.setcolor("Black"); buff4.settheMana("1B"); buff4.settype("Enchantment");
	buff4.ArrangeEffect();
	buff4.arrangeManaCost();
	enchant.push_back(buff4);

	buff4.setname("Restrain"); buff4.seteffect("All green creatures lose Trample"); buff4.setcolor("Red"); buff4.settheMana("2R"); buff4.settype("Enchantment");
	buff4.ArrangeEffect();
	buff4.arrangeManaCost();
	enchant.push_back(buff4);

	buff4.setname("Slow"); buff4.seteffect("1 Target creature loses First Strike"); buff4.setcolor("Black"); buff4.settheMana("B"); buff4.settype("Enchantment");
	buff4.ArrangeEffect();
	buff4.arrangeManaCost();
	enchant.push_back(buff4);




	//Sorcery
	buff3.setname("Disenchant"); buff3.setcolor("White"); buff3.seteffect("Destroy 1 Target Enchantment"); buff3.settheMana("1W");   buff3.settype("Sorcery");
	buff3.ArrangeEffect();
	buff3.arrangeManaCost();
	sorc.push_back(buff3);

	buff3.setname("Lightning Bolt"); buff3.setcolor("Green"); buff3.seteffect("Deal 2 dmg to target creature or player");  buff3.settheMana("1G"); buff3.settype("Sorcery");
	buff3.ArrangeEffect();
	buff3.arrangeManaCost();
	sorc.push_back(buff3);

	buff3.setname("Flood"); buff3.setcolor("Green"); buff3.seteffect("Destroy 1 Target Land");  buff3.settheMana("1GW"); buff3.settype("Sorcery");
	buff3.ArrangeEffect();
	buff3.arrangeManaCost();
	sorc.push_back(buff3);

	buff3.setname("Reanimate"); buff3.setcolor("Black"); buff3.seteffect("Return 1 character card from discard to hand");  buff3.settheMana("B"); buff3.settype("Sorcery");
	buff3.ArrangeEffect();
	buff3.arrangeManaCost();
	sorc.push_back(buff3);

	buff3.setname("Plague"); buff3.setcolor("Black"); buff3.seteffect("Deal 1 dmg to all creatures");  buff3.settheMana("2B"); buff3.settype("Sorcery");
	buff3.ArrangeEffect();
	buff3.arrangeManaCost();
	sorc.push_back(buff3);

	buff3.setname("Terror"); buff3.setcolor("Black"); buff3.seteffect("Destroy 1 Target Creature"); buff3.settheMana("1B"); buff3.settype("Sorcery");
	buff3.ArrangeEffect();
	buff3.arrangeManaCost();
	buff3.ArrangeEffect();
	Card* thecard = &buff3;


	sorc.push_back(buff3);



	buff2.setname("Forest"); 	buff2.settheMana("G"); 	buff2.settype("Land");
	buff2.arrangeManaCost();
	land.push_back(buff2);

	buff2.setname("Island"); buff2.settheMana("L"); buff2.settype("Land");
	buff2.arrangeManaCost();
	land.push_back(buff2);

	buff2.setname("Mountain"); buff2.settheMana("R"); buff2.settype("Land");
	buff2.arrangeManaCost();
	land.push_back(buff2);

	buff2.setname("Plains"); buff2.settheMana("W"); buff2.settype("Land");
	buff2.arrangeManaCost();
	land.push_back(buff2);

	buff2.setname("Swamp"); buff2.settheMana("B"); buff2.settype("Land");
	buff2.arrangeManaCost();
	land.push_back(buff2);
	int j;
	for (j = 0; j < land.size(); j++) {
		cout << land[j].getname() << endl;

	}

	//Creature cards

	buff.setname("Soldier");	buff.setcolor("White"); buff.setattack(1); buff.setHP(1); buff.setability(""); buff.settheMana("W");  buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Armored Pegasus"); buff.setcolor("White"); buff.setattack(1); buff.setHP(2); buff.setability("");  buff.settheMana("1W");  buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("White Knight"); buff.setcolor("White"); buff.setattack(2); buff.setHP(2); buff.setability("First Strike");  buff.settheMana("WW");  buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Angry Bear"); buff.setcolor("Green"); buff.setattack(3); buff.setHP(2); buff.setability("Trample");   buff.settheMana("2G"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Guard"); buff.setcolor("White"); buff.setattack(2); buff.setHP(5); buff.setability("");  buff.settheMana("2WW");  buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Werewolf"); buff.setcolor("Green"); buff.setattack(4); buff.setHP(6); buff.setability("Trample");  buff.settheMana("2GW"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Skeleton"); buff.setcolor("Black"); buff.setattack(1); buff.setHP(1); buff.setability("");  buff.settheMana("B"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Ghost"); buff.setcolor("Black"); buff.setattack(2); buff.setHP(1); buff.setability("");  buff.settheMana("1B"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Black Knight"); buff.setcolor("Black"); buff.setattack(2); buff.setHP(2); buff.setability("First Strike");  buff.settheMana("BB"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Orc Maniac"); buff.setcolor("Red"); buff.setattack(4); buff.setHP(1); buff.setability("");  buff.settheMana("2R"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Hobgoblin"); buff.setcolor("Red"); buff.setattack(3); buff.setHP(3); buff.setability("");  buff.settheMana("1RB"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	buff.setname("Vampire"); buff.setcolor("Black"); buff.setattack(6); buff.setHP(3); buff.setability("");  buff.settheMana("3B"); buff.settype("Creature");
	buff.arrangeManaCost();
	creaturs.push_back(buff);

	for (i = 0; i < creaturs.size(); i++) {
		cout << creaturs[i].getname() << endl;
	}


	Player player1;
	Player player2;

	player1.deck_push_back(land[3]);
	player1.deck_push_back(land[3]);
	player1.deck_push_back(land[3]);
	player1.deck_push_back(land[3]);
	player1.deck_push_back(land[3]);
	player1.deck_push_back(land[0]);
	player1.deck_push_back(land[0]);
	player1.deck_push_back(land[0]);
	player1.deck_push_back(land[1]);
	player1.deck_push_back(creaturs[0]);
	player1.deck_push_back(creaturs[0]);
	player1.deck_push_back(creaturs[0]);
	player1.deck_push_back(creaturs[1]);
	player1.deck_push_back(creaturs[1]);
	player1.deck_push_back(creaturs[2]);
	player1.deck_push_back(creaturs[2]);
	player1.deck_push_back(creaturs[3]);
	player1.deck_push_back(creaturs[4]);
	player1.deck_push_back(creaturs[5]);
	player1.deck_push_back(sorc[0]);
	player1.deck_push_back(sorc[1]);
	player1.deck_push_back(sorc[2]);
	player1.deck_push_back(sorc[2]);

	player1.deck_push_back(enchant[0]);
	player1.deck_push_back(enchant[1]);
	player1.deck_push_back(enchant[2]);



	player2.deck_push_back(land[4]);
	player2.deck_push_back(land[4]);
	player2.deck_push_back(land[4]);
	player2.deck_push_back(land[4]);
	player2.deck_push_back(land[4]);
	player2.deck_push_back(land[2]);
	player2.deck_push_back(land[2]);
	player2.deck_push_back(land[2]);
	player2.deck_push_back(land[1]);
	player2.deck[player2.DeckSize() - 1].PlayCard();
	player2.deck_push_back(creaturs[6]);
	player2.deck_push_back(creaturs[6]);
	player2.deck_push_back(creaturs[6]);
	player2.deck_push_back(creaturs[7]);
	player2.deck_push_back(creaturs[7]);
	player2.deck_push_back(creaturs[8]);
	player2.deck_push_back(creaturs[8]);
	player2.deck_push_back(creaturs[9]);
	player2.deck_push_back(creaturs[10]);
	player2.deck_push_back(creaturs[11]);
	player2.deck_push_back(sorc[3]);
	player2.deck_push_back(sorc[4]);
	player2.deck_push_back(sorc[5]);

	player2.deck_push_back(sorc[5]);

	player2.deck_push_back(enchant[3]);
	player2.deck_push_back(enchant[4]);
	player2.deck_push_back(enchant[5]);


	cout << "Player 1 Cards" << endl;
	cout << "----------------------------------" << endl;
	player1.PrintDeck();


	cout << endl << "----------------------------------" << endl;
	cout << "Player 2 Cards" << endl;
	cout << "----------------------------------" << endl;
	player2.PrintDeck();
	int turn = 1;
	int cardIndex;
	while (1) {
		cout << "---------------" << endl;
		cout << endl << "Cards of Player 1 in Inplay" << endl;
		player1.PrintInplay();
		cout << "---------------" << endl;
		cout << "Cards of Player 2 in Inplay" << endl;
		player2.PrintInplay();
		cout << "---------------" << endl << endl;
		if (turn == 1) {
			cout << "     <<<<<<Player  1>>>>>>" << endl;
			cout << "HP: " << player1.getHP() << " Mana ";
			player1.getMana();
			cout << endl;
			player1.GetCardFromDeck();
			cout << endl << " Player 1 Hand" << endl;
			player1.PrintHand();
			cout << "                   Enter the card number that you want to play(-1 to pass): ";
			cin >> cardIndex;
			player1.GetCardFromHandtoPlay(cardIndex);
			player1.PlayCard(player2);
			turn = 2;
		}
		else if (turn == 2) {
			cout << "     <<<<<<Player  2>>>>>>" << endl;
			cout << "HP: " << player2.getHP() << " Mana ";
			player2.getMana();
			cout << endl;
			player2.GetCardFromDeck();
			cout << endl << " Player 2 Hand" << endl;
			player2.PrintHand();
			cout << "                   Enter the card number that you want to play(-1 to pass): ";
			cin >> cardIndex;
			player2.GetCardFromHandtoPlay(cardIndex);
			player2.PlayCard(player1);


			turn = 1;
		}
	}
	return 0;

}




