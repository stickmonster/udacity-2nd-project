#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

void System::NewProcesses() {
    processes_ = {};
    auto process_ids = LinuxParser::Pids();
    for (int id : process_ids) {
        processes_.push_back(Process(id));
    }
}

// TODO: Return the system's CPU
Processor& System::Cpu() const { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() const { 
    NewProcesses();
    std::sort (processes_.begin, processes_.end, std::greater<Process>())
    return processes_; 
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() const { 
    if (kernel_.length == 0)
    kernel_ = LinuxParser::Kernel(); 
    return kernel_;
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() const {
    if (os_.length == 0) 
    os_ = LinuxParser::OperatingSystem();
    return os_;
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses; }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses; }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime; }