#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include<unistd.h>
int points = 0, count = 0;
char mail[20], pass[20];
using namespace std;
class option
{
protected:
    string element, symbol, password, uses,dochoice;
    int atomic_number, x = 0,choice;
    float atomic_mass;
    char  bchoice;
public:
    void searchby()
    {
    	system("cls");
    	system("color 03");
        cout << "\n1) Search by element name\n";
        cout << "2) Search by atomic number\n";
        cout << "3) Search by symbol\n";
        cout << "4) Back\n\n";
        cout << "Enter the choice number: ";
        cin>>dochoice;
        try{
            choice= stoi(dochoice);
        }
        catch(exception e){
             choice = -1;
        }
        
    }
};

class periodic : public option
{
protected:
    string input_element, input_symbol,atomic;
    int input_atomic_number;

public:
    void search();
    void capital_small();
    void again();
};
void periodic::search()
{
	if (x != 1)
    	searchby();
    ifstream in("table.txt");
    int flag = 0;
    if (choice == 1)
    {
    	system("cls");
        cout << "\nEnter the Name of Element: ";
        cin >> input_element;
        capital_small();
        while (in >> element >> atomic_number >> atomic_mass >> symbol && getline(in, uses))
       	{
           	if (element == input_element)	
           	{
            	system("cls");
                cout << "\nName of element : " << element << "\n\n";
                cout << "Atomic number of " << element << " : " << atomic_number << "\n\n";
                cout << "Atomic mass of " << element << " : " << atomic_mass << "\n\n";
                cout << "Symbol of " << element << " : " << symbol << "\n\n";
                cout << "Charecterstics of " << element << " : " << uses << "\n\n\n\n";
                again();
                choice = 0;
                flag = 1;
                x = 0;
                break;
           	}
       	}
       	if (flag == 0)
       	{
       		cout<<"You have entered wrong name of element.";
			sleep(3);
			x = 1;
			search();	
		}
       		
    }
    else if (choice == 2)
    {
    	system("cls");
        cout << "\nEnter the Atomic Number of element: ";
        cin>>atomic ;
        try{
            input_atomic_number = stoi(atomic);
        }
        catch(exception e){
             input_atomic_number = -1;
        }
        while (in >> element >> atomic_number >> atomic_mass >> symbol && getline(in, uses))
       	{
       		if (atomic_number == input_atomic_number)
            {
            	system("cls");
                cout << "\nName of element : " << element << "\n\n";
                cout << "Atomic number of " << element << " : " << atomic_number << "\n\n";
                cout << "Atomic mass of " << element << " : " << atomic_mass << "\n\n";
                cout << "Symbol of " << element << " : " << symbol << "\n\n";
                cout << "Charecterstics of " << element << " : " << uses << "\n\n\n\n";
                again();
                choice = 0;
                flag = 1;
                x = 0;
                
                break;
            }
       	}
       	if (flag == 0)
       	{
       		cout<<"\nYou have entered wrong Atomic Number.";
			sleep(3);
			x = 1;
			search();	
		}
    }
    else if (choice == 3)
    {
    	system("cls");
        cout << "\nEnter the Symbol of Element: ";
        cin >> input_symbol;
        while (in >> element >> atomic_number >> atomic_mass >> symbol && getline(in, uses))
       	{
       		if (symbol == input_symbol)
            {
            	system("cls");
                cout << "\nName of element : " << element << "\n\n";
                cout << "Atomic number of " << element << " : " << atomic_number << "\n\n";
                cout << "Atomic mass of " << element << " : " << atomic_mass << "\n\n";
                cout << "Symbol of " << element << " : " << symbol << "\n\n";
                cout << "Charecterstics of " << element << " : " << uses << "\n\n\n\n";
                again();
                choice = 0;
                flag = 1;
                x = 0;
                break;
            }
       	}
       	if (flag == 0)
       	{
       		cout<<"\nYou have entered wrong Symbol.";
			sleep(3);
			x = 1;
			search();	
		}
    }
    else if (choice != 4)
    {
        cout << "\nYou have entered wrong choice.\nTry Again.\n\n";
        sleep(3);
        search();
    }
    in.close();
}
void periodic::again()
{
    cout << "Enter '1' Another search" << endl;
    cout << "Enter '2' Back" << endl;
    cout << "Enter your choice: ";
    cin >> bchoice;
    cout << "\n";
    if (bchoice == '1')
    {
    	x = 0;
    	search();
	}  
    else if (bchoice == '2')
    {
    	system("cls");
	}
    else if (bchoice != '2')
    {
    	system("cls");
        cout << "You have entered worong choice.\n" << endl;
        again();
    }
}
void periodic::capital_small()
{
    for (int i = 0; i < input_element.length(); i++)
    {
        if (input_element[i] >= 65 && input_element[i] <= 90)
        {
            int temp = (input_element[i] + 32);
            input_element[i] = char(temp);
        }
    }
    cout << "" << endl;
}
class data
{
public:
    char user_fname[20], user_lname[20], user_pass[20], user_email[20];
    int pcm_mock, physics_mocks, chemistry_mock, mathematics_mock;
};
class quiz : public data
{

protected:
    string question, ans, user_ans, option1, option2, option3, option4,temp;
    int max = 10, random_question, question_no, point = 0, full, sub_choice;

public:
    void sub_display();
};
void quiz::sub_display()
{
    cout << "Select subject for Quize from following list.\n\n";
    cout << "1) PCM Mock test" << endl;
    cout << "2) Physics" << endl;
    cout << "3) chemistry" << endl;
    cout << "4) Mathematics" << endl;
    cout << "5) Log out\n" << endl;
    cout << "Enter your choice number: ";
    cin >> temp;
    try
	{
       sub_choice = stoi(temp);
    }
    catch(exception e)
	{
        cout<<"You Entered wrong choice"<<endl; 
        sleep(3);
        system("cls");
        sub_display();
    }
    if (sub_choice == 1)
    {
        full = 1;
    }
    if(sub_choice < 1 || sub_choice > 5)
	{
        cout<<"You have entered wrong choice."<<endl;
        sleep(3);
        system("cls");
        sub_display();
    }
    
}
class start_quiez : public quiz
{
public:
    void set_sub();
    int random_question_generator();
    void full_test();
    void answer_check();
    void score_display();
    void capital_small(void);
    void update();
};
void start_quiez::update()
{
	sleep(3);
    system("cls");
    data d6;
    fstream fin;
    fin.open("login.txt", ios::binary | ios::in | ios::out);
    fin.seekg(0);
    while (fin.read((char *)&d6, sizeof(d6)))
    {
        if (!strcmp(d6.user_pass, pass) && !strcmp(d6.user_email, mail))
        {
        	
            cout << "Number of Mock Tests you have given: " << endl;
            cout << "PCM : "<< d6.pcm_mock << endl;     	
			cout << "Physics : " << d6.physics_mocks << endl;
			cout << "Chemistry : " << d6.chemistry_mock << endl;
			cout << "Mathematics : " << d6.mathematics_mock << endl;
			cout<<"\n\n\n";
            sub_display();
            if (sub_choice == 2)
                d6.physics_mocks++;
            else if (sub_choice == 3)
                d6.chemistry_mock++;
            else if (sub_choice == 4)
                d6.mathematics_mock++;
            else if (sub_choice == 1)
                d6.pcm_mock++;

            fin.seekp(-96, ios::cur);
            fin.write((char *)&d6, sizeof(d6));
            fin.close();
            if (sub_choice >= 1 && sub_choice < 5)
                set_sub();
            break;
        }
    }
}
int start_quiez::random_question_generator()
{
    if (sub_choice == 1)
        full_test();
    else if (sub_choice == 2)
    {
        srand(time(0));
        random_question = rand() % 30 + 1;
    }
    else if (sub_choice == 3)
    {
        srand(time(0));
        random_question = (rand() % 30 + 1) + 70;
    }
    else if (sub_choice == 4)
    {
        srand(time(0));
        random_question = (rand() % 30 + 1) + 150;
    }
    return random_question;
}
void start_quiez::set_sub()
{
    ifstream in;
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        in.open("test.txt");

        int k = random_question_generator();
        while (in >> question_no && in >> ans && getline(in, option1) && getline(in, option2) && getline(in, option3) && getline(in, option4) && getline(in, question))
        {
            if (question_no == k)
            {
                count++;
                system("color 0A");
                cout << endl << "Q." << count << "] " << question << endl;
                cout << "\n1)" << option1;
				cout << "\n2)" << option2;
                cout << "\n3)" << option3;
                cout << "\n4)" << option4 << endl;
                cout << "\nANS = ";
                cin >> user_ans;
                answer_check();
                sleep(3);
                system("cls");
            }
        }

        in.close();
    }
    if (full != 1)
    {
        count = 0;
        score_display();
        score_display();
        score_display();
        update();
    }
}

