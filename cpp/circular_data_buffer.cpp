#include <vector>
#include <iostream>
#include <limits>

struct DataBuffer {
  public:
    DataBuffer(size_t n)
        : n_(n + 1),
          data_(n_ , std::numeric_limits<double>::quiet_NaN()),
          read_index_(0),
          write_index_(n_-1)
    {}

    void push(double value) {
	size_t next = (write_index_ + 1) % n_;
	if (next == read_index_) {
	    read_index_ = (read_index_ + 1) % n_;
	}
	data_[write_index_] = value;
	write_index_ = next;
    }

    double read() const {
	if (read_index_ == write_index_) {
	    return std::numeric_limits<double>::quiet_NaN();
	}
	size_t latest = (write_index_ + n_ - 1) % n_;
	return data_[latest];
    }

    void print() const {
	size_t i = read_index_;
	while (i != write_index_) {
	    std::cout << data_[i] << " ";
	    i = (i + 1) % n_;
	}
	std::cout << std::endl;
    }

  private:
    size_t n_;
    size_t read_index_;
    size_t write_index_;
    std::vector<double> data_;
};


int main() {
    DataBuffer data1(5);
    data1.print();
    for (int i = 1; i <= 5; i++) {
	data1.push(i);
	data1.print();
    }
    std::cout << "latest = " << data1.read() << "\n";

    std::cout << std::endl;
    DataBuffer data2(5);
    data2.print();
    for (int i = 1; i <= 6; i++) {
	data2.push(i);
	data2.print();
    }
    std::cout << "latest = " << data2.read() << "\n";

    std::cout << std::endl;
    DataBuffer data3(5);
    data3.print();
    for (int i = 1; i <= 7; i++) {
	data3.push(i);
	data3.print();
    }
    std::cout << "latest = " << data3.read() << "\n";
}
