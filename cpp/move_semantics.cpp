#include <iostream>
#include <algorithm>
#include <utility>
#include <print>

/**
 * CHALLENGE: Implement the Rule of Five for the 'IntArray' class.
 * * Your goal is to ensure that this class handles memory correctly:
 * 1. No memory leaks.
 * 2. No double-frees.
 * 3. Deep copies for lvalues.
 * 4. Resource stealing (moves) for rvalues.
 * * DIRECTIONS:
 * - Implement the Destructor.
 * - Implement the Copy Constructor.
 * - Implement the Copy Assignment Operator.
 * - Implement the Move Constructor.
 * - Implement the Move Assignment Operator.
 * * RULE OF THUMB:
 * - For Moves: "Steal" the pointer and set the source's pointer to nullptr.
 * - For Copy Assignment: Remember to handle self-assignment and clean up old memory.
 */

class IntArray {
private:
    size_t m_size;
    int* m_data;

public:
    // Basic Constructor
    explicit IntArray(size_t size)
        : m_size(size), m_data(new int[size]{}) {
        std::cout << "Allocated array of size " << m_size << "\n";
    }

    // TODO: IMPLEMENT THE 5 SPECIAL MEMBER FUNCTIONS HERE

    // destructor
    ~IntArray() {
	if (m_data) {
	    delete[] m_data;
	}
    }

    // Copy constructor
    IntArray(const IntArray& other) {
	std::println("Copy constructor called");
	m_size = other.m_size;
	m_data = new int[m_size]{};
	std::copy(other.m_data, other.m_data + m_size, m_data);
    }

    // Copy assignment operator
    IntArray& operator=(const IntArray& other) {
	if (this != &other) {
	    int* new_data = new int[other.m_size];
	    std::copy(other.m_data, other.m_data + other.m_size, new_data);
	    delete[] m_data;
	    m_data = new_data;
	    m_size = other.m_size;
	}
	return *this;
    }

    // Move constructor
    IntArray(IntArray&& other) noexcept {
	std::println("Move constructor called");
	m_size = other.m_size;
	m_data = other.m_data;
	other.m_size = 0;
	other.m_data = nullptr;
    }

    // Move assignment operator
    IntArray& operator=(IntArray&& other) {
	std::println("Move assignment operator called");
	if (this != &other) {
	    delete[] m_data;
	    m_size = other.m_size;
	    m_data = other.m_data;
	    other.m_size = 0;
	    other.m_data = nullptr;
	}
	return *this;
    }

    // // Alternative: Combined copy and move assignment operators
    // void swap(IntArray& first, IntArray& second) noexcept {
	// using std::swap;
	// swap(first.m_data, second.m_data);
	// swap(first.m_size, second.m_size);
    // }
    // IntArray& operator=(IntArray other) {
	// swap(*this, other);
	// return *this;
    // }


    // Helper for debugging
    void print() const {
        if (m_data) {
            std::cout << "Array at " << m_data << " (size " << m_size << ")\n";
        } else {
            std::cout << "Empty/Moved-from array\n";
        }
    }
};

int main() {
    std::cout << "--- Test 1: Copying ---\n";
    IntArray a(10);
    IntArray b = a; // Should call Copy Constructor (Deep Copy)

    std::cout << "\n--- Test 2: Assignment ---\n";
    IntArray c(5);
    c = a;          // Should call Copy Assignment (Deep Copy)

    std::cout << "\n--- Test 3: Moving ---\n";
    IntArray d = std::move(a); // Should call Move Constructor (Steal)
    std::cout << "A after move: "; a.print();
    std::cout << "D after move: "; d.print();

    std::cout << "\n--- Test 4: Move Assignment ---\n";
    IntArray e(20);
    e = std::move(d); // Should call Move Assignment
    std::cout << "D after move: "; d.print();

    return 0;
} // Destructors will run here. If you didn't implement them, this will leak!
