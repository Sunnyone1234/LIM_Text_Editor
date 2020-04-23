# LIM_Text_Editor
#### tags: c++, sequence of chars

## Some Editor 
#### tags: [Scintilla](https://www.scintilla.org/)
A free source code editing component

## Text Editor Resources
### Data Structure for Text Sequences
#### tags: [Charles Crowley](https://www.cs.unm.edu/~crowley/papers/sds.pdf)
There are six common sequence data structures: [array](https://en.wikipedia.org/wiki/Linked_list), [gap](https://www.geeksforgeeks.org/gap-buffer-data-structure/)(https://iq.opengenus.org/gap-buffer/), [linked list](https://en.wikipedia.org/wiki/Linked_list), [line pointers](https://www.cs.unm.edu/~crowley/papers/sds.pdf), [fixed size buffers](https://www.cs.unm.edu/~crowley/papers/sds.pdf) and piece tables
|   | array  | linked list  | gap  | line pointers  |  fixed size buffers | piece tables  |
|---|---|---|---|---|---|---|
| indexing  | O(1)  | O(n)  | O(n)  | O(1)  | works as array O(1)   |   |
| insert/delete at one site | O(n)  | insert:O(1)/delet:O(n)  | O(1)/grow_up:O(n)/left or right:O(n)  | insert:used copy so O(n) or O(copylength)/ delete: O(1)  | works as arrayO(n)  |   |
| insert/delete in middle  | O(n) | insert:O(1)/delet:O(n)  | O(1)/grow_up:O(n)/left or right:O(n)  | inster:used copy so O(n) or O(copylength)/delete: must moving the rest so O(n)  | works as arrayO(n)  |   |
| insert/delte line | | | | adding or deleting the line descriptor so O(1) | | |

## Choice of language
C and C++ will be used for this project. The text editor control will be written in C++ and provide a interface to main application, which is written in "pure win32" C, the [windows data type](https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types) will be used. For C in windows "\r" means carriage return; "\n" means line feed.
|||
|---|---|
|PAINTSTRUCT,	ULONG|BeginPaint, SelectObject|

## Text Editor structure
The structure of Text Editor is like a tower.  
|component|description|
|---|---|
|Main Window| <- title, menu, status bars|
|TextView| <- child of main window, display and edit text, display scrollbars, process mouse and keyboard input|
|TextDocument| <- store and manipulate a text file|
|Text File||

## Function of text editor control
Fast, smooth graphic display.
Syntax colouring
Full clipboard and drag-and-drop support
Single-font?
complete Undo and Redo support
ASCII, Unicode and UTF-8 compatible

## 
