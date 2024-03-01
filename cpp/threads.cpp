#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

double value = 0.0;
std::mutex value_mutex;

void thread_func() {
    for (int i = 0; i < 5; i++) {
        value_mutex.lock();
        value += 0.1;
        std::cout << "[thread1]: value = " << value << std::endl;
        value_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
         
    std::thread thread1(thread_func);
    for (int i = 0; i < 10; i++) {
        value_mutex.lock();
        std::cout << "[main] value = " << value << std::endl;
        value_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    thread1.join();
    std::cout << "[main] final value = " << value << std::endl;
    return 0;
}
