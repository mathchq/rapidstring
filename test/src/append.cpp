#include "utility.hpp"
#include <string>

TEST_CASE("Stack concatenation")
{
	const std::string first{ "Hello " };
	const std::string second{ " World!" };
	const auto sum{ first + second };

	rapidstring s;
	rs_init(&s);

	rs_cat(&s, first.data());

	CMP_STR(&s, first);
	
	rs_cat(&s, second.data());

	CMP_STR(&s, sum);

	rs_free(&s);
}

TEST_CASE("Stack and heap concatenation")
{
	const std::string first{ "Hello " };
	const std::string second{ " to this very long string to avoid SSO!" };
	const std::string sum{ first + second };

	rapidstring s;
	rs_init(&s);

	rs_cat(&s, first.data());

	CMP_STR(&s, first);
	
	rs_cat(&s, second.data());

	CMP_STR(&s, sum);

	rs_free(&s);
}

TEST_CASE("Heap concatenation")
{
	const std::string first{ "Hello this is a very long string " };
	const std::string second{ " to ensure all concats are on the heap!" };
	const auto sum{ first + second };

	rapidstring s;
	rs_init(&s);
	
	rs_cat(&s, first.data());

	CMP_STR(&s, first);
	
	rs_cat(&s, second.data());

	CMP_STR(&s, sum);

	rs_free(&s);
}
