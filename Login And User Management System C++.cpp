#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
class User 
{
private:
    string username;
    string password;
public:
    User(string name, string pass) 
	 {
        username = name;
        password = pass;
    }
    string getUsername()
	 {
        return username;
    }
    string getPassword() 
	 {
        return password;
    }
};

class UserManager 
{
private:
    vector<User> users;
public:
    void registerUser() 
	 {
        string username;
        string password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        User newUser(username, password);
        users.push_back(newUser);
        cout << "User Registered Successfully..." << endl;
    }

    bool loginUser(const string& name, const string& pass) 
	 {
        for (int i = 0; i < users.size(); i++) 
		  {
            if (users[i].getUsername() == name && users[i].getPassword() == pass) 
				{
                cout << "Login Successfully..." << endl;
                return true;
            }
        }
        cout << "Invalid Username or Password..." << endl;
        return false;
    }

    void showUsers() 
	 {
        cout << "...Users List..." << endl;
        for (int i = 0; i < users.size(); i++) 
		  {
            cout << users[i].getUsername() << endl;
        }
    }

    void searchUser(const string& username) 
	 {
        bool found = false;
        for (int i = 0; i < users.size(); i++) 
		  {
            if (users[i].getUsername() == username) 
				{
                cout << "User Found: " << users[i].getUsername() << endl;
                found = true;
            }
        }
        if (!found) 
		  {
            cout << "User Not Found" << endl;
        }
    }

    void deleteUser(const string& username) 
	 {
        bool found = false;
        for (int i = 0; i < users.size(); i++) 
		  {
            if (users[i].getUsername() == username) 
				{
                users.erase(users.begin() + i);
                cout << "User Removed Successfully..." << endl;
                found = true;
                break; 
            }
        }
        if (!found) 
		  {
            cout << "User Not Found" << endl;
        }
    }
};

void displayMenu() 
{
    	  cout<<"\t| Press 1 to REGISTER                      |"<<endl;
    	  cout<<"\t| Press 2 to LOGIN                         |"<<endl;    
    	  cout<<"\t| Press 3 to SHOW USER LIST                |"<<endl;
    	  cout<<"\t| Press 4 to SEARCH USER                   |"<<endl; 
    	  cout<<"\t| Press 5 to DELETE USER                   |"<<endl; 
    	  cout<<"\t| Press 6 to EXIT                          |"<<endl; 
    	  cout<<"Enter your choice: ";
        cout<<endl; 
        
}

int main() 
{
	     cout<<"\n\n";
	     cout<<"\t\t\t\t\t\t_______________________________________________________________\n\n\n";
	 	  cout<<"\t\t\t\t\t\t                      WELCOME TO LOGIN PAGE                       \n\n";
    	  cout<<"\t\t\t\t\t\t____________________        MENU        _______________________\n\n";
    	  cout<<"                                                                     \n\n";
        cout<<endl;
    UserManager userManager;
    int option;
    char choice;
    bool running = true;

    while (running) 
	 {
        displayMenu();
        cin >> option;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(option) 
		  {
            case 1:
                userManager.registerUser();
                break;
            case 2: 
				{
                string username, password;
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                userManager.loginUser(username, password);
                break;
            }
            case 3:
                userManager.showUsers();
                break;
            case 4: 
				{
                string username;
                cout << "Enter Username: ";
                cin >> username;
                userManager.searchUser(username);
                break;
            }
            case 5: 
				{
                string username;
                cout << "Enter Username: ";
                cin >> username;
                userManager.deleteUser(username);
                break;
            }
            case 6:
                running = false;
                break;
            default:
                cout << "Invalid Option. Please try again." << endl;
        }
        
        if (running) 
		  {
		  	   cout<<"\n\n***********************************\n\n";
            cout << "Do you want to continue [yes/no]? : ";
            
            cin >> choice;
            running = (choice == 'y' || choice == 'Y');
        }
    }

    return 0;
}