void start_quiez::full_test()
{
    max = 30;
    for (int j = 2; j <= 4; j++)
    {
        sub_choice = j;
        set_sub();
        if (j == 4)
        {
        	full = 0;
		}
    }
}
void start_quiez ::answer_check()
{
    if (user_ans == ans)
    {
        cout << "You have selected a right answer.\n" << endl;
        point++;
    }
    else
    {
        cout << "You have selected a wrong answer." << endl;
        cout << "The correct answer is option: " << ans << endl << endl;
    }
}
void start_quiez ::score_display()
{
	system("cls");
	system("color 05");
    cout << "\n\nYour score: " << point << "/ " << max << "\n";
    point = 0;
    max = 10;
    cout<<"\n______________________________________________________________________________________________________\n\n";
}

class login : public start_quiez
{
protected:
    char email[20], password[20], first_name[20], last_name[20], confirm[20];
    int value, succesful = 0, take = 0, attempts = 0, lchoice;
    string dolchoice;
    
public:
    void sign_option()
    {
    	system("cls");
        cout << endl << "1)SIGN UP   (If you don't have a account)";
        cout << endl << "2)LOGIN     (Already have account)";
        cout << endl << "3)Back";
        cout << "\n\nEnter the choice: ";
        cin>>dolchoice ;
        try{
            lchoice = stoi(dolchoice);
        }
        catch(exception e){
             lchoice  = -1 ;
        }
    }
    void reverse();
    int data_saver();
    int data_chacker();
};
class sign : public login
{

public:
    void log()
    {  
	    if(take!=1)
        	sign_option();
        if (lchoice == 3)
        {
            cout << "Program exited succesfully.";
        }
        else if (lchoice == 1)
        {
        	system("cls");
            cout << "Enter the first name : ";
            cin >> first_name;
            cout << "Enter the last name : ";
            cin >> last_name;

            reverse();
        }
        else if (lchoice == 2)
        {
        	system("cls");
            cout << "Enter your email ID : ";
            cin >> email;
            strcpy(mail, email);
            cout << "\nEnter your password : ";
            cin >> password;
            strcpy(pass, password);
            take = data_saver();
            if (attempts == 3)
            {  take  = 0 ;
                cout << "You have reached maximum attempts.\nIf you don't have account, Create account.";
                attempts = 0 ;
                sleep(3);
                if (lchoice != 3)
                    log();
            }
            else if (take == 1)
                log();
        }
        else
        {
            cout << "\nYou have entered wrong choice." << endl;
            sleep(3);
            system("cls");
            log();
        }
    }
};
void login::reverse()
{
    cout << "\n\nEnter your email ID : ";
    cin >> email;
    cout << "\nEnter your password : ";
    cin >> password;
    strcpy(mail, email);
    strcpy(pass, password);

    cout << endl;
    int value = data_chacker();
    if (value == 0)
    {
        cout << "\n\nConfirm password : ";
        cin >> confirm;
        if (!strcmp(password, confirm))
        {
            data d3;
            strcpy(d3.user_email, email);
            strcpy(d3.user_pass, password);
            strcpy(d3.user_fname, first_name);
            strcpy(d3.user_lname, last_name);
            d3.physics_mocks = 0;
            d3.chemistry_mock = 0;
            d3.mathematics_mock = 0;
            d3.pcm_mock = 0;
            ofstream out;
            out.open("login.txt", ios::binary | ios::app);
            out.write((char *)&d3, sizeof(d3));

            out.close();
            system("cls");
            cout << "________________________________________________________________________________________________________\n";
            cout << "Hey, " <<first_name << "\nYour account is created sucessfully.\nNow you can solve mock test\n";
            cout << "________________________________________________________________________________________________________\n\n";
            update();
        }
        else
        {
            cout << "Wrong password.\nConfirm Password again" << endl;
            reverse();
        }
    }
    else
        reverse();
}
int login::data_saver()
{
    data d1;
    fstream fin;
    fin.open("login.txt", ios::binary | ios::in | ios::out);
    int check = 0;
    fin.seekg(0);
    while (fin.read((char *)&d1, sizeof(d1)))
    {
        if (!strcmp(d1.user_pass, password) && !strcmp(d1.user_email, email))
        {
            succesful = 1;
            cout << "\nYou have succesfully signed in as : " << d1.user_fname;
			cout << "\nNow you can solve your mock test " << endl;
			cout << "___________________________________________________________\n";
            check = 1;
            update();
            break;
        }
    }
    if (check == 0)
    {
    	attempts++;
        cout << "You have entered wrong password / email ID.\nPlease try again.\n\n";
        sleep(3);
        return 1;
    }
    return 0;
}

