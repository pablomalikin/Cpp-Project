#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
	public:
		string m_name;
		double m_temp;
		double m_breath;
		double m_heart;
		
		Animal(string name,double temp,double breath,double heart) :
			  m_name(name),m_temp(temp),m_breath(breath),m_heart(heart) {}
		virtual ~Animal() {}
		virtual bool check_health() = 0;
};

class Dog : public Animal {
	public:
		bool m_is_large;
	
		Dog(string name,double temp,double breath,double heart,bool is_large) : 
			Animal(name,temp,breath,heart), m_is_large(is_large) {}
		Dog(Dog &other) : Animal(other.m_name,other.m_temp,other.m_breath,other.m_heart),
						  m_is_large(other.m_is_large) {}
		virtual ~Dog() {}
		virtual bool check_health();
};

class Cat : public Animal {
	public:
		Cat(string name,double temp,double breath,double heart) : 
			Animal(name,temp,breath,heart) {}
		Cat(Cat &other) : Animal(other) {}
		virtual ~Cat() {}
		virtual bool check_health();
};

class Cow : public Animal {
	public:
		double m_milk;
		
		Cow(string name,double temp,double breath,double heart,double litres) : 
			Animal(name,temp,breath,heart), m_milk(litres) {}
		Cow(Cow &other) : Animal(other), m_milk(other.m_milk) {}
		virtual ~Cow() {}
		virtual bool check_health();
};

class Vet {
	public:
		void add_animal(Animal*);
		void show_sick();
		void show_sick_dogs();
		static Vet & get_instance();
	private:
		vector<Animal*> m_animals;
		Vet();
		~Vet();
};

#endif // ANIMAL_H
