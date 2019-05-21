#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"

using namespace std;

int main(void) {
	
	cout << "Program start\n" << endl;
	Vet& vet = Vet::get_instance();
	cout << endl;
	
	//healthy dog
	vet.add_animal(new Dog("Dog1", 38.5, 20, 80, true));
	
	//not healthy dog(temp too high)
	vet.add_animal(new Dog("Dog2", 40.0, 20, 80, true));
	
	//not healthy dog(heart rate too little for small breed)
	vet.add_animal(new Dog("Dog3", 38.5, 20, 80, false));
	
	//healthy cat
	vet.add_animal(new Cat("Cat1", 38.7, 30, 130));
	
	//not healthy cat(temp too high)
	vet.add_animal(new Cat("Cat2", 38.7, 42, 130));
	
	//healthy cow
	vet.add_animal(new Cow("Cow1", 39.0, 37, 70, 32));
	
	//not healthy Cow(milk production too low)
	vet.add_animal(new Cow("Cow2", 39.0, 37, 70, 20));
	
	cout << "*** Sick Animals ***\n\n";
	vet.show_sick();
	cout << "\n\n*** Dogs Sick ***\n\n";
	vet.show_sick_dogs();
	
	return 0;
}
