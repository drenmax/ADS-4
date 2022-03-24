// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0, last = len-1;

  while (arr[last] > value) {
    last--;
  }

  for (int i = 0; i < last; i++) {
    if (arr[i] > value / 2) {
      break;
    }
    for (int j = last; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
      if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return count;
}

int cbinsearch(int* arr, int size, int value, int l) {
  int count = 0, i = l, j = size - 1, mid = 0;
  while (i <= j) {
    mid = i + (j - i) / 2;
    if (arr[mid] == value && mid != l) {
      count++;
      int low = mid, up = mid;
      while (arr[--low] == value && low > l) {
        count++;
      }
      while (arr[++up] == value) {
        count++;
      }
      return count;
    } else if (arr[mid] > value) {
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int i = 0, j = len, count = 0;
  for (i=0; i < j; i++) {
    count += cbinsearch(arr, len, value - arr[i], i);
  }
  return count;
}
