#include <stdio.h>

using namespace std;

int gcd(int a, int b){
  int temp;
  while(b != 0) {
    temp = a%b;
    a = b;
    b = temp;
  }
  return a;
}

int main() {
  int case;
  scanf("%d", &case);

  while(case--) {
    int res = 0;
    int num;
    scanf("%d", &num);
    for(int i = 1; i*i <= num; i++) {
      if(num%i == 0) {
        if(gcd(i, num/i) == 1) {
          res++;
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
