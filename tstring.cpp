
int tstring::stroint(const string a){
	int	n=a.length();
	int fint = 0;
	for(int q=0; q<n; q++){
		int temp=a[n-q-1] - 48;
		fint = fint + temp  * pow(10,q);
	}
	return fint;
}

int tstring::stec(int i){
	// zerototwelve; // +33
	// thirteen; // 47
	// fourteentoeightytwo; // +44
	// eightythreetotwoten; // +45

	if(0<=i and i<=12) return i+33;
	else if(i==13) return 47;
	else if(14<=i and i<=82) return i+44;
	else if(83<=i and i<=210) return i+45;
	else return 0;
	
}

int tstring::revstec(int i){

    if(33<=i and i<=45) return i-33;
	else if(i==47) return 13;
	else if(58<=i and i<=126) return i-44;
	else if(128<=i and i<=255) return i-45;
	else return 0;
}

void tstring::read(){
    
    string temp;
    do{
    	getline(cin,temp);
	    
	    if(temp.length() > 0){
	    	if(str.length()!=0)	str.append(" ");
	    	str.append(temp);
	    }

    }while(temp.length() > 0);

}

void tstring::readTxtFile(){
    
    string temp,direc;

    cout << "Name of the file: " ;
    cin >> direc;
    dir = new char[direc.length()+1];
   	for(unsigned int i =0 ;i<direc.length()+1;i++){
       dir[i] = direc[i];
    }

    ifstream in(dir);

    do{
	    getline(in,temp);
	    if(temp.length() > 0){
		    str.append(" ");
		    str.append(temp);
    	}
    }while(temp.length() > 0);
    ncharinp = str.length();

}

void tstring::wordProcess(){
	ifstream in(dir);

	wordcount=0; // finds the number of words
	
	size_t i=0,b = str.length();
	while(i<b){

		if (str[i] == ' ') wordcount++;
		i++;
		if(i==b) { break; }

	}

	dotcount=0; i = 0; // finds no of dots
	while(i<b){
		
		if (str[i] == '.' and (str[i+1]==' ' or str[i+1] == '\0')) dotcount++;
		i++;
		if(i==b) { break; }
		
	}

	count = wordcount + dotcount;
	
	wptr = new Word[wordcount+dotcount]; // creates words


	string buffer;
	
	for(int i = 0; i < count ; i++){
		in >> buffer; int  bl = buffer.length();
		if(buffer[bl - 1] == '.'){
			buffer.erase(bl-1,1);
			wptr[i].substring = buffer;


			wptr[i+1].substring = '.';
			i++;

		}
		else wptr[i].substring = buffer;

	}
		
}

void tstring::distWord(){
	dcount = 0;
	for(int i = 0;i< count ; i++){
		bool b = true;
		for(int j =0;j< i ; j++){

			if(wptr[j].substring == wptr[i].substring){ b = false; break; }
		}
		if(b) dcount ++;
	}

	dptr = new dword[dcount]; int k = 0;
	for(int i = 0;i< count ; i++){
		bool repfound=false;
		for(int j =0;j< i ; j++){
			if(wptr[j].substring == wptr[i].substring){ repfound=true; wptr[i].ptr = wptr[j].ptr; 	}
		}

		if(!repfound){
			dptr[k].substring = wptr[i].substring;
			wptr[i].ptr = &(dptr[k]);
			k++;
		}
	}
	
	for(int i = 0;i < count;i++){
		for (int j = 0; j < i ; j++){
			if(wptr[i].substring == wptr[j].substring){
				(wptr[i].ptr)->frequency++;
				break;
 			}
		}
	}

}

