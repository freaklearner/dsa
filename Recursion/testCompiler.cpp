#include <iostream>
#include <bitset>

using namespace std;

void decimalToBinary(int decimal, int n) {
    bitset<32> binary(decimal);  // Assuming 32-bit binary representation
    cout << "Binary representation: " << binary.to_string().substr(32-n) << std::endl;
}

int main()
{
    int decimal = 0;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    decimalToBinary(decimal,8);
    cin.get();
    return 0;
    
}