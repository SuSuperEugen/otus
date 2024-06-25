#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	int number_iter;
	Min() {
		number_iter =0;
	}
	void update(double next) override {
		if(number_iter == 0) {
			m_min = next;
			number_iter++;
		}
		else if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};


class Max : public IStatistics {
public:
	int number_iter;
	Max() {
		number_iter =0;
	}
	void update(double next) override {
		if(number_iter == 0) {
			m_max = next;
			number_iter++;
		}
		else if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	double number_iter;
	Mean() {
		summ = 0;
		number_iter =0;
	}
	void update(double next) override {
		summ+=next;
		number_iter++;
	}

	double eval() const override {
		return summ/number_iter;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double summ;
};

class Std : public IStatistics {
public:
	double number_iter;
	std::vector< double > arr;
	double mean;
	Std() {
		summ = 0;
		number_iter =0;
		mean =0;
	}
	void update(double next) override {
		summ+=next;
		number_iter++;
		arr.push_back(next);
	}

	double eval() const override {
		double mean = summ/number_iter;
		double summ_ = 0;
		for(double n:arr){
			summ_+= pow((n-mean),2);
		}
		return sqrt(summ_/number_iter);
	}

	const char * name() const override {
		return "std";
	}

private:
	double summ;
};

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}