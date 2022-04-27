/**
 * 배열 순차 검색
 *
 * 배열에 저장된 데이터가 어떤 데이터인지 알려진 정보가 없고,
 * 정렬되지 않았다면 배열의 첫 원소부터 하나씩 차례대로 검색해야 한다.
 *
 * 시간 복잡도는 O(n)
 */
int Sequential_Search(int arr[], int size, int value) {
  for (int i = 0; i < size; i++) {
    if (value == arr[i]) {
      return i;
    }
  }
  return -1;
}