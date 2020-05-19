#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
	float utilization_ = { 0 };
	long active_ticks = LinuxParser::ActiveJiffies();
	long idle_ticks = LinuxParser::IdleJiffies();
	long duration_active(active_ticks - cached_active_ticks);
	long duration_idle(idle_ticks - cached_idle_ticks);
	long duration(duration_active + duration_idle);
	utilization_ = static_cast<float> (duration_active) / duration;
	cached_active_ticks = active_ticks;
	cached_idle_ticks = idle_ticks;	
	return utilization_;
	return 0.0; }