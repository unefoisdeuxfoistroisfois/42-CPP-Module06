#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
	std::cout << "Base destructor called" << std::endl;
}

Base *generate(void){
	int choice = std::rand() % 3;

	if (choice == 0){
		return (new A());
	} else if (choice == 1){
		return (new B());
	} else {
		return (new C());
	}
}

void identify(Base *p){
	if (dynamic_cast<A *>(p) != NULL){
		std::cout << "Type: A" << std::endl;
		return ;
	}else if (dynamic_cast<B *>(p) != NULL){
		std::cout << "Type: B" << std::endl;
		return ;
	} else if (dynamic_cast<C *>(p) != NULL){
		std::cout << "Type: C" << std::endl;
		return ;
	} else {
		std::cout << "Type: Unknown" << std::endl;
		return ;
	}
}

// une reference ne peux pas etre NULL donc pour gére le cas d'erreru il faure un try catch
void identify(Base &p){
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Type: A" << std::endl;
		return ;
	} catch (std::exception &e){
		(void)e;
	}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Type: B" << std::endl;
		return ;
	} catch (std::exception &e){
		(void)e;
	}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Type: C" << std::endl;
		return ;
	} catch (std::exception &e){
		(void)e;
	}

	std::cout << "Type: Unknown" << std::endl;
}
