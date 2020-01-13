#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

fs::path inputFilePath;
bool directory = false;
fs::path outputFilePath;

enum class command {
	C_ARITHMETIC,
	C_PUSH, C_POP,
	C_LABEL, C_GOTO,
	C_IF,
	C_FUNCTION,
	C_RETURN,
	C_CALL
};

class parserModule {
private:
	bool hasMoreCommands = true;
	command commandType;
	string arg1;
	int arg2;
public:
	parserModule() {

	}

	void advance() {
		if (!hasMoreCommands) return;
	}

	bool getHasMoreCommands() {
		return hasMoreCommands;
	}

	string getArg1() {
		if (commandType == command::C_RETURN) return "-1";
		return arg1;
	}

	int getArg2() {
		if (commandType == command::C_PUSH || commandType == command::C_POP 
			|| commandType == command::C_FUNCTION || commandType == command::C_CALL) {

			return arg2;
		}
		else {
			return -1;
		}
	}

	command getCommandType() {
		return commandType;
	}
};

class codeWriter {
private:

public:
	codeWriter() {

	}

	void setFileName(string fileName) {

	}

	void writeArithmetic(string command) {

	}

	void writePushPop(command cmd, string segment, int index) {

	}

	void close() {

	}
};

int handleArguments(int argc, char* argv[]) {
	if (argc == 2) {
		inputFilePath = argv[1];
		int pos = inputFilePath.string().find(".vm", 1);
		if (pos != string::npos) {
			outputFilePath = inputFilePath.string().substr(0, pos) + ".asm";
		}
		else {
			int lastItem = inputFilePath.string().length() - 1;
			while (inputFilePath.string()[lastItem] == '/' || inputFilePath.string()[lastItem] == '\\') {
				inputFilePath = inputFilePath.string().substr(0, lastItem);
				lastItem = inputFilePath.string().length() - 1;
			}
			outputFilePath = inputFilePath.string() + ".asm";
			directory = true;
		}
	}
	else {
		return 1;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	if (handleArguments(argc, argv) == 1) {
		cerr << "Usage: hackVMTranslatorBasic.exe [inputFileName.vm] or hackVMTranslatorBasic.exe [inputFileDirectory]\noutput filename is inputFileName.asm or inputFileDirectory.asm";
		return 1;
	}
}