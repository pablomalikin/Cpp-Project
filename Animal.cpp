#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"

using namespace std;

bool Cat::check_health() {
	if ( (m_temp < 38) || (m_temp > 39.2) )
		return false;
	if ( (m_breath < 16) || (m_breath > 40) )
		return false;
	if ( (m_heart < 120) || (m_heart > 140) )
			return false;
	return true;
}

bool Dog::check_health() {
	if ( (m_temp < 38) || (m_temp > 39.2) )
		return false;
	if ( (m_breath < 10) || (m_breath > 35) )
		return false;
	if ( m_is_large ){
		if ( (m_heart < 60) || (m_heart > 100) )
			return false;
	}
	else
		if ( (m_heart < 100) || (m_heart > 140) )
			return false;		
	return true;		
}

bool Cow::check_health() {
	if ( (m_temp < 38.5) || (m_temp > 39.5) )
		return false;
	if ( (m_breath < 26) || (m_breath > 50) )
		return false;
	if ( (m_heart < 48) || (m_heart > 84) )
			return false;
	if ( m_milk < 30 )
			return false;
	return true;
}

Vet::Vet() {}
	
Vet::~Vet() {}

void Vet::add_animal(Animal* animal) {
	m_animals.push_back(animal);
}

void Vet::show_sick(){
	size_t size = m_animals.size();
	for(size_t i=0; i < size; ++i) {
		string name = m_animals[i]->m_name;
		double temp = m_animals[i]->m_temp;
		double breath = m_animals[i]->m_breath;
		double heart = m_animals[i]->m_heart;
		
		try {
			if ( typeid((*m_animals[i])) == typeid(Cat) ) 
				throw 1;
			if ( typeid((*m_animals[i])) == typeid(Dog) ) 
				throw 2;
			if ( typeid((*m_animals[i])) == typeid(Cow) ) 
				throw 3;
		}
		catch(int animal) {
			
			if ( animal == 1) {				
				Cat *cat = new Cat( name, temp, breath, heart);
				if ( !cat->check_health() )
					cout << name << ' ';
				continue;
			}
			if ( animal == 2 ) {
				Dog *tdog =  static_cast<Dog*>(m_animals[i]);
				bool is_large = tdog->m_is_large;
				Dog* dog = new Dog(name,temp,breath,heart,is_large);
				if ( !dog->check_health() )
					cout << name << ' ';
				continue;
			}
			if ( animal == 3 ) {
				Cow *tcow =  static_cast<Cow*>(m_animals[i]);
				double milk = tcow->m_milk;
				Cow* cow = new Cow(name,temp,breath,heart,milk);
				if ( !(cow->check_health()) )
					cout << m_animals[i]->m_name << ' ';
			}
		}
	}
}

void Vet::show_sick_dogs(){
	size_t size = m_animals.size();
	for(size_t i=0; i < size; ++i) {
		if ( typeid((*m_animals[i])) == typeid(Dog) ) {
			string name = m_animals[i]->m_name;
			double temp = m_animals[i]->m_temp;
			double breath = m_animals[i]->m_breath;
			double heart = m_animals[i]->m_heart;

			Dog *tdog =  static_cast<Dog*>(m_animals[i]);
			bool is_large = tdog->m_is_large;
			Dog* dog = new Dog(name,temp,breath,heart,is_large);
			if ( !dog->check_health() )
				cout << name << ' ';
		}			
	}
}

Vet& Vet::get_instance() {

	static Vet* instance = new Vet();
	return *instance;
}
	
