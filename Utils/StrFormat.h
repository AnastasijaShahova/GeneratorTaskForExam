#ifndef UNTITLED5_STRFORMAT_H
#define UNTITLED5_STRFORMAT_H

#include <string>
#include <sstream>
#include <boost/format.hpp>
#include <algorithm>

class StrFormat {
private:
    std::string _message;
    boost::format _format;

public:
    StrFormat(const char *message):
    _message(message) {
        _format = boost::format(_message);
    }

    template <class T>
            StrFormat & operator % (T value) {
        try {
            _format % value;
        } catch (...) {
            unformat();
        }
        return *this;
    }

    template<class Ch2, class Tr2> friend
            std::basic_ostream<Ch2, Tr2> & operator << (
                    std::basic_ostream<Ch2, Tr2> &out, const StrFormat &obj) {
        std::stringstream tmp;
        try {
            tmp << obj.format();
        } catch (...) {
            std::string str;
            obj.unformat(str);
            tmp << str;
        }
        out << tmp.str();
        return out;
    }

    const boost::format & format() const {
        return _format;
    }

    void unformat() {
        _message.erase(std::remove(_message.begin(), _message.end(), '%'), _message.end());
        _format = boost::format("[BAD_STRING] %1%") % _message;
    }

    void unformat(std::string &result) const {
        result.assign(_message.begin(), _message.end());
        result.erase(std::remove(result.begin(), result.end(), '%'), result.end());
        result.insert(0, "[BAD_STRING] ");
    }

    std::string str() const {
        std::stringstream tmp;
        tmp << (*this);
        return tmp.str();
    }

};


#endif //UNTITLED5_STRFORMAT_H
