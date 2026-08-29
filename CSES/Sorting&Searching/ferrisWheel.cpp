#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int numberChildren, maxWeight;

  std::cin >> numberChildren;
  std::cin >> maxWeight;

  std::vector<int> weights;
  int weight;
  for (int i = 0; i < numberChildren; ++i) {
    std::cin >> weight;
    weights.push_back(weight);
  }
  std::sort(weights.begin(), weights.end());

  int lightChild = 0;
  int heavyChild = numberChildren - 1;
  int minimumGondolas = 0;

  if (numberChildren == 1) {
    std::cout << 1;
    return 0;
  }

  while (lightChild <= heavyChild) {
    if (weights[lightChild] + weights[heavyChild] > maxWeight) {
      minimumGondolas++;
      heavyChild--;
    } else {
      heavyChild--;
      lightChild++;
      minimumGondolas++;
    }
  }

  std::cout << minimumGondolas;

  // std::cout << weights[2];
}
