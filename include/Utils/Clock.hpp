#ifndef UTILS_CLOCK_HPP
#define UTILS_CLOCK_HPP

#include <chrono>

class Clock
{
public:
	Clock();
	Clock(const Clock&) = delete;
	Clock(Clock&&) = default;
	~Clock() = default;

	double get_elapsed_seconds();
	void restart();

	Clock& operator=(const Clock&) = delete;
	Clock& operator=(Clock&&) = default;
private:
	std::chrono::steady_clock::time_point m_previous_time;
};

#endif