#include <thread>
#include <iostream>
#include <future>

typedef unsigned long long int ULL;
const ULL Fact(const std::shared_future<int>& fut)
{

	int N{ 0 };
	try
	{
		N = fut.get(); //It is waiting for a value to be set by the promise
	}
	catch (const std::future_error& e)
	{
		std::cout << e.code() << " : " << e.what() << '\n';
	}
	ULL result{ 1 };
	for (int i = 2; i <= N; ++i)
	{
		result *= i;
	}
	return result;
}

int main()
{
	std::promise<int> prms;
	std::promise<int> prms2;
	std::shared_future<int> fut1 = prms.get_future().share();

	std::future<ULL> fut1_result = std::async(std::launch::async, Fact, std::ref(fut1));
	prms.set_value(3);

	std::cout << fut1_result.get() << '\n'; //It is waiting for a value to be returned by the Fact function.

	fut1 = prms2.get_future().share();
	std::future<ULL> fut2_result = std::async(std::launch::async, Fact, std::ref(fut1));
	prms2.set_value(4);

	std::cout << fut2_result.get() << '\n'; //It is waiting for a value to be returned by the Fact function.




}
