#include <chrono> // For benchmarking
#include <cmath>
#include <iostream>
#include <vector>

// Function to implement the Sieve of Eratosthenes
std::vector<int> sieveOfEratosthenes(int n) {
  std::vector<bool> primes(
      n + 1, true); // Initialize a boolean vector with true values
  primes[0] = false;
  primes[1] = false;

  for (int i = 2; i <= std::sqrt(n); i++) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    }
  }

  // Collect all prime numbers into a result vector
  std::vector<int> result;
  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      result.push_back(i);
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  // Check if the argument is passed
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
    return 1;
  }

  // Convert the input argument to an integer
  int n = std::stoi(argv[1]);

  // Start the timer
  auto start = std::chrono::high_resolution_clock::now();

  // Run the sieve of Eratosthenes
  std::vector<int> primes = sieveOfEratosthenes(n);

  // Stop the timer
  auto end = std::chrono::high_resolution_clock::now();

  // Calculate the duration
  std::chrono::duration<double> duration = end - start;

  // Output the benchmark result
  std::cout << "Time taken to find primes up to " << n << ": "
            << duration.count() << " seconds" << std::endl;

  // Uncomment the following lines if you want to print the prime numbers
  // std::cout << "Prime numbers up to " << n << " are: ";
  // for (int prime : primes) {
  //     std::cout << prime << " ";
  // }
  // std::cout << std::endl;

  return 0;
}
