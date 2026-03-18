# Libraries — Reusable C Utility Functions

A collection of reusable C function libraries developed during **Informática 1** at **UTNBA (2022)**. Each subfolder is a self-contained module organized by topic.

## Modules

| Module | Files | Description |
|---|---|---|
| **Strings/** | `my_strings.c/h`, `main.c` | String manipulation: copy, compare, tokenize, length, etc. |
| **Sorting/** | `my_sorting.c/h`, `main.c` | Sorting algorithms: bubble, selection, insertion, etc. |
| **LinkedLists/** | `lists.h`, `singly_linked.c`, `doubly_linked.c`, `queue.c`, `stack.c`, `factorial_recursive.c` | Linked lists, queues, stacks, and recursive helpers |
| **Matrix/** | `matrix_ops.c` | Matrix creation, transposition, multiplication, and display |
| **FileIO/** | `file_copy.c`, `file_rename.c`, `file_open_filter.c`, `bin_file_rw.c`, `bin_read_int32.c` | File copy, rename, binary read/write, filtered reading |
| **Math/** | `math_funcs.c` | Mathematical utility functions |
| **Bitwise/** | `bit_ops.c` | Bitwise operation utilities |
| **Encryption/** | `string_encrypt.c` | String encryption and decryption functions |
| **Conversion/** | `itostr_strtol.c` | Integer-to-string (`itoa`) and string-to-long (`strtol`) |
| **Signals/** | `signals_example.c`, `signal_handling.c` | UNIX signal handling examples and utilities |
| **Networking/** | `sock_lib.c/h`, `ServerClient/` | Socket library and a server-client implementation |
| **Misc/** | `char_num_bits_random.c`, `reverse_array.c`, `bubble_sort.c` | Miscellaneous standalone utilities |

## Usage

Each module can be compiled independently with GCC. For modules with a `main.c` test file:

```bash
gcc -o test my_strings.c main.c -Wall
./test
```
