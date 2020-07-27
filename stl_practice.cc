#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <memory>
#include <numeric>


int main(int argc, char** argv) {

	// initializer list example.
	std::vector<std::pair<int,int>> numbers{{1,2},{3,4},{4,3},{2,1}};
	std::sort(numbers.begin(), numbers.end());
	for (const auto& num : numbers) {
		std::cout << num.first << "," << num.second << std::endl;
	}

	// accumulate example.
	std::vector<int> numbers2{1,2,3,4};
	const auto sum = std::accumulate(numbers2.begin(), numbers2.end(), 0);
	std::cout << sum << std::endl;

	// reduce example.
	const auto min = std::reduce(numbers2.begin(), numbers2.end(), 10, [](const int a, const int b) -> int {return std::min(a,b);});
	std::cout << min << std::endl;

	// transform example.
	std::string s("hello");
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << s << std::endl;

    // for_each example.
    std::for_each(s.begin(), s.end(), [](const char& c){std::cout << c << std::endl;});

	return 0;
}