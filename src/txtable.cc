#include "txtable.h"

const std::vector<std::string> Table::heading() const{
    return _headings;
}

const std::vector<std::vector<std::string>> Table::rows() const{
    return _rows;
}

void Table::add_row(const std::vector<std::string> &new_row){
    if(_headings.size() == new_row.size()){
        _rows.push_back(new_row);
    }
    else{
        throw Bad_Row();
    }
    return;
}

Table::Table(const std::vector<std::string> &headings){
    _headings = headings;
}

std::ostream& operator<<(std::ostream& o, const Table &t){

    std::vector<size_t> _column_widths;

    for(size_t i = 0; i < t.heading().size(); i++){
        size_t max_field_width = 0;

        const auto h_size = t.heading()[i].size();
        if(max_field_width < h_size){
            max_field_width = h_size;
        }

        for(const auto& r: t.rows()){
            const auto f_size = r[i].size();
            if(max_field_width < f_size){
                max_field_width = f_size;
            }
        }

        max_field_width++;
        _column_widths.push_back(max_field_width);
    }

    size_t total_width = t.heading().size() + 1;
    for(const auto &w: _column_widths){
        total_width += w;
    }

    for(size_t i = 0; i < total_width; i++){
        o << "-";
    }
    o << std::endl;

    o << "|";
    for(size_t i = 0; i < t.heading().size(); i++){
        o << std::setw(_column_widths[i]) << t.heading()[i];
        o << "|";

    }
    o << std::endl;

    for(const auto &r: t.rows()){

        for(size_t i = 0; i < total_width; i++){
            o << "-";
        }
        o << std::endl;

        o << "|";
        for(size_t i = 0; i < t.heading().size(); i++){
            o << std::setw(_column_widths[i]) << r[i];
            o << "|";
        }
        o << std::endl;

    }

    for(size_t i = 0; i < total_width; i++){
        o << "-";
    }
    o << std::endl;

    return o;
}
