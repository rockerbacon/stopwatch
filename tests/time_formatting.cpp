#include <assertions-test/test.h>
#include <stopwatch.h>

using namespace std::chrono_literals;
begin_tests {
	test_suite("when formatting round time measures") {
		test_case("should format hours correctly") {
			assert(std::to_string(3h), ==, "3h");
		};

		test_case("should format minutes correctly") {
			assert(std::to_string(5min), ==, "5m");
		};

		test_case("should format seconds correctly") {
			assert(std::to_string(4s), ==, "4s");
		};

		test_case("should format milliseconds correctly") {
			assert(std::to_string(554ms), ==, "554ms");
		};

		test_case("should format microseconds correctly") {
			assert(std::to_string(640us), ==, "640us");
		};

		test_case("should format nanoseconds correctly") {
			assert(std::to_string(454ns), ==, "454ns");
		};
	}

	test_suite("when formatting time measures which are convertible to higher time units") {
		test_case("should not format to unit higher than hours") {
			assert(std::to_string(1000h), ==, "1000h");
		};

		test_case("should format minutes as hours") {
			assert(std::to_string(120min), ==, "2h");
		};

		test_case("should format seconds as minutes") {
			assert(std::to_string(240s), ==, "4m");
		};

		test_case("should format milliseconds as seconds") {
			assert(std::to_string(3000ms), ==, "3s");
		};

		test_case("should format microseconds as milliseconds") {
			assert(std::to_string(3000us), ==, "3ms");
		};

		test_case("should format nanoseconds as microseconds") {
			assert(std::to_string(4000ns), ==, "4us");
		};

		test_case("should format nanoseconds to hours") {
			std::chrono::nanoseconds hour_in_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(1h);
			assert(std::to_string(hour_in_nanoseconds), ==, "1h");
		};
	}

	test_suite("when converting broken time measures") {
		test_case("should format measure in multiple time units") {
			assert(std::to_string(7'264'200ms), ==, "2h 1m 4s 200ms");
		};

		test_case("should not include microseconds when measure is greater than 1ms") {
			assert(std::to_string(3222us), ==, "3ms");
		};

		test_case("should not include nanoseconds when measure is greater than 1us") {
			assert(std::to_string(5444ns), ==, "5us");
		};
	}
} end_tests;

