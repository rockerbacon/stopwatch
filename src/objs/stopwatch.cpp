#include "stopwatch.h"
#include <vector>
#include <sstream>

using namespace std;

stopwatch::stopwatch (void) {
	reset();
}

void stopwatch::reset (void) {
	stopwatch_begin = chrono::high_resolution_clock::now();
	lap_begin = stopwatch_begin;
}

chrono::high_resolution_clock::duration stopwatch::total_time (void) const {
	return chrono::high_resolution_clock::now() - this->stopwatch_begin;
}

chrono::high_resolution_clock::duration stopwatch::lap_time (void) {
	auto lap_time = chrono::high_resolution_clock::now() - lap_begin;
	lap_begin = chrono::high_resolution_clock::now();
	return lap_time;
}

struct time_unit_count {
	std::string unit;
	long long count;
};

template<typename stream_t>
void push_duration_into_stream (stream_t& stream, chrono::high_resolution_clock::duration duration) {
	vector<time_unit_count> time_unit_counts;
	bool stream_altered;
	size_t i;

	auto hours = chrono::duration_cast<chrono::hours>(duration);
	duration -= chrono::duration_cast<decltype(duration)>(hours);
	auto minutes = chrono::duration_cast<chrono::minutes>(duration);
	duration -= chrono::duration_cast<decltype(duration)>(minutes);
	auto seconds = chrono::duration_cast<chrono::seconds>(duration);
	duration -= chrono::duration_cast<decltype(duration)>(seconds);
	auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration);
	duration -= chrono::duration_cast<decltype(duration)>(milliseconds);
	auto microseconds = chrono::duration_cast<chrono::microseconds>(duration);

	time_unit_counts.reserve(5);

	time_unit_counts.push_back({"h", hours.count()});
	time_unit_counts.push_back({"m", minutes.count()});
	time_unit_counts.push_back({"s", seconds.count()});
	time_unit_counts.push_back({"ms", milliseconds.count()});
	time_unit_counts.push_back({"us", microseconds.count()});

	stream_altered = false;
	for (i = 0; i < time_unit_counts.size()-1; i++) {
		if (time_unit_counts[i].count > 0) {
			if (stream_altered) {
				stream << ' ';
			}
			stream << time_unit_counts[i].count << time_unit_counts[i].unit;
			stream_altered = true;
		}
	}

	if (!stream_altered) {
		stream << time_unit_counts[i].count << time_unit_counts[i].unit;
	}
}

ostream& operator<<(ostream& stream, const chrono::high_resolution_clock::duration& duration) {
	push_duration_into_stream(stream, duration);
	return stream;
}

string std::to_string(const chrono::high_resolution_clock::duration& duration) {
	stringstream string_builder;
	push_duration_into_stream(string_builder, duration);
	return string_builder.str();
}

