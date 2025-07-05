# cliengine-precompiler

`cliengine-precompiler` is a command-line tool designed to preprocess and compile command definitions for the cliengine CLI engine. It reads command definitions from a JSON file and generates a C++ header file for fast loading in your CLI projects.

## Features

- Converts command definitions from JSON into C++ header files
- Simplifies integration of predefined commands into cliengine projects
- Helps speed up CLI engine startup by avoiding runtime parsing

---

## Installation

### From source

```bash
git clone https://github.com/yourusername/cliengine-precompiler.git
cd cliengine-precompiler
mkdir build && cd build
cmake ..
make
sudo make install
```

### Usage
cliengine-precompiler <input-json-file> <output-header-file>

### Example
cliengine-precompiler commands.json commands.hpp