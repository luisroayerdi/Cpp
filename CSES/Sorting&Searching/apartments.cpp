#include <algorithm>
#include <iostream>
#include <vector>
/*
Input:
4 3 5 applicants, apartments, maximum difference
60 45 80 60 desired apartment size
30 60 75 size of each apartment

Output:
2

45 60 60 80

*/

int main() {
  // first line input
  int n, m, k;
  std::cin >> n;
  std::cin >> m;
  std::cin >> k;

  // second line input
  std::vector<int> desired_apt;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    desired_apt.push_back(x);
  }
  std::sort(desired_apt.begin(), desired_apt.end());

  // Third line input
  std::vector<int> apartments;
  for (int j = 0; j < m; j++) {
    int y;
    std::cin >> y;
    apartments.push_back(y);
  }
  std::sort(apartments.begin(), apartments.end());

  int count = 0;

  int pointer_applicants = 0;
  int pointer_apt = 0;

  // main logic
  while (pointer_applicants < n && pointer_apt < m) {
    if (desired_apt[pointer_applicants] < apartments[pointer_apt] - k) {
      pointer_applicants++;
    }

    if ((desired_apt[pointer_applicants] >= apartments[pointer_apt] - k) &&
        (desired_apt[pointer_applicants] <= apartments[pointer_apt] + k)) {
      count++;
      pointer_applicants++;
      pointer_apt++;
    }

    if (desired_apt[pointer_applicants] > apartments[pointer_apt] + k) {
      pointer_apt++;
    }
  }

  std::cout << count << std::endl;
}
