#include <iostream>
#include <fstream>

class Adress {



public:
	Adress() {};
	Adress(std::string City, std::string Street, int House, int Apparts) {
		this->City = City;
		this->Street = Street;
		this->House = House;
		this->Apparts = Apparts;
	};

	void get_output_address(std::ofstream(&outtxt)) {

		outtxt << this->City << ", " << this->Street << ", " << this->House << ", " << this->Apparts << std::endl;

	};

	void sort(Adress* adress_arr, int count) {
		for (int i = 0; i < count; ++i) {





	}
		
	};

protected:
	std::string City;
	std::string Street;
	int House{};
	int Apparts{};
};



int main() {
	std::ifstream(intxt);
	intxt.open("in.txt");

	if (intxt) {
		int count;
		intxt >> count;
		Adress* adress_arr = new Adress[count];
		for (int i = 0; i < count; ++i) {
			std::string City;
			std::string Street;
			int House{};
			int Apparts{};
			intxt >> City;
			intxt >> Street;
			intxt >> House;
			intxt >> Apparts;
			adress_arr[i] = Adress(City, Street, House, Apparts);

			std::ofstream(outtxt);
			outtxt.open("out.txt");

			if (outtxt) {
				for (int i = 0; i < count; ++i) {
					adress_arr[i].get_output_address(outtxt);

				}
				outtxt.close();
			}
			else {
				std::cout << "output file not found!" << std::endl;
			}

		}

	}
	else {
		std::cout << "input file not found!" << std::endl;
	}

	intxt.close();


	return 0;
}