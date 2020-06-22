#include<iostram>
using namespace std;
class Reader{
    public : virtual int read() = 0;
}
class KeyboardReader : public Reader{
    public : virtual int read(){
        return RdKbd();
    }
}
class PunchTapeReader : public Reader{
    public : virtual int read(){
        return RdPt();
    }
}
class Writer{
    public : virtual void Write(int c) = 0;
}
class PrinterWriter : public Writer{
    public : virtual void Write(int c){
        WrtPrt(c);
    }
}
class PunchTapeWriter : public Writer{
    public : virtual void Write(int c){
        WrtPt(c);
    }
}
KeyboardReader GdefaultReader;
PrinterWriter GdefaultWriter;
void Copy(Reader & reader = GdefaultReader, Writer & writer){
    int c;
    while ((c = reader.read() != EOF))
        writer.write(c);
}

