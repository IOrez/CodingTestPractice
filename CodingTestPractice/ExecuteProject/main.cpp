#include <iostream>

using namespace std;


template<int m,int n,bool res>
struct check_prime {
	static bool const result = res&&check_prime<m, n-1, static_cast<bool>(m% (n - 1))>::result;
};

template<int m,bool res>
struct check_prime<m,1,res> {
	static bool const result = true;
};


template <int N>
struct is_prime{
	static bool const result = check_prime<N,N,true>::result;
};


int main() {
	cout<<std::boolalpha;
	std::cout << "Is prime ? :: " << is_prime<450>::result << std::endl;   // true
	return 0;
}