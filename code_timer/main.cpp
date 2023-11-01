#include <iostream>
#include <chrono>

// Function to be executed
void code_exec() {
    // Replace this with your actual computation
    int sum = 0;
    for (int i = 0; i < 10000000; ++i) {
        sum += i;
    }
}

// Function to be compared
void code_comp() {
    // Replace this with your actual computation
    int sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        sum += i;
    }
}

int main() {
    auto start_exec = std::chrono::high_resolution_clock::now();
    code_exec(); // Execute code_exec
    auto stop_exec = std::chrono::high_resolution_clock::now();
    auto duration_exec = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_exec - start_exec);

    auto start_comp = std::chrono::high_resolution_clock::now();
    code_comp(); // Execute code_comp
    auto stop_comp = std::chrono::high_resolution_clock::now();
    auto duration_comp = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_comp - start_comp);

    // Compare execution times
    std::cout << "code_exec executed in " << duration_exec.count() << " nanoseconds." << std::endl;
    std::cout << "code_comp executed in " << duration_comp.count() << " nanoseconds." << std::endl;

    if (duration_comp.count() < duration_exec.count()) {
        std::cout << "code_comp is faster than code_exec." << std::endl;
    }
    else if (duration_comp.count() > duration_exec.count()) {
        std::cout << "code_exec is faster than code_comp." << std::endl;
    }
    else {
        std::cout << "code_exec and code_comp have the same execution time." << std::endl;
    }
    system("pause > nul");
    return 0;
}
