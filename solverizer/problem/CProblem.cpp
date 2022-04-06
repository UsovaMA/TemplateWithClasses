#include "CProblem.h"

void CProblem::sort(sortType type) {
  if (type == bubble) {
    BubbleSort BS;
    BS.sort(massive, size);
  }
  else if (type == counting) {
    CountingSort CS;
    CS.sort(massive, size);
  }
  else if (type == quick) {
    QuickSort QS;
    QS.sort(massive, size);
  }
}

void CProblem::print() {
  for (int i = 0; i < size; i++) {
    std::cout << massive[i] << " ";
  }
}
