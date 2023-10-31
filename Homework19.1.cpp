// Homework19.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogFile : public LogCommand {
private:
    std::ofstream file_;
public:
    explicit LogFile(){
        file_.open("logfile.txt");
    }
    ~LogFile() {
        file_.close();
    }
    void print(const std::string& message) {
            file_ << message << std::endl;
    }
};

class LogConsole : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << std::endl << "Log message: " << message << std::endl;
    }
};

void print(LogCommand& cmd) {
    std::string message = "Some message!";
    cmd.print(message);
}

int main()
{
    LogFile loggingf;
    LogConsole loggingc;
    print(loggingf);
    print(loggingc);
}