# Makefiles Project

This project involves the creation of various Makefiles with increasing complexity. Each task adds additional features and requirements to the Makefiles.

## Tasks

### Task 0: make -f 0-Makefile
- **Objective**: Create your first Makefile.
- **Executable Name**: school
- **Rules**: all (builds your executable)
- **Variables**: none

### Task 1: make -f 1-Makefile
- **Objective**: Introduction to variables in Makefiles.
- **Executable Name**: school
- **Rules**: all (builds your executable)
- **Variables**: CC (the compiler), SRC (the .c files)

### Task 2: make -f 2-Makefile
- **Objective**: Create your first useful Makefile.
- **Executable Name**: school
- **Rules**: all (builds your executable and only recompiles updated source files)
- **Variables**: CC (the compiler), SRC (the .c files), OBJ (the .o files), NAME (the executable name)

### Task 3: make -f 3-Makefile
- **Objective**: Adding clean-up rules to the Makefile.
- **Executable Name**: school
- **Rules**: all, clean, oclean, fclean, re
- **Variables**: CC, SRC, OBJ, NAME, RM (the program to delete files)

### Task 4: A complete Makefile
- **Objective**: A complete Makefile with compiler flags.
- **Executable Name**: school
- **Rules**: all, clean, fclean, oclean, re
- **Variables**: CC, SRC, OBJ, NAME, RM, CFLAGS (your favorite compiler flags)

### Task 5: Island Perimeter
- **Objective**: Technical interview preparation - function that returns the perimeter of the island described in grid.
- **Requirements**: Script with no imports, documented module and function.

### Task 6: make -f 100-Makefile (Advanced)
- **Objective**: Advanced Makefile with specific variable and rule requirements.
- **Executable Name**: school
- **Rules**: all, clean, fclean, oclean, re
- **Variables**: CC, SRC, OBJ, NAME, RM, CFLAGS
- **Special Requirements**: RM is not set, string restrictions on CC, RM, and CFLAGS, special rules handling and dependencies.

All Makefiles should be stored in the `0x1C-makefiles` directory of the `alx-low_level_programming` GitHub repository.
