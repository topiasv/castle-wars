#include "card.h"

Card::Card(QString name,
           ModelSuit::SuitType suit,
           qint8 cost,
           QHash<QString, qint8> effect,
           QObject *parent) : QObject(parent)
{
    this->name = name;
    this->suit = suit;
    this->cost = cost;
    this->effect = effect;
}
