#include "nearest_value_searcher.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>

namespace nearestvaluesearcher
{
    int NearestValueSearcher::Nearest(const std::vector<int>& numbers, int search) const {

        return *std::min_element(begin(numbers), end(numbers), [search](int a, int b) -> bool {
            return (std::abs(a - search) < std::abs(b - search)) || (a < b);
        });
    }
}

#define CODERUNNER 1
#if CODERUNNER
int main()
{
    using namespace nearestvaluesearcher;
    using namespace std;

    vector<int> sorted_numbers{4, 7, 10, 11, 12, 17};
    cout << "Inputs: ";
    copy(begin(sorted_numbers), end(sorted_numbers), ostream_iterator<int>(cout, ", ") );
    cout << "\n";
    int search = 9;

    NearestValueSearcher searcher;

    cout << searcher.Nearest(sorted_numbers, search);
}
#endif
