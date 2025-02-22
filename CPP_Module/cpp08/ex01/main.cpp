#include "./Span.hpp"

int main()
{
	Span sp = Span(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(110);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	int arr[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	std::vector<int> v(10, 100);
	Span sp2 = Span(15);
	try
	{
		sp2.addAnyArray(arr, 10);
		// sp2.addAnyArray(arr, 6);
		sp2.addAnyArray(v, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}