# Customer Data Filter Program

This C++ program reads customer data from a file, filters them based on user-defined criteria such as age, gender, and yearly income, and displays the number of potential customers who meet the criteria.

## Table of Contents

- [Getting Started](#getting-started)
- [Compilation](#compilation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Example](#example)
- [License](#license)

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`)
- A text editor or IDE (optional)

### Files

- **main.cpp**: Contains the main function and the logic for reading and filtering data.
- **person.h**: The header file containing the definition of the `Person` class.
- **person.cpp**: The implementation file for the `Person` class.

## Compilation

To compile the program, use the following command:

```bash
g++ -o customer_filter main.cpp person.cpp
```
## Usage
To run the program, use the following command:
```bash
./customer_filter [DATA_FILE]
```
Replace [DATA_FILE] with the path to your text file containing customer data.

### Input File Format
The input data file should be structured as follows:
```python
AGE GENDER YEARLY_INCOME
30 male 50000
25 female 45000
40 male 60000
...
```
## Program Example

If you were to run the program, lets say you provided it with the following dataset:
```
30 male 50000
25 female 45000
40 male 60000
35 female 55000
```
If you were to provide the program with the following inputs:
- Age Range: "25-35"
- Gender: Female
- Income: "4000 - 6000" 

The output presented would be:
```java
Number of potential customers = 2
```


## License

This project is licensed under the MIT License.

---
##### Developed by Cedric Nartey




