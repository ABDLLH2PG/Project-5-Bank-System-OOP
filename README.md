# 🏦 Bank Management System (OOP) - Complete Project 🚀

[ **🇸🇦 Read this project in Arabic** ](./README-AR.md)

A robust, console-based banking application developed in **C++**. This project represents the evolution of the banking system into a modern **Object-Oriented Programming (OOP)** architecture, featuring clean design, modularity, file-based data persistence, and a brand-new Currency Exchange module.

---

## 🏗️ Project Modules & Features

### 1️⃣ Core Banking & User Management 👥
* 💼 **Client Management:** Create, Read, Update, Delete (CRUD), and Find bank clients.
* 👨‍💼 **User Management:** Complete system for managing bank staff/admins with granular permissions.
* 💾 **Technical:** Secure data access via Setters/Getters (Encapsulation) and persistent storage in `Clients.txt` and `Users.txt`.

### 2️⃣ Advanced Transactions System 💸
* 💳 **Operations:** Deposit, Withdraw, and Transfer funds securely between accounts.
* 📊 **Reporting:** View total system balances and detailed **Transfer Logs**.
* 💾 **Technical:** Robust validation handling to prevent crashes and ensure data integrity.

### 3️⃣ Currency Exchange Module 💱 (New Feature)
* 🌍 **Functionality:** View available currencies, update exchange rates (pegged to USD), and calculate conversions.
* 🔍 **Search:** Find currencies efficiently by Country Name or Currency Code.
* 💾 **Technical:** Real-time data loading from `Currencies.txt`.

### 4️⃣ Authentication & Security 🔐
* 🔑 **System Access:** Secure login system for authorized users only.
* 📜 **Auditing:** Comprehensive **Login Register History** tracking system access times and user details.

---

## 💻 Code Architecture & OOP Design 🧬

### The Object-Oriented Paradigm
The entire project has been refactored from Procedural to **Object-Oriented Programming (OOP)**. This demonstrates advanced concepts like:
* **Inheritance & Polymorphism:** Using abstract base classes for generic handling.
* **Encapsulation:** Protecting data states via Setters and Getters.
* **Abstraction & Modular Design:** Complete separation between business logic and UI screens.

### 📁 New Project Structure
The project is now reorganized into a strict modular hierarchy for high scalability:
* 🧠 **`Core/`**: Business Logic & Data Models (e.g., `clsBankClient`, `clsCurrency`, `clsUser`).
* 🖥️ **`Screens/`**: User Interface Layers for menus (e.g., `clsMainScreen`, `Client/`, `Currencies/`).
* 🛠️ **`Lib/`**: Reusable Utility Libraries (e.g., `clsString`, `clsInputValidate`, `clsDate`).
* 🗄️ **`Data/`**: Flat-file database storing state (e.g., `Currency.txt`, `TransferLog.txt`).

---

## 🛠️ Key Technical Highlights ✨
* ⚙️ **Standard Template Library (STL):** Extensive use of `std::vector` for efficient memory and data management.
* 🛡️ **Custom Libraries:** Built robust helper classes like `clsString` for parsing data lines and `clsInputValidate` for bulletproof user inputs.
* 🚀 **Clean UI Separation:** The console interface is completely decoupled from the underlying data models.

  
