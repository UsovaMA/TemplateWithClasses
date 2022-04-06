#include "CMethod.h"

void BubbleSort::sort(int* mass, int size) {
  for (int i = 0; i < size - 1; i++) {
    int all_good = true;
    for (int j = 0; j < size - i - 1; j++) {
      if (mass[j + 1] < mass[j]) {
        int tmp = mass[j + 1];
        mass[j + 1] = mass[j];
        mass[j] = tmp;
        all_good = false;
      }
    }
    if (all_good) break;
  }
}

void CountingSort::sort(int* mass, int size) {
  int max = mass[0], min = mass[0];
  for (int i = 0; i < size; i++) {
    if (mass[i] > max) max = mass[i];
    if (mass[i] < min) min = mass[i];
  }

  int* count = new int[max - min + 1];
  for (int i = 0; i < max - min + 1; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[mass[i] - min] += 1;
  }

  for (int i = 0, j = 0; i < size; j++) {
    while (count[j] != 0) {
      mass[i] = min + j;
      count[j] -= 1;
      i++;
    }
  }

  delete[] count;
}

void QuickSort::qsort(int *mass, int left, int right) {
  if (left < right) {
    // указатели в начало и в конец массива
    int i = left;
    int j = right;

    // центральный элемент массива
    int base = mass[(right + left) / 2];

    // делим массив
    do {
      // пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
      while (mass[i] < base) { i++; }
      while (mass[j] > base) { j--; }

      // меняем элементы местами
      if (i <= j) {
        int tmp = mass[i];
        mass[i] = mass[j];
        mass[j] = tmp;
        i++;
        j--;
      }
    } while (i <= j);

    qsort(mass, left, j);
    qsort(mass, i, right);
  }
}
