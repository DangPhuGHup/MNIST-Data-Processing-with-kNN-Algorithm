#include "kNN.hpp"
// g++ -o main main.cpp kNN.cpp -I . -std=c++11 -DDEBUG
void tc_knn_score(int k, int size_X){
int nRows, nCols;
Dataset dataset;
dataset.loadFromCSV("mnist.csv");

kNN knn = kNN(k);
Dataset X_train, X_test, y_train, y_test;
Dataset feature = dataset.extract(0, size_X, 1, -1);
Dataset label = dataset.extract(0, size_X, 0, 0);

train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
knn.fit(X_train, y_train);
Dataset y_pred = knn.predict(X_test);
double accuracy = knn.score(y_test, y_pred);
cout << "Accuracy: " << accuracy << endl;
}



int main() {
    tc_knn_score(10, 100);
    return 0;
}