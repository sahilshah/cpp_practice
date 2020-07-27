#include <iostream>


std::shared_ptr<int> wrap_in_sp(int y) {
	std::shared_ptr<int> sp = std::make_shared<int>(y);
	// std::cout << "Val: " << *sp << std::endl;
	std::shared_ptr<int> sp2 = sp;
	// std::cout << "Use count: " << sp.use_count() << std::endl;
	return sp;
}

// sp is output.
void wrap_in_sp2(int y, std::shared_ptr<int>& sp) {
	sp.reset(new int(y));
	// std::cout << "Val: " << *sp << std::endl;
	// std::cout << "Use count: " << sp.use_count() << std::endl;
}


int main(int argc, char** argv) {

	auto sp = wrap_in_sp(100);
	
	// std::cout << "Val: " << *sp << std::endl;
	// std::cout << "Use count: " << sp.use_count() << std::endl;

	std::shared_ptr<int> sp2 = sp;
	wrap_in_sp2(50, sp2);

	std::shared_ptr<int> sp3 = sp;
	// wrap_in_sp2(50, sp3);

	std::cout << "Ptr: " << sp << std::endl;
	std::cout << "Val: " << *sp << std::endl;
	std::cout << "Use count: " << sp.use_count() << std::endl;
	// std::cout << "Val: " << *sp2 << std::endl;
	// std::cout << "Use count: " << sp2.use_count() << std::endl;
	std::cout << "Ptr: " << sp3 << std::endl;
	std::cout << "Val: " << *sp3 << std::endl;
	std::cout << "Use count: " << sp3.use_count() << std::endl;
	return 0;
}