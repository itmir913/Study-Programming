/**
 * 이진 검색
 *
 * 데이터가 정렬된 배열이라면 이진 검색을 사용한다.
 * 각 단계마다 중간 값을 찾은 후 이 값과 찾는 값을 비교한다.
 * 이후 각 단계에서 검색 공간의 절반씩 제거하므로 시간 복잡도는 O(logn).
 */
int Binary_Search(int arr[], int size, int value) {
  int low = 0, mid;
  int high = size - 1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == value) {
      return mid;
    } else if (arr[mid] < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}