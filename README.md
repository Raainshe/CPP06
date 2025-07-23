# CPP06 - C++ Casts

This project explores different types of C++ casts and type conversions. It consists of three exercises that demonstrate scalar conversion, serialization, and runtime type identification.

## Table of Contents
- [Exercise 00: Conversion of scalar types](#exercise-00-conversion-of-scalar-types)
- [Exercise 01: Serialization](#exercise-01-serialization)
- [Exercise 02: Identify real type](#exercise-02-identify-real-type)
- [Compilation](#compilation)
- [Usage](#usage)

## Exercise 00: Conversion of scalar types

### Description
The `ScalarConverter` class converts string representations of scalar values to different C++ scalar types (char, int, float, double). It handles various edge cases including:
- Character literals (e.g., 'a', 'Z')
- Integer values 
- Float values (with 'f' suffix)
- Double values
- Special values (nan, nanf, inf, inff, +inf, -inf, etc.)
- Impossible/non-displayable conversions

### Features
- **Static-only class**: Cannot be instantiated
- **Comprehensive conversion**: Handles all scalar types
- **Error handling**: Detects impossible conversions
- **Special value support**: Handles infinity and NaN values
- **Display formatting**: Shows appropriate precision for floats/doubles

### Files
- `ScalarConverter.hpp` - Class declaration
- `ScalarConverter.cpp` - Implementation with conversion logic
- `main.cpp` - Test program demonstrating various conversions

## Exercise 01: Serialization

### Description
This exercise implements serialization and deserialization of pointers using the `Serializer` class. It converts between pointer addresses and integer representations using `uintptr_t`.

### Key Concepts
- **Serialization**: Converting a pointer to an unsigned integer (`uintptr_t`)
- **Deserialization**: Converting the integer back to the original pointer
- **Pointer arithmetic**: Understanding memory addresses as integers
- **Static functions**: Utility functions that don't require object instantiation

### Components
- **Serializer class**: Contains static methods for conversion
- **Data structure**: A custom data type for testing serialization
- **Round-trip testing**: Ensures pointer → integer → pointer preserves the original address

### Files
- `Serializer.hpp` - Serializer class declaration
- `Serializer.cpp` - Implementation of serialize/deserialize methods
- `Data.hpp` - Custom data structure definition
- `Data.cpp` - Data structure implementation
- `main.cpp` - Test program verifying round-trip conversion

## Exercise 02: Identify real type

### Description
This exercise demonstrates runtime type identification using `dynamic_cast`. It includes a base class hierarchy and functions to identify the actual type of objects at runtime.

### Key Features
- **Polymorphic base class**: `Base` with virtual destructor
- **Derived classes**: Empty classes `A`, `B`, and `C` inheriting from `Base`
- **Random generation**: Function to randomly create instances of A, B, or C
- **Type identification**: Two overloaded functions using different approaches:
  - Pointer version: Uses `dynamic_cast` with pointers
  - Reference version: Uses `dynamic_cast` with references and exception handling

### Type Identification Methods
1. **Pointer method**: Uses `dynamic_cast<Type*>()` and checks for null return
2. **Reference method**: Uses `dynamic_cast<Type&>()` with try-catch for `std::bad_cast`

### Files
- `Base.hpp` - Base class and function declarations
- `Base.cpp` - Implementation of all functions
- `A.hpp`, `B.hpp`, `C.hpp` - Derived class declarations
- `main.cpp` - Test program demonstrating type identification

## Compilation

Each exercise can be compiled independently using the provided Makefiles:

### Exercise 00
```bash
cd ex00
make
# Creates executable: scalar
```

### Exercise 01  
```bash
cd ex01
make
# Creates executable: serialize
```

### Exercise 02
```bash
cd ex02
make  
# Creates executable: base
```

### Clean compilation files
```bash
# In each exercise directory:
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Clean and rebuild
```

## Usage

### Exercise 00 - Scalar Conversion
```bash
cd ex00
./scalar "42"        # Convert integer
./scalar "42.5f"     # Convert float
./scalar "42.5"      # Convert double  
./scalar "'a'"       # Convert character
./scalar "nan"       # Special value
./scalar "impossible" # Invalid input
```

**Example output:**
```
./scalar "42"
char: '*'
int: 42
float: 42.0f
double: 42.0

./scalar "nan"
char: impossible
int: impossible
float: nanf
double: nan
```

### Exercise 01 - Serialization
```bash
cd ex01
./serialize
```

**Example output:**
```
=== Testing Serialization ===
Data constructor called
Original pointer: 0x7ffd123456789
Serialized value: 140725291808649
Deserialized pointer: 0x7ffd123456789
Pointers match: ✓
Data destructor called
```

### Exercise 02 - Type Identification
```bash
cd ex02
./base
```

**Example output:**
```
=== Testing Base Type Identification ===

--- Test 1 ---
Generated: A
identify(Base* p): A
identify(Base& p): A

--- Test 2 ---
Generated: C  
identify(Base* p): C
identify(Base& p): C

--- Test 3 ---
Generated: B
identify(Base* p): B
identify(Base& p): B
```

## Learning Objectives

This project demonstrates:
- **C++ casting mechanisms**: static_cast, dynamic_cast, reinterpret_cast concepts
- **Type conversion**: Converting between different scalar types safely
- **Serialization techniques**: Converting pointers to integers for storage/transmission
- **Runtime Type Information (RTTI)**: Identifying object types at runtime
- **Polymorphism**: Virtual functions and inheritance
- **Exception handling**: Using try-catch with dynamic_cast references
- **Static class design**: Creating utility classes that cannot be instantiated

## Technical Notes

- All exercises follow C++98 standard
- Memory management is handled properly (no leaks)
- Error cases are handled gracefully
- Code follows 42 School coding standards
- Comprehensive testing covers edge cases and normal usage

---

**Author**: rmakoni  
**School**: 42 Heilbronn  
**Project**: CPP Module 06