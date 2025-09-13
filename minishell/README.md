MiniShell

A simple shell-like program written in C.
This program reads user input and only exits when the command exit is entered.

Features

Reads user input character by character using getchar().

Detects the exit command and terminates the program.

Displays the prompt (MiniShell> ) again after each line of input.

If the user types something like exitt or exit123, it won’t exit — instead, the input is echoed back.