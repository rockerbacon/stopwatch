#include <assertions-test/test.h>
#include <stopwatch.h>
#include <thread>

using namespace std;

begin_tests {
	test_suite("when counting time") {
		test_case("stopwatch should return correct lap time") {
			stopwatch stopwatch;
			this_thread::sleep_for(15ms);
			auto lap_time = stopwatch.lap_time();

			assert(lap_time, >=, 15ms);
			assert(lap_time, <, 20ms);
		};

		test_case("stopwatch total time should be close to the sum of all lap times") {
			stopwatch stopwatch;
			auto lap_time = 15ms;
			auto laps = 3;

			for (decltype(laps) i = 0; i < laps; i++) {
				this_thread::sleep_for(lap_time);
				stopwatch.lap_time();
			}

			auto total_time = stopwatch.total_time();

			auto expected_total_time = lap_time*laps;
			assert(total_time, >=, expected_total_time);
			assert(total_time, <, expected_total_time+5ms);
		};

		test_case("reseting stopwatch should reset total time") {
			stopwatch stopwatch;
			this_thread::sleep_for(15ms);
			stopwatch.reset();
			assert(stopwatch.total_time(), <, 1ms);
		};

		test_case("reseting stopwatch should reset lap time") {
			stopwatch stopwatch;
			this_thread::sleep_for(15ms);
			stopwatch.reset();
			assert(stopwatch.lap_time(), <, 1ms);
		};
	}
} end_tests;

