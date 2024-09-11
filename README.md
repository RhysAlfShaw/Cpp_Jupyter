# Creating a C++ jupyter server for notebooks

This is a concise guide on how to set up a C++ kernal for jupyter notebooks. This let you write C++ code from these cells.

## Create your conda env

```bash
conda create -n cling
conda activate cling
```

## Installing Mamba
There are issues in installing this though conda, but mamba works so lets install mamba.
```bash
conda install conda-forge::mamba
```

## Installing Xeus and JupyterLab

Xeus is a C++ jupyter kernal.

```bash
mamba install -c conda-forge xeus-cling
mamba install jupyterlab -c conda-forge
```

## Test the install of Xeus by running xcpp.

you should see..

```output
registering handler for SIGSEGV
Starting xeus-cling kernel...

If you want to connect to this kernel from an other client, just copy and paste the following content inside of a `kernel.json` file. And then run for example:

# jupyter console --existing kernel.json

kernel.json

{
    "transport": "tcp",
    "ip": "127.0.0.1",
    "control_port": 58601,
    "shell_port": 57998,
    "stdin_port": 53390,
    "iopub_port": 63891,
    "hb_port": 59366,
    "signature_scheme": "hmac-sha256",
    "key": "330de887537f4e228e24df281c46ff3f"
}

Run with XEUS 3.1.5
```

## Connecting to the Jupyter kernal in vscode.

Start the jyputer server with command;

```bash
jupyterlab --no-browser
```

Use the URL of the runing server to connect to it and select you choice of C++ compiler.

Test the kernal with hello world.
```c++
#include <iostream>
std::cout << "Hello World!";
```

## Writing code to file and compiling a binary.

to write you code to a file use the magic command

```c++
%%file [filename]
code to write to file...

```

Then you can compile to a binary in you prefered way.

Note: your code will need to be put int a main(){} function to compile. This is done automatically when executed in a cell, but not when you create a .cpp file.