void tstring::codeassign(){

    assignedcodes = 0;
	dptrb = new dword[dcount];
	for(int i=0; i < dcount; i++){
		dptrb[i].frequency = dptr[i].frequency  ;
	}

	while(assignedcodes<dcount){
		int maxsofar=0, index=0;

        /* probably better code
		int maxsofarn=0;
		for(int i=0; i<dcount ; i++){
		maxsofarn=max( maxsofar, dptrb[i].frequency );
		if( maxsofarn == dptrb[i].frequency and maxsofar!=dptrb[i].frequency ) index=i;
		maxsofarn=maxsofar;
		} */
        
        //alternate code
		for(int i=0; i<dcount ; i++){
			maxsofar=max( maxsofar, dptrb[i].frequency );
		}

		for(int i=0; i<dcount ; i++){
			if(maxsofar == dptrb[i].frequency) { index = i; break; }
		}

		dptrb[index].stecode = assignedcodes;
		dptrb[index].frequency = 0;
		assignedcodes++;

	}

	for(int i=0; i<dcount; i++){ // copying stecode into the main array
        dptr[i].stecode = dptrb[i].stecode;
	}

}

void tstring::compress(){
    
    readTxtFile();
	wordProcess();
	distWord();
	codeassign();
	
    cout << "Name of the compressed file to be created: ";
    string direc;
    cin >> direc;
   	direc = direc + ".stec";
    dir = new char[direc.length()+1];
    for(size_t i =0 ;i<direc.length()+1;i++){
        dir[i] = direc[i];
    }

    ofstream out(dir);
    for(int i = 0;i < dcount;i++){
        out << dptr[i].substring;
        if(i < dcount -1){
            if(dptr[i].stecode <= 210){
                char c = stec(dptr[i].stecode);
                out << " " << c <<" ";
            } else {
                out << " " << dptr[i].stecode - 211 << " ";
            }
        }
        else {if(dptr[i].stecode <= 210){
                char c = stec(dptr[i].stecode);
                out << " " << c <<" ";
            } else {
                out << " " << dptr[i].stecode - 211 << " ";
            }
        }
    }

    out << endl;
    for(int i = 0; i < count;i++){
        if((wptr[i].ptr)->stecode <= 210){
            char c = stec((wptr[i].ptr)->stecode);
            out << c;
        }
        else {
            if(i <count -1){
                if((wptr[i + 1].ptr)->stecode - 211 < 0){
                    out << " " << ((wptr[i].ptr)->stecode - 211) << " ";
                } else {
                    out << " " << ((wptr[i].ptr)->stecode - 211);
                }
            }
            else out << " " << ((wptr[i].ptr)->stecode - 211);
        }
    }
    //input the name the compressed file

    ifstream com(dir);
    string temp;
    do{
    	
	    getline(com,temp);
	    if(temp.length() > 0){
		    str.append(" ");
		    str.append(temp);
    	}
    }while(temp.length() > 0);
    ncharout = str.length();
    
}

