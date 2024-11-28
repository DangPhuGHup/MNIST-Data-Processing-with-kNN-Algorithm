# MNIST Data Processing and kNN Algorithm Implementation

## Project Overview
This project implements the **k-Nearest Neighbors (kNN)** algorithm to classify handwritten digit images from the **MNIST dataset**, using **C++** and custom-built list data structures.

The **kNN algorithm** is a fundamental and effective classification method that predicts labels for new data points based on the labels of **k nearest neighbors**. This project includes:
- Processing and analyzing the MNIST dataset.
- Using custom list structures to manage and manipulate data efficiently.
- Building a kNN model with training, prediction, and accuracy evaluation capabilities.

---

## Key Features
1. **MNIST Data Processing**:
   - Load data from CSV files.
   - View the first/last few rows and extract subsets of data.
2. **kNN Algorithm Implementation**:
   - Train the model on training data.
   - Predict labels for test data.
   - Evaluate the accuracy of predictions.
3. **Custom List Data Structure**:
   - Built from scratch with basic operations like insert, delete, traverse, and reverse.
4. **Command-Line Interface**:
   - Users can interact with and test functions directly from the terminal.

---

## System Requirements
- **Operating System**: Linux/UNIX or Windows (preferably with WSL or MinGW).
- **Compiler**: g++ with C++11 support.
- **Dataset**: The provided `mnist.csv` file.

---

## **How to Use**
### **Data Processing**
  1. Load MNIST Data from File: Use the loadFromCSV function to load data from mnist.csv
  2. Preview Data: Use printHead or printTail to display the first or last few rows of the dataset.


### **Training and Prediction**
1. Training: Call the fit function from the kNN class to load training data (X_train and y_train).
2. Prediction: Use predict with test data (X_test) to predict labels.
3. Evaluation: The score function calculates the model's accuracy based on true labels and predictions.

---

## **Use the following command to compile**
1. g++ -o main main.cpp kNN.cpp -I . -std=c++11
2. ./main
 
---