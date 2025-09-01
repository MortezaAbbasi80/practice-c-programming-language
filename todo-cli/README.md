# Todo CLI

A simple command-line todo list manager written in **C**.  
You can add, remove, list, and mark tasks as done or undone directly from your terminal.

---

## Features
- Add new tasks
- Remove tasks by number
- Mark tasks as **done** or **undone**
- Show all tasks, only done tasks, or only undone tasks
- Clear the whole list
- Data is stored in a text file

---

## Usage
After compiling and running the program:

```bash
todo list> add Buy milk
todo list> add Finish homework
todo list> list
todo list> done 1
todo list> list --done
todo list> remove 2
todo list> clear
todo list> exit
```
---

## Commands

- `add [task]` → Add a new task
- `list` → Show all tasks
- `list --done` → Show only completed tasks
- `list --undone` → Show only undone tasks
- `done [task number]` → Mark task as done
- `undone [task number] `→ Mark task as undone
- `remove [task number]` → Remove a task
- `clear `→ Delete all tasks
- `help `→ Show help menu
- `exit` → Exit program

---
## How To Compile
```bash
gcc todo.c -o todo
./todo
```
---
## License
This project is open source. Use it however you like.
