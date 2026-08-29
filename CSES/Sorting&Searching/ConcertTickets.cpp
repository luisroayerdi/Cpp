#include <iostream>
#include <set>
#include <vector>

int main() {
  int numberTickets, numberCustomers;

  std::cin >> numberTickets;
  std::cin >> numberCustomers;

  std::multiset<int> ticketsPrices;

  for (int i = 0; i < numberTickets; ++i) {
    int price;
    std::cin >> price;
    ticketsPrices.insert(price);
  }

  std::vector<int> maxPrices;

  for (int i = 0; i < numberCustomers; ++i) {
    int max;
    std::cin >> max;
    maxPrices.push_back(max);
  }

  for (int i = 0; i < numberCustomers; ++i) {
    int current = maxPrices[i];
    auto it = ticketsPrices.upper_bound(current);

    if (it == ticketsPrices.begin()) {
      std::cout << -1 << std::endl;
    } else {
      --it;
      std::cout << *it << std::endl;
      ticketsPrices.erase(it);
    }
  }

  return 0;
}
