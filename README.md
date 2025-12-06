# 🚀 Hexagonal Architecture Project with Arduino (ESP8266) - Base Template

## 🌟 1. Project Overview

This project implements the **Hexagonal Architecture (Ports and Adapters)** in C++ for an embedded software application (Arduino/ESP8266).

The main goal is to **isolate the Core Logic** from external dependencies (hardware, LCD, timing, data repository), achieving:

1.  **Testability:** Run complete **unit tests** in a PC environment (GCC).
2.  **Portability:** The business code can change platforms or hardware (LCD to OLED, for example) without modifying the core.

[Image of Clean Architecture layers diagram]

-----

## 🏗️ 2. Architectural Structure

The folder structure reflects the layers of the Hexagonal pattern:

| Folder | Layer | Responsibility |
| :--- | :--- | :--- |
| **`Domain/`** | **Core** | Entities (`User.h`) and **Interfaces/Ports** (`Ports.h`). Defines the *business rule*. |
| **`Services/`** | **Core** | Specific business logic (`UserCycleService.h/cpp`). Manipulates entities. |
| **`Application/`** | **Core** | Orchestration and timers (`Controller.h`). Coordinates services. |
| **`Infrastructure/`** | **Adapters** | Concrete implementations of interfaces, tied to the hardware (`LCDAdapter.h/cpp`, `SimulatedUserRepository.h/cpp`). |
| **`Tests/`** | **Test Environment**| Mocks (`Mocks.h`) and test files (`TestUserCycleService.cpp`, etc.). |
| **`hexa.ino`** | **Composition Root**| Initializes all components and injects dependencies. |

-----

## 🧪 3. Unit Tests (PC with g++)

The unit tests validate the logic in `Services/` and `Application/` in a PC environment, using Mocks to simulate the infrastructure.

### 3.1. Test Compilation

Execute the following command in the root folder (`hexa/`). It compiles the test files and the implementation files (`.cpp`) which were moved to the root to facilitate the Arduino linker:

```bash
g++ -std=c++11 -o test_runner Tests/main_test.cpp Tests/TestUserCycleService.cpp Tests/TestController.cpp UserCycleService.cpp SimulatedUserRepository.cpp
```

### 3.2. Test Execution

```bash
.\test_runner.exe
```

### 3.3. Expected Output

The output must confirm that the core logic is sound:

```
===========================================
 UNIT TESTS - HEXAGONAL ARCHITECTURE
===========================================
--- Executing Service Tests ---
✅ TestUserCycleService PASSED
--- Executing Controller Tests ---
✅ TestController PASSED

===========================================
🎉 Core Logic Tests Finished! 🎉
===========================================
```

-----

## ⚙️ 4. Production Environment (Arduino/ESP8266)

The final code is uploaded via the Arduino IDE.

  * **Platform:** Tested on **ESP8266** (compatible with the Arduino framework).
  * **Real Libraries:** The **`LiquidCrystal.h`** library is required for the `LCDAdapter`.
  * **Linker Solution:** The implementation files (`.cpp`) are placed in the root folder so the Arduino linker can find them correctly.

-----

## ♻️ 5. Reuse Guide (Base Template)

**This repository is designed to be a Master Template for new C++ based firmware projects.**

The structure provides a solid foundation for any application requiring separation of concerns and testability.

  * **To start a new project:** Copy the entire folder structure (`hexa/`) to a new location.
  * **Modify the Core:** Edit the files inside `Domain/`, `Services/`, and `Application/` to implement the **new business logic** required by your new project.
  * **Replace Adapters:** Reuse or modify the files in `Infrastructure/` (e.g., switch `SimulatedUserRepository` for an `EEPROMRepository` or a `WiFiAdapter`).
  