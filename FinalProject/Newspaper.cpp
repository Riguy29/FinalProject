#include "Newspaper.h"

void Newspaper::ToString()
{
    LibraryMedia::ToString();
    cout << " Publish Rate: ";
    switch (publishRate)
    {
    case Newspaper::daily:
        cout << " daily" << endl;
        break;
    case Newspaper::weekly:
        cout << " weekly" << endl;
        break;
    default:
        break;
    }
}

void Newspaper::SetPublishRate()
{
    bool isValid;
    int choice;
    do
    {
        cout << "How often is this newspaper published?" << endl;
        cout << "1. Daily" << endl;
        cout << "2. Weekly" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        try
        {
            switch (choice)
            {
            case 1:
                publishRate = Newspaper::daily;
                return; //If input is valid, return
                break;
            case 2:
                publishRate = Newspaper::weekly;
                return; //If valid input, return
                break;
            default:
                throw(0);
                break;
            }
        }
        catch (int errorCode)
        {
            if (errorCode == 0) {
                system("cls");
                cout << "Invalid Input, try again";
            }
        }
    } while (true);
}

Newspaper::NewspaperPublishRates Newspaper::GetPublishRate()
{
    return NewspaperPublishRates();
}

Newspaper::~Newspaper()
{
}

Newspaper::Newspaper() : LibraryMedia()
{
    publishRate = weekly;
}

Newspaper::Newspaper(Newspaper& copy): LibraryMedia(copy.mediaID, copy.title, copy.mediaType, copy.price, copy.category, copy.subCategory, copy.inventoryCount, copy.doner)
{
    publishRate = copy.publishRate;
}

Newspaper::Newspaper(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat,
    const string& mediaSubCat, int mediaCount, const string& mediaDoner, NewspaperPublishRates newspaperPublishRate)
    : LibraryMedia(id, mediaTitle, newspaper, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{
    publishRate = newspaperPublishRate;
}
