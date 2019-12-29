#include <assertions-test/test.h>
#include <stopwatch.h>

begin_tests {
	test_suite("stopwatch") {
		test_case("stopwatch constructor raises no errors") {
			stopwatch stopwatch;
		};

		test_case("reseting stopwatch raises no errors") {
			stopwatch stopwatch;
			stopwatch.reset();
		};

		test_case("capturing total time returns value greater than 0") {
			stopwatch stopwatch;
			auto total_time = stopwatch.total_time();
			assert(total_time.count(), >, 0);
		};

		test_case("capturing lap time returns value greater than 0") {
			stopwatch stopwatch;
			auto lap_time = stopwatch.lap_time();
			assert(lap_time.count(), >, 0);
		};

		test_case("converting time returns non-empty string") {
			stopwatch stopwatch;
			auto formatted_time = to_string(stopwatch.lap_time());
			assert(formatted_time.size(), >, 0);
		};
	}
} end_tests;

