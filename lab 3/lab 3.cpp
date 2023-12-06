/*#include <iostream>
#include <string>

class Rectangle {
private:
    double height;
    double width;
    std::string color;

public:
   
    Rectangle() : height(0.0), width(0.0), color("white") {}

    Rectangle(double initHeight, double initWidth, const std::string& initColor)
        : height(initHeight), width(initWidth), color(initColor) {}

    
    double calculateArea() const {
        return height * width;
    }

    double calculatePerimeter() const {
        return 2 * (height + width);
    }

    
    void setHeight(double newHeight) {
        if (newHeight > 0) {
            height = newHeight;
        }
        else {
            std::cerr << "Error: Height must be greater than 0." << std::endl;
        }
    }

    void setWidth(double newWidth) {
        if (newWidth > 0) {
            width = newWidth;
        }
        else {
            std::cerr << "Error: Width must be greater than 0." << std::endl;
        }
    }

    void setColor(const std::string& newColor) {
        color = newColor;
    }

   
    double getHeight() const {
        return height;
    }

    double getWidth() const {
        return width;
    }

    const std::string& getColor() const {
        return color;
    }

 
    void print() const {
        std::cout << "Rectangle Information:" << std::endl;
        std::cout << "  Height: " << height << std::endl;
        std::cout << "  Width: " << width << std::endl;
        std::cout << "  Color: " << color << std::endl;
        std::cout << "  Area: " << calculateArea() << std::endl;
        std::cout << "  Perimeter: " << calculatePerimeter() << std::endl;
    }
};

int main() {

    Rectangle rect1; 
    rect1.print();

    Rectangle rect2(4.5, 6.7, "blue"); 
    rect2.print();


    rect1.setHeight(3.0);
    rect1.setWidth(5.0);
    rect1.setColor("green");

    std::cout << "\nUpdated Rectangle 1:" << std::endl;
    rect1.print();


    std::cout << "\nHeight of Rectangle 2: " << rect2.getHeight() << std::endl;
    std::cout << "Width of Rectangle 2: " << rect2.getWidth() << std::endl;
    std::cout << "Color of Rectangle 2: " << rect2.getColor() << std::endl;

    return 0;
}*/

/*#include <iostream>

class Vector {
private:
    double* elements;
    int size;
    bool isInitialized;

public:

    Vector() : size(1), isInitialized(false) {
        elements = new double[size];
        elements[0] = 0.0;
        isInitialized = true;
    }

    Vector(int newSize) : size(newSize), isInitialized(false) {
        elements = new double[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = 0.0;
        }
        isInitialized = true;
    }

    Vector(int newSize, double initValue) : size(newSize), isInitialized(true) {
        elements = new double[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = initValue;
        }
    }

    Vector(const Vector& other) : size(other.size), isInitialized(other.isInitialized) {
        elements = new double[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }


    ~Vector() {
        delete[] elements;
    }


    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new double[size];
            for (int i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
            isInitialized = true;
        }
        return *this;
    }

    void setElement(int index, double value = 0.0) {
        if (index >= 0 && index < size) {
            elements[index] = value;
        }
        else {
            std::cout << "Index out of bounds." << std::endl;
        }
    }

    double getElement(int index) const {
        if (index >= 0 && index < size) {
            return elements[index];
        }
        else {
            std::cout << "Index out of bounds." << std::endl;
            return 0.0;
        }
    }


    void print() const {
        std::cout << "Vector: ";
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }


    Vector add(const Vector& other) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }


    Vector subtract(const Vector& other) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }


    Vector multiply(double scalar) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }


    Vector divide(double scalar) const {
        if (scalar != 0) {
            Vector result(size);
            for (int i = 0; i < size; ++i) {
                result.elements[i] = elements[i] / scalar;
            }
            return result;
        }
        else {
            std::cerr << "Division by zero. Returning a zero vector." << std::endl;
            return Vector(size);
        }
    }
    
    bool operator>(const Vector& other) const{
        for (int i = 0; i < size; ++i) {
            if (elements[i] <= other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator<(const Vector& other) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] >= other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const Vector& other) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }



};

int main() {
    Vector v1(3, 2.0);
    Vector v2(3, 3.0);

    Vector sum = v1.add(v2);
    Vector diff = v1.subtract(v2);
    Vector product = v1.multiply(2.0);
    Vector quotient = v1.divide(2.0);

    std::cout << "Vector 1:" << std::endl;
    v1.print();
    std::cout << "Vector 2:" << std::endl;
    v2.print();

    std::cout << "Sum:" << std::endl;
    sum.print();
    std::cout << "Difference:" << std::endl;
    diff.print();
    std::cout << "Product:" << std::endl;
    product.print();
    std::cout << "Quotient:" << std::endl;
    quotient.print();


    std::cout << "Comparison Operators:" << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2) << std::endl;
    std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    return 0;
}*/

