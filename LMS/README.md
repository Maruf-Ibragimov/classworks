

# Library Management System (LMS)

A simple console-based Library Management System (LMS) implemented in C++.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Compilation](#compilation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

- Add new books to the library.
- Remove books from the library.
- Search for books by title, author, or ISBN.
- List all books in the library.

## Prerequisites

- A C++ compiler supporting C++17 (e.g., GCC, Clang).
- `make` utility for building the project.

## Compilation

1. Clone this repository:

```bash
git clone <repository-url>
cd path-to-repo
```

2. Build the project using the `make` command:

```bash
make
```

This will generate the executable `lms` inside the `bin` directory.

## Usage

Run the LMS:

```bash
./bin/lms
```

Follow the on-screen prompts to use the system's features.

## File Structure

```
.
├── src/             # Source files
├── headers/         # Header files
├── data/            # Data files (e.g., books.txt)
├── bin/             # Compiled binary
└── Makefile         # Make utility to automate builds
```

## Contributing

Contributions are welcome! Please read the contribution guidelines first.

## License

This project is open source and available under the [MIT License](LICENSE).

