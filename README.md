# 📝 To-Do Application (v2.0 – Qt GUI)

A clean and scalable **To-Do application built using C++ and Qt**, upgraded from a CLI-based version to a full **GUI application**.

This project focuses on **clean architecture**, **proper separation of concerns**, and **real-world Qt development practices**.

---

## 🚀 Features

### ✅ Core Features
- Add tasks with title and description
- Edit existing tasks
- Delete tasks
- Mark tasks as completed / pending
- Visual indication for completed tasks

### 💾 Persistence
- Tasks are loaded automatically on application startup
- Tasks are saved automatically on application close
- File-based storage using `tasks.txt`

### 🧠 Architecture Highlights
- Clear separation between **UI layer** and **backend logic**
- Backend (`TodoManager`) is the single source of truth
- ID-based task management (robust and scalable)
- UI always reflects backend state (no UI-only mutations)

---

## 🛠 Tech Stack

- **Language:** C++
- **GUI Framework:** Qt (Qt Widgets)
- **Build System:** CMake
- **IDE:** Qt Creator
- **Platform:** Cross-platform (Windows / Linux / macOS)

---

## 📁 Project Structure

```
todo-gui/
├── backend/
│   ├── Task.hpp
│   ├── TodoManager.hpp
│   └── TodoManager.cpp
│
├── build/              # (ignored by git)
│
├── main.cpp
├── mainwindow.h
├── mainwindow.cpp
├── mainwindow.ui
├── CMakeLists.txt
└── README.md
```

---

## 🧩 Design Decisions

- **Backend-driven design**  
  All task operations (add, delete, edit, toggle) are handled by the backend.  
  The UI simply displays backend data.

- **Signal safety**  
  Qt signals are carefully managed to avoid infinite loops and unintended state changes.

- **Scalability**  
  The architecture supports future enhancements without refactoring core logic.

---

## 📌 Version History

### v1.0 – CLI
- Command-line interface
- Basic task management
- File persistence

### v2.0 – GUI (Current)
- Full Qt GUI
- Add / Edit / Delete tasks
- Mark tasks as complete
- Persistent storage
- Clean backend architecture

---

## 🔮 Planned Enhancements

- **v2.1:** Categories & Priority
- **v2.2:** Sorting & Filtering
- **v2.3:** Due dates & timestamps
- **v2.4:** Themes & drag-and-drop reordering
- **v3.0:** Authentication & cloud sync

---

## ▶️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/Ayush16110/todo-cpp-gui.git
   ```
2. Open the project in **Qt Creator**
3. Configure using **CMake**
4. Build and run the application

---

## 👤 Author

**Ayush**  
B.Tech CSE Student  
Interested in C++, Qt, Backend Systems, and Scalable Software Design

---

## ⭐ Feedback

If you find this project useful, feel free to ⭐ star the repository and share feedback!
