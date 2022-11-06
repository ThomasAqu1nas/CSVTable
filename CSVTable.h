#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "windows.h"
class CSVTable {
    uint64_t rows;
    uint64_t cols;
    uint64_t quantityOfSymbols = data.size();
    std::string path;
    std::string data;
    std::vector<std::vector<std::string> > table;
public:
    CSVTable(uint64_t _rows, uint64_t _cols);
    CSVTable(std::string path);
    ~CSVTable() {
    }
    /*
            reading information from a file, determining the number of rows, columns, rows "data"
            and determining the total number of characters in a row
    */
    void readCSV(std::string path);
    void setRows(uint64_t _rows) { this->rows = _rows; }
    void setCols(uint64_t _cols) { this->cols = _cols; }
    void setData(std::string _data) { this->data = _data; }
    /*
            restructuring data from a string into a two-dimensional array
    */
    void getTable();
    /*
            output of the "data" string to the console
            1-st parameter: horizontal separator;
            2-nd parameter: number of horizontal separators;
            3-rd parameter: vertical separator;
            4-th parameter: number of vertical separators;
    */
    void outputTable(char _horSep, int _horTabs, char _vertSep, int _vertTabs);
    /*
        output table to the console
    */
    void printMatrix();
    uint64_t getRows() { return (this->rows); }
    uint64_t getCols() { return (this->cols); }
};
