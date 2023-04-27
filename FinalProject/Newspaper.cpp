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

void Newspaper::SetPublishRate(NewspaperPublishRates rate)
{
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

Newspaper::Newspaper(Newspaper& copy): LibraryMedia(copy.mediaID, *copy.title, copy.mediaType, copy.price, *copy.category, *copy.subCategory, copy.inventoryCount, *copy.doner)
{
    publishRate = copy.publishRate;
}

Newspaper::Newspaper(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat,
    const string& mediaSubCat, int mediaCount, const string& mediaDoner, NewspaperPublishRates newspaperPublishRate)
    : LibraryMedia(id, mediaTitle, newspaper, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{
    publishRate = newspaperPublishRate;
}
