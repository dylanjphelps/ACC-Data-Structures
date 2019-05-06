//Code takes a value stored in memory and is able interpret it as both a float and an integer
union FloatValue
{
   int intView;
   float floatView;
};

//Function recieves a float and displays it's binary representation
void printFloat(float fnum){
    FloatValue num;
    num.floatView = fnum;
    unsigned int mask = 0x80000000;
    int space = 0;
    for(int count = (sizeof(int)*8)-1; count >= 0; count--){
        if ((space%4)==0){
            std::cout << " ";
        }
        if((num.intView & mask)!=0){
            std::cout << '1';
        } else{
            std::cout << '0';
        }
        mask = mask >> 1;
        space++;
    }
}

//Function recieves a character and displays it's binary representation
void printChar(char c){
    int ch = c;
    unsigned char mask = 0x80;
    int space = 0;
    for(int count = (sizeof(char)*8)-1; count >= 0; count--){
        if ((space%4)==0){
            std::cout << " ";
        }
        if((ch & mask)!=0){
            std::cout << '1';
        } else{
            std::cout << '0';
        }
        mask = mask >> 1;
        space++;
    }
}

//Function recieves a short and displays it's binary representation
void printShort(short s){

    unsigned short mask = 0x8000;
    int space = 0;
    for(int count = (sizeof(short)*8)-1; count >= 0; count--){
        if ((space%4)==0){
            std::cout << " ";
        }
        if((s & mask)!=0){
            std::cout << '1';
        } else{
            std::cout << '0';
        }
        mask = mask >> 1;
        space++;
    }
}
