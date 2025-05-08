# 42 Philosopher Project

![Project Banner](./image.png)

## 🧠 Project Overview
The Philosopher project is a concurrency exercise inspired by the classic "Dining Philosophers" problem. It teaches the fundamental challenges of process synchronization, deadlock prevention, and thread management in C.

## 🚀 Getting Started

### Installation
Clone the repository and build the project:
```bash
git clone https://github.com/seg-fault0/philosopher.git
cd philosopher
make
```

### Usage
Run the program with the following syntax:
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
Example:
```bash
./philo 5 800 200 200
```
This starts a simulation with 5 philosophers, each with 800 ms to live without eating, 200 ms to eat, and 200 ms to sleep.

## 📂 Project Structure
- **src/** - Source code files.
- **includes/** - Header files.
- **Makefile** - Build automation script.

