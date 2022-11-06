#include "CSVTable.h";

CSVTable::CSVTable(uint64_t _rows, uint64_t _cols) {
    this->rows = _rows;
    this->cols = _cols;
    this->path = "null";
}

CSVTable::CSVTable(std::string path) {
    (this->path) = path;
    readCSV(path);
}

void CSVTable::readCSV(std::string path) {
    std::string tempData;
    std::string _data = "";
    int i = 0;
    uint64_t _cols = 0;
    uint64_t _rows = 0;
    std::ifstream fin;

    fin.open(path);
    if (fin.is_open()) {
        std::cout << "the file is successfully opened" << std::endl;
        while (std::getline(fin, tempData)) {
            ++_rows;
            _data.append(tempData);
            _data.append("\n");
        }
        fin.close();
    }
    else {
        std::cout << "error" << std::endl;
    }
    while (_data[i] != '\n') {
        if (_data[i] == ',') {
            ++_cols;
        }
        ++i;
    }
    _cols += 1;
    (this->rows) = _rows;
    (this->cols) = _cols;
    (this->data) = _data;
    (this->quantityOfSymbols) = _data.size();
}

void CSVTable::getTable() {
    uint64_t counter = 0;
    (this->table).resize(this->rows);
    for (uint64_t i = 0; i < rows; i++) {
        (this->table)[i].resize(this->cols);
    }
    for (uint64_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            while ((this->data)[counter] != ',' && (this->data)[counter] != '\n') {
                (this->table)[i][j].push_back((this->data)[counter]);
                counter++;
            }
            counter++;
        }
    }
}

void CSVTable::outputTable(char _horSep, int _horTabs, char _vertSep, int _vertTabs) {
    std::string horTabsStr = std::string(_horTabs, _horSep);
    std::string vertTabsStr = std::string(_vertTabs, _vertSep);
    std::cout << "Table____________________" << std::endl;
    for (int i = 0; i < (this->quantityOfSymbols); i++) {
        if ((this->data)[i] == ',') {
            std::cout << horTabsStr;
        }
        else if ((this->data)[i] == '\n') {
            std::cout << vertTabsStr;
        }
        else {
            std::cout << (this->data)[i];
        }
    }
}

void CSVTable::printMatrix() {
    uint64_t max = 0;
    uint64_t counter = 0;
    uint64_t size = 0;
    std::string s = "";
    std::vector<std::vector<std::string> > tTable = (this->table);
    std::vector<int> sizes(this->cols);
    for (uint64_t i = 0; i < (this->cols); i++) {
        for (uint64_t j = 0; j < (this->rows); j++) {
            if (tTable[j][i].size() > max) {
                max = tTable[j][i].size();
            }
        }
        sizes[i] = max;
        max = 0;
    }
    for (uint64_t i = 0; i < (this->cols); i++) {
        for (uint64_t j = 0; j < (this->rows); j++) {
            tTable[j][i].resize(sizes[i], ' ');
        }
        size += sizes[i];
    }
    s.resize(size + 3 * (this->cols), '-');
    std::cout << '\n';
    std::cout << '\t' << s << '\n';
    for (uint64_t i = 0; i < (this->rows); i++) {
        std::cout << '\t' << "|";
        for (uint64_t j = 0; j < (this->cols); j++) {
            std::cout << tTable[i][j] << " | ";
        }
        std::cout << "\n";
        std::cout << '\t' << s;
        std::cout << "\n";
    }
}