#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(){

  std::cout << "--- A ---" << std::endl;
	A a;
  identify(&a);
  identify(a);

  std::cout << "--- B ---" << std::endl;
  B b;
  identify(&b);
  identify(b);

  std::cout << "--- C ---" << std::endl;
  C c;
  identify(&c);
  identify(c);

  std::cout << "--- Random ---" << std::endl;
	std::srand(std::time(NULL));
	Base *obj = generate();
	
	identify(obj);  //pointeur
  identify(*obj); //référence

	delete (obj);
	return(0);
}