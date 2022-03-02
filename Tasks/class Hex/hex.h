#include <string>

class Hex {
    
private:
    unsigned char* hexSymbols;
    int num;
    
public:
    Hex();
    ~Hex();
    
    Hex& operator=(const Hex& elem);
    
    Hex operator+(const Hex& elem);
    Hex operator-(const Hex& elem);
    
    bool operator>(const Hex& elem);
    bool operator<(const Hex& elem);
    bool operator>=(const Hex& elem);
    bool operator<=(const Hex& elem);
    
    bool operator==(const Hex& elem);
    bool operator!=(const Hex& elem);
    
    Hex operator*(const Hex& elem);
    Hex operator/(const Hex& elem);
    
    friend std::ostream& operator << (std::ostream& out, const Hex& elem);
    friend std::istream& operator >> (std::istream& in, Hex& elem);
};
