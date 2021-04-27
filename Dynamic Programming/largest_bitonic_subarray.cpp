#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int * arr, int n) {

  int * output_asc = new int[n]();
  int * output_desc = new int[n]();

  output_asc[0] = 1;
  output_desc[n - 1] = 1;
  for (int i = 1; i < n; i++) {

    output_asc[i] = 1;
    for (int j = 0; j < i; j++) {

      if (arr[i] > arr[j]) {
        if (output_asc[i] < output_asc[j] + 1)
          output_asc[i] = output_asc[j] + 1;
      }
    }
  }

  for (int i = n - 2; i >= 0; i--) {

    output_desc[i] = 1;
    for (int j = n - 1; j > i; j--) {
      if (arr[i] > arr[j]) {
        if (output_desc[i] < output_desc[j] + 1)
          output_desc[i] = output_desc[j] + 1;
      }

    }
  }

  int max = -1;

  for (int i = 0; i < n; i++) {
    if (output_asc[i] + output_desc[i] > max)
      max = output_asc[i] + output_desc[i];
  }

  return max - 1;

}

int main() {
  int n, input[100000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  cout << longestBitonicSubarray(input, n)<<endl;
  return 0;
}
