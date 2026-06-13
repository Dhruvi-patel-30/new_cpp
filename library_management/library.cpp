#include <iostream>
using namespace std;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    // Getters
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

   
    void setTitle(string t)
    {
        title = t;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    void setDueDate(string d)
    {
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};


class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        if (i.length() != 13)
            throw "ISBN must contain 13 digits";

        isbn = i;
    }

    void checkOut()
    {
        cout << "\nBook Checked Out Successfully!";
    }

    void returnItem()
    {
        cout << "\nBook Returned Successfully!";
    }

    void displayDetails()
    {
        cout << "\n----- Book Details -----";
        cout << "\nTitle : " << getTitle();
        cout << "\nAuthor : " << getAuthor();
        cout << "\nDue Date : " << getDueDate();
        cout << "\nISBN : " << isbn << endl;
    }
};


class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur <= 0)
            throw "Duration cannot be negative";

        duration = dur;
    }

    void checkOut()
    {
        cout << "\nDVD Checked Out Successfully!";
    }

    void returnItem()
    {
        cout << "\nDVD Returned Successfully!";
    }

    void displayDetails()
    {
        cout << "\n----- DVD Details -----";
        cout << "\nTitle : " << getTitle();
        cout << "\nAuthor : " << getAuthor();
        cout << "\nDue Date : " << getDueDate();
        cout << "\nDuration : " << duration << " minutes" << endl;
    }
};

int main()
{
    const int MAX_ITEMS = 10;

    LibraryItem *libraryItems[MAX_ITEMS];

    int count = 0;
    int choice;

    do
    {
        cout << "\n\n===== Library Management System =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add DVD";
        cout << "\n3. Display All Items";
        cout << "\n4. Check Out Item";
        cout << "\n5. Return Item";
        cout << "\n6. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                string title, author, date, isbn;

                cout << "\nEnter Title : ";
                cin >> title;

                cout << "Enter Author : ";
                cin >> author;

                cout << "Enter Due Date : ";
                cin >> date;

                cout << "Enter ISBN (13 digits) : ";
                cin >> isbn;

                libraryItems[count++] =
                    new Book(title, author, date, isbn);

                cout << "\nBook Added Successfully!";
                break;
            }

            case 2:
            {
                string title, author, date;
                int duration;

                cout << "\nEnter Title : ";
                cin >> title;

                cout << "Enter Author : ";
                cin >> author;

                cout << "Enter Due Date : ";
                cin >> date;

                cout << "Enter Duration : ";
                cin >> duration;

                libraryItems[count++] =
                    new DVD(title, author, date, duration);

                cout << "\nDVD Added Successfully!";
                break;
            }

            case 3:
            {
                for (int i = 0; i < count; i++)
                {
                    libraryItems[i]->displayDetails();
                }
                break;
            }

            case 4:
            {
                int index;

                cout << "\nEnter Item Number (1-" << count << ") : ";
                cin >> index;

                libraryItems[index - 1]->checkOut();

                break;
            }

            case 5:
            {
                int index;

                cout << "\nEnter Item Number (1-" << count << ") : ";
                cin >> index;

                libraryItems[index - 1]->returnItem();

                break;
            }

            case 6:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
            }
        }
        catch (const char *msg)
        {
            cout << "\nException : " << msg;
        }
        catch (...)
        {
            cout << "\nUnknown Exception!";
        }

    } while (choice != 6);


    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

}