int login ::data_chacker()
{
    data d2;
    ifstream fin;
    fin.open("login.txt", ios::binary);
    while (fin.read((char *)&d2, sizeof(d2)))
    {
        if (!strcmp(d2.user_email, email) && !strcmp(d2.user_pass, password))
        {
            cout << "This e-mail ID and password is alredy used.\nChoose another password and email.\n";
            return 1;
        }
        else if (!strcmp(d2.user_email, email))
        {
            cout << "This e-mail ID is alredy used.\nChoose another email ID.\n";
            return 1;
        }
        else if (!strcmp(d2.user_pass, password))
        {
            cout << "This password is alredy used.\nChoose another password.\n";
            return 1;
        }
    }
    return 0;
}

int main()
{
    int   select;
   string str  ;
    periodic p;
    system("cls");
    system("color 05");
    cout << "SKILL UP\n\nWelcome!";
    sleep(4);
    sign q;
    while (select != 3)
    {
    	system("cls");
        cout << "\n1)Explore the periodic table\n2)Mock test\n3)Exit\n\n";
        cout << "Enter your choice: ";

        cin>>str;
        try{
           select = stoi(str);
        }
        catch(exception e){
            select = 10;
        }
        
        switch (select)
        {
        	case 1:	p.search();				break;
        	case 2:	q.log();				break;
        	case 3:	system("color 03");		
						system("cls");			
						cout << "\n\n!! Closing Application !!\n\nThank you\n\n";	break;
        	default:	cout << "You have entered wrong choice" << endl;
        				sleep(3);
        }
    }
    return 0;
}
