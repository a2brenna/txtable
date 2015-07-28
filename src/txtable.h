#ifndef __TXTABLE_H__
#define __TXTABLE_H__

#include <string>
#include <iostream>
#include <vector>
#include <iomanip> //for std::setw()

class Table {

    private:

        std::vector<std::string> _headings;
        std::vector<std::vector<std::string>> _rows;

    public:

        const std::vector<std::string> heading() const;
        const std::vector<std::vector<std::string>> rows() const;
        bool add_row(const std::vector<std::string> &new_row);
        Table(const std::vector<std::string> &headings);

};

std::ostream& operator<<(std::ostream& o, const Table &t);

#endif
