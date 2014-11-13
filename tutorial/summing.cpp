#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int sum = 0;

        for (int j = 0; j < 10; ++j) {
            int num;
            cin >> num;

            sum += num;
        }

        cout << sum << endl;
    }

    return 0;
}
