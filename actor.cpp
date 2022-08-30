#include <iostream>
#include <future>

using namespace std;

bool is_prime (int x) {
  std::cout << "Calculating. Please, wait...\n";
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}


int main(const int argc, const char* argv[])
{
    std::future<bool> fut = std::async (is_prime,313222313);

    std::cout << "Checking whether 313222313 is prime.\n";

    bool ret = fut.get();      // waits for is_prime to return

    if (ret) std::cout << "It is prime!\n";
    else std::cout << "It is not prime.\n";


    return 0;
}