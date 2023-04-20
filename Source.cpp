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

	void get_output_address(int count, std::ofstream(&outtxt)) {

		outtxt << this->City << ", " << this->Street << ", " << this->House << ", " << this->Apparts << std::endl;

	};

	void sort(Adress* adress_arr, int count) {

		for (int i = 0; i < count; ++i) {
			for (int j = i + 1; j < count; ++j) {
				if (adress_arr[i].City > adress_arr[j].City) {
					Adress temp_adr = adress_arr[i];
					adress_arr[i] = adress_arr[j];
					adress_arr[j] = temp_adr;

				}
			}
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

		}
		//
		adress_arr->sort(adress_arr, count);
		std::ofstream(outtxt);
		outtxt.open("out.txt");
		if (outtxt) {
			outtxt << count << std::endl;
			for (int i = 0; i < count; ++i) {
				adress_arr[i].get_output_address(count, outtxt);

			}
			outtxt.close();
		}
		else {
			std::cout << "output file not found!" << std::endl;
		}
		delete[] adress_arr;
		adress_arr = nullptr;
	}
	else {
		std::cout << "input file not found!" << std::endl;
	}

	intxt.close();


	return 0;
}