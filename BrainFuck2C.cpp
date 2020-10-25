#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
const string REPLACE_STRING="$$$BRAINFUCK2C_CONTENT$$$";
string getFileContent(char* filePath) {
	ifstream fin(filePath);
	ostringstream buf;
	char ch;
	while(buf&&fin.get(ch))buf.put(ch);
	return buf.str();
}
void putFileContent(const string& content, char* filePath) {
	ofstream fout(filePath);
	fout<<content;
	fout.close();
}
string processBrainFuckCode(const string& bfCodeContent) {
	stringstream CCodeBuffer;
	for(int i=0; i<bfCodeContent.size(); i++) {
		char INST = bfCodeContent[i];
		switch(INST) {
			case '>':
				CCodeBuffer << "++BP;\n";
				break;
			case '<':
				CCodeBuffer << "--BP;\n";
				break;
			case '+':
				CCodeBuffer << "++*BP;\n";
				break;
			case '-':
				CCodeBuffer << "--*BP;\n";
				break;
			case '.':
				CCodeBuffer << "OUTPUT();\n";
				break;
			case ',':
				CCodeBuffer << "INPUT();\n";
				break;
			case '[':
				CCodeBuffer << "while(*BP){\n";
				break;
			case ']':
				CCodeBuffer << "}\n";
				break;
		}
	}
	return CCodeBuffer.str();
}
int main(int argc,char* argv[]) {
	if(argc!=3) {
		printf("Brainfuck2C [input.bf] [output.c]\n");
		return 0;
	}
	string bfCodeContent = getFileContent(argv[1]);
	string BrainFuck2CCode = processBrainFuckCode(bfCodeContent);
	string templateCode = getFileContent("template.c");
	templateCode.replace(templateCode.find(REPLACE_STRING),REPLACE_STRING.length(),BrainFuck2CCode);
	putFileContent(templateCode,argv[2]);
	return 0;
}