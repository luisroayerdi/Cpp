#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  int numberCustomers;
  std::cin >> numberCustomers;

  std::vector<int> arrivals(numberCustomers), departures(numberCustomers);

  for (int i = 0; i < numberCustomers; ++i) {
    std::cin >> arrivals[i] >> departures[i];
  }

  std::sort(arrivals.begin(), arrivals.end());
  std::sort(departures.begin(), departures.end());

  int currentCount = 0;
  int maxCount = 0;
  int arrivalsPointer = 0;
  int departuresPointer = 0;

  while ((arrivalsPointer + 1 <= numberCustomers) &&
         (departuresPointer + 1 <= numberCustomers)) {
    if (arrivals[arrivalsPointer] < departures[departuresPointer]) {
      currentCount++;
      if (currentCount > maxCount) {
        maxCount = currentCount;
      }
      arrivalsPointer++;
    } else if (arrivals[arrivalsPointer] == departures[departuresPointer]) {
      arrivalsPointer++;
      departuresPointer++;
    } else {
      currentCount--;
      departuresPointer++;
    }
  }

  std::cout << maxCount;
}
