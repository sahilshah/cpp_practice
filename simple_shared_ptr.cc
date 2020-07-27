#include <iostream>


template <typename T>
class SimpleSharedPtr {
	public:

		SimpleSharedPtr() {
			counter_ = new int(0);
			ptr_ = nullptr;
		}

		explicit SimpleSharedPtr(T* t_ptr) {
			ptr_ = t_ptr;
			counter_ = new int(1);
		}

		~SimpleSharedPtr() {
			if (counter_) {
				std::cout << "Decrementing on destruct" << std::endl;
				(*counter_)--;
			}
			if (*counter_ == 0) {
				std::cout << "Deleting on count 0" << std::endl;
				if (ptr_){
					delete(ptr_);
				}
				delete(counter_);
			}
		}

		SimpleSharedPtr(SimpleSharedPtr& other) {
			counter_ = other.counter_;
			ptr_ = other.ptr_;
			if (counter_) {
				std::cout << "Incrementing on copy" << std::endl;
				(*counter_)++;
				std::cout << "Counter: " << *counter_ << std::endl;
			}
		}

		void reset(T* t_ptr) {
			ptr_ = t_ptr;
			*counter_ = 1;
		}

		int use_count() const {
			return *counter_;
		}

		T* get() const {
			return ptr_;
		}

		T& operator*() {
			return *ptr_;
		}

	private:
		int* counter_;
		T* ptr_;
};


int main(int argc, char** argv) {

	SimpleSharedPtr<int> sp;
	sp.reset(new int(10));
	std::cout << "use count: " << sp.use_count() << std::endl;
	SimpleSharedPtr<int> sp2(sp);
	std::cout << "use count: " << sp2.use_count() << std::endl;
	int* x = new int(5);
	SimpleSharedPtr<int> sp3(x);
	SimpleSharedPtr<int> sp4 = sp3;
	std::cout << "raw ptr: " << x << std::endl;
	std::cout << "smart ptr: " << sp3.get() << std::endl;
	std::cout << "val: " << *sp3 << std::endl;
	std::cout << "use count: " << sp3.use_count() << std::endl;

	return 0;
}