# Multi File Copy Program

## Introduction

### 1. Overview

This project is to implement a Multi File Copy Program with C

This program copys muliple files from current directory to specific directory using 256 buffer.

### 2. Usage Example & Testing

### How To Use?

1. Use gcc to compile main.c

```bash
gcc main.c
```

* This proccess will make **a.out** file

2. Test files are provided (temp1.txt ~ temp5.txt)
3. Execute **a.out**

```bash
./a.out <filename1> <filename2> ... <filenameN> <directory name>
```

* \<directory name> supprots both Absolute Path and Relative Path

* \<directory name> should be under 256
* Last Parameter should be \<directory name>

### Testing

#### 1. SUCCESS CASE

#### 1.1Relative Path

INPUT

```bash
./a.out temp1.txt temp2.txt temp3.txt temp4.txt temp5.txt ./Temp
```

OUTPUT

```bash
ARGC : 7

Copying File Number: 1
Length : 256
!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^
Length : 256
&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@
Length : 89
#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()


Copying File Number: 2
Length : 11
!@#$%^&*()


Copying File Number: 3
Length : 4
123


Copying File Number: 4
Length : 4
abc


Copying File Number: 5
Length : 6
apple
```

#### 1.2 Absolute Path

INPUT

```bash
./a.out temp1.txt temp2.txt temp3.txt temp4.txt temp5.txt /Users/hanseunghun/Downloads/Test/Temp
```

OUTPUT

```bash
ARGC : 7

Copying File Number: 1
Length : 256
!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^
Length : 256
&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@
Length : 89
#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()


Copying File Number: 2
Length : 11
!@#$%^&*()


Copying File Number: 3
Length : 4
123


Copying File Number: 4
Length : 4
abc


Copying File Number: 5
Length : 6
apple
```

#### 2. ERROR CASE

#### 2.1 File Not Found

INPUT

```bash
./a.out temp1.txt temp2.txt temp3.txt nofile.txt temp5.txt ./Temp
```

OUTPUT

```bash
ARGC : 7
ERROR: Number 4 file dosen't exist
```

#### 2.2 DIR not found

INPUT

```bash
./a.out temp1.txt temp2.txt temp3.txt temp4.txt temp5.txt ./noDIR
```

OUTPUT

```bash
ARGC : 7
ERROR: ./noDIR DIR dosen't exist
```

#### 2.3 Less Parameter

INPUT

```bash
./a.out temp1.txt
```

OUTPUT

```bash
ARGC : 2
Usage : ./a.out <filename1> <filename2> ... <filenameN> <directory name>
```



