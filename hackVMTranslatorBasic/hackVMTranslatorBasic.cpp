#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

fs::path inputFilePath;
bool directory = false;
fs::path outputFilePath;

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
	handleArguments(argc, argv);
}