void tstring::decompress(){

    dcount = 0;
    string temp,direc;

    cout << "Name of the file to be decompressed: ";
    cin >> direc;

    char * dir;
    dir = new char[direc.length()+1];
    for(size_t i =0 ;i<direc.length()+1;i++){
        dir[i] = direc[i];
    }
    ifstream in1(dir);
    string tem;
    getline(in1,tem);
    for(int i = 0;tem[i] != '\0';i++){
        if(tem[i] == ' ') dcount++;
    }
    dcount = (dcount/2);

    dptr = new dword[dcount];
    ifstream in2(dir);
    for(int i = 0; i < dcount ; i++){
	    in2 >> dptr[i].substring;

	    in2 >> tem;
	    if(tem[0]>57 or tem[0] <48){
	        char c = tem[0];
	        int x = c;
	        if(x < 0){ x += 256;}
	        
	        dptr[i].stecode = revstec(x);
	    }
	    else {
	    	dptr[i].stecode = stroint(tem) + 211;
	    }

    }
    
    ifstream in3(dir);
    getline(in3,tem);
    getline(in3,tem);


    int nos = 1;
    for(int i = 0;tem[i] != '\0';i++){
        if(tem[i] == ' ') nos++;
    }
    
    ifstream in4(dir);
    getline(in4,tem);

    count = 0;
    for(int i = 0;i < nos;i++){
    	int ind;
    	in4 >> tem;
    	ind = tem[0];
    	if (ind>=48 and ind <=57){
    		count++;
    	}else count+= tem.length();
    }
    
    wptr = new Word[count];
    
    int wi = 0;
    ifstream in5(dir);
    getline(in5,tem);
    for(int i = 0;i < nos;i++){
    	int ind;

    	in5 >> tem; ;ind = tem[0];
    	if (ind >= 48 and ind <= 57){
    		wptr[wi].stecode = stroint(tem) + 211; wi++;
    	}else {
    		for(size_t i = 0 ; i < tem.length();i++){
    			int x = tem[i];
    			if(x < 0) { x += 256;}

    			wptr[wi].stecode = revstec(x); wi++;
    		}
    	}

    }
      
    for(int i = 0;i < count;i++){
    	for(int j = 0;j < dcount;j++){

    		if(wptr[i].stecode == (dptr[j].stecode) ){
    			wptr[i].ptr = &(dptr[j]);
    			
    		}
    	}
    }
    
   	//input the name of the decompressed output file
    cout << "Enter the name of the decompressed file to created: ";
   	cin >> direc;
   
    dir = new char[direc.length()+1];
    for(size_t i =0 ;i<direc.length()+1;i++){
        dir[i] = direc[i];
    }

    ofstream out(dir);
   	for(int i = 0;i<count;i++){
	   	if(i < count - 1){
	   		if((wptr[i + 1].ptr)->substring == "."){
	   			
	   			out << (wptr[i].ptr)->substring;
	   		}else {
	   			out << (wptr[i].ptr)->substring << " ";
	   		}
	   	}
	   	else out << (wptr[i].ptr)->substring;
   	}

}

tstring::~tstring(){
	//delete[] dir;
	//delete[] wptr;
	//delete[] dptr;
	//delete[] dptrb;
	cout << "Process Complete." << endl;
}
void tstring::analyse(){
	readTxtFile();
	wordProcess();
	distWord();
	codeassign();
	

    ofstream out("temp");
    for(int i = 0;i < dcount;i++){
        out << dptr[i].substring;
        if(i < dcount -1){
            if(dptr[i].stecode <= 210){
                char c = stec(dptr[i].stecode);
                out << " " << c <<" ";
            } else {
                out << " " << dptr[i].stecode - 211 << " ";
            }
        }
        else {if(dptr[i].stecode <= 210){
                char c = stec(dptr[i].stecode);
                out << " " << c <<" ";
            } else {
                out << " " << dptr[i].stecode - 211 << " ";
            }
        }
    }

    out << endl;
    for(int i = 0; i < count;i++){
        if((wptr[i].ptr)->stecode <= 210){
            char c = stec((wptr[i].ptr)->stecode);
            out << c;
        }
        else {
            if(i <count -1){
                if((wptr[i + 1].ptr)->stecode - 211 < 0){
                    out << " " << ((wptr[i].ptr)->stecode - 211) << " ";
                } else {
                    out << " " << ((wptr[i].ptr)->stecode - 211);
                }
            }
            else out << " " << ((wptr[i].ptr)->stecode - 211);
        }
    }
    //input the name the compressed file

    ifstream com("temp");
    string temp;
    do{
    	
	    getline(com,temp);
	    if(temp.length() > 0){
		    str.append(" ");
		    str.append(temp);
    	}
    }while(temp.length() > 0);
    ncharout = str.length();

    cout << "No of characters in the file: " << ncharinp << endl;
    cout << "No of characters if compressed: " << ncharout << endl;
    cout << "The above result may not be significant if the file doesnt have repeated words." << endl;
    cout << "Click on the Canvas to continue." << endl;
    getClick();
    remove("temp");
}
