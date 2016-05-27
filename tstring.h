
struct dword{
	string substring;
	int frequency = 1;
	int stecode;

};

struct Word{

	string substring;
	int stecode;
	dword * ptr;

};

class tstring{
	char * dir;
	string str;
	Word* wptr;
	dword * dptr; dword * dptrb;
	int wordcount, dotcount, count, dcount, assignedcodes;   
	bool huffman;
	int n,ncharinp,ncharout;

public:
	
	~tstring();
    void read(); // input through terminal
	void readTxtFile(); // input from text file
	int length(); // length of the string
	void wordProcess(); // searches the string for a word and creates words & dots array
	void distWord();
	void freqAssign(); // assigns frequency // creates parallel array of frequencies // optional ; can be enabled later
	void isequalto(tstring p);
	void codeassign(); // assigns lowest code to most frequent word
	void encode();
	void decode();
	void compress(); // creates text file or prints out text // #*#*# First Call This #*#*#
	void decompress(); // reverses all these processes
	int stec(int i);
	int revstec(int i);
	int stroint(string a);
	void analyse();
};






