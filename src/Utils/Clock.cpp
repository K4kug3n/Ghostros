#include "Utils/Clock.hpp"

Clock::Clock()
	: m_previous_time(std::chrono::high_resolution_clock::now())
{}

double Clock::get_elapsed_seconds()
{
	std::chrono::steady_clock::time_point new_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = new_time - m_previous_time;
	m_previous_time = std::move(new_time);

	return std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count() / 1000000000.f;
}

void Clock::restart()
{
	m_previous_time = std::chrono::high_resolution_clock::now();
}
