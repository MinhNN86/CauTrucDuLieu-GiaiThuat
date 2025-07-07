#include <stdio.h>
#define MAX 100

// khai báo mảng
int Stack[MAX];
// khai báo biến top
int top = -1;
// hàm kiểm tra ngăn xếp rỗng
int isEmpty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}
// hàm kiểm tra xem ngăn xếp đầy
int isFull() {
  if (top == MAX - 1) {
    return 1;
  }
  return 0;
}
// hàm để thêm phần tử trong ngăn xếp
void push(int x) {
  if (isFull()) {
    return;
  }
  top+=1;
  Stack[top] = x;
}
// hàm lấy phần tử trên đỉnh
int pop() {
  if (isEmpty()) {
    return -1;
  }
  int temp = Stack[top];
  top--;
  return temp;
}
int main() {
  int n = 5; // thêm 5 phần tử vào ngăn xếp
  while (n--) {
    int t;
    scanf("%d", &t);
    push(t);
  }
  // hiển thị các phần tử trong ngăn xếp
  while (!isEmpty()) {
    printf("%d ", pop());
  }
}