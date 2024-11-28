# Merge Sort Implementation in MIPS Assembly

## **Introduction**
This project showcases a **MIPS Assembly** implementation of the **Merge Sort Algorithm**, a classical divide-and-conquer sorting technique. The program takes an array of integers as input, validates the size of the array, and sorts it using the merge sort algorithm. The result is then printed to the console. This implementation demonstrates proficiency in low-level programming, recursion, and stack management.

---

## **Features**
- **Input Validation**: Ensures the array size is between 1 and 20.
- **Recursive Merge Sort**: Implements a highly efficient sorting algorithm using recursion.
- **Dynamic Stack Management**: Leverages the stack to handle array segments during sorting.
- **User-Friendly Output**: Prints the sorted array in an easily readable format.

---

## **Program Structure**
### 1. **Data Section**
Defines constants, messages, and storage for the array:
- `maxsize`: Maximum allowed size of the array.
- `arr`: Memory space for storing the input array.
- Strings like `inputsize_msg`, `invalidsize_msg`, and `input_msg` are used to guide the user.

### 2. **Text Section**
Contains the main logic:
- **Main Function**: Handles input, validation, and initiates the merge sort process.
- **Merge Sort Function**: Divides the array into halves recursively and merges them in sorted order.
- **Auxiliary Logic**: Ensures smooth handling of edge cases, stack adjustments, and clean printing of results.

---

## **How to Use**
### **Input Requirements**
- The program prompts the user to:
  1. Enter the size of the array (between 1 and 20).
  2. Input integers to populate the array.

### **Execution**
1. Assemble and run the program using any MIPS simulator like **SPIM** or **MARS**.
2. Follow the prompts on the console.
3. The sorted array will be displayed as output.

---

## **Core Functions**
### **Main**
- Handles user interaction.
- Validates inputs for size and elements.
- Calls the `mergesort` function to sort the array.

### **Merge Sort**
- **Divide**: Splits the array into two halves.
- **Conquer**: Sorts each half recursively.
- **Merge**: Combines sorted halves back into the original array.

### **Print**
- Traverses the sorted array and prints each element in a formatted manner.

---
