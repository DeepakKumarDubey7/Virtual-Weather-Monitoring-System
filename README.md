# Virtual Weather Monitoring & Alert System

A Linux-based C++ application that simulates weather conditions (temperature,
humidity, air pressure), raises alerts when values cross safe limits, and logs
every reading to a text file. No hardware required.

## Modules
| Module | Files | Purpose |
|---|---|---|
| Temperature | `TemperatureModule` | Generates random temperature (15-45 °C) |
| Humidity | `HumidityModule` | Generates random humidity (20-100 %) |
| Pressure | `PressureModule` | Generates random pressure (960-1040 hPa) |
| Alert | `AlertModule` | Checks safe limits and builds alert messages |
| Logger | `Logger` | Appends readings to `logs/weather_log.txt` |
| Report | `ReportModule` | Prints the weather report to the terminal |

## Safe limits
- Temperature > 35 °C → High Temperature Warning
- Humidity > 80 % → High Humidity Warning
- Pressure < 990 hPa → Low Pressure Warning
- High humidity + low pressure → Heavy Rain Possibility

## Build & Run
```bash
make                      # compile
./weather_monitor         # 5 readings, 1 second apart
./weather_monitor 10 2    # 10 readings, 2 seconds apart
make clean                # remove build files
```
Requires `g++` and `make` (`sudo apt install build-essential`).

## Sample output
```
====================================
   Virtual Weather Monitoring System
====================================

Temperature : 37 °C
Humidity    : 82 %
Pressure    : 985 hPa

Alerts:
✓ High Temperature Warning
✓ High Humidity Warning
✓ Low Pressure Warning
✓ Heavy Rain Possibility

Data Saved Successfully.

====================================
```

## Linux concepts used
File handling (`fstream`), terminal commands, `mkdir()` / `sleep()` / `getpid()`
system calls, Makefile, Git & GitHub.

## C++ concepts used
Classes and objects, functions, file handling, random number generation,
conditionals, loops, exception handling.

## Folder structure
```
Virtual-Weather-Monitoring-System/
├── src/        implementation (.cpp)
├── include/    headers (.h)
├── logs/       generated log files
├── docs/       project documentation
├── README.md
└── Makefile
```