#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
private:
    double** elements;
    int rows;
    int cols;
    bool error;
    static int objectCount;

public:
    Matrix() : rows(4), cols(3), error(false) {
        allocateMemory();
        initializeMatrix(0.0);
        objectCount++;
    }

    Matrix(int n) : rows(n), cols(n), error(false) {
        allocateMemory();
        initializeMatrix(0.0);
        objectCount++;
    }

    Matrix(int n, int m, double value) : rows(n), cols(m), error(false) {
        allocateMemory();
        initializeMatrix(value);
        objectCount++;
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), error(other.error) {
        allocateMemory();
        copyMatrix(other.elements);
        objectCount++;
    }

    ~Matrix() {
        deallocateMemory();
        objectCount--;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocateMemory();
            rows = other.rows;
            cols = other.cols;
            error = other.error;
            allocateMemory();
            copyMatrix(other.elements);
        }
        return *this;
    }

    void setElement(int i, int j, double value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        }
        else {
            error = true;
        }
    }

    double getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return elements[i][j];
        }
        else {
            const_cast<Matrix*>(this)->error = true;
            return 0.0;
        }
    }

    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << elements[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    static int getObjectCount() {
        return objectCount;
    }

private:
    void allocateMemory() {
        elements = new double* [rows];
        for (int i = 0; i < rows; ++i) {
            elements[i] = new double[cols];
        }
    }

    void initializeMatrix(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                elements[i][j] = value;
            }
        }
    }

    void copyMatrix(double** otherElements) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                elements[i][j] = otherElements[i][j];
            }
        }
    }


    void deallocateMemory() {
        if (elements) {
            for (int i = 0; i < rows; ++i) {
                delete[] elements[i];
            }
            delete[] elements;
            elements = nullptr;
        }
    }
};

int Matrix::objectCount = 0;

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.setElement(i, j, getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.setElement(i, j, getElement(i, j) * scalar);
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (std::fabs(getElement(i, j) - other.getElement(i, j)) > 1e-9) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

int main() {
    Matrix matrix1;
    Matrix matrix2(3);
    Matrix matrix3(2, 4, 5.0);
    Matrix matrix4 = matrix1;
    Matrix matrix5;
    matrix5 = matrix3;

    std::cout << "Matrix 1:" << std::endl;
    matrix1.printMatrix();

    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.printMatrix();

    std::cout << "\nMatrix 3:" << std::endl;
    matrix3.printMatrix();

    std::cout << "\nMatrix 4 (copy of Matrix 1):" << std::endl;
    matrix4.printMatrix();

    std::cout << "\nMatrix 5 (assigned Matrix 3):" << std::endl;
    matrix5.printMatrix();

    matrix1.setElement(1, 1, 10.5);
    std::cout << "\nMatrix 1 after setting element (1,1) to 10.5:" << std::endl;
    matrix1.printMatrix();
    std::cout << "Value at (1,1): " << matrix1.getElement(1, 1) << std::endl;

    Matrix sumMatrix = matrix1 + matrix2;
    std::cout << "\nSum of Matrix 1 and Matrix 2:" << std::endl;
    sumMatrix.printMatrix();

    Matrix diffMatrix = matrix1 - matrix2;
    std::cout << "\nDifference of Matrix 1 and Matrix 2:" << std::endl;
    diffMatrix.printMatrix();

    Matrix scalarMultMatrix = matrix1 * 2.0;
    std::cout << "\nMatrix 1 multiplied by scalar (2.0):" << std::endl;
    scalarMultMatrix.printMatrix();

    if (matrix1 == matrix4) {
        std::cout << "\nMatrix 1 is equal to Matrix 4." << std::endl;
    }
    else {
        std::cout << "\nMatrix 1 is not equal to Matrix 4." << std::endl;
    }

    if (matrix2 != matrix3) {
        std::cout << "Matrix 2 is not equal to Matrix 3." << std::endl;
    }
    else {
        std::cout << "Matrix 2 is equal to Matrix 3." << std::endl;
    }

    std::cout << "\nNumber of Matrix objects created: " << Matrix::getObjectCount() << std::endl;

    return 0;
}