#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

/*
	Fill in the following program according to the comments.

	As you add your functionality, remove the print statements, and
	comment out the "incomplete" increment.

	If your program does not have a certain functionality implemented
	leave the print statement instead.

	Also leave the print statement if your implementation is incomplete
	or causes a segfault with your code.
*/

int main()
{
	int fi = 0;

	//--------- FILE IO ----------------------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"FILE IO FUNCTIONS"<<endl;

	//read in file Brady.txt to create a story
	// cout<<"Reading file for story not implemented"<<endl;
	// ++fi;
    Story story = Story("./STORIES/Brady.txt");

	//save story
	// cout<<"Save story not implemented"<<endl;
	// ++fi;
    story.save("garbage.txt");

	//print out story
	// cout<<"<< for story not implemented"<<endl;
	// ++fi;
    cout << story << endl;

	cout<<endl<<"----------------------------------------------"<<endl;

	//--------- FIRST FUNCTIONS --------------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"FIRST FUNCTIONS"<<endl;

	//get paragraph using story.first()
	// cout<<"story.first() not implemented"<<endl;
	// ++fi;
    Paragraph para = story.first();

	//print out paragraph
	// cout<<"<<for para not implemented"<<endl;
	// ++fi;
    cout << para << endl;

	//get sentence using para.first()
	// cout<<"para.first() not implemented"<<endl;
	// ++fi;
    Sentence sen = para.first();

	//print out sentence
	// cout<<"<<for sentence not implemented"<<endl;
	// ++fi;
    cout << sen << endl;

	//get word using sentence.first()
	// cout<<"sentence.first() not implemented"<<endl;
	// ++fi;
    Word word = sen.first();

	//print out word
	// cout<<"<< for word not implemented"<<endl;
	// ++fi;
    cout << word << endl;

	cout<<endl<<"----------------------------------------------"<<endl;

	//---------- OPERATORS IN FORM A + B --------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"A+B OPERATORS"<<endl;

	//For this and the following sections either use the above
	//created word/sent/para/story
	//or instantiate them using some other constructor
	//After using each operator, print out the result

	//story + story = story
	// cout<<"story + story = story not implemented"<<endl;
	// ++fi;
    cout << story + story << endl;

	//story + para = story
	// cout<<"story + para = story not implemented"<<endl;
	// ++fi;
    cout << story + para << endl;

	//para + story = story
	// cout<<"para + story = story not implemented"<<endl;
	// ++fi;
    cout << para + story << endl;

	//para + para = para
	// cout<<"para + para = para not implemented"<<endl;
	// ++fi;
    cout << para + para << endl;

	//para + sentence = para
	// cout<<"para + sent = para not implemented"<<endl;
	// ++fi;
    cout << para + sen << endl;

	//sent + para = para
	// cout<<"sent + para = para not implemented"<<endl;
	// ++fi;
    cout << sen + para << endl;

	//sent + sent = para
	// cout<<"sent + sent = para not implemented"<<endl;
	// ++fi;
    cout << sen + sen << endl;

	//sent + word = sent
	// cout<<"sent + word = sent not implemented"<<endl;
	// ++fi;
    cout << sen + word << endl;

	//word + sent = sent
	// cout<<"word + sent = sent not implemented"<<endl;
	// ++fi;
    cout << word + sen << endl;

	//word + word = sent
	// cout<<"word + word = sent not implemented"<<endl;
	// ++fi;
    cout << word + word << endl;

	cout<<endl<<"----------------------------------------------"<<endl;

	//---------- OPERATORS IN FORM A++ and A-- --------------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"A++ AND A-- OPERATORS"<<endl;

	//word++
	// cout<<"word in caps not implemented"<<endl;
	// ++fi;
    cout << word++ << endl;

	//word--
	// cout<<"word in lower not implemented"<<endl;
	// ++fi;
    cout << word-- << endl;

	//sent++
	// cout<<"sent in caps not implemented"<<endl;
	// ++fi;
    cout << sen++ << endl;

	//sent--
	// cout<<"sent in lower not implemented"<<endl;
	// ++fi;
    cout << sen-- << endl;

	//para++
	// cout<<"para in caps not implemented"<<endl;
	// ++fi;
    cout << para++ << endl;

	//para--
	// cout<<"para in lower not implemented"<<endl;
	// ++fi;
    cout << para-- << endl;

	//story++
	// cout<<"story in caps not implemented"<<endl;
	// ++fi;
    cout << story++ << endl;

	//story--
	// cout<<"story in lower not implemented"<<endl;
	// ++fi;
    cout << story-- << endl;

	cout<<endl<<"----------------------------------------------"<<endl;

	//---------- OPERATORS IN FORM A+1----------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"A+1 OPERATORS"<<endl;

	//word+1
	// cout<<"word + 1 not implemented"<<endl;
	// ++fi;
    cout << word + 1 << endl;

	//sent+1
	// cout<<"sent + 1 not implemented"<<endl;
	// ++fi;
    cout << sen + 1 << endl;

	//para+1
	// cout<<"para + 1 not implemented"<<endl;
	// ++fi;
    cout << para + 1 << endl;

	//story+1
	// cout<<"story + 1 not implemented"<<endl;
	// ++fi;
    cout << story + 1 << endl;

	cout<<endl<<"----------------------------------------------"<<endl;

	//----------- PIG LATIN OPERATORS -----------

	cout<<endl<<"----------------------------------------------"<<endl;
    cout<<"PIG LATIN OPERATORS"<<endl;
    Word w1 = Word("correct");
    Word w2 = Word("horse");
    Word w3 = Word("battery");
    Sentence s1 = (w1 + w2);
    Paragraph p1 = (w1 + w2) + w3;
    Paragraph p2 = (w3 + w2) + w1;
    Story st1 = Story(p1);

    //word pig latin
	// cout<<"word in pig latin not implemented"<<endl;
	// ++fi;
    cout << ++w1 << endl;

	//word unpig latin
	// cout<<"word pig latin undone not implemented"<<endl;
	// ++fi;
    cout << --w1 << endl;

	//sent pig latin
	// cout<<"sent pig latin not implemented"<<endl;
	// ++fi;
    cout << ++s1 << endl;

	//sent unpig latin
	// cout<<"sent pig latin undone not implemented"<<endl;
	// ++fi;
    cout << --s1 << endl;

	//para pig latin
	// cout<<"para pig latin not implemented"<<endl;
	// ++fi;
    cout << ++p1 << endl;

	//para unpig latin
	// cout<<"para pig latin undone not implemented"<<endl;
	// ++fi;
    cout << --p1 << endl;

	//story pig latin
	// cout<<"story pig latin not implemented"<<endl;
	// ++fi;
    cout << ++st1 << endl;

	//story unpig latin
	// cout<<"story pig latin undone not implemented"<<endl;
	// ++fi;
    cout << --st1 << endl;

	cout<<endl<<"----------------------------------------------"<<endl;

	cout<<endl<<"TOTAL INCOMPLETE: "<<fi<<endl;
	return 0;
}

