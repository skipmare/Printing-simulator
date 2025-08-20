# Printing Simulator 🖨️
*A C++ simulator for modeling and testing print systems, jobs, and devices.*

## 📖 Overview
This project is a **printing system simulator** written in C++.  
It allows testing of multiple devices (black & white printers, color printers, scanners) and job scheduling without the need for physical hardware.  
The simulator uses XML/text input files to define systems, devices, and job configurations, and runs them through a simulated environment.

---

##  Features
- 🖨Simulates **Black & White** and **Color printers**.
- Includes **Scanner** functionality.
- Job scheduling and queue management.
- System configuration loaded from **XML input files**.
- Error handling for inconsistent or illegal inputs.
- Modular structure (Objects, Jobs, Scheduler, Logger).

---

## Getting Started

### 1. Prerequisites
- C++17 or later
- [CMake](https://cmake.org/) (>= 3.10)

### 2. Build
```bash
git clone https://github.com/skipmare/Printing-simulator.git
cd Printing-simulator-master
mkdir build && cd build
cmake ..
make
