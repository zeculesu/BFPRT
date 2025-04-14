#include "bfprt.h"
#include <iostream>
#include <vector>

int main() try {
    std::vector<int> data = { 9, 5, 7, 1, 3, 2, 8, 6, 4 };

    for (int k = 1; k <= data.size(); ++k)
    {
        int result = bfprt(data.begin(), data.end(), k);
        std::cout << k << "-th smallest element is " << result << "\n";
    }

    return 0;
}
catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
}