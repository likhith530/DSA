#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>

using namespace std;

bool is_prime(long long num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (long long i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

long long find_smallest_prime(const vector<long long>& input_numbers) {
    long long q = *min_element(input_numbers.begin(), input_numbers.end());
    for (long long p = q + 1; p < 10000000000LL; ++p) {
        if (is_prime(p)) {
            bool is_valid = true;
            for (long long num : input_numbers) {
                if (num != q && p % num != q) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) return p;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<long long> input_numbers(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> input_numbers[i];
    }

    long long result = find_smallest_prime(input_numbers);
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "None" << endl;
    }

    return 0;
}
