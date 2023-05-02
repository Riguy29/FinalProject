#include "Periodical.h"

void Periodical::ToString()
{
	LibraryMedia::ToString();
	cout << " Publish Rate: ";
	switch (publishRate)
	{
	case Periodical::monthly:
		cout << "Monthly";
		break;
	case Periodical::bimonthly:
		cout << "BiMontly";
		break;
	case Periodical::yearly:
		cout << "Yearly";
		break;
	case Periodical::halfYearly:
		cout << "Half Yearly";
		break;
	default:
		break;
	}
}

void Periodical::SetPublishRate()
{
    bool isValid;
    int choice;
    do
    {
        cout << "How often is this periodical published?" << endl;
        cout << "1. Monthly" << endl;
        cout << "2. BiMonthly" << endl;
        cout << "3. Half Yearly" << endl;
        cout << "4. Yearly" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        try
        {
            switch (choice)
            {
            case 1:
                publishRate = Periodical::monthly;
                return; //If input is valid, return
                break;
            case 2:
                publishRate = Periodical::bimonthly;
                return; //If valid input, return
                break;
            case 3:
                publishRate = Periodical::halfYearly;
                return; //If valid input, return
                break;
            case 4:
                publishRate = Periodical::yearly;
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

Periodical::PeriodicalPublishRates Periodical::GetPublishRate()
{
	return PeriodicalPublishRates();
}

Periodical::~Periodical()
{
}

Periodical::Periodical() : LibraryMedia()
{
	publishRate = monthly;
}

Periodical::Periodical(Periodical& newP) : LibraryMedia(newP)
{
	publishRate = newP.publishRate;
}

Periodical::Periodical(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, const string& mediaDoner, PeriodicalPublishRates rate) 
	: LibraryMedia(id, mediaTitle, periodical, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{
	publishRate = rate;
}
