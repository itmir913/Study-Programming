/**
 * 배열의 합 구하는 함수
 * 시간 복잡도는 O(n)
 */
int SumArray(int arr[], int size) {
  int total = 0;
  for (int index = 0; index < size; index++) {
    total = total + arr[index];
  }
  return total;
}