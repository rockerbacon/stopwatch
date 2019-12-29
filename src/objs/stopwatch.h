#pragma once

#include <chrono>
#include <ostream>

class stopwatch {
	private:
		std::chrono::high_resolution_clock::time_point lap_begin;
		std::chrono::high_resolution_clock::time_point stopwatch_begin;
	public:
		stopwatch (void);

		void reset (void);
		std::chrono::high_resolution_clock::duration total_time (void) const;
		std::chrono::high_resolution_clock::duration lap_time (void);
};

std::ostream& operator<<(std::ostream& stream, const std::chrono::high_resolution_clock::duration& duration);

namespace std {
	std::string to_string (const std::chrono::high_resolution_clock::duration& duration);
}

