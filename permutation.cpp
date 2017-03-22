#include <iostream>

using namespace std;

void lexic_ord (int *arr, int leng, int n) {
    if (leng == n - 1) {
        for (auto i = 0; i < n; ++i) {
            cout << arr[i];
        } cout << endl;
    }
    else {
        for (auto i = leng; i < n; ++i){
        auto tmp = arr[i];
        arr[i] = arr[leng];
        arr[leng] = tmp;
        lexic_ord(arr, leng + 1, n);
        tmp = arr[leng];
        arr[leng] = arr[i];
        arr[i] = tmp;
        }
    }
}

void dijkstra (int *arr, int leng, int n) {
    auto i;
    for (i = 1; i <= n; ++i) {
        arr[i] = leng;
    }
    i = n - 1;
    while (i > 0){
        auto j = n;
        while (arr[i] > arr[j]) {
            --j;
        }
        auto tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        leng = i + 1;
        auto tail = n;
        while (i < tail){
            auto tmp = arr[leng];
            arr[leng] = arr[tail];
            arr[tail] = tmp;
            leng++;
            tail--;
        }
        i = n - 1;
        while(i > 0 && arr[i] > arr[i + 1]) {
            --i;
        }
    }
}

int main () {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (auto i = 0; i < n; ++i) {
         arr[i] = i + 1;
    }
    lexic_ord(arr, 0, n);
}