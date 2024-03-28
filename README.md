# MinilibC Project Summary

## Overview

The MinilibC project, coded in x86-64 Assembly, aimed to delve deeper into the intricacies of system libraries. The primary objective was to develop a dynamic ELF library, `libasm.so`, to replace, to some extent, the standard C library commonly used on everyday systems.

## Repository Details

- **Binary Name:** `libasm.so`
- **Group Size:** 1
- **Language:** x86-64 Assembly, tests in C
- **Compilation:** Managed via a Makefile, including `re`, `clean`, and `fclean` rules.

## Key Objectives

1. **Dynamic Library Creation:** Developed a dynamic ELF library to emulate standard C library functionalities.
  
2. **Weak Binding:** Leveraged `LD_PRELOAD` for weak binding to allow the replacement of standard library functions with custom implementations.

## Implemented Functions

The following standard C library functions were successfully implemented:

- `strlen`
- `strchr`
- `memset`
- `memcpy`
- `strcmp`
- `memmove`
- `strncmp`
- `strcasecmp`
- `rindex`
- `strstr`
- `strpbrk`
- `strcspn`

## Bonus Features

Explored potential bonus points including:

- Additional functions like `read` and `write`.
- Support for other architectures such as 32-bit x86 or ARM.


## Conclusion

The MinilibC project was a challenging yet rewarding experience that provided a deeper understanding of system libraries and the underlying mechanisms that power them. The project also helped in honing assembly language skills and exploring the intricacies of dynamic libraries and weak binding.

---

