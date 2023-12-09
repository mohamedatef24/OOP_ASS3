/// File name: A3_SheetPb2_20220293.cpp
/// Purpose: Problem5 --> Perform operations on processes and display process information.
/// Author(s): Mohamed Atef Mouad
/// ID(s): 20220293
/// Section: S23
/// Date: 7/12/2023
/// TA: Eng. Mohammed Talaat
/*
 This code defines two classes: Process and list_of_running_processes.
 The Process class represents an individual process with attributes like process name, ID, and memory usage.
 The list_of_running_processes class manages a list of Process objects and provides methods to add processes, sort them by name, ID, or memory usage, display sorted processes
 and fetch processes from the operating system using Windows API functions like EnumProcesses, OpenProcess, and GetProcessMemoryInfo.
 The main function demonstrates the usage of these functionalities by adding sample processes, displaying them sorted by different criteria
 fetching and displaying processes from the operating system.
 */
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <algorithm>

#pragma comment(lib, "Psapi.lib")

 // Class representing an individual process
class Process {
    std::string pName, pID, memory_usage;

public:
    // Constructors
    Process() : pName(""), pID(""), memory_usage("") {}
    Process(std::string pName, std::string pID, std::string memory_usage) : pName(pName), pID(pID), memory_usage(memory_usage) {}

    // Method to display process information
    void display_process() const {
        std::cout << "Process Name: " << pName << " ,Process ID: " << pID << " ,Memory Usage: " << memory_usage << '\n';
    }

    // Getter methods for process attributes
    std::string Get_Name() const {
        return pName;
    }
    std::string Get_ID() const {
        return pID;
    }
    std::string Get_Memory_Usage() const {
        return memory_usage;
    }
};

// Class representing a list of running processes
class list_of_running_processes {
    std::vector<Process> processes;

public:
    // Default constructor
    list_of_running_processes() = default;

    // Method to add a process to the list
    void add_process(std::string name, std::string id, std::string memory) {
        Process p(name, id, memory);
        processes.push_back(p);
    }

    // Methods to sort processes by name, ID, and memory usage
    void sort_by_name() {
        std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.Get_Name() < b.Get_Name();
            });
    }

    void sort_by_ID() {
        std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return std::stod(a.Get_ID()) < std::stod(b.Get_ID());
            });
    }

    void sort_by_Memory() {
        std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return std::stod(a.Get_Memory_Usage()) < std::stod(b.Get_Memory_Usage());
            });
    }

    // Methods to display sorted processes
    void display_processes_Sorted_by_Name() {
        sort_by_name();
        std::cout << "\n================== Display Processes Sorted by Name ==================\n\n";
        for (auto p : processes) {
            p.display_process();
        }
        std::cout << "\n======================================================================\n";
    }

    void display_processes_Sorted_by_ID() {
        sort_by_ID();
        std::cout << "\n=================== Display Processes Sorted by ID ===================\n\n";
        for (auto p : processes) {
            p.display_process();
        }
        std::cout << "\n======================================================================\n";
    }

    void display_processes_Sorted_by_Memory_Usage() {
        sort_by_Memory();
        std::cout << "\n============== Display Processes Sorted by Memory Usage ==============\n\n";
        for (auto p : processes) {
            p.display_process();
        }
        std::cout << "\n======================================================================\n";
    }

    // Method to fetch and display processes from the operating system
    void Processes_from_OS() {
        processes.clear();
        DWORD processes_from_OS[1024], bytesReturned;
        unsigned int numProcesses;

        // Enumerate all processes
        if (!EnumProcesses(processes_from_OS, sizeof(processes_from_OS), &bytesReturned)) {
            std::cerr << "Failed to enumerate processes!" << std::endl;
            return;
        }

        // Calculate the number of processes
        numProcesses = bytesReturned / sizeof(DWORD);

        // Iterate through the processes and retrieve their information
        for (unsigned int i = 0; i < numProcesses; ++i) {
            if (processes_from_OS[i] != 0) {
                HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processes_from_OS[i]);
                if (processHandle != nullptr) {
                    TCHAR processName[MAX_PATH];
                    if (GetModuleBaseName(processHandle, nullptr, processName, MAX_PATH) != 0) {
                        PROCESS_MEMORY_COUNTERS_EX memoryInfo;
                        if (GetProcessMemoryInfo(processHandle, (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo))) {
                            Process p(processName, std::to_string(processes_from_OS[i]), std::to_string(memoryInfo.WorkingSetSize));
                            processes.push_back(p);
                        }
                        else {
                            std::cerr << "Failed to retrieve memory info for the process ID: " << processes_from_OS[i] << std::endl;
                        }
                    }
                    CloseHandle(processHandle);
                }
            }
        }
    }
};

// Main function
int main() {
    list_of_running_processes obj;

    // Adding sample processes
    obj.add_process("mohamed", "02", "10,500");
    obj.add_process("atef", "01", "20,600");

    // Displaying processes sorted by different criteria
    obj.display_processes_Sorted_by_ID();
    obj.display_processes_Sorted_by_Name();
    obj.display_processes_Sorted_by_Memory_Usage();

    // Fetching processes from the operating system and displaying sorted results
    obj.Processes_from_OS();
    obj.display_processes_Sorted_by_Name();
    obj.display_processes_Sorted_by_ID();
    obj.display_processes_Sorted_by_Memory_Usage();

    return 0;
}
